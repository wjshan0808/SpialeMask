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
     * @param[in] szFile 文件路径
     * @return 标识码
     * @remark 不使用时请调用DeleteSpiale删除
    */
    SPIALEMASK_EXPORT int RestoreSpiale(Spiale** paSpiale
                                        , const char* szFile);


    /*!
     * 保存轮轴结构
     * @param[in] szFile 文件路径
     * @param[in] pSpiale 轮轴结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int SaveSpiale(const char* szFile
                                      , const Spiale* pSpiale);



/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_ASSEMBLE_H_ */

