#pragma once
#include "pch.hpp"

namespace Sq {

	template<typename T>
	using unique = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr unique<T> makeunique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> MakeRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Log.hpp"

using f32 	= float;
using f64	= double;
using ui 	= unsigned int;
using usi 	= unsigned short int;

using i8 	= std::int8_t;
using i16 	= std::int16_t;
using i32 	= std::int32_t;
using i64 	= std::int64_t;

using byte 	= std::uint8_t;
using u8 	= std::uint8_t;
using u16 	= std::uint16_t;
using u32 	= std::uint32_t;
using u64 	= std::uint64_t;

#define svec 	std::vector
#define slst 	std::list
#define	silst	std::initializer_list
#define sarr 	std::array
#define smap 	std::map
#define sset 	std::set
#define sstr 	std::string
#define sstrs 	std::stringstream
#define sfun 	std::function
#define sifs	std::ifstream

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
#define __EXIT { exit(-1); }
#define ASSERT(x, ...) { if(!(x)) { SQ_CORE_ERROR("\nAssert > [{0}(ln: {1})] {2} \nFile: {3}", __FUNCTION__, __LINE__, __VA_ARGS__, __FILE__); __EXIT } }