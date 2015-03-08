
#ifndef SR_MATERIAL_H
#define SR_MATERIAL_H

namespace SR
{
  class Material
  {
    private:
      Color     m_abient;
      Color     m_specular;
      Color     m_diffuse;
    public:
      Material();
      ~Material();
      
      void SetAmbient( const Color& ambient);
      void SetSpecular( const Color& specular);
      void SetDiffuse( const Color& diffuse);
      
      Color&  GetAmbient();
      Color&  GetSpecular();
      Color&  GetDiffuse();
  };
}
#endif