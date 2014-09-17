// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVUJ_UTILS_IO
#define SSVUJ_UTILS_IO

namespace ssvuj
{
	namespace Internal
	{
		inline bool tryParse(Obj& mObj, Reader& mReader, const std::string& mSrc)
		{
			if(mReader.parse(mSrc, mObj, false)) return true;
			ssvu::lo("ssvuj::logReadError") << mReader.getFormattedErrorMessages() << "\nFrom: [" << mSrc << "]" << std::endl;
			return false;
		}
	}

	inline void readFromString(Obj& mObj, const std::string& mStr)	{ Reader reader; Internal::tryParse(mObj, reader, mStr); }
	inline void readFromFile(Obj& mObj, const Path& mPath)			{ Reader reader; Internal::tryParse(mObj, reader, mPath.getContentsAsString()); }

	inline Obj getFromString(const std::string& mStr)	{ Obj result; readFromString(result, mStr); return result; }
	inline Obj getFromFile(const Path& mPath)			{ Obj result; readFromFile(result, mPath); return result; }

	inline void writeToStream(const Obj& mObj, std::ostream& mStream)	{ Writer writer; writer.write(mStream, mObj); mStream.flush(); }
	inline void writeToString(const Obj& mObj, std::string& mStr)		{ std::ostringstream o; writeToStream(mObj, o); mStr = o.str(); }
	inline void writeToFile(const Obj& mObj, const Path& mPath)			{ std::ofstream o{mPath}; writeToStream(mObj, o); o.close(); }
	inline auto getWriteToString(const Obj& mObj)						{ std::string result; writeToString(mObj, result); return result; }
}

#endif
