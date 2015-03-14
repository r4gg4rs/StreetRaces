/**
 * @author      Jani Haippo
 * @version     03.2015
 * */
 
 #ifndef SR_IMODEL_H
 #define SR_IMODEL_H
 
 #include "IShader.h"
 #include "IMesh.h"
 #include "IMaterial.h"
 
 namespace SR
 {
  class IModel
  {
    public:
      
      virtual IShader*    GetShader()=0;
      virtual IMaterial*  GetMaterial()=0;
      virtual IMesh*      GetMesh()=0;
  }
 }
 #endif