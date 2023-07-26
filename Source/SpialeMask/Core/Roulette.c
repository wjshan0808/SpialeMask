#include "Roulette.h"


/*!
 * 新建轮盘结构
 * @param[in,out] paRoulette 轮盘结构指针地址
 * @param[in]     pAnchorCog 锚点轮齿结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DelRoulette删除
*/
int NewRoulette(Roulette** paRoulette
                , const Cog* pAnchorCog)
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

    /*新建轮齿链*/
    CogChain* pCogChain = NULL;
    int iFlag = NewCogChain((&pCogChain), pAnchorCog);
    if(APP_FLAG_SUCCESS != iFlag)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮盘内存*/
    Roulette* pRoulette = calloc(0x01, sizeof(Roulette));
    if(NULL == pRoulette)
    {
        /*删除轮齿链*/
        DeleteCogChain((&pCogChain));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*完善轮盘结构*/
    {
        /*赋值轮齿链*/
        pRoulette->m_pCogChain = pCogChain;
        /*赋值锚点轮齿*/
        pRoulette->m_pAnchor = pAnchorCog;

        /*获取轮盘的当前轮齿*/
        {
            Cog* pCog = NULL;
            GetForwardCogInCogChain(pCogChain
                                    , (&pCog));
            {
                pRoulette->m_pCurrent = pCog;
            }
        }
        /*获取轮盘中轮齿的数量*/
        {
            size_t uiCount = 0x00;
            GetCountOfCogInCogChain(pCogChain
                                    , (&uiCount));
            {
                pRoulette->m_uiCount = uiCount;
            }
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
 * @remark 不使用时请调用DelRoulette删除
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
    if(0x00 != memcpy_s(pRoulette, sizeof(Roulette), pSrcRoulette, sizeof(Roulette)))
    {
        /*清理轮盘内存*/
        DeleteRoulette(&pRoulette);

        /*复制失败*/
        return APP_FLAG_FAILURE;
    }

    /*定向指针地址*/
    {
        (*paRoulette) = pRoulette;
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


