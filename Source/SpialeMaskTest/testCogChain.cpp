
#include "testSpialeMask.cpp"


void testCogChainAPI()
{
    LogRegist(LogArchiveExample);

    int iCode = 0x00;
    size_t uiCount = 0x00;


    LOG_INFO("\n=== P1 ===");

    CogChain* pCogChainA = NULL;
    {
        LOG_INFO("Test API NewCogChain(a) ...");
        iCode = NewCogChain(&pCogChainA, "a");
        printCogChain(pCogChainA);

        iCode = CountCogChain(pCogChainA, &uiCount);
        LOG_INFO("Test API CountCogChain(a = %zu).", uiCount);
    }
    CogChain* pCloneCogChainA = NULL;
    {
        LOG_INFO("Test API CloneCogChain(a) ...");
        iCode = CloneCogChain(&pCloneCogChainA, pCogChainA);
        printCogChain(pCloneCogChainA);

        iCode = CountCogChain(pCloneCogChainA, &uiCount);
        LOG_INFO("Test API CountCogChain(a = %zu).", uiCount);
    }

    CogChain* pCogChainB = NULL;
    CogChain* pCloneCogChainB = NULL;
    {
        iCode = NewCogChain(&pCogChainB, "b");
        iCode = CloneCogChain(&pCloneCogChainB, pCogChainB);
    }

    CogChain* pCogChainC = NULL;
    CogChain* pCloneCogChainC = NULL;
    {
        iCode = NewCogChain(&pCogChainC, "c");
        iCode = CloneCogChain(&pCloneCogChainC, pCogChainC);
    }

    CogChain* pCogChainD = NULL;
    CogChain* pCloneCogChainD = NULL;
    {
        iCode = NewCogChain(&pCogChainD, "d");
        iCode = CloneCogChain(&pCloneCogChainD, pCogChainD);
    }

    CogChain* pCogChainE = NULL;
    CogChain* pCloneCogChainE = NULL;
    {
        iCode = NewCogChain(&pCogChainE, "e");
        iCode = CloneCogChain(&pCloneCogChainE, pCogChainE);
    }

    CogChain* pCogChainF = NULL;
    CogChain* pCloneCogChainF = NULL;
    {
        iCode = NewCogChain(&pCogChainF, "f");
        iCode = CloneCogChain(&pCloneCogChainF, pCogChainF);
    }

    CogChain* pCogChainG = NULL;
    CogChain* pCloneCogChainG = NULL;
    {
        iCode = NewCogChain(&pCogChainG, "g");
        iCode = CloneCogChain(&pCloneCogChainG, pCogChainG);
    }

    CogChain* pCogChainH = NULL;
    CogChain* pCloneCogChainH = NULL;
    {
        iCode = NewCogChain(&pCogChainH, "h");
        iCode = CloneCogChain(&pCloneCogChainH, pCogChainH);
    }

    CogChain* pCogChainI = NULL;
    CogChain* pCloneCogChainI = NULL;
    {
        iCode = NewCogChain(&pCogChainI, "i");
        iCode = CloneCogChain(&pCloneCogChainI, pCogChainI);
    }

    CogChain* pCogChainJ = NULL;
    CogChain* pCloneCogChainJ = NULL;
    {
        iCode = NewCogChain(&pCogChainJ, "j");
        iCode = CloneCogChain(&pCloneCogChainJ, pCogChainJ);
    }

    CogChain* pCogChainK = NULL;
    CogChain* pCloneCogChainK = NULL;
    {
        iCode = NewCogChain(&pCogChainK, "k");
        iCode = CloneCogChain(&pCloneCogChainK, pCogChainK);
    }

    CogChain* pCogChainL = NULL;
    CogChain* pCloneCogChainL = NULL;
    {
        iCode = NewCogChain(&pCogChainL, "l");
        iCode = CloneCogChain(&pCloneCogChainL, pCogChainL);
    }



    LOG_INFO("\n=== P2 ===");


    //pCogChainA, pCogChainB
    CogChain* pCloneCogChainAB = NULL;
    {
        LOG_INFO("pCogChainA = pCogChainB");

        LOG_INFO("Test API InsertCogChain(a,b) ...");
        iCode = InsertCogChain(pCogChainA, pCogChainB);
        printCogChain(pCogChainA);
        iCode = CountCogChain(pCogChainA, &uiCount);
        LOG_INFO("Test API CountCogChain(a,b = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(a,b) ...");
        iCode = CloneCogChain(&pCloneCogChainAB, pCogChainA);
        printCogChain(pCloneCogChainAB);
        iCode = CountCogChain(pCloneCogChainAB, &uiCount);
        LOG_INFO("Test API CountCogChain(a,b = %zu).", uiCount);
    }

    //pCloneCogChainB, pCloneCogChainC
    CogChain* pCloneCogChainCloneBC = NULL;
    {
        LOG_INFO("pCloneCogChainB = pCloneCogChainC");

        LOG_INFO("Test API InsertCogChain(b,c) ...");
        iCode = InsertCogChain(pCloneCogChainB, pCloneCogChainC);
        printCogChain(pCloneCogChainB);
        iCode = CountCogChain(pCloneCogChainB, &uiCount);
        LOG_INFO("Test API CountCogChain(b,c = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(b,c) ...");
        iCode = CloneCogChain(&pCloneCogChainCloneBC, pCloneCogChainB);
        printCogChain(pCloneCogChainCloneBC);
        iCode = CountCogChain(pCloneCogChainCloneBC, &uiCount);
        LOG_INFO("Test API CountCogChain(b,c = %zu).", uiCount);
    }

    //pCogChainC, pCloneCogChainA
    CogChain* pCloneCogChainCCloneA = NULL;
    {
        LOG_INFO("pCogChainC = pCloneCogChainA");

        LOG_INFO("Test API InsertCogChain(c,a) ...");
        iCode = InsertCogChain(pCogChainC, pCloneCogChainA);
        printCogChain(pCogChainC);
        iCode = CountCogChain(pCogChainC, &uiCount);
        LOG_INFO("Test API CountCogChain(c,a = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(c,a) ...");
        iCode = CloneCogChain(&pCloneCogChainCCloneA, pCogChainC);
        printCogChain(pCloneCogChainCCloneA);
        iCode = CountCogChain(pCloneCogChainCCloneA, &uiCount);
        LOG_INFO("Test API CountCogChain(c,a = %zu).", uiCount);
    }

    //以上 6 个 2 (a,b,c)
    //<pCogChainA> , <pCloneCogChainB> , <pCogChainC>
    //<pCloneCogChainAB> , pCloneCogChainCloneBC , <pCloneCogChainCCloneA>


    //pCogChainD, pCogChainE
    CogChain* pCloneCogChainDE = NULL;
    {
        LOG_INFO("pCogChainD = pCogChainE");

        LOG_INFO("Test API InsertCogChain(d,e) ...");
        iCode = JoinCogChain(pCogChainD, pCogChainE);
        printCogChain(pCogChainD);
        iCode = CountCogChain(pCogChainD, &uiCount);
        LOG_INFO("Test API CountCogChain(d,e = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(d,e) ...");
        iCode = CloneCogChain(&pCloneCogChainDE, pCogChainD);
        printCogChain(pCloneCogChainDE);
        iCode = CountCogChain(pCloneCogChainDE, &uiCount);
        LOG_INFO("Test API CountCogChain(d,e = %zu).", uiCount);
    }

    //pCloneCogChainE, pCloneCogChainF
    CogChain* pCloneCogChainCloneEF = NULL;
    {
        LOG_INFO("pCloneCogChainE = pCloneCogChainF");

        LOG_INFO("Test API InsertCogChain(e,f) ...");
        iCode = JoinCogChain(pCloneCogChainE, pCloneCogChainF);
        printCogChain(pCloneCogChainE);
        iCode = CountCogChain(pCloneCogChainE, &uiCount);
        LOG_INFO("Test API CountCogChain(e,f = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(e,f) ...");
        iCode = CloneCogChain(&pCloneCogChainCloneEF, pCloneCogChainE);
        printCogChain(pCloneCogChainCloneEF);
        iCode = CountCogChain(pCloneCogChainCloneEF, &uiCount);
        LOG_INFO("Test API CountCogChain(e,f = %zu).", uiCount);
    }

    //pCogChainF, pCloneCogChainD
    CogChain* pCloneCogChainFCloneD = NULL;
    {
        LOG_INFO("pCogChainF = pCloneCogChainD");

        LOG_INFO("Test API InsertCogChain(f,d) ...");
        iCode = JoinCogChain(pCogChainF, pCloneCogChainD);
        printCogChain(pCogChainF);
        iCode = CountCogChain(pCogChainF, &uiCount);
        LOG_INFO("Test API CountCogChain(f,d = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(f,d) ...");
        iCode = CloneCogChain(&pCloneCogChainFCloneD, pCogChainF);
        printCogChain(pCloneCogChainFCloneD);
        iCode = CountCogChain(pCloneCogChainFCloneD, &uiCount);
        LOG_INFO("Test API CountCogChain(f,d = %zu).", uiCount);
    }

    //以上 6 个 2 (d,e,f)
    //<pCogChainD> , <pCloneCogChainE> , pCogChainF
    //<pCloneCogChainDE> , <pCloneCogChainCloneEF>, <pCloneCogChainFCloneD>



    LOG_INFO("\n=== P3 ===");


    //pCogChainG, pCogChainI, pCogChainH
    {
        LOG_INFO("pCogChainG = pCogChainI = pCogChainH");

        LOG_INFO("Test API InsertCogChain(g,i,h) ...");
        iCode = InsertCogChain(pCogChainG, pCogChainH);
        iCode = InsertCogChain(pCogChainG, pCogChainI);
        printCogChain(pCogChainG);
        iCode = CountCogChain(pCogChainG, &uiCount);
        LOG_INFO("Test API CountCogChain(g,i,h = %zu).", uiCount);

    }

    //pCloneCogChainG, pCloneCogChainH, pCloneCogChainI
    CogChain* pCloneCogChainGHI = NULL;
    {
        LOG_INFO("pCloneCogChainG = pCloneCogChainH = pCloneCogChainI");

        LOG_INFO("Test API InsertCogChain(g,h,i) ...");
        iCode = InsertCogChain(pCloneCogChainG, pCloneCogChainH);
        iCode = InsertCogChain(pCloneCogChainH, pCloneCogChainI);
        printCogChain(pCloneCogChainG);
        iCode = CountCogChain(pCloneCogChainG, &uiCount);
        LOG_INFO("Test API CountCogChain(g,h,i = %zu).", uiCount);

        LOG_INFO("Test API CloneCogChain(g,h,i) ...");
        iCode = CloneCogChain(&pCloneCogChainGHI, pCloneCogChainG);
        printCogChain(pCloneCogChainGHI);
        iCode = CountCogChain(pCloneCogChainGHI, &uiCount);
        LOG_INFO("Test API CountCogChain(g,h,i = %zu).", uiCount);
    }
    //以上 3 个 3 (g,h,i)
    //pCogChainG , <pCloneCogChainG>
    //pCloneCogChainGHI



    CogChain* pCloneCogChainJAB = NULL;
    {
        LOG_INFO("pCloneCogChainAB = pCogChainJ");

        LOG_INFO("Test API InsertCogChain(a,b,j) ...");
        iCode = JoinCogChain(pCloneCogChainAB, pCogChainJ);
        printCogChain(pCloneCogChainAB);
        iCode = CountCogChain(pCloneCogChainAB, &uiCount);
        LOG_INFO("Test API CountCogChain(a,b,j = %zu).", uiCount);


        LOG_INFO("pCloneCogChainJ = pCogChainA = pCogChainB");

        LOG_INFO("Test API InsertCogChain(j,a,b) ...");
        iCode = JoinCogChain(pCloneCogChainJ, pCogChainA);
        printCogChain(pCloneCogChainJ);
        iCode = CountCogChain(pCloneCogChainJ, &uiCount);
        LOG_INFO("Test API CountCogChain(j,a,b = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(j,a,b) ...");
        iCode = CloneCogChain(&pCloneCogChainJAB, pCloneCogChainJ);
        printCogChain(pCloneCogChainJAB);
        iCode = CountCogChain(pCloneCogChainJAB, &uiCount);
        LOG_INFO("Test API CountCogChain(j,a,b = %zu).", uiCount);
    }
    //以上 3 个 3 (j)
    //pCloneCogChainAB , pCloneCogChainJ
    //<pCloneCogChainJAB>



    CogChain* pCloneCogChainKD = NULL;
    {
        LOG_INFO("pCloneCogChainK = pCogChainD");

        LOG_INFO("Test API InsertCogChain(k,d,e) ...");
        iCode = JoinCogChain(pCloneCogChainK, pCogChainD);
        printCogChain(pCloneCogChainK);
        iCode = CountCogChain(pCloneCogChainK, &uiCount);
        LOG_INFO("Test API CountCogChain(k,d,e = %zu).", uiCount);


        LOG_INFO("pCloneCogChainDE = pCogChainK");

        LOG_INFO("Test API InsertCogChain(d,e,k) ...");
        iCode = JoinCogChain(pCloneCogChainDE, pCogChainK);
        printCogChain(pCloneCogChainDE);
        iCode = CountCogChain(pCloneCogChainDE, &uiCount);
        LOG_INFO("Test API CountCogChain(d,e,k = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(k,d,e) ...");
        iCode = CloneCogChain(&pCloneCogChainKD, pCloneCogChainK);
        printCogChain(pCloneCogChainKD);
        iCode = CountCogChain(pCloneCogChainKD, &uiCount);
        LOG_INFO("Test API CountCogChain(k,d,e = %zu).", uiCount);
    }
    //以上 3 个 3 (k)
    //<pCloneCogChainK> , pCloneCogChainDE
    //pCloneCogChainKD




    LOG_INFO("\n=== P4 ===");


    CogChain* pCloneCogChainCloneEFC = NULL;
    {
        LOG_INFO("pCloneCogChainB, pCloneCogChainCCloneA");

        LOG_INFO("Test API InsertCogChain(b,c,c,a) ...");
        iCode = JoinCogChain(pCloneCogChainB, pCloneCogChainCCloneA);
        printCogChain(pCloneCogChainB);
        iCode = CountCogChain(pCloneCogChainB, &uiCount);
        LOG_INFO("Test API CountCogChain(b,c,c,a = %zu).", uiCount);


        LOG_INFO("pCloneCogChainE, pCloneCogChainFCloneD");

        LOG_INFO("Test API InsertCogChain(e,f,f,d) ...");
        iCode = JoinCogChain(pCloneCogChainE, pCloneCogChainFCloneD);
        printCogChain(pCloneCogChainE);
        iCode = CountCogChain(pCloneCogChainE, &uiCount);
        LOG_INFO("Test API CountCogChain(e,f,f,d = %zu).", uiCount);


        LOG_INFO("pCloneCogChainCloneEF, pCogChainC");

        LOG_INFO("Test API InsertCogChain(e,f,c,a) ...");
        iCode = JoinCogChain(pCloneCogChainCloneEF, pCogChainC);
        printCogChain(pCloneCogChainCloneEF);
        iCode = CountCogChain(pCloneCogChainCloneEF, &uiCount);
        LOG_INFO("Test API CountCogChain(e,f,c,a = %zu).", uiCount);


        LOG_INFO("Test API CloneCogChain(e,f,c,a) ...");
        iCode = CloneCogChain(&pCloneCogChainCloneEFC, pCloneCogChainCloneEF);
        printCogChain(pCloneCogChainCloneEFC);
        iCode = CountCogChain(pCloneCogChainCloneEFC, &uiCount);
        LOG_INFO("Test API CountCogChain(e,f,c,a = %zu).", uiCount);

    }
    //以上 4 个 4
    //pCloneCogChainB , pCloneCogChainE , pCloneCogChainCloneEF
    //pCloneCogChainCloneEFC




    LOG_INFO("\n=== P9 ===");
    {
        LOG_INFO("pCloneCogChainB, pCloneCogChainCCloneA");

        LOG_INFO("Test API InsertCogChain(g,j,k,d,e,a,b,h,i) ...");
        iCode = JoinCogChain(pCloneCogChainG, pCloneCogChainJAB);
        iCode = JoinCogChain(pCloneCogChainJAB, pCloneCogChainK);
        printCogChain(pCloneCogChainG);
        iCode = CountCogChain(pCloneCogChainG, &uiCount);
        LOG_INFO("Test API CountCogChain(g,j,k,d,e,a,b,h,i = %zu).", uiCount);
    }




    {
        //1
        LOG_INFO("Test API DeleteCogChain() ...");
        iCode = DeleteCogChain(&pCloneCogChainL);
        printCogChain(pCloneCogChainL);
        {
            iCode = DeleteCogChain(&pCogChainL);
            printCogChain(pCogChainL);
        }


        //2
        LOG_INFO("Test API CleanCogChain() ...");
        iCode = CleanCogChain(&pCogChainF);
        printCogChain(pCogChainF);
        {
            iCode = CleanCogChain(&pCloneCogChainCloneBC);
            printCogChain(pCloneCogChainCloneBC);

        }


        //3
        LOG_INFO("Test API CleanCogChain() ...");
        iCode = CleanCogChain(&pCloneCogChainGHI);
        printCogChain(pCloneCogChainGHI);
        {
            iCode = CleanCogChain(&pCogChainG);
            printCogChain(pCogChainG);

            iCode = CleanCogChain(&pCloneCogChainGHI);
            printCogChain(pCloneCogChainGHI);

            iCode = CleanCogChain(&pCloneCogChainAB);
            printCogChain(pCloneCogChainAB);

            iCode = CleanCogChain(&pCloneCogChainJ);
            printCogChain(pCloneCogChainJ);

            iCode = CleanCogChain(&pCloneCogChainDE);
            printCogChain(pCloneCogChainDE);

            iCode = CleanCogChain(&pCloneCogChainKD);
            printCogChain(pCloneCogChainKD);

        }


        //4
        LOG_INFO("Test API CleanCogChain() ...");
        iCode = CleanCogChain(&pCloneCogChainCloneEFC);
        printCogChain(pCloneCogChainCloneEFC);
        {
            iCode = CleanCogChain(&pCloneCogChainB);
            printCogChain(pCloneCogChainB);

            iCode = CleanCogChain(&pCloneCogChainE);
            printCogChain(pCloneCogChainE);

            iCode = CleanCogChain(&pCloneCogChainCloneEF);
            printCogChain(pCloneCogChainCloneEF);

            iCode = CleanCogChain(&pCloneCogChainCloneEFC);
            printCogChain(pCloneCogChainCloneEFC);


        }



        //9
        LOG_INFO("Test API CleanCogChain() ...");
        iCode = CleanCogChain(&pCloneCogChainG);
        printCogChain(pCloneCogChainG);



    }


    LogDestory();
}
