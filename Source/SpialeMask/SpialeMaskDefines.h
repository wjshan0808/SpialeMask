#pragma once
#ifndef _H_SPIALEMASK_DEFINES_H_
#define _H_SPIALEMASK_DEFINES_H_

/*
 * 导入导出符号定义
*/
#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define Q_DECL_EXPORT __declspec(dllexport)
    #define Q_DECL_IMPORT __declspec(dllimport)
#else
    #define Q_DECL_EXPORT __attribute__((visibility("default")))
    #define Q_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if defined(SPIALEMASK_LIBRARY)
    #define SPIALEMASK_EXPORT Q_DECL_EXPORT
#else
    #define SPIALEMASK_EXPORT Q_DECL_IMPORT
#endif

/*
 * C/C++
*/
#ifdef __cplusplus
    #define EXTERN_C_BEGIN extern "C" {
    #define EXTERN_C_END }
#else
    #define EXTERN_C_BEGIN
    #define EXTERN_C_END
#endif /* __cplusplus */




#endif /* _H_SPIALEMASK_DEFINES_H_ */
