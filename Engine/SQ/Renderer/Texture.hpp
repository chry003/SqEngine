#pragma once

#include "Core/Base.hpp"

namespace Sq {

	class Texture
	{
	public:
		virtual ~Texture() = default;
		virtual void Bind(const u32& TextureID) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		Texture2D();
		virtual ~Texture2D();
		virtual void Bind(const u32& TextureID) const override;
	};

	class Image2D
	{
	public:
		static u32 Load(const sstr& path);
	};

}