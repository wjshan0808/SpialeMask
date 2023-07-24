/*#pragma once*/
#ifndef _C_COG_H_
#define _C_COG_H_


#include "../SpialeMask.h"


/*!
 * 轮齿结构
*/
typedef struct
{
    size_t m_uiLength;                          /*内容长度包含\0*/
    char m_szContent[SM_SIZE_COG_CONTENT];      /*内容*/
} __attribute__((packed)) Cog;


/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮齿结构
     * @param[in] paCog 轮齿结构指针地址
     * @param[in] szContent 内容
     * @return 标识码
     * @remark 不使用时调用DelCog删除
    */
    SPIALEMASK_EXPORT int NewCog(Cog** paCog
                                 , const char* szContent);

    /*!
     * 删除轮齿结构
     * @param[in] pCog 轮齿结构指针
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DelCog(Cog* pCog);


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_COG_H_ */

