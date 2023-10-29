#include "Spiale.h"



/*!
 * 恢复轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
*/
int RestoreSpiale(Spiale** paSpiale)
{
    /*检测指针*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 保存轮轴结构
 * @param[in,out] paSpiale 轮轴结构指针地址
 * @param[in]     pSrcSpiale 源轮轴结构常量指针
 * @return 标识码
 * @remark 不使用时请调用DeleteSpiale删除
*/
int SaveSpiale(Spiale** paSpiale
                , const Spiale* pSrcSpiale)
{
    /*检测指针*/
    if(NULL == paSpiale)
    {
        return APP_FLAG_FAILURE;
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

