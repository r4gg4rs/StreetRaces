#version 400

in vec3 Position;

uniform vec3 color;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec4 Color;

void main(void)
{
	gl_Position = projectionMatrix*viewMatrix*  modelMatrix * vec4(Position,1.0);
	Color = vec4(color, 1.0);
}
