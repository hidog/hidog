#ifndef SHARED_H
#define SHARED_H

#ifdef WIN32
	#ifdef USE_DLL
		#define DLL_EXPORT __declspec(dllexport)
	#else
		#define DLL_EXPORT __declspec(dllimport)
	#endif
#else 
	#define DLL_EXPORT
#endif


#define setMemberDataMacro( type, name ) \
	void set##_##name( type _n ) \
	{ \
		name = _n; \
	}
	
#define getMemberDataMacro( type, name ) \
	type get##_##name() \
	{ \
		return 	name; \
	}



#endif