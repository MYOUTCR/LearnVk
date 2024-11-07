
#ifndef _VK_ENGINE_GLOBAL_H
#define _VK_ENGINE_GLOBAL_H

#ifdef _WIN32
#ifndef VK_ENGINE_API_LIB  
#define VK_ENGINE_API_EXPORT _declspec(dllexport)  //导出函数
#else
#define VK_ENGINE_API_EXPORT _declspec(dllimport)  //导入函数
#endif
#else
//在其他平台上不需要特别处理
#define TRADE_CORE_EXPORT
#endif




#endif // !_VK_ENGINE_GLOBAL_H