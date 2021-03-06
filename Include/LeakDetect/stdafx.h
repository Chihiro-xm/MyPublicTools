#pragma once
// Windows 头文件:
#include <windows.h>

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _CONVERSION_DONT_USE_THREAD_LOCALE
#define _WTL_NO_CSTRING
#define _WTL_NO_WTYPES

//ATL头文件
#include <atlstr.h>
#include <vector>
#include <map>

#include <iostream>
#include <strsafe.h>

#include <ShlObj.h>
#pragma comment(lib, "Version.lib")


#include "CorrectInstalledPatches.h"
#include "LogWriter.h"
#include "SomRuntime.h"


#define WRITE_LOG(x,...)	g_logger.Write(x,__VA_ARGS__)
using namespace std;