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
    struct CogChain* m_pBackward;
    Cog* m_pCog;
    struct CogChain* m_pForward;

} __attribute__((packed)) CogChain;



/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @param[in]     pCog 轮齿结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DelCogChain删除
    */
    SPIALEMASK_EXPORT int NewCogChain(CogChain** paCogChain
                                      , const Cog* pCog);


    /*!
     * 深度克隆轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @param[in]     pSrcCogChain 源轮齿链结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DelCogChain删除
    */
    SPIALEMASK_EXPORT int CloneCogChain(CogChain** paCogChain
                                        , const CogChain* pSrcCogChain);


    /*!
     * 获取轮齿链的向前轮齿
     * @param[in]     pCogChain 轮齿链结构常量指针
     * @param[in,out] paCog 轮齿结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int GetForwardCogInCogChain(const CogChain* pCogChain
                                                  , Cog** paCog);


    /*!
     * 获取轮齿链中轮齿的数量
     * @param[in]     pCogChain 轮齿链结构常量指针
     * @param[in,out] paCount 轮齿数量指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int GetCountOfCogInCogChain(const CogChain* pCogChain
                                                  , size_t* paCount);


    /*!
     * 删除轮齿链结构
     * @param[in,out] paCogChain 轮齿链结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DeleteCogChain(CogChain** paCogChain);




/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_COGCHAIN_H_ */

