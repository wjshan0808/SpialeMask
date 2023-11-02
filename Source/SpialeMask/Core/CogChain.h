/*#pragma once*/
#ifndef _C_COGCHAIN_H_
#define _C_COGCHAIN_H_


#include "../SpialeMask.h"
#include "Cog.h"


/*!
 * 轮齿链结构
*/
typedef struct CogChain
{
    struct CogChain* m_pForward;        /*轮齿链的前一个轮齿链*/
    Cog* m_pCog;                        /*轮齿链中的轮齿*/
    struct CogChain* m_pBackward;       /*轮齿链的后一个轮齿链*/

} __attribute__((packed)) CogChain;



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @param[in]     szContent 轮齿内容
     * @return 标识码
     * @remark 不使用时请调用DeleteCogChain删除
    */
    SPIALEMASK_EXPORT int NewCogChain(CogChain** paCogChain
                                      , const char* szContent);


    /*!
     * 深度克隆轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @param[in]     pSrcCogChain 源轮齿链结构常量指针
     * @return 标识码
     * @remark 不使用时请调用CleanCogChain删除
    */
    SPIALEMASK_EXPORT int CloneCogChain(CogChain** paCogChain
                                        , const CogChain* pSrcCogChain);


    /*!
     * 插入轮齿到轮齿链结构
     * @param[in,out] pDstCogChain 目标轮齿链结构指针
     * @param[in,out] pSrcCogChain 源轮齿链结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int InsertCogChain(CogChain* pDstCogChain
                                         , CogChain* pSrcCogChain);


    /*!
     * 融合轮齿链结构
     * @param[in,out] pDstCogChain 目标轮齿链结构指针
     * @param[in,out] pSrcCogChain 源轮齿链结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int JoinCogChain(CogChain* pDstCogChain
                                       , CogChain* pSrcCogChain);


    /*!
     * 获取轮齿链中轮齿的数量
     * @param[in]     pCogChain 轮齿链结构常量指针
     * @param[in,out] pCount 轮齿数量指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int CountCogChain(const CogChain* pCogChain
                                        , size_t* pCount);


    /*!
     * 清空轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @return 标识码
     * @remark 调用CleanCogChain前请必要修复轮齿链关系
    */
    SPIALEMASK_EXPORT int CleanCogChain(CogChain** paCogChain);


    /*!
     * 删除轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @return 标识码
     * @remark 调用DeleteCogChain前请必要修复轮齿链关系
    */
    SPIALEMASK_EXPORT int DeleteCogChain(CogChain** paCogChain);




/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_COGCHAIN_H_ */

