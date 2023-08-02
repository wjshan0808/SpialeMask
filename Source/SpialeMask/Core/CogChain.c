#include "CogChain.h"


/*!
 * 新建轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @param[in]     szContent 轮齿内容
 * @return 标识码
 * @remark 不使用时请调用DeleteCogChain删除
*/
int NewCogChain(CogChain** paCogChain
                , const char* szContent)
{
    /*检测指针地址*/
    if(NULL == paCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paCogChain) = NULL;
    }

    /*新建轮齿结构*/
    Cog* pCog = NULL;
    if(APP_FLAG_SUCCESS != NewCog((&pCog)
                                  , szContent))
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮齿链内存*/
    CogChain* pCogChain = calloc(0x01, sizeof(CogChain));
    if(NULL == pCogChain)
    {
        /*删除轮齿结构*/
        DeleteCog((&pCog));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿链结构*/
    {
        /*赋值轮齿链中的轮齿*/
        {
            pCogChain->m_pCog = pCog;
        }

        /*赋值轮齿链的后一个轮齿链*/
        {
            pCogChain->m_pBackward = pCogChain;
        }
        /*赋值轮齿链的前一个轮齿链*/
        {
            pCogChain->m_pForward = pCogChain;
        }
    }

    /*定向指针地址*/
    {
        (*paCogChain) = pCogChain;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 深度克隆轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @param[in]     pSrcCogChain 源轮齿链结构常量指针
 * @return 标识码
 * @remark 不使用时请调用CleanCogChain删除
*/
int CloneCogChain(CogChain** paCogChain
             , const CogChain* pSrcCogChain)
{
    /*检测指针地址*/
    if(NULL == paCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paCogChain) = NULL;
    }

    /*检测指针*/
    if(NULL == pSrcCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮齿链内存*/
    CogChain* pCogChain = calloc(0x01, sizeof(CogChain));
    if(NULL == pCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    //。。。

    /*定向指针地址*/
    {
        (*paCogChain) = pCogChain;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 插入轮齿到轮齿链结构
 * @param[in,out] pDstCogChain 目标轮齿链结构指针
 * @param[in,out] pSrcCogChain 源轮齿链结构指针
 * @return 标识码
*/
int InsertCogChain(CogChain* pDstCogChain
                   , CogChain* pSrcCogChain)
{
    /*检测指针*/
    if(NULL == pSrcCogChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstCogChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstCogChain->m_pBackward)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿链结构*/
    {        
        /*源轮齿链结构*/
        pSrcCogChain->m_pForward = pDstCogChain;
        pSrcCogChain->m_pBackward = pDstCogChain->m_pBackward;

        /*目标轮齿链后一个轮齿链结构*/
        pDstCogChain->m_pBackward->m_pForward = pSrcCogChain;

        /*目标轮齿链结构*/
        pDstCogChain->m_pBackward = pSrcCogChain;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 获取轮齿链中轮齿的数量
 * @param[in]     pCogChain 轮齿链结构常量指针
 * @param[in,out] pCount 轮齿数量指针
 * @return 标识码
*/
int CountCogChain(const CogChain* pCogChain
                  , size_t* pCount)
{
    /*检测指针*/
    if(NULL == pCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针值*/
    {
        (*pCount) = 0x00;
    }

    /*轮齿链的后一个轮齿链*/
    const CogChain* pBackward = pCogChain;
    do
    {
        /*递增轮齿数量*/
        ++(*pCount);

        /*遍历后一个轮齿*/
        pBackward = pBackward->m_pBackward;

        /*循环遍历终止条件: 轮齿链相同*/
    } while((NULL != pBackward) && (pCogChain != pBackward));

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 清空轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @return 标识码
*/
int CleanCogChain(CogChain** paCogChain)
{
    /*检测地址指针*/
    if(NULL == paCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮齿链结构指针*/
    if(NULL == (*paCogChain))
    {
        return APP_FLAG_SUCCESS;
    }

    /*循环遍历终止条件: 轮齿链相同*/
    while((*paCogChain) != (*paCogChain)->m_pBackward)
    {
        /*后一个轮齿链*/
        CleanCogChain(&((*paCogChain)->m_pBackward));
    }

    /*删除轮齿链*/
    DeleteCogChain(paCogChain);

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 删除轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @return 标识码
 * @remark 调用DeleteCogChain前请必要修复轮齿链关系
*/
int DeleteCogChain(CogChain** paCogChain)
{
    /*检测地址指针*/
    if(NULL == paCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮齿链结构指针*/
    if(NULL == (*paCogChain))
    {
        return APP_FLAG_SUCCESS;
    }

    /*释放轮齿内存*/
    DeleteCog(&((*paCogChain)->m_pCog));

    /*释放轮齿链内存*/
    free((*paCogChain));
    {
        (*paCogChain) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

