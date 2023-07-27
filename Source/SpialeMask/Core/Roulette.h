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
    CogChain* m_pCurrent;               /*轮盘中的当前轮齿链*/
    size_t m_uiCount;                   /*轮盘中轮齿链的数量*/
    const CogChain* m_pAnchor;          /*轮盘中的锚点轮齿链*/
    unsigned char m_ucIsNullity;        /*轮盘无效性*/
    unsigned short m_usIdentity;        /*轮盘标识*/

} __attribute__((packed)) Roulette;



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @return 标识码
     * @remark 不使用时请调用DeleteRoulette删除
    */
    SPIALEMASK_EXPORT int NewRoulette(Roulette** paRoulette);


    /*!
     * 深度克隆轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @param[in]     pSrcRoulette 源轮盘结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DeleteRoulette删除
    */
    SPIALEMASK_EXPORT int CloneRoulette(Roulette** paRoulette
                                        , const Roulette* pSrcRoulette);


    /*!
     * 追加轮齿到轮盘结构
     * @param[in,out] pRoulette 轮盘结构指针
     * @param[in]     szContent 轮齿内容
     * @return 标识码
    */
    SPIALEMASK_EXPORT int AppendCog2Roulette(Roulette* pRoulette
                                             , const char* szContent);


    /*!
     * 变更轮盘结构无效性
     * @param[in,out] pRoulette 轮盘结构指针
     * @param[in]     ucIsNullity 轮盘结构是否无效
     * @return 标识码
     * @footnote APP_STATE_*为有效输入值
    */
    SPIALEMASK_EXPORT int NullifyRoulette(Roulette* pRoulette
                                          , unsigned char ucIsNullity);


    /*!
     * 删除轮盘结构
     * @param[in,out] paRoulette 轮盘结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DeleteRoulette(Roulette** paRoulette);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ROULETTE_H_ */

