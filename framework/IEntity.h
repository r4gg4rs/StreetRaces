/**
 * @author    Jani Haippo
 * @version   03.2015
 * @file      IEntity.h
 * */
 
 #ifndef STREETRACER_IENTITY_H
 #define STREETRACER_IENTITY_H
 
 #include "../math/math.inc"
 #include <memory>
 
 namespace SR
 {
   class IEntity
   {
     public:
    //  virtual Matrix4&   GetModelMatrix()=0; //Onko tarpeen jos ei ole meshiä?
   };
   
   typedef std::shared_ptr<IEntity> IEntityPtr;
 }
 #endif