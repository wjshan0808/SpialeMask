/*#pragma once*/
#ifndef _C_ASSEMBLE_H_
#define _C_ASSEMBLE_H_


#include "../SpialeMask.h"
#include "Spiale.h"



/* begin extern "C" */
APP_EXTERN_C_BEGIN



    /*!
     * 恢复轮轴结构
     * @param[in,out] paSpiale 轮轴结构指针地址
     * @return 标识码
     * @remark 不使用时请调用DeleteSpiale删除
    */
    SPIALEMASK_EXPORT int RestoreSpiale(Spiale** paSpiale);


    /*!
     * 旋转轮轴结构
     * @param[in,out] pSpiale 轮轴结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int SpinSpiale(Spiale* pSpiale);


    /*!
     * 捕捉轮轴结构
     * @param[in,out] pSpiale 轮轴结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int SnapSpiale(Spiale* pSpiale);


    /*!
     * 保存轮轴结构
     * @param[in,out] paSpiale 轮轴结构指针地址
     * @param[in]     pSrcSpiale 源轮轴结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DeleteSpiale删除
    */
    SPIALEMASK_EXPORT int SaveSpiale(Spiale** paSpiale
                                      , const Spiale* pSrcSpiale);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ASSEMBLE_H_ */

