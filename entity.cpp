#include "entity.h"
#include <iostream>
Entity::Entity()
{
 	
}

Entity::~Entity()
{

}

void Entity::Load()
{
  p_mesh = new Mesh();
  p_mesh->Load("Cube");
}

void Entity::Update(float dt)
{
  //m_angle += 0.01f;
        float x = 0.0f;
        float z = 0.0f;
        MATH::SinCos(x,z, MATH::DegToRad(m_angle));
        m_heading = Vector3(x,0.0f,z);
       
}

void Entity::Render(RenderState& state)
{
  /*
  std::cout << " Renderöidään objeckito  id : "<< GetID() << std::endl;
  if(p_mesh == NULL) std::cout << "Mesh puuttuu "<<std::endl;
  std::cout <<" X " << m_position.x << " Y "<< m_position.y << std::endl;
  */
  std::vector<Vertex> vertices = p_mesh->GetVertices();
  std::vector<int> indices = p_mesh->GetIndices();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  
  glTranslatef(m_Position.x, m_Position.y, m_Position.z);
  glRotatef(m_angle,0.0f,1.0f,0.0f);
  glBegin(GL_TRIANGLES);
  for(unsigned int i=0; i< indices.size(); i++)
    {
      unsigned int index = indices[i];
      glVertex3f(vertices[index].Position.x, vertices[index].Position.y, vertices[index].Position.z);
     
    }
  glEnd();
  glPopMatrix();
  //  p_mesh->Render();
}

void Entity::SetPosition(const Vector3& pos)
{
  m_Position = pos;
}

const Vector3& Entity::GetPosition() const
{
  return m_Position;
}

std::string Entity::Type() const
{
  return "Entity";
}

