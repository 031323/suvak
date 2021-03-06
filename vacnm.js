/*
 * Copyright (C) 2014-2017 Eitan Isaacson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see: <http://www.gnu.org/licenses/>.
 */

/* An audio node that can have audio chunks pushed to it */

function PushAudioNode(context, start_callback, end_callback, buffer_size) {
  this.context = context;
  this.start_callback = start_callback;
  this.end_callback = end_callback;
  this.buffer_size = buffer_size || 4096;
  this.samples_queue = [];
  this.scriptNode = context.createScriptProcessor(this.buffer_size, 1, 1);
  this.connected = false;
  this.sinks = [];
  this.startTime = 0;
  this.closed = false;
  this.track_callbacks = new Map();
}

PushAudioNode.prototype.push = function(chunk) {
  if (this.closed) {
    throw 'Cannot push more chunks after node was closed';
  }
  this.samples_queue.push(chunk);
  if (!this.connected) {
    if (!this.sinks.length) {
      throw 'No destination set for PushAudioNode';
    }
    this._do_connect();
  }
}

PushAudioNode.prototype.close = function() {
  this.closed = true;
}

PushAudioNode.prototype.connect = function(dest) {
  this.sinks.push(dest);
  if (this.samples_queue.length) {
    this._do_connect();
  }
}

PushAudioNode.prototype._do_connect = function() {
  if (this.connected) return;
  this.connected = true;
  for (var dest of this.sinks) {
    this.scriptNode.connect(dest);
  }
  this.scriptNode.onaudioprocess = this.handleEvent.bind(this);
}

PushAudioNode.prototype.disconnect = function() {
  this.scriptNode.onaudioprocess = null;
  this.scriptNode.disconnect();
  this.connected = false;
}

PushAudioNode.prototype.addTrackCallback = function(aTimestamp, aCallback) {
  var callbacks = this.track_callbacks.get(aTimestamp) || [];
  callbacks.push(aCallback);
  this.track_callbacks.set(aTimestamp, callbacks);
}

PushAudioNode.prototype.handleEvent = function(evt) {
  if (!this.startTime) {
    this.startTime = evt.playbackTime;
    if (this.start_callback) {
      this.start_callback();
    }
  }

  var currentTime = evt.playbackTime - this.startTime;
  var playbackDuration = this.scriptNode.bufferSize / this.context.sampleRate;
  for (var entry of this.track_callbacks) {
    var timestamp = entry[0];
    var callbacks = entry[1];
    if (timestamp < currentTime) {
      this.track_callbacks.delete(timestamp);
    } else if (timestamp < currentTime + playbackDuration) {
      for (var cb of callbacks) {
        cb();
      }
      this.track_callbacks.delete(timestamp);
    }
  }

  var offset = 0;
  while (this.samples_queue.length && offset < evt.target.bufferSize) {
    var chunk = this.samples_queue[0];
    var to_copy = chunk.subarray(0, evt.target.bufferSize - offset);
    if (evt.outputBuffer.copyToChannel) {
      evt.outputBuffer.copyToChannel(to_copy, 0, offset);
    } else {
      evt.outputBuffer.getChannelData(0).set(to_copy, offset);
    }
    offset += to_copy.length;
    chunk = chunk.subarray(to_copy.length);
    if (chunk.length)
      this.samples_queue[0] = chunk;
    else
      this.samples_queue.shift();
  }

  if (!this.samples_queue.length && this.closed) {
    if (this.end_callback) {
      this.end_callback(evt.playbackTime - this.startTime);
    }
    this.disconnect();
  }
}



/* Code specific to the demo */

var ctx = new (window.AudioContext || window.webkitAudioContext)();
var tts;
var pusher;
var pusher_buffer_size = 4096;
var chunkID = 0;

function stgnm() {
  console.log('Inside stop()');
  if (pusher) {
    console.log('  Calling pusher.disconnect...');
    pusher.disconnect();
    console.log('  Calling pusher.disconnect... done');
    pusher = null;
  }
  console.log('Leaving stop()');
} // end of stop()

function vacnm(text,antym) {
	console.log(text)
  console.log('Inside speak()');

  if (ctx.state === 'suspended') {
    console.log('Resuming AudioContext...');
    ctx.resume();
    console.log('Resuming AudioContext... done');
  }
  console.log('  Stopping...');
  stgnm();
  console.log('  Stopping... done');

  console.log('  Setting rate...');
  //tts.set_rate(Number(document.getElementById('rate').value));
  tts.set_rate('100');
  console.log('  Setting rate... done');
  console.log('  Setting pitch...');
  //tts.set_pitch(Number(document.getElementById('pitch').value));
  tts.set_pitch('30');
  console.log('  Setting pitch... done');
  console.log('  Setting voice...');
  //tts.set_voice(document.getElementById('voice').value);
  tts.set_voice('sa');
  console.log('  Setting voice... done');
	
  var now = Date.now();
  chunkID = 0;
  console.log('  Creating pusher...');
  pusher = new PushAudioNode(
    ctx,
    function() {
      //console.log('PushAudioNode started!', ctx.currentTime, pusher.startTime);
    },
    antym,
    pusher_buffer_size
  );
  pusher.connect(ctx.destination);
  console.log('  Creating pusher... done');

  //var user_text = document.getElementById('texttospeak').value;
  var user_text=UTF8ToString(Module.ccall('anulekh','number',['string'],[text]));
  //user_text='[[a]] [[q]] [[i]] <mark /> [[Ru___ ]]'
  console.log(user_text)
  // actual synthesis
  console.log('  Calling synthesize...');
  tts.synthesize(
    user_text,
    function cb(samples, events) {
    	console.log(events)
      //console.log('  Receiving synthesis samples...');
      if (!samples) {
        if (pusher) {
          pusher.close();
        }
        return;
      }
      if (pusher) {
        //console.log('  Pushing chunk ' + chunkID, Date.now());
        pusher.push(new Float32Array(samples));
        ++chunkID;
      }
      if (now) {
        //console.log('  Latency:', Date.now() - now);
        now = 0;
      }
      //console.log('  Leaving synt cb');
    } // end of function cb
  ); // end of tts.synthesize()
  console.log('  Calling synthesize... done');  
  console.log('Leaving speak()');
} // end of speak()

function ipa() {
  
  console.log("Synthesizing ipa ... ");
  var ts = new Date();
  var user_text = document.getElementById('texttospeak').value;

 //user_text = user_text.repeat(50);
  
  tts.set_voice(document.getElementById('voice').value);

  tts.synthesize_ipa(user_text, function(result) { 
    var te = new Date();
    document.getElementById('ipaarea').value = result.ipa;
    console.log("Ipa synthesis done in " + (te-ts) + " ms.")
  });
}

function speakAndIpa() {
  speak();
  ipa();
}

function resetPitch() {
  document.getElementById('pitch').value = 50;
}

function resetRate() {
  document.getElementById('rate').value = 175;
}

function resetVoice() {
  document.getElementById('default-voice').selected = true;
}
var scripts = document.getElementsByTagName("script"),
    src = scripts[scripts.length-1].src;
    
function armbh(cb) {
	workerUrl=src.substring(0, src.lastIndexOf("/"))+'/js/espeakng.worker.js';
	//workerUrl="https://031323.github.io/suvak/js/espeakng.worker.js"
	/*var blob;
			blob = new Blob(["importScripts('" + workerUrl + "');"], { "type": 'application/javascript' });
		
	var url = window.URL || window.webkitURL;
	var blobUrl = url.createObjectURL(blob);
	console.log(blobUrl)*/
  console.log('Creating eSpeakNG instance...');
  window.cb=cb
  tts = new eSpeakNG(
  	workerUrl,
    function()
    {
			window.espeak='1';
    	if(window.suvacnm==='1')
    		window.cb()
    }
  );
    
  console.log('Creating eSpeakNG instance... done');
}
