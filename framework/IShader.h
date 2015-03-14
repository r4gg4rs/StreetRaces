/**
 * Streetracer
 * 
 * @author    Jani Haippo
 * @version   03.2015
 **/

#ifndef SR_ISHADER_H
#define SR_ISHADER_H

namespace SR
{
  /**
   * Shader base class
   **/
  class IShader
  {
    public:
      virtual void Bind()=0;
      virtual void SetUniform(std::string& name, int value)=0;
			virtual void SetUniform(std::string& mame, float value)=0;
			virtual void SetUniform(std::string& name, float value1, float value2)=0;
			virtual void SetUniform(std::string& name, float value1, float value2,float value3)=0;
			virtual void SetUniform(std::string& name, const Vector3& value)=0;
			virtual void SetUniform(std::string& name, const Matrix4& value)=0;
  }
}

#endif