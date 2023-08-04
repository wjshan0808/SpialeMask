#include "Roulette.h"


/*!
 * 新建轮盘结构
 * @param[in,out] paRoulette 轮盘结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteRoulette删除
*/
int NewRoulette(Roulette** paRoulette)
{
    /*检测指针地址*/
    if(NULL == paRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paRoulette) = NULL;
    }

    /*申请轮盘内存*/
    Roulette* pRoulette = calloc(0x01, sizeof(Roulette));
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘结构*/
    {
        /*轮盘中轮齿链的数量*/
        pRoulette->m_uiCount = 0x00;

        /*轮盘中的锚点轮齿链*/
        pRoulette->m_pAnchor = NULL;

        /*轮盘中的当前轮齿链*/
        pRoulette->m_pCurrent = NULL;

        /*轮盘标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidRoulette, (&usIdentity));
        {
            pRoulette->m_usIdentity = usIdentity;
        }

        /*轮盘无效性*/
        pRoulette->m_ucIsNullity = APP_STATE_FALSE;

    }

    /*定向指针地址*/
    {
        (*paRoulette) = pRoulette;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 深度克隆轮盘结构
 * @param[in,out] paRoulette 轮盘结构指针地址
 * @param[in]     pSrcRoulette 源轮盘结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DeleteRoulette删除
*/
int CloneRoulette(Roulette** paRoulette
                  , const Roulette* pSrcRoulette)
{
    /*检测指针地址*/
    if(NULL == paRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paRoulette) = NULL;
    }

    /*检测指针*/
    if(NULL == pSrcRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮盘内存*/
    Roulette* pRoulette = calloc(0x01, sizeof(Roulette));
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*复制源轮盘内容*/
    {
        //...
    }

    /*定向指针地址*/
    {
        (*paRoulette) = pRoulette;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 追加轮齿到轮盘结构
 * @param[in,out] pRoulette 轮盘结构指针
 * @param[in]     szContent 轮齿内容
 * @return 标识码
*/
int AppendCog2Roulette(Roulette* pRoulette
                       , const char* szContent)
{
    /*检测指针*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*新建轮齿链结构*/
    CogChain* pCogChain = NULL;
    if(APP_FLAG_SUCCESS != NewCogChain((&pCogChain)
                                       , szContent))
    {
        return APP_FLAG_FAILURE;
    }

    /*更新轮盘结构*/
    {
        /*轮盘中的锚点轮齿链*/
        if(NULL == pRoulette->m_pAnchor)
        {
            pRoulette->m_pAnchor = pCogChain;
        }

        /*追加轮齿到轮齿链结构*/
        InsertCogChain(pRoulette->m_pAnchor->m_pForward
                       , pCogChain);

        /*轮盘中轮齿链的数量*/
        size_t uiCount = 0x00;
        CountCogChain(pRoulette->m_pAnchor
                      , (&uiCount));
        {
            pRoulette->m_uiCount = uiCount;
        }

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 变更轮盘结构无效性
 * @param[in,out] pRoulette 轮盘结构指针
 * @param[in]     ucIsNullity 轮盘结构是否无效
 * @return 标识码
 * @footnote APP_STATE_*为有效输入值
*/
int NullifyRoulette(Roulette* pRoulette
                    , unsigned char ucIsNullity)
{
    /*检测指针地址*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘结构*/
    {
        /*轮盘无效性*/
        pRoulette->m_ucIsNullity = ucIsNullity;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 删除轮盘结构
 * @param[in,out] paRoulette 轮盘结构指针地址
 * @return 标识码
*/
int DeleteRoulette(Roulette** paRoulette)
{
    /*检测地址指针*/
    if(NULL == paRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮盘结构指针*/
    if(NULL == (*paRoulette))
    {
        return APP_FLAG_SUCCESS;
    }

    /*释放内存
    free((*paRoulette));
    {
        (*paRoulette) = NULL;
    }*/

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


