#include "Spiale.h"


/*!
 * 旋转轮轴
 * @param[in,out] pSpiale 轮轴结构指针
 * @return 标识码
*/
int SpinSpiale(Spiale* pSpiale)
{
    /*检测指针*/
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 新建轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
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
        /*轮轴中的锚点轮盘链*/
        pSpiale->m_pAnchor = NULL;

        /*轮轴中的当前轮盘链*/
        pSpiale->m_pCurrent = NULL;

        /*轮轴中轮盘链的数量*/
        pSpiale->m_uiCount = 0x00;

        /*轮轴标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidSpiale, (&usIdentity));
        {
            pSpiale->m_usIdentity = usIdentity;
        }

        /*轮轴无效性*/
        pSpiale->m_ucIsNullity = APP_STATE_FALSE;
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

    /*申请轮轴内存*/
    Spiale* pSpiale = calloc(0x01, sizeof(Spiale));
    if(NULL == pSpiale)
    {
        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*源轮轴中的轮盘链*/
    RouletteChain* pRouletteChain = NULL;
    if(APP_FLAG_SUCCESS != CloneRouletteChain((&pRouletteChain)
                                              , pSrcSpiale->m_pAnchor))
    {
        /*删除轮轴结构*/
        DeleteSpiale((&pSpiale));

        /*返回失败*/
        return APP_FLAG_FAILURE;
    }

    /*赋值轮轴结构*/
    {
        /*轮轴中的锚点轮盘链*/
        pSpiale->m_pAnchor = pRouletteChain;

        /*轮轴中的当前轮盘链*/
        pSpiale->m_pCurrent = pRouletteChain;

        /*轮轴中轮盘链的数量*/
        size_t uiCount = 0x00;
        CountRouletteChain(pSpiale->m_pAnchor
                           , (&uiCount));
        {
            pSpiale->m_uiCount = uiCount;
        }

        /*轮轴标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidSpiale, (&usIdentity));
        {
            pSpiale->m_usIdentity = usIdentity;
        }

        /*轮轴无效性*/
        pSpiale->m_ucIsNullity = APP_STATE_FALSE;
    }

    /*定向指针地址*/
    {
        (*paSpiale) = pSpiale;
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
        /*轮轴中的锚点轮盘链*/
        if(NULL == pSpiale->m_pAnchor)
        {
            pSpiale->m_pAnchor = pRouletteChain;
        }

        /*轮轴中的当前轮盘链*/
        if(NULL == pSpiale->m_pCurrent)
        {
            pSpiale->m_pCurrent = pRouletteChain;
        }

        /*追加轮盘链结构*/
        {
            InsertRouletteChain(pSpiale->m_pAnchor->m_pForward
                                , pRouletteChain);
        }

        /*轮轴中轮盘链的数量*/
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

    /*赋值轮轴结构*/
    {
        /*轮轴无效性*/
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

    /*清空轮盘链结构*/
    CleanRouletteChain(&((*paSpiale)->m_pCurrent));

    /*释放内存*/
    free((*paSpiale));
    {
        (*paSpiale) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

