/*#pragma once*/
#ifndef _C_ROULETTE_H_
#define _C_ROULETTE_H_


#include "../SpialeMask.h"
#include "Cog.h"


/*!
 * 轮盘
*/
typedef struct
{
    unsigned char m_ucCount;                   /*内容长度*/
    Cog* m_pFirst;
    Cog* m_pCurrent;
    Cog* m_pLast;
}__attribute__((packed)) Roulette;


/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 测试库函数
     * @param[in] iA 参数A
     * @param[in] iB 参数B
     * @return  返回输入参数相加和
    */
    SPIALEMASK_EXPORT int Spin();


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ROULETTE_H_ */

