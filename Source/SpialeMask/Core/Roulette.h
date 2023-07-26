/*#pragma once*/
#ifndef _C_ROULETTE_H_
#define _C_ROULETTE_H_


#include "../SpialeMask.h"
#include "CogChain.h"


/*!
 * 轮盘结构
*/
typedef struct
{
    size_t m_uiCount;                   /*轮盘中轮齿的数量*/
    const Cog* m_pCurrent;              /*轮盘的当前轮齿*/
    const Cog* m_pAnchor;               /*轮盘的锚点轮齿*/
    CogChain* m_pCogChain;              /*轮盘的轮齿链*/

} __attribute__((packed)) Roulette;



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @param[in]     pAnchorCog 锚点轮齿结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DelRoulette删除
    */
    SPIALEMASK_EXPORT int NewRoulette(Roulette** paRoulette
                                      , const Cog* pAnchorCog);


    /*!
     * 深度克隆轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @param[in]     pSrcRoulette 源轮盘结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DelRoulette删除
    */
    SPIALEMASK_EXPORT int CloneRoulette(Roulette** paRoulette
                                        , const Roulette* pSrcRoulette);


    /*!
     * 删除轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DeleteRoulette(Roulette** paRoulette);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ROULETTE_H_ */

