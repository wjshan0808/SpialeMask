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

#include "App/AppDefines.h"

#include "App/Log/Log.h"
#include "App/Kit/Utility.h"


#define SPIALEMASK_EXPORT APP_EXPORT


/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*
     * 测试库函数
     * @param[in] iA 参数A
     * @param[in] iB 参数B
     * @return  返回输入参数相加和
    */
    SPIALEMASK_EXPORT int foo(int iA, int iB);


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_H_SPIALEMASK_H_ */

