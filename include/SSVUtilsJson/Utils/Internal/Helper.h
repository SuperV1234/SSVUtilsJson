// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVUJ_INTERNAL_HELPER
#define SSVUJ_INTERNAL_HELPER

#include <vector>
#include <string>
#include "SSVUtilsJson/Utils/Internal/Typedefs.h"

namespace ssvuj
{
	namespace Internal
	{
		template<typename T> struct AsHelper		{ inline static T as(const Value& Value); };
		template<> struct AsHelper<Value>			{ inline static Value as(const Value& mValue)			{ return mValue; } };
		template<> struct AsHelper<int>				{ inline static int as(const Value& mValue)				{ return mValue.asInt(); } };
		template<> struct AsHelper<float>			{ inline static float as(const Value& mValue)			{ return mValue.asFloat(); } };
		template<> struct AsHelper<double>			{ inline static double as(const Value& mValue)			{ return mValue.asDouble(); } };
		template<> struct AsHelper<bool>			{ inline static bool as(const Value& mValue)			{ return mValue.asBool(); } };
		template<> struct AsHelper<std::string>		{ inline static std::string as(const Value& mValue)		{ return mValue.asString(); } };
		template<> struct AsHelper<char const*>		{ inline static char const* as(const Value& mValue)		{ return mValue.asCString(); } };
		template<> struct AsHelper<unsigned int>	{ inline static unsigned int as(const Value& mValue)	{ return static_cast<unsigned int>(mValue.asInt()); } };
		template<typename T> struct AsHelper<std::vector<T>>
		{
			inline static std::vector<T> as(const Value& mValue)
			{
				std::vector<T> result;
				for(unsigned int i{0}; i < mValue.size(); ++i) result.push_back(AsHelper<T>::as(mValue[i]));
				return result;
			}
		};
	}
}

#endif
