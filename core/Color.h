/**
 * @author    Jani Haippo
 * @version   03.2015
 * 
 * Color
 * */
 
#ifndef SR_COLOR_H
#define SR_COLOR_H

namespace SR
{
  class Color
  {
    public:
      Real r;
      Real g;
      Real b;
      Real a;
      
    public:
      Color() {r=0.0f; g=0.0f; b=0.0f; a=0.0f;} // :r(0.0f), b(0.0f), g(0.0f), a(0.0f){}
      Color(Real red, Real green, Real blue, Real alpha)
      :r(red), g(green), b(blue), a(alpha){}
      ~Color(){}
     
     	const Real& operator [] ( const size_t i) const
		  {
			  return *(&r+i);
		  }
      
       Real* Ptr() { return &r; }
       const Real* Ptr() const { return &r; }
     
  };
  
}
#endif