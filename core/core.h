#ifndef SR_CORE_H
#define SR_CORE_H

namespace SR
{
	typedef float Real;
	
	class Str : public std::string
	{
		public:
			Str(){}
			Str(const char* string) {std::string(string);} 
			
			void Trim() { }
	};
	
	
}
#endif
