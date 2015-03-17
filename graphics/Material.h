
#ifndef SR_MATERIAL_H
#define SR_MATERIAL_H

#include "../core/Color.h"

namespace SR
{
  class MaterialO
  {
    private:
      Color     m_abient;
      Color     m_specular;
      Color     m_diffuse;
    public:
      Material();
      ~Material();
      
      void SetAmbient( const Color& ambient)
      {
        m_ambient = ambien;
      }
      
      void SetSpecular( const Color& specular)
      {
        m_specular = specilar;
      }
      
      void SetDiffuse( const Color& diffuse)
      {
        m_diffuse = diffuse;
      }
      
      Color&  GetAmbient()
      {
        return m_ambient;
      }
      
      
      Color&  GetSpecular()
      {
        return m_specular;
      }
      
      
      Color&  GetDiffuse()
      {
        return m_diffuse;
      }
  };
}
#endif