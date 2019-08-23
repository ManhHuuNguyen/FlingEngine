#pragma once

#if defined FLING_WINDOWS

#   define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <direct.h>

#   ifdef _MSC_VER

#	pragma warning(disable:26495)
#	pragma warning(disable:4267)
#	pragma warning(disable:26451)

#   endif   // _MSC_VER

#	define INLINE			        inline
#	define FORCEINLINE		        __forceinline

// API Export/Import

#	define FLING_NOT_EXPORTED

#	ifdef FLING_EXPORT		        // Export functions
#		define FLING_API        __declspec(dllexport) 
#       define FLING_EXTERN      
#	else					        // Not exporting function
#		define FLING_API        
#       define FLING_EXTERN        extern
#	endif

#endif	// FLING_WINDOWS