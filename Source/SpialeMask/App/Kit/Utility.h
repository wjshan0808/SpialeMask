/*#pragma once*/
#ifndef _C_UTILITY_H_
#define _C_UTILITY_H_


#include "../AppDefines.h"


/*!
 * 数据转储定义
*/
#define KIT_DDT_ASCII_DOT       (0x2E)                      /*ASCII码'.'*/
#define KIT_DDT_ASCII_BEGIN     (0x02 << 0x04)              /*ASCII码起始范围*/
#define KIT_DDT_ASCII_END       ((0x02 << 0x06) - 0x01)     /*ASCII码结束范围*/
#define KIT_DDT_ASCII(uc)       (((KIT_DDT_ASCII_BEGIN <= uc) && (uc < KIT_DDT_ASCII_END)) ? uc : KIT_DDT_ASCII_DOT)


/*
 * begin extern "C"
*/
APP_EXTERN_C_BEGIN


    /*!
     * 数据转储表
     * @param[in,out] szDumpTable 数据转储表空间
     * @param[in]     szData 转储数据
     * @param[in]     uiDataSize 转储数据大小
     * @param[in]     ucDataColumns 设置转储数据列数
     * @param[in]     ucASCII 是否转储数据ASCII码
     * @param[in]     ucAddress 是否转储数据地址
     * @return 返回转储表空间大小
    */
    APP_EXPORT unsigned int DataDumpTable(char* szDumpTable
                                          , const char* szData
                                          , unsigned int uiDataSize
                                          , unsigned char ucDataColumns
                                          , unsigned char ucASCII
                                          , unsigned char ucAddress);

    /*!
     * 数据转储表
     * @param[in,out] szDumpTable 数据转储表空间
     * @param[in]     szData 转储数据
     * @param[in]     uiDataSize 转储数据大小
     * @param[in]     ucDataColumns 设置转储数据列数
     * @param[in]     ucASCII 是否转储数据ASCII码
     * @param[in]     ucAddress 是否转储数据地址
     * @return 返回转储表空间大小
    */
    APP_EXPORT unsigned int DataDumpTable_s(char* szDumpTable
                                            , const char* szData
                                            , unsigned int uiDataSize
                                            , unsigned char ucDataColumns
                                            , unsigned char ucASCII
                                            , unsigned char ucAddress);


/*
 * end extern "C"
*/
APP_EXTERN_C_END


#endif /* !_C_UTILITY_H_ */

