#include "RouletteChain.h"



/*!
 * 清空轮盘链结构
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @param[in,out] paBackward 后一个轮盘链结构指针地址
 * @return 标识码
*/
int InlineCleanRouletteChain(RouletteChain** paRouletteChain
                             , RouletteChain** paBackward);




/*!
 * 铸造轮盘链
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @param[in]     uiCount 轮盘的若干轮齿数量
 * @param[in]     szContents 轮盘的若干轮齿内容
 * @return 标识码
 * @remark 不使用时请调用CleanRouletteChain删除
*/
int MoldingRouletteChain(RouletteChain** paRouletteChain
                         , size_t uiCount
                         , const char* szContents[])
{
    /*检测指针地址*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paRouletteChain) = NULL;
    }

    /*检测轮齿内容*/
    if(0x00 == uiCount)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == szContents)
    {
        return APP_FLAG_FAILURE;
    }

    /*新建轮盘链结构*/
    if(APP_FLAG_FAILURE == NewRouletteChain(paRouletteChain))
    {
        return APP_FLAG_FAILURE;
    }

    /*遍历若干轮齿内容*/
    for(size_t uiIndex = 0x00; uiIndex < uiCount; ++uiIndex)
    {
        /*新建轮齿链结构*/
        CogChain* pCogChain = NULL;
        if(APP_FLAG_FAILURE == NewCogChain((&pCogChain), szContents[uiIndex]))
        {
            continue;
        }

        /*追加轮齿链到轮盘结构*/
        AppendCogChain2Roulette((*paRouletteChain)->m_pRoulette, pCogChain);

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 新建轮盘链结构
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteRouletteChain删除
*/
int NewRouletteChain(RouletteChain** paRouletteChain)
{
    /*检测指针地址*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paRouletteChain) = NULL;
    }

    /*新建轮盘结构*/
    Roulette* pRoulette = NULL;
    if(APP_FLAG_SUCCESS != NewRoulette((&pRoulette)))
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮盘链内存*/
    RouletteChain* pRouletteChain = calloc(0x01, sizeof(RouletteChain));
    if(NULL == pRouletteChain)
    {
        /*申请轮盘链内存失败, 删除新建轮盘结构*/
        DeleteRoulette((&pRoulette));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘链结构*/
    {
        /*赋值轮盘链中的轮盘, 为新建轮盘*/
        {
            pRouletteChain->m_pRoulette = pRoulette;
        }

        /*赋值轮盘链的前一个轮盘链, 为新建轮盘链*/
        {
            pRouletteChain->m_pForward = pRouletteChain;
        }

        /*赋值轮盘链的后一个轮盘链, 为新建轮盘链*/
        {
            pRouletteChain->m_pBackward = pRouletteChain;
        }

    }

    /*定向指针地址*/
    {
        (*paRouletteChain) = pRouletteChain;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 深度克隆轮盘链结构
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @param[in]     pSrcRouletteChain 源轮盘链结构常量指针
 * @return 标识码
 * @remark 不使用时请调用CleanRouletteChain删除
*/
int CloneRouletteChain(RouletteChain** paRouletteChain
                       , const RouletteChain* pSrcRouletteChain)
{
    /*检测指针地址*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paRouletteChain) = NULL;
    }

    /*检测指针*/
    if(NULL == pSrcRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*标记: 轮盘链的后一个轮盘链*/
    RouletteChain* pBackward = NULL;

    /*源轮盘链的后一个轮盘链*/
    const RouletteChain* pSrcBackward = pSrcRouletteChain;

    do
    {
        /*克隆轮盘链*/
        {
            /*克隆轮盘, 其轮齿链数量有保证*/
            Roulette* pRoulette = NULL;
            if(APP_FLAG_SUCCESS != CloneRoulette((&pRoulette)
                                                 , pSrcBackward->m_pRoulette))
            {
                /*克隆轮盘失败, 清空已克隆的轮盘链*/
                CleanRouletteChain(paRouletteChain);

                /*返回失败*/
                return APP_FLAG_FAILURE;
            }

            /*申请轮盘链内存*/
            RouletteChain* pRouletteChain = calloc(0x01, sizeof(RouletteChain));
            if(NULL == pRouletteChain)
            {
                /*申请轮盘链内存失败, 清空已克隆的轮盘链*/
                CleanRouletteChain(paRouletteChain);

                /*返回失败*/
                return APP_FLAG_FAILURE;
            }

            /*赋值轮盘链结构, 构建环型轮盘链*/
            {
                /*赋值轮盘链中的轮盘, 为克隆轮盘*/
                {
                    pRouletteChain->m_pRoulette = pRoulette;
                }

                /*赋值轮盘链的前一个轮盘链, 为新建轮盘链*/
                {
                    pRouletteChain->m_pForward = pRouletteChain;
                }

                /*赋值轮盘链的后一个轮盘链, 为新建轮盘链*/
                {
                    pRouletteChain->m_pBackward = pRouletteChain;
                }
            }

            /*当首次遍历源轮盘链时*/
            if(pSrcBackward == pSrcRouletteChain)
            {
                /*轮盘链赋值给轮盘链结构指针, 并标记轮盘链的后一个轮盘链, 为新建轮盘链*/
                pBackward = (*paRouletteChain) = pRouletteChain;
            }
            else
            {
                /*标记轮盘链的后一个轮盘链, 为后一个轮盘链*/
                pBackward = pBackward->m_pBackward;
            }

            /*插入轮盘到轮盘链结构*/
            InsertRouletteChain(pBackward
                                , pRouletteChain);
        }

        /*循环遍历后一个轮盘链*/
        pSrcBackward = pSrcBackward->m_pBackward;

        /*循环遍历终止条件: 轮盘链首尾相同*/
    } while((NULL != pSrcBackward) && (pSrcBackward != pSrcRouletteChain));

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 插入轮盘到轮盘链结构
 * @param[in,out] pDstRouletteChain 目标轮盘链结构指针
 * @param[in,out] pSrcRouletteChain 源轮盘链结构指针
 * @return 标识码
*/
int InsertRouletteChain(RouletteChain* pDstRouletteChain
                        , RouletteChain* pSrcRouletteChain)
{
    /*检测指针*/
    if(NULL == pSrcRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstRouletteChain->m_pBackward)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘链结构*/
    {        
        /*赋值源轮盘链结构*/
        {
            pSrcRouletteChain->m_pForward = pDstRouletteChain;
            pSrcRouletteChain->m_pBackward = pDstRouletteChain->m_pBackward;
        }

        /*赋值目标轮盘链结构*/
        {
            pDstRouletteChain->m_pBackward->m_pForward = pSrcRouletteChain;
            pDstRouletteChain->m_pBackward = pSrcRouletteChain;
        }

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 融合轮盘链结构
 * @param[in,out] pDstRouletteChain 目标轮盘链结构指针
 * @param[in,out] pSrcRouletteChain 源轮盘链结构指针
 * @return 标识码
*/
int JoinRouletteChain(RouletteChain* pDstRouletteChain
                      , RouletteChain* pSrcRouletteChain)
{
    /*检测指针*/
    if(NULL == pSrcRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pSrcRouletteChain->m_pForward)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pDstRouletteChain->m_pForward)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮盘链结构*/
    {
        /*目标轮盘链前一个轮盘链结构*/
        RouletteChain* pDstForward = pDstRouletteChain->m_pForward;

        /*赋值目标轮盘链结构*/
        {
            pDstRouletteChain->m_pForward->m_pBackward = pSrcRouletteChain;
            pDstRouletteChain->m_pForward = pSrcRouletteChain->m_pForward;
        }

        /*赋值源轮盘链结构*/
        {
            pSrcRouletteChain->m_pForward->m_pBackward = pDstRouletteChain;
            pSrcRouletteChain->m_pForward = pDstForward;
        }

    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 获取轮盘链中轮盘的数量
 * @param[in]     pRouletteChain 轮盘链结构常量指针
 * @param[in,out] pCount 轮盘数量指针
 * @return 标识码
*/
int CountRouletteChain(const RouletteChain* pRouletteChain
                       , size_t* pCount)
{
    /*检测指针*/
    if(NULL == pRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针值*/
    {
        (*pCount) = 0x00;
    }

    /*轮盘链的后一个轮盘链*/
    const RouletteChain* pBackward = pRouletteChain;
    do
    {
        /*累计轮盘数量*/
        ++(*pCount);

        /*循环遍历后一个轮盘*/
        pBackward = pBackward->m_pBackward;

        /*循环遍历终止条件: 轮盘链首尾相同*/
    } while((NULL != pBackward) && (pBackward != pRouletteChain));

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 清空轮盘链结构
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @return 标识码
*/
int CleanRouletteChain(RouletteChain** paRouletteChain)
{
    /*检测地址指针*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮盘链结构指针*/
    if(NULL == (*paRouletteChain))
    {
        return APP_FLAG_SUCCESS;
    }

    /*删除轮盘链*/
    return InlineCleanRouletteChain(paRouletteChain
                                    , paRouletteChain);
}
int InlineCleanRouletteChain(RouletteChain** paRouletteChain
                             , RouletteChain** paBackward)
{
    /*检测地址指针*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == paBackward)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮盘链结构指针*/
    if(NULL == (*paRouletteChain))
    {
        return APP_FLAG_SUCCESS;
    }
    if(NULL == (*paBackward))
    {
        return APP_FLAG_SUCCESS;
    }

    /*终止条件: 轮盘链首尾相同*/
    if((*paRouletteChain) != (*paBackward)->m_pBackward)
    {
        InlineCleanRouletteChain(paRouletteChain
                                 , &((*paBackward)->m_pBackward));
    }

    /*删除轮盘链*/
    return DeleteRouletteChain(paBackward);
}


/*!
 * 删除轮盘链结构
 * @param[in,out] paRouletteChain 轮盘链结构指针地址
 * @return 标识码
 * @remark 调用DeleteRouletteChain前请必要修复轮盘链关系
*/
int DeleteRouletteChain(RouletteChain** paRouletteChain)
{
    /*检测地址指针*/
    if(NULL == paRouletteChain)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮盘链结构指针*/
    if(NULL == (*paRouletteChain))
    {
        return APP_FLAG_SUCCESS;
    }

    /*释放轮盘内存*/
    {
        DeleteRoulette(&((*paRouletteChain)->m_pRoulette));
    }

    /*释放轮盘链内存*/
    {
        free((*paRouletteChain));
        (*paRouletteChain) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

