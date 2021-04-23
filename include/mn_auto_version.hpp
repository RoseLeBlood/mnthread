#ifndef _MINLIB_AUTO_VERSION_H_
#define _MINLIB_AUTO_VERSION_H_

namespace mn{
	
	//Software Status
	static const char MN_VERSION_STATUS[] =  "Beta";
	static const char MN_VERSION_STATUS_SHORT[] =  "b";
	
	//Standard Version Type
	static const long MN_VERSION_MAJOR  = 2;
	static const long MN_VERSION_MINOR  = 27;
	static const long MN_VERSION_BUILD  = 3049;
	static const long MN_VERSION_REVISION  = 74;
	
	//Miscellaneous Version Types
	static const long MN_VERSION_BUILDS_COUNT  = 3;
	#define MN_VERSION_RC_FILEVERSION 2,27,3049,74
	#define MN_VERSION_RC_FILEVERSION_STRING "2, 27, 3049, 74\0"
	static const char MN_VERSION_FULLVERSION_STRING [] = "2.27.3049.74";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long MN_VERSION_BUILD_HISTORY  = 1;
	

}
#endif //_MINLIB_AUTO_VERSION_H_