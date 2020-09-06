#include<list>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#include<fstream>
#include<cstdlib>

enum वर्णः {अत्=1,आत्,इत्,ईत्,उत्,ऊत्,ऋत्,ॠत्,ऌत्,ॡत्,एत्,ऐत्,ओत्,औत्,
					कः,खः,गः,घः,ङः,चः,छः,जः,झः,ञः,टः,ठः,डः,ढः,णः,तः,थः,दः,धः,नः,पः,फः,बः,भः,मः,यः,रः,लः,वः,शः,षः,सः,हः,
					विसर्गः,अनुस्वारः,लँः};




[[maybe_unused]] constexpr वर्णः
		स्वरः[]={अत्,आत्,इत्,ईत्,उत्,ऊत्,ऋत्,ॠत्,ऌत्,ॡत्,एत्,ऐत्,ओत्,औत्},
		ह्रस्वः[]={अत्,इत्,उत्,ऋत्,ऌत्},
		दीर्घः[]={आत्,ईत्,ऊत्,ॠत्,ॡत्,एत्,ऐत्,ओत्,औत्},
		व्यञ्जनः[]={कः,खः,गः,घः,ङः,चः,छः,जः,झः,ञः,टः,ठः,डः,ढः,णः,तः,थः,दः,धः,नः,पः,फः,बः,भः,मः,यः,रः,लः,वः,शः,षः,सः,हः},
		उष्मा[]={शः,षः,सः,हः},
		अन्तःस्थः[]={यः,रः,लः,वः},
		नासिक्यः[]={अनुस्वारः,ङः,ञः,णः,नः,मः},
		वर्गीयः[]={कः,खः,गः,घः,ङः,चः,छः,जः,झः,ञः,टः,ठः,डः,ढः,णः,तः,थः,दः,धः,नः,पः,फः,बः,भः,मः},
		कवर्गीयः[]={कः,खः,गः,घः,ङः},
		चवर्गीयः[]={चः,छः,जः,झः,ञः},
		टवर्गीयः[]={टः,ठः,डः,ढः,णः},
		तवर्गीयः[]={तः,थः,दः,धः,नः},
		पवर्गीयः[]={पः,फः,बः,भः,मः},
		खरः[]={कः,चः,टः,तः,पः},
		अतिखरः[]={खः,छः,ठः,थः,फः},
		मृदुः[]={गः,जः,डः,दः,बः},
		घोषः[]={घः,झः,ढः,धः,भः};

template <size_t गणना>
bool अधिकारः(वर्णः द्रष्टव्यः,const वर्णः (&गणः)[गणना])
{
	for(int क्रमः=0;क्रमः<गणना;क्रमः++)if(द्रष्टव्यः==गणः[क्रमः])return true;
	return false;
}

auto वर्णनिर्णयः(const char* पाठः)
{
	std::list<वर्णः> वर्णाः;
	std::list<int> स्वराः;
	std::list<int> स्वरक्रमः;
	auto समत्वम्=[](const char* प्रथमः,const char* द्वितीयः)
	{
		for(int क्रमः=0;क्रमः<3;क्रमः++)
			if(प्रथमः[क्रमः]!=द्वितीयः[क्रमः])return false;
		return true;
	};
	auto लक्ष्यः=[समत्वम्](const char* अङ्कः,वर्णः &उपस्थितः)
	{
		उपस्थितः=
			समत्वम्(अङ्कः,"क")?कः:समत्वम्(अङ्कः,"ख")?खः:समत्वम्(अङ्कः,"ग")?गः:समत्वम्(अङ्कः,"घ")?घः:समत्वम्(अङ्कः,"ङ")?ङः:
			समत्वम्(अङ्कः,"च")?चः:समत्वम्(अङ्कः,"छ")?छः:समत्वम्(अङ्कः,"ज")?जः:समत्वम्(अङ्कः,"झ")?झः:समत्वम्(अङ्कः,"ञ")?ञः:
			समत्वम्(अङ्कः,"ट")?टः:समत्वम्(अङ्कः,"ठ")?ठः:समत्वम्(अङ्कः,"ड")?डः:समत्वम्(अङ्कः,"ढ")?ढः:समत्वम्(अङ्कः,"ण")?णः:
			समत्वम्(अङ्कः,"त")?तः:समत्वम्(अङ्कः,"थ")?थः:समत्वम्(अङ्कः,"द")?दः:समत्वम्(अङ्कः,"ध")?धः:समत्वम्(अङ्कः,"न")?नः:
			समत्वम्(अङ्कः,"प")?पः:समत्वम्(अङ्कः,"फ")?फः:समत्वम्(अङ्कः,"ब")?बः:समत्वम्(अङ्कः,"भ")?भः:समत्वम्(अङ्कः,"म")?मः:
			समत्वम्(अङ्कः,"य")?यः:समत्वम्(अङ्कः,"र")?रः:समत्वम्(अङ्कः,"ल")?लः:समत्वम्(अङ्कः,"व")?वः:
			समत्वम्(अङ्कः,"श")?शः:समत्वम्(अङ्कः,"ष")?षः:समत्वम्(अङ्कः,"स")?सः:समत्वम्(अङ्कः,"ह")?हः:
			समत्वम्(अङ्कः,"ः")?विसर्गः:समत्वम्(अङ्कः,"ं")?अनुस्वारः:
			समत्वम्(अङ्कः,"अ")?अत्:समत्वम्(अङ्कः,"आ")||समत्वम्(अङ्कः,"ा")?आत्:समत्वम्(अङ्कः,"इ")||समत्वम्(अङ्कः,"ि")?इत्:समत्वम्(अङ्कः,"ई")||समत्वम्(अङ्कः,"ी")?ईत्:
			समत्वम्(अङ्कः,"उ")||समत्वम्(अङ्कः,"ु")?उत्:समत्वम्(अङ्कः,"ऊ")||समत्वम्(अङ्कः,"ू")?ऊत्:समत्वम्(अङ्कः,"ऋ")||समत्वम्(अङ्कः,"ृ")?ऋत्:समत्वम्(अङ्कः,"ॠ")||समत्वम्(अङ्कः,"ॄ")?ॠत्:
			समत्वम्(अङ्कः,"ऌ")||समत्वम्(अङ्कः,"ॢ")?ऌत्:समत्वम्(अङ्कः,"ॡ")||समत्वम्(अङ्कः,"ॣ")?ॡत्:समत्वम्(अङ्कः,"ए")||समत्वम्(अङ्कः,"े")?एत्:समत्वम्(अङ्कः,"ऐ")||समत्वम्(अङ्कः,"ै")?ऐत्:
			समत्वम्(अङ्कः,"ओ")||समत्वम्(अङ्कः,"ो")?ओत्:समत्वम्(अङ्कः,"औ")||समत्वम्(अङ्कः,"ौ")?औत्:समत्वम्(अङ्कः,"।")||समत्वम्(अङ्कः,"॥")?(वर्णः)0:(वर्णः)0;
			if(!(समत्वम्(अङ्कः,"।")||समत्वम्(अङ्कः,"॥"))&&उपस्थितः==0)return false;
			else return true;
	};
	auto प्रक्षिप्तः=[समत्वम्](const char* अङ्कः)
	{return समत्वम्(अङ्कः,"ा")||समत्वम्(अङ्कः,"ि")||समत्वम्(अङ्कः,"ी")||समत्वम्(अङ्कः,"ु")||समत्वम्(अङ्कः,"ू")||समत्वम्(अङ्कः,"ृ")||समत्वम्(अङ्कः,"ॄ")||
		समत्वम्(अङ्कः,"ॢ")||समत्वम्(अङ्कः,"ॣ")||समत्वम्(अङ्कः,"े")||समत्वम्(अङ्कः,"ै")||समत्वम्(अङ्कः,"ो")||समत्वम्(अङ्कः,"ौ");};
	const int अनुदात्तलक्षणम् = -1;
	const int स्वरितलक्षणम् = -2;
	const int स्वरलक्षणम् = -3;
	const int मौनलक्षणम् = -7;
	while(*पाठः!='\0')
	{
		if(*पाठः>=0){पाठः++;continue;}
		वर्णः उपस्थितः;
		if(समत्वम्(पाठः,"॒"))
			स्वराः.push_back(अनुदात्तलक्षणम्);
		else if(समत्वम्(पाठः,"॑"))
			स्वराः.push_back(स्वरितलक्षणम्);
		if(!लक्ष्यः(पाठः,उपस्थितः)){पाठः+=3;continue;}
		if(अधिकारः(उपस्थितः,वर्गीयः)||अधिकारः(उपस्थितः,उष्मा)||अधिकारः(उपस्थितः,अन्तःस्थः))
		{
			if(*(पाठः+3)=='\0'||*(पाठः+3)>=0){वर्णाः.push_back(उपस्थितः);वर्णाः.push_back(अत्);}
			else if(समत्वम्(पाठः+3,"्")){वर्णाः.push_back(उपस्थितः);पाठः+=3;}
			else if(प्रक्षिप्तः(पाठः+3))वर्णाः.push_back(उपस्थितः);
			else {वर्णाः.push_back(उपस्थितः);वर्णाः.push_back(अत्);}
		}
		else वर्णाः.push_back(उपस्थितः);
		if(अधिकारः(वर्णाः.back(), स्वरः)) {
			if(वर्णाः.size()>1 && अधिकारः(*std::prev(वर्णाः.end(),2), स्वरः)) {
				वर्णाः.insert(std::prev(वर्णाः.end(),1),(वर्णः)-1);
			}
			स्वराः.push_back(स्वरलक्षणम्);
		}
		else if(वर्णाः.back()==0)
			स्वराः.push_back(मौनलक्षणम्);
		पाठः+=3;
	}
	const int उदात्तः = -4;
	const int अनुदात्तः = -5;
	const int स्वरितः = -6;
	int गतिः = उदात्तः;
	for(auto लक्षणपदम्=स्वराः.begin(); लक्षणपदम्!=स्वराः.end(); ++लक्षणपदम्) {
		auto const पश्चिमम् = std::next(लक्षणपदम्, 1);
		if(*लक्षणपदम्==मौनलक्षणम्)
			गतिः=उदात्तः;
		else if(*लक्षणपदम्==स्वरलक्षणम् && (पश्चिमम्==स्वराः.end() || *पश्चिमम्==स्वरलक्षणम् || *पश्चिमम्==मौनलक्षणम्))
			*लक्षणपदम् = गतिः;
		else if(*लक्षणपदम्==अनुदात्तलक्षणम्) {
			*std::prev(लक्षणपदम्, 1)=अनुदात्तः;
			गतिः=उदात्तः;
		}
		else if(*लक्षणपदम्==स्वरितलक्षणम्) {
			*std::prev(लक्षणपदम्, 1)=स्वरितः;
			गतिः=अनुदात्तः;
		}
	}
	
	स्वराः.erase(std::remove_if(स्वराः.begin(), स्वराः.end(), [](auto const स्वरः){
		return स्वरः==स्वरलक्षणम्||स्वरः==स्वरितलक्षणम्||स्वरः==अनुदात्तलक्षणम्||स्वरः==मौनलक्षणम्;
	}), स्वराः.end());
	
	for(auto const& i:स्वराः){
		//printf("%s", [](auto const x){return x==उदात्तः?"u":x==स्वरितः?"s":"a";}(i));
	}
	गतिः = स्वराः.front()==अनुदात्तः?0:2;
	auto वर्णपदम्=वर्णाः.begin();
	auto स्वरपदम्=स्वराः.begin();
	if(अधिकारः(वर्णाः.front(),स्वरः)) {
		गतिः=स्वराः.front()==उदात्तः?2:0;
		स्वरक्रमः.push_back(गतिः);
		वर्णपदम्++;स्वरपदम्++;
	}
	while(वर्णपदम्!=वर्णाः.end()) {
		auto const पश्चिमम्=std::next(वर्णपदम्, 1);
		if(पश्चिमम्==वर्णाः.end() || !अधिकारः(*पश्चिमम्, स्वरः))
			स्वरक्रमः.push_back(गतिः);
		else {
			auto const पश्चिमस्वरः=*(स्वरपदम्++);
			if(पश्चिमस्वरः==अनुदात्तः) {
				स्वरक्रमः.push_back(0);
				गतिः=0;
			}
			else {
				स्वरक्रमः.push_back(2);
				गतिः=पश्चिमस्वरः==उदात्तः?2:0;
			}
		}
		वर्णपदम्++;
	}
	if(वर्णाः.back()==0)
		स्वरक्रमः.back()=स्वरक्रमः.front();
	//printf("\n");
	for(auto const&i:स्वरक्रमः) {
		//printf("%d", i);
	}
	return std::make_pair(वर्णाः, स्वरक्रमः);
}

class वाचकम्
{
public:
	class वर्णसङ्ग्रहः
	{
		static const int अवकाशः=20;
		std::pair<वर्णः,int> सङ्ग्रहः[अवकाशः];
		size_t स्थानम्=0,आदिः=0,अन्तः=0;
		bool लोपः=false;
	public:
		struct वर्णक्रमः
		{
			std::pair<वर्णः,int> (*क्रमणम्)(void*);
			void* अन्वयः;
		};
	private:
		 वर्णक्रमः वर्णाः;
	public:
		वर्णसङ्ग्रहः(वर्णक्रमः यद्वर्णाः)
		{
			वर्णाः=यद्वर्णाः;
			सङ्ग्रहः[0]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
		}
		
		template <typename अङ्कनम्>
		void वृद्धिः(अङ्कनम् & अङ्कः){अङ्कः++;if(अङ्कः==अवकाशः)अङ्कः=0;}
		template <typename अङ्कनम्>
		अङ्कनम् अन्तरम्(const अङ्कनम् आदिः,const अङ्कनम् अन्तः)
		{
			if(अन्तः>=आदिः)return अन्तः-आदिः;
			else return अन्तः-आदिः+अवकाशः;
		}
		
		std::pair<वर्णः,int> पठनम्(int अतिक्रमः=0)
		{
			if(अतिक्रमः==0)return सङ्ग्रहः[स्थानम्];
			else if(अतिक्रमः<0)
			{
				if(-अतिक्रमः<=अन्तरम्(आदिः,स्थानम्))
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः<0)लक्ष्यः+=अवकाशः;
					return सङ्ग्रहः[लक्ष्यः];
				}
				else if(!लोपः)return std::make_pair((वर्णः)0,सङ्ग्रहः[0].second);
				else throw(अतिक्रमः);
			}
			else
			{
				if(अतिक्रमः<=अन्तरम्(स्थानम्,अन्तः))
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः>अवकाशः)लक्ष्यः-=अवकाशः;
					return सङ्ग्रहः[लक्ष्यः];
				}
				else if(अतिक्रमः<अवकाशः)
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः>=अवकाशः)लक्ष्यः-=अवकाशः;
					while(अन्तः!=लक्ष्यः)
					{
						वृद्धिः(अन्तः);
						if(अन्तः==आदिः){वृद्धिः(आदिः);लोपः=true;}
						सङ्ग्रहः[अन्तः]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
					}
					return सङ्ग्रहः[लक्ष्यः];
				}
				else throw(अतिक्रमः);
			}
		}
		void क्रमणम्()
		{
			if(स्थानम्!=अन्तः)वृद्धिः(स्थानम्);
			else
			{
				वृद्धिः(अन्तः);
				स्थानम्=अन्तः;
				if(अन्तः==आदिः){वृद्धिः(आदिः);लोपः=true;}
				सङ्ग्रहः[अन्तः]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
			}
		}
	};
	वर्णसङ्ग्रहः पाठः;
	वाचकम्(वर्णसङ्ग्रहः::वर्णक्रमः यद्वर्णाः):पाठः(यद्वर्णाः){}
	वाचकम्(const वाचकम् &)=delete;
	वाचकम्& operator=(const वाचकम् &)=delete;
	void वाचनम्()
	{
		/*unsigned long int कालः=0;
		
		std::ofstream कण्ठ्यान्तरम्("x1",std::ios::binary);
		std::ofstream गुणः("x2",std::ios::binary);
		*/
		const int देशः=1;
		
		std::map<वर्णः,std::string> अङ्कनम्_[2]={{{अत्,"a"}, {आत्,"aa"}, {इत्,"ii"}, {ईत्,"ii"}, {उत्,"uu"}, {ऊत्,"uu"}, {ऋत्,"r"}, {ॠत्,"r"}, {ऌत्,"l"}, {ॡत्,"l"}, {एत्,"e"}, {ऐत्,"ai"}, {ओत्,"o"}, {औत्,"au"}, {कः,"k"}, {खः,"kh"}, {गः,"g"}, {घः,"gh"}, {ङः,"an1"}, {चः,"c"}, {छः,"ch"}, {जः,"j"}, {झः,"jh"}, {ञः,"an"}, {टः,"T"}, {ठः,"Th"}, {डः,"D"}, {ढः,"Dh"}, {णः,"N"}, {तः,"t"}, {थः,"th"}, {दः,"d"}, {धः,"dh"}, {नः,"n"}, {पः,"p"}, {फः,"ph"}, {बः,"b"}, {भः,"bh"}, {मः,"m"}, {यः,"y"}, {रः,"r"}, {लः,"l"}, {वः,"v"}, {शः,"_ 10\nc"}, {षः,"sh"}, {सः,"s"}, {हः,"h"}, {विसर्गः,"h"}, {अनुस्वारः,"m"}, {लँः,"n"}},

		{{अत्,"a"}, {आत्,"a:"}, {इत्,"i"}, {ईत्,"i:"}, {उत्,"u"}, {ऊत्,"u:"}, {ऋत्,"r"}, {ॠत्,"r"}, {ऌत्,"l"}, {ॡत्,"l"}, {एत्,"e:"}, {ऐत्,"ai"}, {ओत्,"o"}, {औत्,"au"}, {कः,"k"}, {खः,"kh"}, {गः,"g"}, {घः,"gh"}, {ङः,"n~"}, {चः,"c"}, {छः,"ch"}, {जः,"j"}, {झः,"jh"}, {ञः,"N~"}, {टः,"T"}, {ठः,"Th"}, {डः,"D"}, {ढः,"Dh"}, {णः,"N"}, {तः,"t"}, {थः,"th"}, {दः,"d"}, {धः,"dh"}, {नः,"n"}, {पः,"p"}, {फः,"ph"}, {बः,"b"}, {भः,"bh"}, {मः,"m"}, {यः,"y"}, {रः,"r"}, {लः,"l"}, {वः,"v"}, {शः,"s\'"}, {षः,"S"}, {सः,"s"}, {हः,"h"}, {विसर्गः,"h"}, {अनुस्वारः,"m"}, {लँः,"n"}}};
		
		std::map<वर्णः,std::string> अङ्कनम्=अङ्कनम्_[देशः];
		while(true)
		{
			std::string उत्पत्तिः="";
			std::string उदात्तस्य="220",अनुदात्तस्य="180";
			वर्णः पूर्वः=पाठः.पठनम्(-1).first,पश्चिमः=पाठः.पठनम्(1).first,उपस्थितः=पाठः.पठनम्().first;
			int स्वरः_=पाठः.पठनम्().second;
			int पूर्वस्वरः=पाठः.पठनम्(-1).second;
			उत्पत्तिः+=उपस्थितः<1?"_ ":अङ्कनम्[उपस्थितः]+" ";
			int अवधिः=(अधिकारः(उपस्थितः,दीर्घः)?250:अधिकारः(उपस्थितः,ह्रस्वः)?100:उपस्थितः==0?200:उपस्थितः==-1?30:अधिकारः(उपस्थितः,उष्मा)?150:60);
			if((अधिकारः(उपस्थितः,उष्मा)||अधिकारः(उपस्थितः,अन्तःस्थः)||अधिकारः(उपस्थितः,नासिक्यः)||उपस्थितः==विसर्गः)&&अधिकारः(पश्चिमः,व्यञ्जनः))अवधिः=150;
			if((अधिकारः(उपस्थितः,खरः)||अधिकारः(उपस्थितः,अतिखरः)||अधिकारः(उपस्थितः,मृदुः)||अधिकारः(उपस्थितः,घोषः))&&अधिकारः(पश्चिमः,व्यञ्जनः))अवधिः=150;
			if(देशः==0)
			{
				if(उपस्थितः==पश्चिमः){पाठः.क्रमणम्();continue;}
				if(उपस्थितः==पूर्वः)अवधिः=250;
			}
			//if(अधिकारः(उपस्थितः,खरः)&&अधिकारः(पश्चिमः,वर्गीयः))अवधिः=20;
			if(देशः==0)if(अधिकारः(उपस्थितः,स्वरः)&&पश्चिमः==0)अवधिः*=1.5;
			उत्पत्तिः+=std::to_string(अवधिः)+" ";
			if(पूर्वस्वरः==2&&स्वरः_==0)उत्पत्तिः+="0 "+उदात्तस्य+" "+(अधिकारः(उपस्थितः,दीर्घः)?"30":"60")+" "+अनुदात्तस्य+" 100 "+अनुदात्तस्य;
			else उत्पत्तिः+="0 "+(पूर्वस्वरः==2?उदात्तस्य:अनुदात्तस्य)+" 100 "+(स्वरः_==2?उदात्तस्य:अनुदात्तस्य);
			उत्पत्तिः+="\n";
			//if(उपस्थितः==ओत्)उत्पत्तिः+="_ 10\n";
			//if(उपस्थितः==ओत्)उत्पत्तिः+="u 10\n";
			//if(अधिकारः(उपस्थितः,खरः)&&अधिकारः(पश्चिमः,वर्गीयः))उत्पत्तिः+="_ 60\n";
			if(देशः==0)
			{
				if(अधिकारः(उपस्थितः,स्वरः)&&अधिकारः(पश्चिमः,स्वरः))
					उत्पत्तिः+="_ 30\n";
				if((!अधिकारः(उपस्थितः,स्वरः))&&(!अधिकारः(पश्चिमः,स्वरः)&&पश्चिमः!=0))
				{
					if(पश्चिमः==वः)
						उत्पत्तिः+="uu 20\n";
					else if(पश्चिमः==लः||पश्चिमः==रः||पश्चिमः==यः)
						उत्पत्तिः+="ii 20\n";
					else उत्पत्तिः+="_ 20\n";
				}
				if(उपस्थितः==ऋत्||उपस्थितः==ॠत्)उत्पत्तिः="_ 20\n"+उत्पत्तिः+"ii 20\n";
				//if(उपस्थितः==मः&&पश्चिमः==0)उत्पत्तिः+="a 10\n";
			}
			if(देशः==1)
			{
				if(उपस्थितः==हः&&पश्चिमः==मः)उत्पत्तिः+="_ 10\n";
				if(अङ्कनम्[उपस्थितः]=="r"&&पश्चिमः==ङः)उत्पत्तिः+="i 10\n";
			}
			if(उपस्थितः==-2){उत्पत्तिः+="#\n";std::cout<<उत्पत्तिः;break;}
			else पाठः.क्रमणम्();
			//std::cout<<अङ्कनम्[उपस्थितः]<<std::endl;
			std::cout<<उत्पत्तिः;
		}
	}
};

int main()
{
	std::string लेखः="";
	while(true)
	{
		std::getline(std::cin,लेखः);
		if(लेखः=="0")break;
		auto वर्णस्वराः=वर्णनिर्णयः(लेखः.c_str());
		std::list<वर्णः> क्रमः=वर्णस्वराः.first;
		std::list<int> स्वरक्रमः=वर्णस्वराः.second;
		क्रमः.push_back((वर्णः)-2);
		स्वरक्रमः.push_back(0);
		std::list<वर्णः>::iterator स्थानम्=क्रमः.begin();
		std::list<int>::iterator स्वरस्थानम्=स्वरक्रमः.begin();
		auto क्रमणम्=[&क्रमः,&स्थानम्,&स्वरक्रमः,&स्वरस्थानम्]()
		{
			वर्णः उपस्थितः=*स्थानम्;
			int स्वरः=*स्वरस्थानम्;
			स्थानम्++;
			स्वरस्थानम्++;
			if(स्थानम्==क्रमः.end()){स्थानम्=क्रमः.begin();स्वरस्थानम्=स्वरक्रमः.begin();}
			return std::make_pair(उपस्थितः,स्वरः);
		};
		वाचकम् मुखम्({(std::pair<वर्णः,int> (*)(void*))([](void* d){return (*static_cast<decltype(क्रमणम्)*>(d))();}),&क्रमणम्});
		मुखम्.वाचनम्();
	}
}
