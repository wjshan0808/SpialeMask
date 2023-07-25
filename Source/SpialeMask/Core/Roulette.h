/*#pragma once*/
#ifndef _C_ROULETTE_H_
#define _C_ROULETTE_H_


#include "../SpialeMask.h"
#include "Cog.h"


/*!
 * 轮盘结构
*/
typedef struct
{
    size_t m_uiCount;                   /*轮盘中轮齿的数量*/
    Cog* m_pAnchor;                     /*轮盘的锚点轮齿*/
    Cog* m_pCurrent;                    /*轮盘的当前轮齿*/
} __attribute__((packed)) Roulette;


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

