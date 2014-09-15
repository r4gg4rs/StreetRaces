#ifndef STREETRACER_RTTI_H
#define STRAATRACER_RTTI_H

#include <string>

/*
  Runtime type information
*/
class Rtti
{
 public: 
    Rtti(std::string& typeString,const Rtti* baseType);
    ~Rtti();

std::string& GetName() const;
bool IsType(const Rtti& type) const;
bool IsType(std::strin& typeString)const;
bool IsDerived(const Rtti& type)const;
bool IsDerived(std::string& typeString)const;

private:
std::string   m_typeString;
const Rtti*   p_baseType;
};
#endif
