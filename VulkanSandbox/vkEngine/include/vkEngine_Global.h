
#ifndef _VK_ENGINE_GLOBAL_H
#define _VK_ENGINE_GLOBAL_H

#ifdef _WIN32
#ifndef VK_ENGINE_API_LIB  
#define VK_ENGINE_API_EXPORT _declspec(dllexport)  //��������
#else
#define VK_ENGINE_API_EXPORT _declspec(dllimport)  //���뺯��
#endif
#else
//������ƽ̨�ϲ���Ҫ�ر���
#define TRADE_CORE_EXPORT
#endif




#endif // !_VK_ENGINE_GLOBAL_H