#include "Utility.h"

#include <stdio.h>


/*
 * 数据转储表
 * @param[in,out] szDumpTable 数据转储表空间
 * @param[in]     szData 转储数据
 * @param[in]     uiDataSize 转储数据大小
 * @param[in]     ucDataColumns 设置转储数据列数
 * @param[in]     ucASCII 是否转储数据ASCII码
 * @param[in]     ucAddress 是否转储数据地址
 * @return  返回转储表空间大小
*/
unsigned int DataDumpTable(char* szDumpTable
                           , const char* szData
                           , unsigned int uiDataSize
                           , unsigned char ucDataColumns
                           , unsigned char ucASCII
                           , unsigned char ucAddress)
{
    /*检测转储表数据列数*/
    if(0x00 == ucDataColumns)
    {
        /*输出检测*/
        fprintf(stderr, "Source:%s, data-column is zero.\n", __func__);

        /*返回失败*/
        return 0x00;
    }

    /*计算转储表数据行数*/
    unsigned int uiDataRows = uiDataSize / ucDataColumns;
    if(0x00 != (uiDataSize % ucDataColumns))
    {
        ++uiDataRows;
    }

    /*计算转储表空间列数                   ((hex  + ' ')   * data-cols)    + ('\r\n')*/
    unsigned short usDumpTableColumns = ((0x02 + 0x01) * ucDataColumns) + (0x02);
    {
        /*若转储表存在地址列时        (0x  + addr + '  ')*/
        if(0x00 != ucAddress)
        {
            usDumpTableColumns += (0x02 + 0x08 + 0x02);
        }

        /*若转储表存在ASCII码列时    (' '  + (ASCII * data-cols))*/
        if(0x00 != ucASCII)
        {
            usDumpTableColumns += (0x01 + (0x01 * ucDataColumns));
        }
    }

    /*计算转储表空间大小               '\0'*/
    unsigned int uiDumpTableSize = (0x01 + (uiDataRows * usDumpTableColumns));

    /*若不存在转储表或不存在数据时*/
    if((NULL == szDumpTable) || (NULL == szData))
    {
        /*返回转储表空间大小*/
        return uiDumpTableSize;
    }

    /*声明数据索引, 数据行起始索引变量*/
    unsigned int uiDataIndex = 0x00, uiDataIndexOfRowStart = 0x00;
    /*声明数据行索引数变量*/
    unsigned char ucDataIndexCountOfRow = (ucDataColumns - 0x01);

    /*开始转储数据为表*/
    for(uiDataIndex = 0x00; uiDataIndex < uiDataSize; ++uiDataIndex)
    {
        /*计数至新的数据行*/
        if(0x00 == (uiDataIndex % ucDataColumns))
        {
            /*若转储数据地址*/
            if(0x00 != ucAddress)
            {
                sprintf_s(szDumpTable, uiDumpTableSize, "%s%s%08X  ", szDumpTable, "0x", (unsigned int)(uiDataIndex + szData));
            }
        }

        /*转储数据值*/
        sprintf_s(szDumpTable, uiDumpTableSize, "%s%02x ", szDumpTable, szData[uiDataIndex]);

        /*计数至新的数据行结尾*/
        if(ucDataIndexCountOfRow == (uiDataIndex % ucDataColumns))
        {
            /*若转储数据ASCII码*/
            if(0x00 != ucASCII)
            {
                /*在数据行结尾插入与ASCII码之间的空格*/
                sprintf_s(szDumpTable, uiDumpTableSize, "%s ", szDumpTable);

                /*计数至该数据行的起始*/
                for(uiDataIndexOfRowStart = (uiDataIndex - ucDataIndexCountOfRow); uiDataIndexOfRowStart <= uiDataIndex; ++uiDataIndexOfRowStart)
                {
                    sprintf_s(szDumpTable, uiDumpTableSize, "%s%c", szDumpTable, KIT_DDT_ASCII(szData[uiDataIndexOfRowStart]));
                }
            }

            /*在数据行结尾插入换行符*/
            sprintf_s(szDumpTable, uiDumpTableSize, "%s\r\n", szDumpTable);
        }
    }

    /*声明数据行数据剩余数变量*/
    unsigned char ucDataCountOfRowLeft = (uiDataIndex % ucDataColumns);
    if(0x00 != ucDataCountOfRowLeft)
    {
        /*用空格填充数据行中的空数据位*/
        for(uiDataIndexOfRowStart = 0x00; uiDataIndexOfRowStart < (unsigned int)(ucDataColumns - ucDataCountOfRowLeft); ++uiDataIndexOfRowStart)
        {
            sprintf_s(szDumpTable, uiDumpTableSize, "%s   ", szDumpTable);
        }

        /*若转储数据ASCII码*/
        if(0x00 != ucASCII)
        {            
            /*在数据行结尾插入与ASCII码之间的空格*/
            sprintf_s(szDumpTable, uiDumpTableSize, "%s ", szDumpTable);

            /*计数至该数据行的起始*/
            for(uiDataIndexOfRowStart = (uiDataIndex - ucDataCountOfRowLeft); uiDataIndexOfRowStart < uiDataIndex; ++uiDataIndexOfRowStart)
            {
                sprintf_s(szDumpTable, uiDumpTableSize, "%s%c", szDumpTable, KIT_DDT_ASCII(szData[uiDataIndexOfRowStart]));
            }
        }

        /*在数据行结尾插入换行符*/
        sprintf_s(szDumpTable, uiDumpTableSize, "%s\r\n", szDumpTable);
    }

    /*返回转储表空间大小*/
    return uiDumpTableSize;
}

