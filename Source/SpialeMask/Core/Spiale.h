/*#pragma once*/
#ifndef _C_SPIALE_H_
#define _C_SPIALE_H_


#include "../SpialeMask.h"



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


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_SPIALE_H_ */

