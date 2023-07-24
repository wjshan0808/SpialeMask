/*#pragma once*/
#ifndef _H_SPIALEMASK_H_
#define _H_SPIALEMASK_H_


/*
 * 导入导出符号
*/
#undef APP_LIBRARY
#if defined(SPIALEMASK_LIBRARY)
    #define APP_LIBRARY
#endif


/*!
 * App头文件
*/
#include "App/AppDefines.h"
#include "App/Log/Log.h"
#include "App/Kit/Utility.h"


#define SPIALEMASK_EXPORT APP_EXPORT


/*!
 * Cog 宏定义
*/
#define SM_SIZE_COG_CONTENT     (0x80)      /*Cog内容大小*/




/*!
 * 头文件
*/
#define __STDC_WANT_LIB_EXT1__ (0x01)
#include <string.h>
#include <stdlib.h>
/* #define __STDC_LIB_EXT1__ */



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 测试库函数
     * @param[in] iA 参数A
     * @param[in] iB 参数B
     * @return 返回输入参数相加和
    */
    SPIALEMASK_EXPORT int foo(int iA, int iB);


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_H_SPIALEMASK_H_ */

