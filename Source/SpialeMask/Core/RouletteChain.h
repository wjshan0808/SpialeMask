/*#pragma once*/
#ifndef _C_ROULETTECHAIN_H_
#define _C_ROULETTECHAIN_H_


#include "../SpialeMask.h"
#include "Roulette.h"


/*!
 * 轮盘链结构
*/
typedef struct RouletteChain
{
    struct RouletteChain* m_pForward;        /*轮盘链的前一个轮盘链*/
    Roulette* m_pRoulette;                   /*轮盘链中的轮盘*/
    struct RouletteChain* m_pBackward;       /*轮盘链的后一个轮盘链*/

} __attribute__((packed)) RouletteChain;



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 铸造轮盘链
     * @param[in,out] paRouletteChain 轮盘链结构指针地址
     * @param[in]     uiCount 轮盘的若干轮齿数量
     * @param[in]     szContents 轮盘的若干轮齿内容
     * @return 标识码
     * @remark 不使用时请调用CleanRouletteChain删除
    */
    SPIALEMASK_EXPORT int MoldingRouletteChain(RouletteChain** paRouletteChain
                                               , size_t uiCount
                                               , const char* szContents[]);


    /*!
     * 新建轮盘链结构
     * @param[in,out] paRouletteChain 轮盘链结构指针地址
     * @return 标识码
     * @remark 不使用时请调用DeleteRouletteChain删除
    */
    SPIALEMASK_EXPORT int NewRouletteChain(RouletteChain** paRouletteChain);


    /*!
     * 深度克隆轮盘链结构
     * @param[in,out] paRouletteChain 轮盘链结构指针地址
     * @param[in]     pSrcRouletteChain 源轮盘链结构常量指针
     * @return 标识码
     * @remark 不使用时请调用CleanRouletteChain删除
    */
    SPIALEMASK_EXPORT int CloneRouletteChain(RouletteChain** paRouletteChain
                                             , const RouletteChain* pSrcRouletteChain);


    /*!
     * 插入轮盘到轮盘链结构
     * @param[in,out] pDstRouletteChain 目标轮盘链结构指针
     * @param[in,out] pSrcRouletteChain 源轮盘链结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int InsertRouletteChain(RouletteChain* pDstRouletteChain
                                              , RouletteChain* pSrcRouletteChain);


    /*!
     * 融合轮盘链结构
     * @param[in,out] pDstRouletteChain 目标轮盘链结构指针
     * @param[in,out] pSrcRouletteChain 源轮盘链结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int JoinRouletteChain(RouletteChain* pDstRouletteChain
                                            , RouletteChain* pSrcRouletteChain);


    /*!
     * 获取轮盘链中轮盘的数量
     * @param[in]     pRouletteChain 轮盘链结构常量指针
     * @param[in,out] pCount 轮盘数量指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int CountRouletteChain(const RouletteChain* pRouletteChain
                                             , size_t* pCount);


    /*!
     * 清空轮盘链结构
     * @param[in,out] paRouletteChain 轮盘链结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int CleanRouletteChain(RouletteChain** paRouletteChain);


    /*!
     * 删除轮盘链结构
     * @param[in,out] paRouletteChain 轮盘链结构指针地址
     * @return 标识码
     * @remark 调用DeleteRouletteChain前请必要修复轮盘链关系
    */
    SPIALEMASK_EXPORT int DeleteRouletteChain(RouletteChain** paRouletteChain);




/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ROULETTECHAIN_H_ */

