#include "Spiale.h"


/*!
 * 新建轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
 * @footnote 请随后挂载轮盘链使轮轴有效
*/
int NewSpiale(Spiale** paSpiale)
{
    /*检测指针地址*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paSpiale) = NULL;
    }

    /*申请轮轴内存*/
    Spiale* pSpiale = calloc(0x01, sizeof(Spiale));
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴结构*/
    {
        /*轮轴中的锚点轮盘链, 为空*/
        {
            pSpiale->m_pAnchor = NULL;
        }

        /*轮轴中的当前轮盘链, 为空*/
        {
            pSpiale->m_pCurrent = NULL;
        }

        /*轮轴中轮盘链的数量, 为0x00*/
        {
            pSpiale->m_uiCount = 0x00;
        }

        /*轮轴全局递增标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidSpiale, (&usIdentity));
        {
            pSpiale->m_usIdentity = usIdentity;
        }

        /*轮轴默认无效*/
        {
            pSpiale->m_ucIsNullity = APP_STATE_TRUE;
        }

    }

    /*定向指针地址*/
    {
        (*paSpiale) = pSpiale;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 深度克隆轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @param[in]     pSrcSpiale 源轮轴结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
*/
int CloneSpiale(Spiale** paSpiale
                , const Spiale* pSrcSpiale)
{
    /*检测指针地址*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paSpiale) = NULL;
    }

    /*检测指针*/
    if(NULL == pSrcSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测源轮轴中轮盘链数量*/
    if(0x00 == pSrcSpiale->m_uiCount)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮轴内存*/
    Spiale* pSpiale = calloc(0x01, sizeof(Spiale));
    if(NULL == pSpiale)
    {
        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*克隆源轮轴中的轮盘链*/
    RouletteChain* pRouletteChain = NULL;
    if(APP_FLAG_SUCCESS != CloneRouletteChain((&pRouletteChain)
                                              , pSrcSpiale->m_pAnchor))
    {
        /*克隆轮盘链失败, 删除申请轮轴内存*/
        DeleteSpiale((&pSpiale));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴结构*/
    {
        /*轮轴中的锚点轮盘链, 为克隆源轮轴中的轮盘链*/
        {
            pSpiale->m_pAnchor = pRouletteChain;
        }

        /*轮轴中的当前轮盘链, 为克隆源轮轴中的轮盘链*/
        {
            pSpiale->m_pCurrent = pRouletteChain;
        }

        /*计算轮轴中轮盘链的数量*/
        size_t uiCount = 0x00;
        CountRouletteChain(pSpiale->m_pAnchor
                           , (&uiCount));
        {
            pSpiale->m_uiCount = uiCount;
        }

        /*轮轴全局递增标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidSpiale, (&usIdentity));
        {
            pSpiale->m_usIdentity = usIdentity;
        }

        /*轮轴默认有效*/
        {
            pSpiale->m_ucIsNullity = APP_STATE_FALSE;
        }

    }

    /*定向指针地址*/
    {
        (*paSpiale) = pSpiale;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 从轮轴结构移除轮盘链
 * @param[in,out] pSpiale 轮轴结构指针
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @return 标识码
*/
int RemoveRouletteChainFromSpiale(Spiale* pSpiale
                                  , RouletteChain** paRouletteChain)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测指针地址*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*标识: 轮轴中包含轮盘链*/
    unsigned char ucContains = APP_STATE_FALSE;

    /*指定移除的轮盘链*/
    RouletteChain* pRouletteChain = (*paRouletteChain);

    /*轮盘链的下一个轮盘*/
    const RouletteChain* pForword = pSpiale->m_pAnchor;
    {
        while (NULL != pForword)
        {
            /*循环遍历终止: 当前轮盘链 等于 给定轮盘链*/
            if(pForword == pRouletteChain)
            {
                ucContains = APP_STATE_TRUE;
                break;
            }

            /*循环遍历下一个轮盘*/
            pForword = pForword->m_pForward;

            /*循环遍历终止条件: 轮盘链首尾相同*/
            if(pSpiale->m_pAnchor == pForword)
            {
                break;
            }
        }
    }

    /*条件: 轮轴中不包含轮盘链*/
    if(APP_STATE_FALSE == ucContains)
    {
        return APP_FLAG_FAILURE;
    }

    /*计算轮轴中轮盘链的数量*/
    size_t uiCount = 0x00;
    {
        CountRouletteChain(pSpiale->m_pAnchor, (&uiCount));
    }

    /*条件: 轮轴中轮盘链的数量至少一个*/
    if(0x01 == uiCount)
    {
        /*轮轴中的锚点轮盘链, 为空*/
        {
            pSpiale->m_pAnchor = NULL;
        }

        /*轮轴中的当前轮盘链, 为空*/
        {
            pSpiale->m_pCurrent = NULL;
        }

        /*轮轴中轮盘链的数量, 为0x00*/
        {
            pSpiale->m_uiCount = 0x00;
        }

        /*轮轴无效*/
        {
            pSpiale->m_ucIsNullity = APP_STATE_TRUE;
        }
    }
    else
    {
        /*修复给定轮盘链前一个轮盘链*/
        {
            pRouletteChain->m_pForward->m_pBackward = pRouletteChain->m_pBackward;
        }

        /*修复给定轮盘链后一个轮盘链*/
        {
            pRouletteChain->m_pBackward->m_pForward = pRouletteChain->m_pForward;
        }

        /*条件: 轮轴锚点轮盘链 等于 给定轮盘链*/
        if(pSpiale->m_pAnchor == pRouletteChain)
        {
            /*轮轴锚点轮盘链: 前移*/
            pSpiale->m_pAnchor = pRouletteChain->m_pForward;
        }

        /*条件: 轮轴当前轮盘链 等于 给定轮盘链*/
        if(pSpiale->m_pCurrent == pRouletteChain)
        {
            /*轮轴当前轮盘链: 前移*/
            pSpiale->m_pCurrent = pRouletteChain->m_pForward;
        }

        /*轮轴中轮盘链的数量, 减一*/
        {
            pSpiale->m_uiCount = (uiCount - 0x01);
        }

    }

    /*释放轮盘链内存*/
    {
        DeleteRouletteChain(&pRouletteChain);
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 追加轮盘链到轮轴结构
 * @param[in,out] pSpiale 轮轴结构指针
 * @param[in,out] pRouletteChain 轮盘链指针
 * @return 标识码
*/
int AppendRouletteChain2Spiale(Spiale* pSpiale
                               , RouletteChain* pRouletteChain)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴结构*/
    {
        /*使轮轴从无效转变回有效状态*/
        if((APP_STATE_TRUE == pSpiale->m_ucIsNullity)
           && (0x00 == pSpiale->m_uiCount))
        {
            pSpiale->m_ucIsNullity = APP_STATE_FALSE;
        }

        /*轮轴中的锚点轮盘链, 为当前轮盘链结构*/
        if(NULL == pSpiale->m_pAnchor)
        {
            pSpiale->m_pAnchor = pRouletteChain;
        }

        /*轮轴中的当前轮盘链, 为当前轮盘链结构*/
        if(NULL == pSpiale->m_pCurrent)
        {
            pSpiale->m_pCurrent = pRouletteChain;
        }

        /*条件: 向轮轴中已有轮盘链追加轮盘*/
        if(0x00 < pSpiale->m_uiCount)
        {
            InsertRouletteChain(pSpiale->m_pAnchor->m_pForward
                                , pRouletteChain);
        }

        /*计算轮轴中轮盘链的数量*/
        size_t uiCount = 0x00;
        CountRouletteChain(pSpiale->m_pAnchor
                           , (&uiCount));
        {
            pSpiale->m_uiCount = uiCount;
        }

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 融合轮盘链到轮轴结构
 * @param[in,out] pSpiale 轮轴结构指针
 * @param[in,out] pRouletteChain 轮盘链指针
 * @return 标识码
*/
int JoinRouletteChain2Spiale(Spiale* pSpiale
                             , RouletteChain* pRouletteChain)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴结构*/
    {
        /*使轮轴从无效转变回有效状态*/
        if((APP_STATE_TRUE == pSpiale->m_ucIsNullity)
           && (0x00 == pSpiale->m_uiCount))
        {
            pSpiale->m_ucIsNullity = APP_STATE_FALSE;
        }

        /*轮轴中的锚点轮盘链, 为当前轮盘链结构*/
        if(NULL == pSpiale->m_pAnchor)
        {
            pSpiale->m_pAnchor = pRouletteChain;
        }

        /*轮轴中的当前轮盘链, 为当前轮盘链结构*/
        if(NULL == pSpiale->m_pCurrent)
        {
            pSpiale->m_pCurrent = pRouletteChain;
        }

        /*条件: 向轮轴中已有轮盘链融合轮盘链结构*/
        if(0x00 < pSpiale->m_uiCount)
        {
            JoinRouletteChain(pSpiale->m_pAnchor->m_pForward
                              , pRouletteChain);
        }

        /*计算轮轴中轮盘链的数量*/
        size_t uiCount = 0x00;
        CountRouletteChain(pSpiale->m_pAnchor
                           , (&uiCount));
        {
            pSpiale->m_uiCount = uiCount;
        }

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 计量轮轴轮齿
 * @param[in]     pSpiale 轮轴结构常量指针
 * @param[in,out] pMeasure 计量指针
 * @param[in]     ucIgnoreNullity 是否忽略轮轴无效性
 * @return 标识码
 * @footnote APP_STATE_*为有效输入值
*/
int MeasureSpiale(const Spiale* pSpiale
                  , size_t* pMeasure
                  , unsigned char ucIgnoreNullity)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pMeasure)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮轴中轮盘数量*/
    if(0x00 == pSpiale->m_uiCount)
    {
        return APP_FLAG_FAILURE;
    }

    /*计量初始大小*/
    size_t uiSizeMeasure = 0x00;
    {
        (*pMeasure) = uiSizeMeasure;
    }

    /*条件: 不忽略无效性, 并且当前轮轴无效*/
    if((APP_STATE_FALSE == ucIgnoreNullity)
       && (APP_STATE_TRUE == pSpiale->m_ucIsNullity))
    {
        return APP_FLAG_SUCCESS;
    }

    /*轮轴中的轮盘数量, 及锚点轮盘链*/
    size_t uiCountRoulette = pSpiale->m_uiCount;
    const RouletteChain* pRoulette = pSpiale->m_pAnchor;

    /*轮盘中的轮齿数量, 及锚点轮齿链*/
    size_t uiCountCog = pRoulette->m_pRoulette->m_uiCount;
    const CogChain* pCog = pRoulette->m_pRoulette->m_pAnchor;

    /*标记: 最大标量初值*/
    size_t uiMaxLength = 0x00;

    /*遍历轮轴中的轮盘*/
    for(size_t uiIndexRoulette = 0x00; uiIndexRoulette < uiCountRoulette; ++uiIndexRoulette)
    {
        /*遍历轮盘中的轮齿*/
        for(size_t uiIndexCog = 0x00; uiIndexCog < uiCountCog; ++uiIndexCog)
        {
            /*当前轮齿计量值 大于 最大标量值*/
            size_t uiLength = pCog->m_pCog->m_uiLength;
            if(uiLength > uiMaxLength)
            {
                /*条件: 不忽略无效性, 并且当前轮齿无效*/
                if((APP_STATE_FALSE == ucIgnoreNullity)
                   && (APP_STATE_TRUE == pCog->m_pCog->m_ucIsNullity))
                {
                    /*跳过标量*/
                }
                else
                {
                    /*标记: 最大标量值*/
                    uiMaxLength = uiLength;
                }
            }

            /*下一个轮齿: 数量担保*/
            pCog = pCog->m_pBackward;
        }

        /*条件: 不忽略无效性, 并且当前轮盘无效*/
        if((APP_STATE_FALSE == ucIgnoreNullity)
           && (APP_STATE_TRUE == pRoulette->m_pRoulette->m_ucIsNullity))
        {
            /*跳过累计*/
        }
        else
        {
            /*累计计量值*/
            uiSizeMeasure += uiMaxLength;
        }

        /*遍历下一个轮盘链: 有轮盘数量担保(非NULL)*/
        pRoulette = pRoulette->m_pBackward;
        {
            /*重置: 最大标量值*/
            uiMaxLength = 0x00;

            /*下一个轮盘中的轮齿数量, 及锚点轮齿链*/
            uiCountCog = pRoulette->m_pRoulette->m_uiCount;
            pCog = pRoulette->m_pRoulette->m_pAnchor;
        }

    }

    /*获取计量值*/
    {
        (*pMeasure) = uiSizeMeasure;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 旋转轮轴结构
 * @param[in,out] pSpiale 轮轴结构指针
 * @param[in,out] szSnap 轮轴快照
 * @param[in]     uiMeasure 轮轴计量大小
 * @param[in]     ucIgnoreNullity 是否忽略轮轴无效性
 * @return 标识码
 * @footnote APP_STATE_*为有效输入值
*/
int SpinSpiale(Spiale* pSpiale
               , char* szSnap
               , size_t uiMeasure
               , unsigned char ucIgnoreNullity)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == szSnap)
    {
        return APP_FLAG_FAILURE;
    }

    /*清空轮轴快照*/
    size_t uiIndex = 0x00;
    while((uiIndex < uiMeasure) && (0x00 != (*(szSnap + uiIndex))))
    {
        (*(szSnap + uiIndex++)) = 0x00;
    }

    /*检测轮盘*/
    if(0x00 == pSpiale->m_uiCount)
    {
        return APP_FLAG_SUCCESS;
    }

    /*条件: 不忽略无效性, 并且当前轮轴无效*/
    if((APP_STATE_FALSE == ucIgnoreNullity)
       && (APP_STATE_TRUE == pSpiale->m_ucIsNullity))
    {
        return APP_FLAG_SUCCESS;
    }

    /*标识: 轮轴旋转结束*/
    unsigned char ucIsSpinOver = APP_STATE_TRUE;
    /*标识: 轮盘推进*/
    unsigned char ucPropelling = APP_STATE_FALSE;

    /*轮轴中锚点轮盘链: 有轮盘数量担保(非NULL)*/
    const RouletteChain* pRoulette = pSpiale->m_pAnchor;

    do
    {
        /*条件: 不存在轮齿; 或者; 不忽略无效性, 并且当前轮盘无效*/
        if((0x00 == pRoulette->m_pRoulette->m_uiCount)
           || ((APP_STATE_FALSE == ucIgnoreNullity) && (APP_STATE_TRUE == pRoulette->m_pRoulette->m_ucIsNullity)))
        {
            /*忽略轮盘*/
        }
        else
        {
            /*轮盘中当前轮齿: 有轮齿数量担保(非NULL)*/
            const CogChain* pCog = pRoulette->m_pRoulette->m_pCurrent;
            {
                /*条件: 不忽略无效性, 并且当前轮盘无效*/
                if((APP_STATE_FALSE == ucIgnoreNullity)
                   && (APP_STATE_TRUE == pCog->m_pCog->m_ucIsNullity))
                {
                    /*忽略轮齿*/
                }
                else
                {
                    /*获取齿轮内容快照*/
                    int iError = strncat_s(szSnap, uiMeasure, pCog->m_pCog->m_szContent, pCog->m_pCog->m_uiLength);
                    if(0x00 != iError)
                    {
                        /*获取齿轮内容快照错误*/
                    }
                }
            }

            /*轮盘推进条件: 锚点轮盘*/
            if(pSpiale->m_pAnchor == pRoulette)
            {
                pRoulette->m_pRoulette->m_pCurrent = pCog->m_pBackward;

                /*轮盘推进标识开启条件: 锚点轮盘旋转后, 当前轮齿 回归于 锚点*/
                if(pRoulette->m_pRoulette->m_pAnchor == pRoulette->m_pRoulette->m_pCurrent)
                {
                    ucPropelling = APP_STATE_TRUE;
                }
                else
                {
                    ucPropelling = APP_STATE_FALSE;
                }
            }

            /*轮盘推进条件: 非锚点轮盘, 并且轮盘推进标识开启*/
            if((pSpiale->m_pAnchor != pRoulette)
               && (APP_STATE_TRUE == ucPropelling))
            {
                pRoulette->m_pRoulette->m_pCurrent = pCog->m_pBackward;

                /*轮盘推进标识开启条件: 非锚点轮盘旋转后, 当前轮齿 回归于 锚点*/
                if(pRoulette->m_pRoulette->m_pAnchor == pRoulette->m_pRoulette->m_pCurrent)
                {
                    ucPropelling = APP_STATE_TRUE;
                }
                else
                {
                    ucPropelling = APP_STATE_FALSE;
                }
            }

            /*轮轴旋转结束条件: 轮轴上所有轮盘中当前轮齿 回归于 锚点*/
            {
                ucIsSpinOver &= ucPropelling;
            }

        }

        /*循环遍历下一个轮盘链*/
        pRoulette = pRoulette->m_pBackward;

        /*循环遍历终止条件: 当前轮盘 回归于 锚点*/
    } while((NULL != pRoulette) && (pSpiale->m_pAnchor != pRoulette));

    /*条件: 轮轴旋转结束标识*/
    if(APP_STATE_TRUE == ucIsSpinOver)
    {
        return APP_FLAG_SM_SPIN_OVER;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 变更轮轴结构无效性
 * @param[in,out] pSpiale 轮轴结构指针
 * @param[in]     ucIsNullity 轮轴结构是否无效
 * @return 标识码
 * @footnote APP_STATE_*为有效输入值
*/
int NullifySpiale(Spiale* pSpiale
                  , unsigned char ucIsNullity)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴无效性*/
    {
        pSpiale->m_ucIsNullity = ucIsNullity;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 删除轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @return 标识码
*/
int DeleteSpiale(Spiale** paSpiale)
{
    /*检测地址指针*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮轴结构指针*/
    if(NULL == (*paSpiale))
    {
        return APP_FLAG_SUCCESS;
    }

    /*清空轮轴轮盘链结构*/
    {
        CleanRouletteChain(&((*paSpiale)->m_pCurrent));
    }

    /*释放轮轴内存*/
    {
        free((*paSpiale));
        (*paSpiale) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

