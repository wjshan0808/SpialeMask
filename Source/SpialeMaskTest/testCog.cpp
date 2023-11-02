
#include "testSpialeMask.cpp"


void testCogAPI()
{
    LogRegist(LogArchiveExample);


    int iCode = 0x00;
    Cog* pCog = NULL;
    Cog* pCloneCog = NULL;
    char* szContent = NULL;


    LOG_INFO("\n=== P1 ===");
    {

        LOG_INFO("Test API NewCog(NULL) ...");
        szContent = NULL;
        iCode = NewCog(&pCog, szContent);
        printCog(pCog);

        LOG_INFO("Test API CloneCog(NULL) ...");
        iCode = CloneCog(&pCloneCog, pCog);
        printCog(pCloneCog);


        {
            Cog* pCloneCog1 = NULL;
            Cog* pCloneCog2 = NULL;
            Cog* pCloneCog3 = NULL;
            iCode = CloneCog(&pCloneCog1, pCloneCog);
            iCode = CloneCog(&pCloneCog2, pCloneCog);
            iCode = CloneCog(&pCloneCog3, pCloneCog);

            LOG_INFO("Test API UpdateCog(NULL -> NULL) ...");
            iCode = UpdateCog(pCog, NULL);
            printCog(pCog);

            LOG_INFO("Test API UpdateCog(NULL -> 1) ...");
            iCode = UpdateCog(pCloneCog, "1");
            printCog(pCloneCog);

            LOG_INFO("Test API UpdateCog(NULL -> 1234567) ...");
            iCode = UpdateCog(pCloneCog1, "1234567");
            printCog(pCloneCog1);

            LOG_INFO("Test API UpdateCog(NULL -> 12345678) ...");
            iCode = UpdateCog(pCloneCog2, "12345678");
            printCog(pCloneCog2);

            LOG_INFO("Test API UpdateCog(NULL -> 123456789) ...");
            iCode = UpdateCog(pCloneCog3, "123456789");
            printCog(pCloneCog3);

            {
                iCode = DeleteCog(&pCloneCog1);
                printCog(pCloneCog1);
                iCode = DeleteCog(&pCloneCog2);
                printCog(pCloneCog2);
                iCode = DeleteCog(&pCloneCog3);
                printCog(pCloneCog3);
            }
        }
        {
            iCode = DeleteCog(&pCog);
            printCog(pCog);
            iCode = DeleteCog(&pCloneCog);
            printCog(pCloneCog);
        }
    }


    LOG_INFO("\n=== P2 ===");
    {

        LOG_INFO("Test API NewCog(1) ...");
        szContent = "1";
        iCode = NewCog(&pCog, szContent);
        printCog(pCog);

        LOG_INFO("Test API CloneCog(1) ...");
        iCode = CloneCog(&pCloneCog, pCog);
        printCog(pCloneCog);


        {
            Cog* pCloneCog1 = NULL;
            Cog* pCloneCog2 = NULL;
            Cog* pCloneCog3 = NULL;
            iCode = CloneCog(&pCloneCog1, pCloneCog);
            iCode = CloneCog(&pCloneCog2, pCloneCog);
            iCode = CloneCog(&pCloneCog3, pCloneCog);

            LOG_INFO("Test API UpdateCog(1 -> NULL) ...");
            iCode = UpdateCog(pCog, NULL);
            printCog(pCog);

            LOG_INFO("Test API UpdateCog(1 -> 2) ...");
            iCode = UpdateCog(pCloneCog, "2");
            printCog(pCloneCog);

            LOG_INFO("Test API UpdateCog(1 -> 1234567) ...");
            iCode = UpdateCog(pCloneCog1, "1234567");
            printCog(pCloneCog1);

            LOG_INFO("Test API UpdateCog(1 -> 12345678) ...");
            iCode = UpdateCog(pCloneCog2, "12345678");
            printCog(pCloneCog2);

            LOG_INFO("Test API UpdateCog(1 -> 123456789) ...");
            iCode = UpdateCog(pCloneCog3, "123456789");
            printCog(pCloneCog3);

            {
                iCode = DeleteCog(&pCloneCog1);
                printCog(pCloneCog1);
                iCode = DeleteCog(&pCloneCog2);
                printCog(pCloneCog2);
                iCode = DeleteCog(&pCloneCog3);
                printCog(pCloneCog3);
            }
        }
        {
            iCode = DeleteCog(&pCog);
            printCog(pCog);
            iCode = DeleteCog(&pCloneCog);
            printCog(pCloneCog);
        }
    }


    LOG_INFO("\n=== P3 ===");
    {

        LOG_INFO("Test API NewCog(1234567) ...");
        szContent = "1234567";
        iCode = NewCog(&pCog, szContent);
        printCog(pCog);

        LOG_INFO("Test API CloneCog(1234567) ...");
        iCode = CloneCog(&pCloneCog, pCog);
        printCog(pCloneCog);


        {
            Cog* pCloneCog1 = NULL;
            Cog* pCloneCog2 = NULL;
            Cog* pCloneCog3 = NULL;
            iCode = CloneCog(&pCloneCog1, pCloneCog);
            iCode = CloneCog(&pCloneCog2, pCloneCog);
            iCode = CloneCog(&pCloneCog3, pCloneCog);

            LOG_INFO("Test API UpdateCog(1234567 -> NULL) ...");
            iCode = UpdateCog(pCog, NULL);
            printCog(pCog);

            LOG_INFO("Test API UpdateCog(1234567 -> 3) ...");
            iCode = UpdateCog(pCloneCog, "3");
            printCog(pCloneCog);

            LOG_INFO("Test API UpdateCog(1234567 -> 1234567) ...");
            iCode = UpdateCog(pCloneCog1, "1234567");
            printCog(pCloneCog1);

            LOG_INFO("Test API UpdateCog(1234567 -> 12345678) ...");
            iCode = UpdateCog(pCloneCog2, "12345678");
            printCog(pCloneCog2);

            LOG_INFO("Test API UpdateCog(1234567 -> 123456789) ...");
            iCode = UpdateCog(pCloneCog3, "123456789");
            printCog(pCloneCog3);

            {
                iCode = DeleteCog(&pCloneCog1);
                printCog(pCloneCog1);
                iCode = DeleteCog(&pCloneCog2);
                printCog(pCloneCog2);
                iCode = DeleteCog(&pCloneCog3);
                printCog(pCloneCog3);
            }
        }
        {
            iCode = DeleteCog(&pCog);
            printCog(pCog);
            iCode = DeleteCog(&pCloneCog);
            printCog(pCloneCog);
        }
    }


    LOG_INFO("\n=== P4 ===");
    {

        LOG_INFO("Test API NewCog(12345678) ...");
        szContent = "12345678";
        iCode = NewCog(&pCog, szContent);
        printCog(pCog);

        LOG_INFO("Test API CloneCog(12345678) ...");
        iCode = CloneCog(&pCloneCog, pCog);
        printCog(pCloneCog);


        {
            Cog* pCloneCog1 = NULL;
            Cog* pCloneCog2 = NULL;
            Cog* pCloneCog3 = NULL;
            iCode = CloneCog(&pCloneCog1, pCloneCog);
            iCode = CloneCog(&pCloneCog2, pCloneCog);
            iCode = CloneCog(&pCloneCog3, pCloneCog);

            LOG_INFO("Test API UpdateCog(12345678 -> NULL) ...");
            iCode = UpdateCog(pCog, NULL);
            printCog(pCog);

            LOG_INFO("Test API UpdateCog(12345678 -> 4) ...");
            iCode = UpdateCog(pCloneCog, "4");
            printCog(pCloneCog);

            LOG_INFO("Test API UpdateCog(12345678 -> 1234567) ...");
            iCode = UpdateCog(pCloneCog1, "1234567");
            printCog(pCloneCog1);

            LOG_INFO("Test API UpdateCog(12345678 -> 12345678) ...");
            iCode = UpdateCog(pCloneCog2, "12345678");
            printCog(pCloneCog2);

            LOG_INFO("Test API UpdateCog(12345678 -> 123456789) ...");
            iCode = UpdateCog(pCloneCog3, "123456789");
            printCog(pCloneCog3);

            {
                iCode = DeleteCog(&pCloneCog1);
                printCog(pCloneCog1);
                iCode = DeleteCog(&pCloneCog2);
                printCog(pCloneCog2);
                iCode = DeleteCog(&pCloneCog3);
                printCog(pCloneCog3);
            }
        }
        {
            iCode = DeleteCog(&pCog);
            printCog(pCog);
            iCode = DeleteCog(&pCloneCog);
            printCog(pCloneCog);
        }
    }


    LOG_INFO("\n=== P5 ===");
    {
        LOG_INFO("Test API NewCog(123456789) ...");
        szContent = "123456789";
        iCode = NewCog(&pCog, szContent);
        printCog(pCog);

        LOG_INFO("Test API CloneCog(123456789) ...");
        iCode = CloneCog(&pCloneCog, pCog);
        printCog(pCloneCog);


        {
            Cog* pCloneCog1 = NULL;
            Cog* pCloneCog2 = NULL;
            Cog* pCloneCog3 = NULL;
            iCode = CloneCog(&pCloneCog1, pCloneCog);
            iCode = CloneCog(&pCloneCog2, pCloneCog);
            iCode = CloneCog(&pCloneCog3, pCloneCog);

            LOG_INFO("Test API UpdateCog(123456789 -> NULL) ...");
            iCode = UpdateCog(pCog, NULL);
            printCog(pCog);

            LOG_INFO("Test API UpdateCog(123456789 -> 5) ...");
            iCode = UpdateCog(pCloneCog, "5");
            printCog(pCloneCog);

            LOG_INFO("Test API UpdateCog(123456789 -> 1234567) ...");
            iCode = UpdateCog(pCloneCog1, "1234567");
            printCog(pCloneCog1);

            LOG_INFO("Test API UpdateCog(123456789 -> 12345678) ...");
            iCode = UpdateCog(pCloneCog2, "12345678");
            printCog(pCloneCog2);

            LOG_INFO("Test API UpdateCog(123456789 -> 123456789) ...");
            iCode = UpdateCog(pCloneCog3, "123456789");
            printCog(pCloneCog3);

            {
                iCode = DeleteCog(&pCloneCog1);
                printCog(pCloneCog1);
                iCode = DeleteCog(&pCloneCog2);
                printCog(pCloneCog2);
                iCode = DeleteCog(&pCloneCog3);
                printCog(pCloneCog3);
            }
        }
    }


    LOG_INFO("\n=== P6 ===");
    {

        LOG_INFO("Test API NullifyCog(%d) ...", APP_STATE_TRUE);
        iCode = NullifyCog(pCloneCog, APP_STATE_TRUE);
        printCog(pCloneCog);


        LOG_INFO("Test API DeleteCog() ...");

        {
            iCode = DeleteCog(&pCog);
            printCog(pCog);
            iCode = DeleteCog(&pCloneCog);
            printCog(pCloneCog);
        }
    }



    LogDestory();
}
