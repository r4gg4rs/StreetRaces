#ifndef STREETRACER_ILOADABLE_H
#define STREETRACER_ILOADABLE_H

class ILoadable 
{
	public:
		virtual void Load(std::string filename) =0;
};
#endif
