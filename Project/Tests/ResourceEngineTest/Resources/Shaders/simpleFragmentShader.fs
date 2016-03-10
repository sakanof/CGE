#version 400

out vec4 FragColor;

varying vec3 color;

void main()
{
	FragColor =  vec4(color, 1);
}