#ifndef COLOR4_H
#define COLOR4_H

class Color4
{
 public:
  Color4();
  Color4(float red,float green,float blue,float alpha);
  
 public:
  float r,b,g,a;

  static Color4 White(){ return Color4(1.0f,1.0f,1.0f,1.0f); }
  static Color4 Red(){ return Color4(1.0f,0.0f,0.0f,1.0f);}
  static Color4 Green(){ return Color4(0.0f,1.0f,0.0f,1.0f); } 
  static Color4 Blue(){ return Color4(0.0f,0.0f,1.0f,1.0f); }
 
};
#ndif
