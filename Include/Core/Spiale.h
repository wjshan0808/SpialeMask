/*#pragma once*/
#ifndef _C_SPIALE_H_
#define _C_SPIALE_H_


#include "../SpialeMask.h"
#include "RouletteChain.h"


/*!
 * 轮轴结构
*/
typedef struct
{
    RouletteChain* m_pCurrent;          /*轮轴中的当前轮盘链*/
    size_t m_uiCount;                   /*轮轴中轮盘链的数量*/
    const RouletteChain* m_pAnchor;     /*轮轴中的锚点轮盘链*/
    unsigned char m_ucIsNullity;        /*轮轴无效性*/
    unsigned short m_usIdentity;        /*轮轴标识*/

} __attribute__((packed)) Spiale;



/* begin extern "C" */
APP_EXTERN_C_BEGIN




    /*!
     * 旋转轮轴
     * @param[in,out] pSpiale 轮轴结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int SpinSpiale(Spiale* pSpiale);


    /*!
     * 新建轮轴结构
     * @param[in,out] paSpiale 轮轴结构指针地址
     * @return 标识码
     * @remark 不使用时请调用DeleteSpiale删除
    */
    SPIALEMASK_EXPORT int NewSpiale(Spiale** paSpiale);


    /*!
     * 深度克隆轮轴结构
     * @param[in,out] paSpiale 轮轴结构指针地址
     * @param[in]     pSrcSpiale 源轮轴结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DeleteSpiale删除
    */
    SPIALEMASK_EXPORT int CloneSpiale(Spiale** paSpiale
                                      , const Spiale* pSrcSpiale);


    /*!
     * 追加轮盘链到轮轴结构
     * @param[in,out] pSpiale 轮轴结构指针
     * @param[in,out] pRouletteChain 轮盘链指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int AppendRouletteChain2Spiale(Spiale* pSpiale
                                                     , RouletteChain* pRouletteChain);


    /*!
     * 变更轮轴结构无效性
     * @param[in,out] pSpiale 轮轴结构指针
     * @param[in]     ucIsNullity 轮轴结构是否无效
     * @return 标识码
     * @footnote APP_STATE_*为有效输入值
    */
    SPIALEMASK_EXPORT int NullifySpiale(Spiale* pSpiale
                                        , unsigned char ucIsNullity);


    /*!
     * 删除轮轴结构
     * @param[in,out] paSpiale 轮轴结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DeleteSpiale(Spiale** paSpiale);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_SPIALE_H_ */

