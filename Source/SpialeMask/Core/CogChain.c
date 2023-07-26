#include "CogChain.h"


/*!
 * 新建轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @param[in]     pCog 轮齿结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DelCogChain删除
*/
int NewCogChain(CogChain** paCogChain
                , const Cog* pCog)
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

    /*申请轮齿链内存*/
    CogChain* pCogChain = calloc(0x01, sizeof(CogChain));
    if(NULL == pCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿*/
    {
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
 * @remark 不使用时请调用DelCogChain删除
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

    /*复制源轮齿链内容*/
    if(0x00 != memcpy_s(pCogChain, sizeof(CogChain), pSrcCogChain, sizeof(CogChain)))
    {
        /*清理轮齿链内存*/
        DeleteCogChain(&pCogChain);

        /*复制失败*/
        return APP_FLAG_FAILURE;
    }

    /*定向指针地址*/
    {
        (*paCogChain) = pCogChain;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 删除轮齿链结构
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @return 标识码
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

    /*释放内存
    free((*paCogChain));
    {
        (*paCogChain) = NULL;
    }*/

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}



