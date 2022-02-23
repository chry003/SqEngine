#include "pch.hpp"
#include "Texture.hpp"

#include <glad/glad.h>
#include "stb_image.h"

namespace Sq {

	Texture2D::Texture2D()
	{
	}

	Texture2D::~Texture2D() 
	{
	}
	
	void Texture2D::Bind(const u32& TextureID) const 
	{
		glBindTexture(GL_TEXTURE_2D, TextureID);
	}

	u32 Image2D::Load(const sstr& path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		ASSERT(data, "Failed to load image!");

		u32 TextureID;

		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if (channels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else if (channels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		else
			ASSERT(false, "Wrong Channel, expected(RGB, RGBA)");

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(data);

		return TextureID;
	}

}