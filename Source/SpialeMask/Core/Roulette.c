#include "Roulette.h"


/*!
 * 新建轮盘结构
 * @param[in,out] paRoulette 轮盘结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteRoulette删除
 * @footnote 请随后挂载轮齿链使轮盘有效
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
        /*轮盘中的锚点轮齿链, 为空*/
        {
            pRoulette->m_pAnchor = NULL;
        }

        /*轮盘中的当前轮齿链, 为空*/
        {
            pRoulette->m_pCurrent = NULL;
        }

        /*轮盘中轮齿链的数量, 为0x00*/
        {
            pRoulette->m_uiCount = 0x00;
        }

        /*轮盘全局递增标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidRoulette, (&usIdentity));
        {
            pRoulette->m_usIdentity = usIdentity;
        }

        /*轮盘默认无效*/
        {
            pRoulette->m_ucIsNullity = APP_STATE_TRUE;
        }

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

    /*检测源轮盘中轮齿链数量*/
    if(0x00 == pSrcRoulette->m_uiCount)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮盘内存*/
    Roulette* pRoulette = calloc(0x01, sizeof(Roulette));
    if(NULL == pRoulette)
    {
        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*克隆源轮盘中的轮齿链*/
    CogChain* pCogChain = NULL;
    if(APP_FLAG_SUCCESS != CloneCogChain((&pCogChain)
                                         , pSrcRoulette->m_pAnchor))
    {
        /*克隆轮齿链失败, 删除申请轮盘内存*/
        DeleteRoulette((&pRoulette));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘结构*/
    {
        /*轮盘中的锚点轮齿链, 为克隆源轮盘中的轮齿链*/
        {
            pRoulette->m_pAnchor = pCogChain;
        }

        /*轮盘中的当前轮齿链, 为克隆源轮盘中的轮齿链*/
        {
            pRoulette->m_pCurrent = pCogChain;
        }

        /*计算轮盘中轮齿链的数量*/
        size_t uiCount = 0x00;
        CountCogChain(pRoulette->m_pAnchor
                      , (&uiCount));
        {
            pRoulette->m_uiCount = uiCount;
        }

        /*轮盘全局递增标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidRoulette, (&usIdentity));
        {
            pRoulette->m_usIdentity = usIdentity;
        }

        /*轮盘默认有效*/
        {
            pRoulette->m_ucIsNullity = APP_STATE_FALSE;
        }

    }

    /*定向指针地址*/
    {
        (*paRoulette) = pRoulette;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 从轮盘结构移除轮齿链
 * @param[in,out] pRoulette 轮盘结构指针
 * @param[in,out] paCogChain 轮齿链结构指针地址
 * @return 标识码
*/
int RemoveCogChainFromRoulette(Roulette* pRoulette
                               , CogChain** paCogChain)
{
    /*检测指针*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测指针地址*/
    if(NULL == paCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*标识: 轮盘中包含轮齿链*/
    unsigned char ucContains = APP_STATE_FALSE;

    /*轮齿链的下一个轮齿*/
    const CogChain* pForword = pRoulette->m_pAnchor;
    {
        while (NULL != pForword)
        {
            /*循环遍历终止: 当前轮齿链 等于 给定轮齿链*/
            if(pForword == (*paCogChain))
            {
                ucContains = APP_STATE_TRUE;
                break;
            }

            /*循环遍历下一个轮齿*/
            pForword = pForword->m_pForward;

            /*循环遍历终止条件: 轮齿链首尾相同*/
            if(pRoulette->m_pAnchor == pForword)
            {
                break;
            }
        }
    }

    /*条件: 轮盘中不包含轮齿链*/
    if(APP_STATE_FALSE == ucContains)
    {
        return APP_FLAG_FAILURE;
    }

    /*计算轮盘中轮齿链的数量*/
    size_t uiCount = 0x00;
    {
        CountCogChain(pRoulette->m_pAnchor, (&uiCount));
    }

    /*条件: 轮盘中轮齿链的数量至少一个*/
    if(0x01 == uiCount)
    {
        /*轮盘中的锚点轮齿链, 为空*/
        {
            pRoulette->m_pAnchor = NULL;
        }

        /*轮盘中的当前轮齿链, 为空*/
        {
            pRoulette->m_pCurrent = NULL;
        }

        /*轮盘中轮齿链的数量, 为0x00*/
        {
            pRoulette->m_uiCount = 0x00;
        }

        /*轮盘无效*/
        {
            pRoulette->m_ucIsNullity = APP_STATE_TRUE;
        }
    }
    else
    {
        /*修复给定轮齿链前一个轮齿链*/
        {
            (*paCogChain)->m_pForward->m_pBackward = (*paCogChain)->m_pBackward;
        }

        /*修复给定轮齿链后一个轮齿链*/
        {
            (*paCogChain)->m_pBackward->m_pForward = (*paCogChain)->m_pForward;
        }

        /*条件: 轮盘锚点轮齿链 等于 给定轮齿链*/
        if(pRoulette->m_pAnchor == (*paCogChain))
        {
            /*轮盘锚点轮齿链: 前移*/
            pRoulette->m_pAnchor = (*paCogChain)->m_pForward;
        }

        /*条件: 轮盘当前轮齿链 等于 给定轮齿链*/
        if(pRoulette->m_pCurrent == (*paCogChain))
        {
            /*轮盘当前轮齿链: 前移*/
            pRoulette->m_pCurrent = (*paCogChain)->m_pForward;
        }

        /*轮盘中轮齿链的数量, 减一*/
        {
            pRoulette->m_uiCount = (uiCount - 0x01);
        }

    }

    /*释放轮齿链内存*/
    {
        DeleteCogChain(paCogChain);
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 追加轮齿链到轮盘结构
 * @param[in,out] pRoulette 轮盘结构指针
 * @param[in,out] pCogChain 轮齿链结构指针
 * @return 标识码
*/
int AppendCogChain2Roulette(Roulette* pRoulette
                            , CogChain* pCogChain)
{
    /*检测指针*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘结构*/
    {
        /*使轮盘从无效转变回有效状态*/
        if((APP_STATE_TRUE == pRoulette->m_ucIsNullity)
           && (0x00 == pRoulette->m_uiCount))
        {
            pRoulette->m_ucIsNullity = APP_STATE_FALSE;
        }

        /*轮盘中的锚点轮齿链为空时, 为指定轮齿链结构*/
        if(NULL == pRoulette->m_pAnchor)
        {
            pRoulette->m_pAnchor = pCogChain;
        }

        /*轮盘中的当前轮齿链为空时, 为指定轮齿链结构*/
        if(NULL == pRoulette->m_pCurrent)
        {
            pRoulette->m_pCurrent = pCogChain;
        }

        /*追加轮齿链结构*/
        {
            InsertCogChain(pRoulette->m_pAnchor->m_pForward
                           , pCogChain);
        }

        /*计算轮盘中轮齿链的数量*/
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
 * 融合轮齿链到轮盘结构
 * @param[in,out] pRoulette 轮盘结构指针
 * @param[in,out] pCogChain 轮齿链结构指针
 * @return 标识码
*/
int JoinCogChain2Roulette(Roulette* pRoulette
                          , CogChain* pCogChain)
{
    /*检测指针*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pCogChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘结构*/
    {
        /*使轮盘从无效转变回有效状态*/
        if((APP_STATE_TRUE == pRoulette->m_ucIsNullity)
           && (0x00 == pRoulette->m_uiCount))
        {
            pRoulette->m_ucIsNullity = APP_STATE_FALSE;
        }

        /*轮盘中的锚点轮齿链为空时, 为当前轮齿链结构*/
        if(NULL == pRoulette->m_pAnchor)
        {
            pRoulette->m_pAnchor = pCogChain;
        }

        /*轮盘中的当前轮齿链为空时, 为当前轮齿链结构*/
        if(NULL == pRoulette->m_pCurrent)
        {
            pRoulette->m_pCurrent = pCogChain;
        }

        /*融合轮齿链结构*/
        {
            JoinCogChain(pRoulette->m_pAnchor->m_pForward
                         , pCogChain);
        }

        /*计算轮盘中轮齿链的数量*/
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
    /*检测指针*/
    if(NULL == pRoulette)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘无效性*/
    {
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

    /*清空轮盘轮齿链结构*/
    {
        CleanCogChain(&((*paRoulette)->m_pCurrent));
    }

    /*释放轮盘内存*/
    {
        free((*paRoulette));
        (*paRoulette) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

