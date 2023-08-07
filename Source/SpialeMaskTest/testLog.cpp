
#include "SpialeMask.h"


#include <stdio.h>
#include <stdlib.h>

void testLogArchiverOuter(const LogContent* p)
{
    if(NULL == p)
    {
        return;
    }

    printf("L:%i, S:%lu, N:%lu, R:%s, C:%s.\r\n"
           , p->m_ucLevel
           , p->m_stTime.tv_sec
           , p->m_stTime.tv_nsec
           , p->m_szSource
           , p->m_szContent
           );

    if(0x00 != p->m_uiDataSize)
    {
        unsigned int ui = DataDumpTable_s(nullptr, p->m_szData, p->m_uiDataSize, 0x10, 0x01, 0x01);
        char* sz = (char*)calloc(ui, sizeof(char));
        DataDumpTable_s(sz, p->m_szData, p->m_uiDataSize, 0x10, 0x01, 0x01);
        printf("%s", sz);
        free(sz);
    }

}
void testLog()
{
    {
        LogRegist(LogArchiveExample);


        LOG_DEBUG("");
        LOG_INFO("%d + %d = %d.", 1, 2, 1+2);
        LOG_ERROR("Error:%s", "error.");

        const char* szEmpty = {};
        unsigned int uiEmptySize = 0x00;
        LOG_HEX("", &szEmpty, uiEmptySize);

        const char szOne[0x02] = { 0x00, 0x31 };
        unsigned int uiOne = 0x02;
        LOG_HEX("sizeof(szOne) = %zu.", &szOne, uiOne, sizeof(szOne)/sizeof(szOne[0]));

        char* szOne2 = (char*)calloc(0x01, sizeof(char));
        unsigned int uiOne2 = 0x01;
        LOG_HEX("sizeof(*szOne) = %zu.", szOne2, uiOne2, sizeof(*szOne2)/sizeof(szOne2[0]));
        free(szOne2);

        char* szOne3 = (char*)calloc(0xff5, sizeof(char));
        unsigned int uiOne3 = 0xff5;
        LOG_HEX("sizeof(&szOne) = %zu.", szOne3, uiOne3, sizeof(&szOne3)/sizeof(szOne3[0]));
        free(szOne3);


        LogRegist(testLogArchiverOuter);

        LOG_WARN("Warn:%s.", "warn");
        LOG_FATAL("Fatal:%p", NULL);

        const char szSixteen[16] =
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        unsigned int uiSixteen = 0x10;
        LOG_HEX("", szSixteen, uiSixteen);

        //const char szSeventeen[] =
        //{
        //    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        //    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        //};
        char* szSeventeen = (char*)calloc(0xff5, sizeof(char));
        unsigned int uiSeventeen = 0xff5;
        LOG_HEX("sizeof(szSeventeen) = %zu.", szSeventeen, uiSeventeen, sizeof(*szSeventeen)/sizeof(szSeventeen[0]));
        free(szSeventeen);

    }
    LogDestory();

}

