#ifndef SR_MOVABLEOBJECT_H
#define SR_MOVABLEOBJECT_H

namespace SR
{
  typedef Vector3 EulerAngle;
  class MovableObject: public Entity
  {
    typedef std::shared_ptr<MovebleObject> MovableObjectPtr;
    typedef std::list<MovableObjectPtr> m_children;
    protected:
      Vector3         m_position;
      EulerAngle      m_eulerAngle;
      Matrix4         m_modelMatrix;
    
    public:
      void            Add             (MovableObjectPtr child);
      void            SetPosition     (const Vector3& position);
      Vector3&        GetPosition     ();
  
      const Matrix4&  GetModelMatrix  () const;
      Matrix4&        GetModelMatrix  ();
      
      
      void            SetRotation     (const Euler& angle);
      
      void            RotateX         (Real angle);
      void            RotateY         (Real angle);
      void            RotateZ         (Real angle);
      void            Rotate          (Vector3 axel, Real angle);
  };
}
#endif