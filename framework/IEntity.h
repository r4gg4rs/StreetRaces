/**
 * @author    Jani Haippo
 * @version   03.2015
 * @file      IEntity.h
 * */
 
 #ifndef STREETRACER_IENTITY_H
 #define STREETRACER_IENTITY_H
 
 #include "../math/mat.h"
 
 namespace SR
 {
   class IEntity
   {
     virtual Matrix4&   GetModelMatrix(); //Onko tarpeen jos ei ole meshiä?
   };
 }
 #endif