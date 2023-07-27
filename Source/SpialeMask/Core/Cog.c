#include "Cog.h"


/*!
 * 新建轮齿结构
 * @param[in,out] paCog 轮齿结构指针地址
 * @param[in]     szContent 轮齿内容
 * @return 标识码
 * @remark 不使用时请调用DeleteCog删除
*/
int NewCog(Cog** paCog
           , const char* szContent)
{
    /*检测指针地址*/
    if(NULL == paCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paCog) = NULL;
    }

    /*申请轮齿内存*/
    Cog* pCog = calloc(0x01, sizeof(Cog));
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿结构*/
    {
        /*长度限制条件*/
        while(sizeof(pCog->m_szContent) > pCog->m_uiLength)
        {
            /*获取轮齿内容长度包含\0*/
            ++(pCog->m_uiLength);

            /*检测\0*/
            if((NULL == szContent) || (0x00 == (*(szContent++))))
            {
                break;
            }
        }

        /*复制轮齿内容*/
        if(0x01 < pCog->m_uiLength)
        {
            strncpy_s(pCog->m_szContent, pCog->m_uiLength
                      , (szContent - pCog->m_uiLength), (pCog->m_uiLength - 0x01));
        }

        /*轮齿标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidCog, (&usIdentity));
        {
            pCog->m_usIdentity = usIdentity;
        }

        /*轮齿无效性*/
        pCog->m_ucIsNullity = APP_STATE_FALSE;

    }

    /*定向指针地址*/
    {
        (*paCog) = pCog;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 深度克隆轮齿结构
 * @param[in,out] paCog 轮齿结构指针地址
 * @param[in]     pSrcCog 源轮齿结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DeleteCog删除
*/
int CloneCog(Cog** paCog
             , const Cog* pSrcCog)
{
    /*检测指针地址*/
    if(NULL == paCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*空向指针地址*/
    {
        (*paCog) = NULL;
    }

    /*检测指针*/
    if(NULL == pSrcCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请轮齿内存*/
    Cog* pCog = calloc(0x01, sizeof(Cog));
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿结构*/
    {
        /*复制源轮齿内容*/
        if(0x00 != memcpy_s(pCog, sizeof(Cog), pSrcCog, sizeof(Cog)))
        {
            /*清理轮齿内存*/
            DeleteCog(&pCog);

            /*复制失败*/
            return APP_FLAG_FAILURE;
        }

        /*轮齿标识*/
        unsigned short usIdentity = 0x00;
        AutoIncrementIdentity(kaidCog, (&usIdentity));
        {
            pCog->m_usIdentity = usIdentity;
        }

    }

    /*定向指针地址*/
    {
        (*paCog) = pCog;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 更新轮齿内容
 * @param[in,out] pCog 轮齿结构指针
 * @param[in]     szUpdate 轮齿更新内容
 * @return 标识码
*/
int UpdateCog(Cog* pCog
              , const char* szUpdate)
{
    /*检测指针地址*/
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*重置轮齿内容*/
    while((0x00 < pCog->m_uiLength) && (sizeof(pCog->m_szContent) > pCog->m_uiLength))
    {
        pCog->m_szContent[--(pCog->m_uiLength)] = 0x00;
    }

    /*长度限制条件*/
    while(sizeof(pCog->m_szContent) > pCog->m_uiLength)
    {
        /*获取轮齿内容长度包含\0*/
        ++(pCog->m_uiLength);

        /*检测\0*/
        if((NULL == szUpdate) || (0x00 == (*(szUpdate++))))
        {
            break;
        }
    }

    /*复制轮齿内容*/
    if(0x01 < pCog->m_uiLength)
    {
        strncpy_s(pCog->m_szContent, pCog->m_uiLength, (szUpdate - pCog->m_uiLength), (pCog->m_uiLength - 0x01));
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 变更轮齿结构无效性
 * @param[in,out] pCog 轮齿结构指针
 * @param[in]     ucIsNullity 轮齿结构是否无效
 * @return 标识码
 * @footnote APP_STATE_*为有效输入值
*/
int NullifyCog(Cog* pCog
               , unsigned char ucIsNullity)
{
    /*检测指针地址*/
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*赋值轮齿结构*/
    {
        /*轮齿无效性*/
        pCog->m_ucIsNullity = ucIsNullity;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 删除轮齿结构
 * @param[in,out] paCog 轮齿结构指针地址
 * @return 标识码
*/
int DeleteCog(Cog** paCog)
{
    /*检测地址指针*/
    if(NULL == paCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测轮齿结构指针*/
    if(NULL == (*paCog))
    {
        return APP_FLAG_SUCCESS;
    }

    /*释放内存*/
    free((*paCog));
    {
        (*paCog) = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

