#include "Log.h"
#include "../Kit/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <sys/time.h>


/*!
 * 全局静态日志归档函数指针
*/
static LogArchiver gs_pfnLogArchiver = NULL;


/*!
 * 日志注册
 * @param[in] pfnLogArchiver 日志归档函数指针
 * @return 返回-1失败, 否则成功
*/
int LogRegist(LogArchiver pfnLogArchiver)
{
    /*注册日志归档函数*/
    gs_pfnLogArchiver = pfnLogArchiver;

    /*返回成功标识*/
    return APP_FLAG_SUCCESS;
}

/*!
 * 日志销毁
 * @return 返回-1失败, 否则成功
*/
int LogDestory()
{
    /*反注册日志归档函数*/
    gs_pfnLogArchiver = NULL;

    /*返回成功标识*/
    return APP_FLAG_SUCCESS;
}


/*!
 * 记录日志
 * @param[in] ucLevel 日志等级
 * @param[in] szSource 记录日志源
 * @param[in] szContent 日志内容
 * @param[in] ... 日志内容参数
 * @return
*/
void Logging(unsigned char ucLevel, const char* szSource, const char* szContent, ...)
{
    /*空检测*/
    if(NULL == szContent)
    {
        /*输出检测*/
        fprintf(stderr, "Source:%s, Level:%x no content.\n", szSource, ucLevel);

        /*返回*/
        return;
    }

    /*声明并初始化日志内容实体*/
    LogContent stLogContent =
    {
        {
            0x00,
            0x00
        },
        szSource,
        NULL,
        NULL,
        0x00,
        ucLevel
    };

    /*获取日志时间*/
    struct timespec stTime;
    clock_gettime(CLOCK_REALTIME, &stTime);
    stLogContent.m_stTime = stTime;

    /*开始获取日志参数列表*/
    va_list args;
    va_start(args, szContent);

    /*数据日志类型*/
    if(LOG_LEVEL_HEX == ucLevel)
    {
        /*获取日志数据参数*/
        stLogContent.m_szData = va_arg(args, const char*);
        stLogContent.m_uiDataSize = va_arg(args, unsigned int);
    }

    /*计算日志内容长度    '\0'*/
    int iContentSize = 0x01;
    {
        /*开始获取日志内容参数列表*/
        va_list argsContent;
        va_copy(argsContent, args);
        {
            iContentSize += vsnprintf(NULL, 0x00, szContent, argsContent);
        }
        /*结束获取日志内容参数列表*/
        va_end(argsContent);
    }

    /*分配资源并获取日志内容*/
    char* szContentData = calloc(iContentSize, sizeof(char));
    if(NULL != szContentData)
    {
        vsprintf_s(szContentData, iContentSize, szContent, args);
        stLogContent.m_szContent = szContentData;
    }

    /*结束获取日志内容参数列表*/
    va_end(args);

    /*将日志归档*/
    if(NULL != gs_pfnLogArchiver)
    {
        (*gs_pfnLogArchiver)(&stLogContent);
    }

    /*释放资源*/
    if(NULL != szContentData)
    {
        free(szContentData);
    }

    /*返回*/
    return;
}


/*!
 * 日志归档函数范例
 * @param[in] pLogContent 日志内容
 * @return
*/
void LogArchiveExample(const LogContent* pLogContent)
{
    /*空检测*/
    if(NULL == pLogContent)
    {
        /*输出检测*/
        fprintf(stderr, "Source:%s, No log-content.\n", __func__);

        /*返回*/
        return;
    }

    /*时间内容大小                       [0000-00-00 00.00.00.000]*/
    unsigned int uiTimestampDataSize = (0x01 + 0x04 + 0x01 + 0x02 + 0x01 + 0x02 + 0x01 + 0x02 + 0x01 + 0x02 + 0x01 + 0x02 + 0x01 + 0x03 + 0x01);

    /*等级内容大小                   [ LEVEL]*/
    unsigned int uiLevelDataSize = (0x01 + 0x06 + 0x01);

    /*源内容大小                      [?]*/
    unsigned int uiSourceDataSize = ((NULL == pLogContent->m_szSource) ? (0x00) : (0x01 + strlen(pLogContent->m_szSource) + 0x01));

    /*内容大小                        ' '*/
    unsigned int uiContentDataSize = ((NULL == pLogContent->m_szContent) ? (0x00) : (0x01 + strlen(pLogContent->m_szContent)));

    /*数据内容大小*/
    unsigned int uiDataDataSize = DataDumpTable(NULL, pLogContent->m_szData, pLogContent->m_uiDataSize, 0x10, 0x00, 0x00);

    /*计算日志内容数据大小                                                                                                 '\r\n'                  '\0'*/
    unsigned int uiLogContentDataSize = (uiTimestampDataSize + uiLevelDataSize + uiSourceDataSize + uiContentDataSize + 0x02 + uiDataDataSize + 0x01);

    /*分配日志内容数据资源*/
    char* szLogContentData = calloc(uiLogContentDataSize, sizeof(char));
    if(NULL != szLogContentData)
    {
        /*日志内容数据资源游离指针*/
        char* szLogContentDataMovable = szLogContentData;

        /*获取日志时间戳*/
        time_t uiTimeSeconds = pLogContent->m_stTime.tv_sec;
        struct tm* pTimestamp = localtime(&uiTimeSeconds);

        /*归档日志时间内容*/
        if(NULL != pTimestamp)
        {
            sprintf_s(szLogContentDataMovable, uiTimestampDataSize + 0x01, "[%04d-%02d-%02d %02d:%02d:%02d.%03ld]"
                    , pTimestamp->tm_year + 1900
                    , pTimestamp->tm_mon + 0x01
                    , pTimestamp->tm_mday
                    , pTimestamp->tm_hour
                    , pTimestamp->tm_min
                    , pTimestamp->tm_sec
                    , (pLogContent->m_stTime.tv_nsec / 1000000));

            /*移动资源指针*/
            szLogContentDataMovable += uiTimestampDataSize;
        }

        /*归档日志等级内容*/
        {
            const char* arrLevels[0x07] =
            {
                " FATAL",
                " ERROR",
                "  WARN",
                "NOTICE",
                "  INFO",
                " DEBUG",
                "   HEX"
            };
            sprintf_s(szLogContentDataMovable, uiLevelDataSize + 0x01, "[%s]"
                      , arrLevels[((unsigned char)log2(pLogContent->m_ucLevel) % 0x07)]);

            /*移动资源指针*/
            szLogContentDataMovable += uiLevelDataSize;
        }

        /*归档日志源内容*/
        if(NULL != pLogContent->m_szSource)
        {
            sprintf_s(szLogContentDataMovable, uiSourceDataSize + 0x01, "[%s]"
                      , pLogContent->m_szSource);

            /*移动资源指针*/
            szLogContentDataMovable += uiSourceDataSize;
        }

        /*归档日志内容*/
        if(NULL != pLogContent->m_szContent)
        {
            sprintf_s(szLogContentDataMovable, uiContentDataSize + 0x01, " %s"
                      , pLogContent->m_szContent);

            /*移动资源指针*/
            szLogContentDataMovable += uiContentDataSize;
        }

        /*归档日志换行符*/
        {
            sprintf_s(szLogContentDataMovable, 0x02 + 0x01, "%s"
                      , "\r\n");

            /*移动资源指针*/
            szLogContentDataMovable += 0x02;
        }

        /*归档日志数据内容*/
        if((NULL != pLogContent->m_szData) && (0x00 != pLogContent->m_uiDataSize))
        {
            DataDumpTable(szLogContentDataMovable, pLogContent->m_szData, pLogContent->m_uiDataSize, 0x10, 0x00, 0x00);
        }
    }

    /*此范例输出归档日志*/
    if(NULL != szLogContentData)
    {
        fprintf(stdout, "%s", szLogContentData);
    }

    /*释放日志内容数据资源*/
    if(NULL != szLogContentData)
    {
        free(szLogContentData);
    }

    /*返回*/
    return;
}

