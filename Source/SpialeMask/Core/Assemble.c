#include "Spiale.h"



/*!
 * 恢复轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @param[in] szFile 文件路径
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
*/
int RestoreSpiale(Spiale** paSpiale
                  , const char* szFile)
{
    /*检测指针地址*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*检测指针*/
    if(NULL == szFile)
    {
        return APP_FLAG_FAILURE;
    }

    /*加载指定的文件, 解析恢复轮轴结构*/
    {
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 保存轮轴结构
 * @param[in] szFile 文件路径
 * @param[in] pSpiale 轮轴结构指针
 * @return 标识码
*/
int SaveSpiale(const char* szFile
               , const Spiale* pSpiale)
{
    /*检测指针*/
    if(NULL == szFile)
    {
        return APP_FLAG_FAILURE;
    }
    if(NULL == pSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*保存轮轴结构到指定的文件*/
    {
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

