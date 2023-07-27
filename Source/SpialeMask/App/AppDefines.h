/*#pragma once*/
#ifndef _H_APP_DEFINES_H_
#define _H_APP_DEFINES_H_


#define APP_LIBRARY

/*!
 * 导入导出符号
*/
#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define APP_DECL_EXPORT __declspec(dllexport)
    #define APP_DECL_IMPORT __declspec(dllimport)
#else
    #define APP_DECL_EXPORT __attribute__((visibility("default")))
    #define APP_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(APP_LIBRARY)
    #define APP_EXPORT APP_DECL_EXPORT
#else
    #define APP_EXPORT APP_DECL_IMPORT
#endif


/*!
 * C/C++
*/
#ifdef __cplusplus
    #define APP_EXTERN_C_BEGIN extern "C" {
    #define APP_EXTERN_C_END }
#else
    #define APP_EXTERN_C_BEGIN
    #define APP_EXTERN_C_END
#endif /* __cplusplus */


/*!
 * APP标识码
*/
#define APP_FLAG_FAILURE        (0xFFFF)        /*失败标识*/
#define APP_FLAG_SUCCESS        (0x0001)        /*成功标识*/

/*!
 * APP状态码
*/
#define APP_STATE_TRUE          (0x01)          /*真状态*/
#define APP_STATE_FALSE         (0x00)          /*假状态*/




#endif /* !_H_APP_DEFINES_H_ */

