/*#pragma once*/
#ifndef _C_LOG_H_
#define _C_LOG_H_


#include "../AppDefines.h"
#include <time.h>

/*
 * 日志等级定义
*/
#define LOG_LEVEL_FATAL         (0x01)      /*日志 致命 等级*/
#define LOG_LEVEL_ERROR         (0x02)      /*日志 错误 等级*/
#define LOG_LEVEL_WARN          (0x04)      /*日志 警告 等级*/
#define LOG_LEVEL_NOTICE        (0x08)      /*日志 注意 等级*/
#define LOG_LEVEL_INFO          (0x10)      /*日志 信息 等级*/
#define LOG_LEVEL_DEBUG         (0x20)      /*日志 调试 等级*/
#define LOG_LEVEL_HEX           (0x40)      /*日志 Hex 等级*/
#define LOG_LEVEL_MASK          (0x3F)      /*日志掩码(except hex)*/


/*
 * 日志内容实体
*/
typedef struct
{
    struct timespec m_stTime;       /*日志时间*/
    const char* m_szSource;         /*日志源*/
    const char* m_szContent;        /*日志内容*/
    const char* m_szData;           /*日志数据*/
    unsigned int m_uiDataSize;      /*日志数据大小*/
    unsigned char m_ucLevel;        /*日志等级*/
} __attribute__((packed/*, aligned(1)*/)) LogContent;

/*
 * 日志归档函数声明
 * @param[in] pLogContent 日志内容
 * @return
*/
typedef void(* LogArchiver)(const LogContent* pLogContent);


/*
 * begin extern "C"
*/
APP_EXTERN_C_BEGIN


    /*
     * 日志初始化
     * @param[in] pfnLogArchiver 日志归档函数指针
     * @return  返回-1失败, 否则成功
    */
    APP_EXPORT int LogInit(LogArchiver pfnLogArchiver);

    /*
     * 日志销毁
     * @return  返回-1失败, 否则成功
    */
    APP_EXPORT int LogDestory();


    /*
     * 日志归档函数范例
     * @param[in] pLogContent 日志内容
     * @return
    */
    APP_EXPORT void LogArchiveExample(const LogContent* pLogContent);



    /*
     * 记录日志
     * @param[in] ucLevel 日志等级
     * @param[in] szSource 记录日志源
     * @param[in] szContent 日志内容
     * @param[in] ... 日志内容参数
     * @return
    */
    APP_EXPORT void Logging(unsigned char ucLevel, const char* szSource, const char* szContent, ...);


/*
 * end extern "C"
*/
APP_EXTERN_C_END


/*
 * 等级日志记录宏
*/
#define LOG(L, F, ...)          Logging(L, __FUNCTION__, F, ##__VA_ARGS__)      /*记录日志*/
#define LOG_HEX(F, ...)         LOG(LOG_LEVEL_HEX,    F, ##__VA_ARGS__)         /*记录Hex日志*/
#define LOG_DEBUG(F, ...)       LOG(LOG_LEVEL_DEBUG,  F, ##__VA_ARGS__)         /*记录调试日志*/
#define LOG_INFO(F, ...)        LOG(LOG_LEVEL_INFO,   F, ##__VA_ARGS__)         /*记录信息日志*/
#define LOG_NOTICE(F, ...)      LOG(LOG_LEVEL_NOTICE, F, ##__VA_ARGS__)         /*记录注意日志*/
#define LOG_WARN(F, ...)        LOG(LOG_LEVEL_WARN,   F, ##__VA_ARGS__)         /*记录警告日志*/
#define LOG_ERROR(F, ...)       LOG(LOG_LEVEL_ERROR,  F, ##__VA_ARGS__)         /*记录错误日志*/
#define LOG_FATAL(F, ...)       LOG(LOG_LEVEL_FATAL,  F, ##__VA_ARGS__)         /*记录致命日志*/


#endif /* !_C_LOG_H_ */

