all:

suvak1.js:HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c HTS_vocoder.c svradesh.c pre.js
	emcc -Wcast-align -Wover-aligned -O2 HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c svradesh.c -s EXPORTED_FUNCTIONS='["_main","_hts_armbh","_hts_vacnm","_hts_vrnanvh","_hts_anukalh","_svradesadesh", "_svrstapnm","_pro_vacnarmbh","_pro_sbdh"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -o suvak1.js -s SAFE_HEAP=1 -s WARN_UNALIGNED=1 --post-js pre.js --preload-file assets -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -s ALLOW_TABLE_GROWTH=1
	
suvakworker.js:HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c HTS_vocoder.c svradesh.c pre.js worker.js 2pre.js
	cat pre.js worker.js > suvakpost.js && \
	emcc -Wcast-align -Wover-aligned -O2 HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c  svradesh.c -s EXPORTED_FUNCTIONS='["_main","_hts_armbh","_hts_vacnm","_hts_vrnanvh","_hts_anukalh","_svradesadesh","_svrprivrtnm","_pro_vegh", "_svrstapnm","_pro_vacnarmbh","_pro_sbdh", "_pro_sbdah"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -o suvakworker.js -s WARN_UNALIGNED=1 --extern-pre-js 2pre.js --post-js suvakpost.js --embed-file assets -s ALLOW_MEMORY_GROWTH=1 -s BINARYEN_ASYNC_COMPILATION=0 -s SINGLE_FILE=1 && \
	sed -i -e 's/else{throw new Error(xhr/else{abort("network1");throw new Error(xhr/g' suvakworker.js && \
	sed -i -e 's/xhr.onerror=function(event){/xhr.onerror=function(event){abort("network2");/g' suvakworker.js && \
	sed -i -e 's/xhr.status===304))throw new Error(\"Couldn'\''t load \"+url+\". Status: \"+xhr.status);/xhr.status===304)){abort("network3");throw new Error("couldnot load");}/g' suvakworker.js && \
	sh ed.sh
	
suvakww.js:HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c HTS_vocoder.c svradesh.c pre.js worker3.js 3pre.js
	cat pre.js worker3.js > suvakpost3.js && \
	emcc -Wcast-align -Wover-aligned -O3 HTS_audio.c HTS_engine.c HTS_label.c HTS_model.c HTS_sstream.c hts_engine.c HTS_gstream.c HTS_misc.c HTS_pstream.c  svradesh.c -s EXPORTED_FUNCTIONS='["_main","_hts_armbh","_hts_vacnm","_hts_vrnanvh","_hts_anukalh","_svradesadesh", "_svrstapnm","_pro_vacnarmbh","_pro_sbdh", "_pro_sbdah"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -o suvakww.js -s WARN_UNALIGNED=1 --extern-pre-js 3pre.js --post-js suvakpost3.js --preload-file assets -s ALLOW_MEMORY_GROWTH=1 && \
	sed -i -e 's/else{throw new Error(xhr/else{abort("network1");throw new Error(xhr/g' suvakww.js && \
	sed -i -e 's/xhr.onerror=function(event){/xhr.onerror=function(event){abort("network2");/g' suvakww.js && \
	sed -i -e 's/xhr.status===304))throw new Error(\"Couldn'\''t load \"+url+\". Status: \"+xhr.status);/xhr.status===304)){abort("network3");throw new Error("couldnot load");}/g' suvakww.js
	
suvak.js:suvak2.js suvakmodule.js suvakworker.js
	#echo "const suvakworker=\`">suvak.js && \
	#cat suvakworker.js>>suvak.js && \
	#echo "\`;">>suvak.js && \
	cat suvak2.js suvakmodule.js > suvak.js
	
pages:
	sh pages.sh
