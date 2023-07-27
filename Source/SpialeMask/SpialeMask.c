#include "SpialeMask.h"


/*!
 * 自增标识值
*/
volatile static unsigned int gs_arrValueAutoIncrementIdentity[kaidNone] = { 0x00 };



/*!
 * 获取自增标识键对应的自增标识值
 * @param[in]     enKaid 自增标识键
 * @param[in,out] pValue 自增标识值指针
 * @return 标识码
 * @footnote xxx
*/
int AutoIncrementIdentity(KeyAutoIncrementIdentity enKaid
                          , unsigned short* pValue)
{
    /*检测指针地址*/
    if(NULL == pValue)
    {
        return APP_FLAG_FAILURE;
    }

    /*获取自增标识值*/
    if((kaidNaN >= enKaid) || (enKaid >= kaidNone))
    {
        (*pValue) = 0x00;
    }
    else
    {
        (*pValue) = ++(gs_arrValueAutoIncrementIdentity[enKaid]);
    }

    /*返回成功*/
    return APP_FLAG_SUCCESS;
}

