#version 460 core
out vec4 FragColor;

//uniform - special keyword use to send data from cpu to gpu
//swizzling - glsl
uniform vec3 objectColor;
in vec3 Color;

void main()
{
    FragColor = vec4(Color, 1.0f);
} 