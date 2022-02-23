#version 330 core

layout (location = 0) in vec4 u_Position;
layout (location = 1) in vec2 u_TexCoord;

out vec2 v_TexCoord;

uniform mat4 u_ViewPorjectionMatrix;
uniform mat4 u_ModalViewMatrix = mat4(1.0f);

void main()
{
	v_TexCoord = u_TexCoord;
	gl_Position = u_ViewPorjectionMatrix * u_ModalViewMatrix * u_Position;
};