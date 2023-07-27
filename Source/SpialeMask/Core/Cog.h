/*#pragma once*/
#ifndef _C_COG_H_
#define _C_COG_H_


#include "../SpialeMask.h"


/*!
 * 轮齿结构
*/
typedef struct
{
    size_t m_uiLength;                          /*轮齿内容长度包含\0*/
    char m_szContent[SM_SIZE_COG_CONTENT];      /*轮齿内容*/
    unsigned char m_ucIsNullity;                /*轮齿无效性*/
    unsigned short m_usIdentity;                /*轮齿标识*/

} __attribute__((packed)) Cog;


/* begin extern "C" */
APP_EXTERN_C_BEGIN


    /*!
     * 新建轮齿结构
     * @param[in,out] paCog 轮齿结构指针地址
     * @param[in]     szContent 轮齿内容
     * @return 标识码
     * @remark 不使用时请调用DeleteCog删除
    */
    SPIALEMASK_EXPORT int NewCog(Cog** paCog
                                 , const char* szContent);


    /*!
     * 深度克隆轮齿结构
     * @param[in,out] paCog 轮齿结构指针地址
     * @param[in]     pSrcCog 源轮齿结构常量指针
     * @return 标识码
     * @remark 不使用时请调用DeleteCog删除
    */
    SPIALEMASK_EXPORT int CloneCog(Cog** paCog
                                   , const Cog* pSrcCog);


    /*!
     * 更新轮齿内容
     * @param[in,out] pCog 轮齿结构指针
     * @param[in]     szUpdate 轮齿更新内容
     * @return 标识码
    */
    SPIALEMASK_EXPORT int UpdateCog(Cog* pCog
                                    , const char* szUpdate);


    /*!
     * 变更轮齿结构无效性
     * @param[in,out] pCog 轮齿结构指针
     * @param[in]     ucIsNullity 轮齿结构是否无效
     * @return 标识码
     * @footnote APP_STATE_*为有效输入值
    */
    SPIALEMASK_EXPORT int NullifyCog(Cog* pCog
                                     , unsigned char ucIsNullity);


    /*!
     * 删除轮齿结构
     * @param[in,out] paCog 轮齿结构指针地址
     * @return 标识码
    */
    SPIALEMASK_EXPORT int DeleteCog(Cog** paCog);


/* end extern "C" */
APP_EXTERN_C_END


#endif /* !_C_COG_H_ */

