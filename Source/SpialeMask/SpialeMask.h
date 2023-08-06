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


/*!
 * SpialeMask Export
*/
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

#ifdef __STDC_NO_ATOMICS__
#error "the header <stdatomic.h> and all of the names provided in it are not provided."
#else
/*#include <stdatomic.h>*/
#endif /* !__STDC_NO_ATOMICS__ */


/*!
 * 自增标识键
*/
typedef enum /*: unsigned char*/
{
    kaidNaN = 0x00,     /*无效自增标识键*/

    kaidCog,            /*轮齿自增标识键*/
    kaidRoulette,       /*轮盘自增标识键*/
    kaidSpiale,         /*轮轴自增标识键*/

    kaidNone,           /*空 自增标识键*/

} KeyAutoIncrementIdentity;


/* begin extern "C" */
APP_EXTERN_C_BEGIN




    /*!
     * 测试库函数
     * @param[in] iA 参数A
     * @param[in] iB 参数B
     * @return  返回输入参数相加和
    */
    SPIALEMASK_EXPORT int Rolls();


    /*!
    * 测试库函数
    * @param[in] iA 参数A
    * @param[in] iB 参数B
    * @return  返回输入参数相加和
    */
    SPIALEMASK_EXPORT int Spin();


    /*!
     * 获取自增标识键对应的自增标识值
     * @param[in]     enKaid 自增标识键
     * @param[in,out] pValue 自增标识值指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int AutoIncrementIdentity(KeyAutoIncrementIdentity enKaid
                                                , unsigned short* pValue);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_H_SPIALEMASK_H_ */

