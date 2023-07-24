#include "Cog.h"


/*!
 * 新建轮齿结构
 * @param[in] paCog 轮齿结构指针地址
 * @param[in] szContent 内容
 * @return 标识码
 * @remark 不使用时调用DelCog删除
*/
int NewCog(Cog** paCog
           , const char* szContent)
{
    /*空向指针地址*/
    (*paCog) = NULL;

    /*检测指针地址*/
    if(NULL == paCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*申请齿轮内存*/
    Cog *pCog = calloc(0x01, sizeof(Cog));
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*获取齿轮内容长度包含\0*/
    do
    {
        /*默认长度*/
        ++(pCog->m_uiLength);

        /*检测\0*/
        if((NULL == szContent) || (0x00 == (*(++szContent))))
        {
            break;
        }

        /*长度限制条件*/
    } while(SM_SIZE_COG_CONTENT > pCog->m_uiLength);

    /*复制齿轮内容*/
    if(0x01 < pCog->m_uiLength)
    {
        strcpy_s(pCog->m_szContent, pCog->m_uiLength, szContent);
    }

    /*定向指针地址*/
    (*paCog) = pCog;

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

/*!
 * 删除轮齿结构
 * @param[in] pCog 轮齿结构指针
 * @return 标识码
*/
int DelCog(Cog* pCog)
{
    /*检测指针地址*/
    if(NULL == pCog)
    {
        return APP_FLAG_FAILURE;
    }

    /*释放内存*/
    free(pCog);
    {
        pCog = NULL;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

