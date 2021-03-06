#ifndef _SAPCLASSBASIC_H_
#define _SAPCLASSBASIC_H_

//	SapClassBasic.h : header file
//

// For Visual Studio 2005, disable Unicode support, as Sapera++ headers generate compiler errors
#if defined(_MSC_VER) && _MSC_VER >= 1400
   #ifdef UNICODE
      #undef UNICODE
      #define SAP_NEED_UNICODE
   #endif
#endif

// Disable some Visual Studio level 4 warnings
//    4239 -> nonstandard extension used : 'token' : conversion from 'type' to 'type'
//    4514 -> 'function' : unreferenced inline function has been removed
#ifdef _MSC_VER
#pragma warning(disable: 4239 4514)
#endif

// Disable some level C++ Builder warnings
#ifdef __BORLANDC__
   #pragma warn -8004   // 'identifier' is assigned a value that is never used
   #pragma warn -8022   // 'function1' hides virtual function 'function2'
   #pragma warn -8026   // Unable to expand inline functions with class-by-value arguments
   #pragma warn -8027   // Unable to expand inline functions containing 'for' and 'if'
   #pragma warn -8057   // Parameter 'parameter' is never used	
   #pragma warn -8058   // Cannot create pre-compiled header: 'reason'	
#endif


/////////////////////////////////////////////////////////////////////////////
// Sapera header files
#include "corapi.h"


/////////////////////////////////////////////////////////////////////////////
// Class header files

#if COR_WIN64

#include "SapClassBasicDef.h"
#include "SapData.h"
#include "SapManager.h"
#include "SapLut.h"
#include "SapXferNode.h"
#include "SapAcquisition.h"
#include "SapAcqDevice.h"
#include "SapFeature.h"
#include "SapBuffer.h"
#include "SapBufferWithTrash.h"
#include "SapBufferRoi.h"
#include "SapTransfer.h"
#include "SapXferMultiNode.h"
#include "SapRTPro.h"
#include "SapRTProDesign.h"
#include "SapTransferEx.h"
#include "SapDisplay.h"
#include "SapProcessing.h"
#include "SapPerformance.h"
#include "SapView.h"
#include "SapGraphic.h"
#include "SapGio.h"
#include "SapFlatField.h"
#include "SapBayer.h"

#else    // COR_WIN64

#include "SapClassBasicDef.h"

#include "SapData.h"
#include "SapManager.h"
#include "SapLut.h"
#include "SapXferNode.h"
#include "SapAcquisition.h"
#include "SapBuffer.h"
#include "SapBufferWithTrash.h"
#include "SapBufferRoi.h"
#include "SapBufferRemote.h"

#if COR_WIN32
   #include "SapAcqDevice.h"
   #include "SapFeature.h"
	#include "SapCab.h"
	#include "SapPixPro.h"
	#include "SapDsp.h"
#endif

#include "SapTransfer.h"
#include "SapXferMultiNode.h"
#include "SapRTPro.h"
#include "SapRTProDesign.h"
#include "SapTransferEx.h"

#if COR_WIN32
	#include "SapAcqToBufThruCab.h"
	#include "SapDisplay.h"
#endif

#include "SapProcessing.h"
#include "SapPerformance.h"

#if COR_WIN32
	#include "SapView.h"
	#include "SapGraphic.h"
	#include "SapMultiAcqToBufThruCab.h"
#endif

#include "SapCounter.h"
#include "SapGio.h"
#include "SapFlatField.h"
#include "SapBayer.h"

#include "SapClassBasicObsolete.h"

#endif   // COR_WIN64

// For Visual Studio 2005, restore Unicode support if it was previously disabled
#if defined(_MSC_VER) && _MSC_VER >= 1400
   #ifdef SAP_NEED_UNICODE
      #define UNICODE
      #undef SAP_NEED_UNICODE
   #endif
#endif

#endif	// _SAPCLASSBASIC_H_

