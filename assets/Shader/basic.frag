#version 330 core

layout (location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec3 u_Color;

void main()
{
	color = texture(u_Texture, v_TexCoord);
}