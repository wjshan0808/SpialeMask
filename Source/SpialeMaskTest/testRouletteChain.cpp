

#include "testSpialeMask.cpp"


void testRouletteChainAPI()
{
    LogRegist(LogArchiveExample);


    int iCode = 0x00;
    size_t uiCount = 0x00;


    LOG_INFO("\n=== P1 ===");

    RouletteChain* pRouletteChainA = NULL;
    {
        LOG_INFO("Test API NewRouletteChain(a) ...");
        iCode = NewRouletteChain(&pRouletteChainA);
        {
            CogChain* pCogChain = NULL;
            iCode = NewCogChain((&pCogChain), "a");
            iCode = JoinCogChain2Roulette(pRouletteChainA->m_pRoulette , pCogChain);
        }
        printRouletteChain(pRouletteChainA);

        iCode = CountRouletteChain(pRouletteChainA, &uiCount);
        LOG_INFO("Test API CountRouletteChain(a = %zu).", uiCount);
    }
    RouletteChain* pCloneRouletteChainA = NULL;
    {
        LOG_INFO("Test API CloneRouletteChain(a) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainA, pRouletteChainA);
        printRouletteChain(pCloneRouletteChainA);

        iCode = CountRouletteChain(pCloneRouletteChainA, &uiCount);
        LOG_INFO("Test API CountRouletteChain(a = %zu).", uiCount);
    }


    RouletteChain* pRouletteChainB = NULL;
    RouletteChain* pCloneRouletteChainB = NULL;
    {
        const char* sz[] = { "b" };
        iCode = MoldingRouletteChain(&pRouletteChainB, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainB, pRouletteChainB);
    }

    RouletteChain* pRouletteChainC = NULL;
    RouletteChain* pCloneRouletteChainC = NULL;
    {
        const char* sz[] = { "c" };
        iCode = MoldingRouletteChain(&pRouletteChainC, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainC, pRouletteChainC);
    }

    RouletteChain* pRouletteChainD = NULL;
    RouletteChain* pCloneRouletteChainD = NULL;
    {
        const char* sz[] = { "d" };
        iCode = MoldingRouletteChain(&pRouletteChainD, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainD, pRouletteChainD);
    }

    RouletteChain* pRouletteChainE = NULL;
    RouletteChain* pCloneRouletteChainE = NULL;
    {
        const char* sz[] = { "e" };
        iCode = MoldingRouletteChain(&pRouletteChainE, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainE, pRouletteChainE);
    }

    RouletteChain* pRouletteChainF = NULL;
    RouletteChain* pCloneRouletteChainF = NULL;
    {
        const char* sz[] = { "f" };
        iCode = MoldingRouletteChain(&pRouletteChainF, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainF, pRouletteChainF);
    }

    RouletteChain* pRouletteChainG = NULL;
    RouletteChain* pCloneRouletteChainG = NULL;
    {
        const char* sz[] = { "g" };
        iCode = MoldingRouletteChain(&pRouletteChainG, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainG, pRouletteChainG);
    }

    RouletteChain* pRouletteChainH = NULL;
    RouletteChain* pCloneRouletteChainH = NULL;
    {
        const char* sz[] = { "h" };
        iCode = MoldingRouletteChain(&pRouletteChainH, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainH, pRouletteChainH);
    }

    RouletteChain* pRouletteChainI = NULL;
    RouletteChain* pCloneRouletteChainI = NULL;
    {
        const char* sz[] = { "i" };
        iCode = MoldingRouletteChain(&pRouletteChainI, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainI, pRouletteChainI);
    }

    RouletteChain* pRouletteChainJ = NULL;
    RouletteChain* pCloneRouletteChainJ = NULL;
    {
        const char* sz[] = { "j" };
        iCode = MoldingRouletteChain(&pRouletteChainJ, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainJ, pRouletteChainJ);
    }

    RouletteChain* pRouletteChainK = NULL;
    RouletteChain* pCloneRouletteChainK = NULL;
    {
        const char* sz[] = { "k" };
        iCode = MoldingRouletteChain(&pRouletteChainK, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainK, pRouletteChainK);
    }

    RouletteChain* pRouletteChainL = NULL;
    RouletteChain* pCloneRouletteChainL = NULL;
    {
        const char* sz[] = { "l" };
        iCode = MoldingRouletteChain(&pRouletteChainL, sizeof(sz) / sizeof(sz[0x00]), sz);
        iCode = CloneRouletteChain(&pCloneRouletteChainL, pRouletteChainL);
    }



    LOG_INFO("\n=== P2 ===");


    //pRouletteChainA, pRouletteChainB
    RouletteChain* pCloneRouletteChainAB = NULL;
    {
        LOG_INFO("pRouletteChainA = pRouletteChainB");

        LOG_INFO("Test API InsertRouletteChain(a,b) ...");
        iCode = InsertRouletteChain(pRouletteChainA, pRouletteChainB);
        printRouletteChain(pRouletteChainA);
        iCode = CountRouletteChain(pRouletteChainA, &uiCount);
        LOG_INFO("Test API CountRouletteChain(a,b = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(a,b) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainAB, pRouletteChainA);
        printRouletteChain(pCloneRouletteChainAB);
        iCode = CountRouletteChain(pCloneRouletteChainAB, &uiCount);
        LOG_INFO("Test API CountRouletteChain(a,b = %zu).", uiCount);
    }

    //pCloneRouletteChainB, pCloneRouletteChainC
    RouletteChain* pCloneRouletteChainCloneBC = NULL;
    {
        LOG_INFO("pCloneRouletteChainB = pCloneRouletteChainC");

        LOG_INFO("Test API InsertRouletteChain(b,c) ...");
        iCode = InsertRouletteChain(pCloneRouletteChainB, pCloneRouletteChainC);
        printRouletteChain(pCloneRouletteChainB);
        iCode = CountRouletteChain(pCloneRouletteChainB, &uiCount);
        LOG_INFO("Test API CountRouletteChain(b,c = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(b,c) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainCloneBC, pCloneRouletteChainB);
        printRouletteChain(pCloneRouletteChainCloneBC);
        iCode = CountRouletteChain(pCloneRouletteChainCloneBC, &uiCount);
        LOG_INFO("Test API CountRouletteChain(b,c = %zu).", uiCount);
    }

    //pRouletteChainC, pCloneRouletteChainA
    RouletteChain* pCloneRouletteChainCCloneA = NULL;
    {
        LOG_INFO("pRouletteChainC = pCloneRouletteChainA");

        LOG_INFO("Test API InsertRouletteChain(c,a) ...");
        iCode = InsertRouletteChain(pRouletteChainC, pCloneRouletteChainA);
        printRouletteChain(pRouletteChainC);
        iCode = CountRouletteChain(pRouletteChainC, &uiCount);
        LOG_INFO("Test API CountRouletteChain(c,a = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(c,a) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainCCloneA, pRouletteChainC);
        printRouletteChain(pCloneRouletteChainCCloneA);
        iCode = CountRouletteChain(pCloneRouletteChainCCloneA, &uiCount);
        LOG_INFO("Test API CountRouletteChain(c,a = %zu).", uiCount);
    }

    //以上 6 个 2 (a,b,c)
    //<pRouletteChainA> , <pCloneRouletteChainB> , <pRouletteChainC>
    //<pCloneRouletteChainAB> , pCloneRouletteChainCloneBC , <pCloneRouletteChainCCloneA>


    //pRouletteChainD, pRouletteChainE
    RouletteChain* pCloneRouletteChainDE = NULL;
    {
        LOG_INFO("pRouletteChainD = pRouletteChainE");

        LOG_INFO("Test API InsertRouletteChain(d,e) ...");
        iCode = JoinRouletteChain(pRouletteChainD, pRouletteChainE);
        printRouletteChain(pRouletteChainD);
        iCode = CountRouletteChain(pRouletteChainD, &uiCount);
        LOG_INFO("Test API CountRouletteChain(d,e = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(d,e) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainDE, pRouletteChainD);
        printRouletteChain(pCloneRouletteChainDE);
        iCode = CountRouletteChain(pCloneRouletteChainDE, &uiCount);
        LOG_INFO("Test API CountRouletteChain(d,e = %zu).", uiCount);
    }

    //pCloneRouletteChainE, pCloneRouletteChainF
    RouletteChain* pCloneRouletteChainCloneEF = NULL;
    {
        LOG_INFO("pCloneRouletteChainE = pCloneRouletteChainF");

        LOG_INFO("Test API InsertRouletteChain(e,f) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainE, pCloneRouletteChainF);
        printRouletteChain(pCloneRouletteChainE);
        iCode = CountRouletteChain(pCloneRouletteChainE, &uiCount);
        LOG_INFO("Test API CountRouletteChain(e,f = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(e,f) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainCloneEF, pCloneRouletteChainE);
        printRouletteChain(pCloneRouletteChainCloneEF);
        iCode = CountRouletteChain(pCloneRouletteChainCloneEF, &uiCount);
        LOG_INFO("Test API CountRouletteChain(e,f = %zu).", uiCount);
    }

    //pRouletteChainF, pCloneRouletteChainD
    RouletteChain* pCloneRouletteChainFCloneD = NULL;
    {
        LOG_INFO("pRouletteChainF = pCloneRouletteChainD");

        LOG_INFO("Test API InsertRouletteChain(f,d) ...");
        iCode = JoinRouletteChain(pRouletteChainF, pCloneRouletteChainD);
        printRouletteChain(pRouletteChainF);
        iCode = CountRouletteChain(pRouletteChainF, &uiCount);
        LOG_INFO("Test API CountRouletteChain(f,d = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(f,d) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainFCloneD, pRouletteChainF);
        printRouletteChain(pCloneRouletteChainFCloneD);
        iCode = CountRouletteChain(pCloneRouletteChainFCloneD, &uiCount);
        LOG_INFO("Test API CountRouletteChain(f,d = %zu).", uiCount);
    }

    //以上 6 个 2 (d,e,f)
    //<pRouletteChainD> , <pCloneRouletteChainE> , pRouletteChainF
    //<pCloneRouletteChainDE> , <pCloneRouletteChainCloneEF>, <pCloneRouletteChainFCloneD>



    LOG_INFO("\n=== P3 ===");


    //pRouletteChainG, pRouletteChainI, pRouletteChainH
    {
        LOG_INFO("pRouletteChainG = pRouletteChainI = pRouletteChainH");

        LOG_INFO("Test API InsertRouletteChain(g,i,h) ...");
        iCode = InsertRouletteChain(pRouletteChainG, pRouletteChainH);
        iCode = InsertRouletteChain(pRouletteChainG, pRouletteChainI);
        printRouletteChain(pRouletteChainG);
        iCode = CountRouletteChain(pRouletteChainG, &uiCount);
        LOG_INFO("Test API CountRouletteChain(g,i,h = %zu).", uiCount);

    }

    //pCloneRouletteChainG, pCloneRouletteChainH, pCloneRouletteChainI
    RouletteChain* pCloneRouletteChainGHI = NULL;
    {
        LOG_INFO("pCloneRouletteChainG = pCloneRouletteChainH = pCloneRouletteChainI");

        LOG_INFO("Test API InsertRouletteChain(g,h,i) ...");
        iCode = InsertRouletteChain(pCloneRouletteChainG, pCloneRouletteChainH);
        iCode = InsertRouletteChain(pCloneRouletteChainH, pCloneRouletteChainI);
        printRouletteChain(pCloneRouletteChainG);
        iCode = CountRouletteChain(pCloneRouletteChainG, &uiCount);
        LOG_INFO("Test API CountRouletteChain(g,h,i = %zu).", uiCount);

        LOG_INFO("Test API CloneRouletteChain(g,h,i) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainGHI, pCloneRouletteChainG);
        printRouletteChain(pCloneRouletteChainGHI);
        iCode = CountRouletteChain(pCloneRouletteChainGHI, &uiCount);
        LOG_INFO("Test API CountRouletteChain(g,h,i = %zu).", uiCount);
    }
    //以上 3 个 3 (g,h,i)
    //pRouletteChainG , <pCloneRouletteChainG>
    //pCloneRouletteChainGHI



    RouletteChain* pCloneRouletteChainJAB = NULL;
    {
        LOG_INFO("pCloneRouletteChainAB = pRouletteChainJ");

        LOG_INFO("Test API InsertRouletteChain(a,b,j) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainAB, pRouletteChainJ);
        printRouletteChain(pCloneRouletteChainAB);
        iCode = CountRouletteChain(pCloneRouletteChainAB, &uiCount);
        LOG_INFO("Test API CountRouletteChain(a,b,j = %zu).", uiCount);


        LOG_INFO("pCloneRouletteChainJ = pRouletteChainA = pRouletteChainB");

        LOG_INFO("Test API InsertRouletteChain(j,a,b) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainJ, pRouletteChainA);
        printRouletteChain(pCloneRouletteChainJ);
        iCode = CountRouletteChain(pCloneRouletteChainJ, &uiCount);
        LOG_INFO("Test API CountRouletteChain(j,a,b = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(j,a,b) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainJAB, pCloneRouletteChainJ);
        printRouletteChain(pCloneRouletteChainJAB);
        iCode = CountRouletteChain(pCloneRouletteChainJAB, &uiCount);
        LOG_INFO("Test API CountRouletteChain(j,a,b = %zu).", uiCount);
    }
    //以上 3 个 3 (j)
    //pCloneRouletteChainAB , pCloneRouletteChainJ
    //<pCloneRouletteChainJAB>



    RouletteChain* pCloneRouletteChainKD = NULL;
    {
        LOG_INFO("pCloneRouletteChainK = pRouletteChainD");

        LOG_INFO("Test API InsertRouletteChain(k,d,e) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainK, pRouletteChainD);
        printRouletteChain(pCloneRouletteChainK);
        iCode = CountRouletteChain(pCloneRouletteChainK, &uiCount);
        LOG_INFO("Test API CountRouletteChain(k,d,e = %zu).", uiCount);


        LOG_INFO("pCloneRouletteChainDE = pRouletteChainK");

        LOG_INFO("Test API InsertRouletteChain(d,e,k) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainDE, pRouletteChainK);
        printRouletteChain(pCloneRouletteChainDE);
        iCode = CountRouletteChain(pCloneRouletteChainDE, &uiCount);
        LOG_INFO("Test API CountRouletteChain(d,e,k = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(k,d,e) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainKD, pCloneRouletteChainK);
        printRouletteChain(pCloneRouletteChainKD);
        iCode = CountRouletteChain(pCloneRouletteChainKD, &uiCount);
        LOG_INFO("Test API CountRouletteChain(k,d,e = %zu).", uiCount);
    }
    //以上 3 个 3 (k)
    //<pCloneRouletteChainK> , pCloneRouletteChainDE
    //pCloneRouletteChainKD




    LOG_INFO("\n=== P4 ===");


    RouletteChain* pCloneRouletteChainCloneEFC = NULL;
    {
        LOG_INFO("pCloneRouletteChainB, pCloneRouletteChainCCloneA");

        LOG_INFO("Test API InsertRouletteChain(b,c,c,a) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainB, pCloneRouletteChainCCloneA);
        printRouletteChain(pCloneRouletteChainB);
        iCode = CountRouletteChain(pCloneRouletteChainB, &uiCount);
        LOG_INFO("Test API CountRouletteChain(b,c,c,a = %zu).", uiCount);


        LOG_INFO("pCloneRouletteChainE, pCloneRouletteChainFCloneD");

        LOG_INFO("Test API InsertRouletteChain(e,f,f,d) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainE, pCloneRouletteChainFCloneD);
        printRouletteChain(pCloneRouletteChainE);
        iCode = CountRouletteChain(pCloneRouletteChainE, &uiCount);
        LOG_INFO("Test API CountRouletteChain(e,f,f,d = %zu).", uiCount);


        LOG_INFO("pCloneRouletteChainCloneEF, pRouletteChainC");

        LOG_INFO("Test API InsertRouletteChain(e,f,c,a) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainCloneEF, pRouletteChainC);
        printRouletteChain(pCloneRouletteChainCloneEF);
        iCode = CountRouletteChain(pCloneRouletteChainCloneEF, &uiCount);
        LOG_INFO("Test API CountRouletteChain(e,f,c,a = %zu).", uiCount);


        LOG_INFO("Test API CloneRouletteChain(e,f,c,a) ...");
        iCode = CloneRouletteChain(&pCloneRouletteChainCloneEFC, pCloneRouletteChainCloneEF);
        printRouletteChain(pCloneRouletteChainCloneEFC);
        iCode = CountRouletteChain(pCloneRouletteChainCloneEFC, &uiCount);
        LOG_INFO("Test API CountRouletteChain(e,f,c,a = %zu).", uiCount);

    }
    //以上 4 个 4
    //pCloneRouletteChainB , pCloneRouletteChainE , pCloneRouletteChainCloneEF
    //pCloneRouletteChainCloneEFC




    LOG_INFO("\n=== P9 ===");
    {
        LOG_INFO("pCloneRouletteChainB, pCloneRouletteChainCCloneA");

        LOG_INFO("Test API InsertRouletteChain(g,j,k,d,e,a,b,h,i) ...");
        iCode = JoinRouletteChain(pCloneRouletteChainG, pCloneRouletteChainJAB);
        iCode = JoinRouletteChain(pCloneRouletteChainJAB, pCloneRouletteChainK);
        printRouletteChain(pCloneRouletteChainG);
        iCode = CountRouletteChain(pCloneRouletteChainG, &uiCount);
        LOG_INFO("Test API CountRouletteChain(g,j,k,d,e,a,b,h,i = %zu).", uiCount);
    }




    {
        //1
        LOG_INFO("Test API DeleteRouletteChain() ...");
        iCode = DeleteRouletteChain(&pCloneRouletteChainL);
        printRouletteChain(pCloneRouletteChainL);
        {
            iCode = DeleteRouletteChain(&pRouletteChainL);
            printRouletteChain(pRouletteChainL);
        }


        //2
        LOG_INFO("Test API CleanRouletteChain() ...");
        iCode = CleanRouletteChain(&pRouletteChainF);
        printRouletteChain(pRouletteChainF);
        {
            iCode = CleanRouletteChain(&pCloneRouletteChainCloneBC);
            printRouletteChain(pCloneRouletteChainCloneBC);

        }


        //3
        LOG_INFO("Test API CleanRouletteChain() ...");
        iCode = CleanRouletteChain(&pCloneRouletteChainGHI);
        printRouletteChain(pCloneRouletteChainGHI);
        {
            iCode = CleanRouletteChain(&pRouletteChainG);
            printRouletteChain(pRouletteChainG);

            iCode = CleanRouletteChain(&pCloneRouletteChainGHI);
            printRouletteChain(pCloneRouletteChainGHI);

            iCode = CleanRouletteChain(&pCloneRouletteChainAB);
            printRouletteChain(pCloneRouletteChainAB);

            iCode = CleanRouletteChain(&pCloneRouletteChainJ);
            printRouletteChain(pCloneRouletteChainJ);

            iCode = CleanRouletteChain(&pCloneRouletteChainDE);
            printRouletteChain(pCloneRouletteChainDE);

            iCode = CleanRouletteChain(&pCloneRouletteChainKD);
            printRouletteChain(pCloneRouletteChainKD);

        }


        //4
        LOG_INFO("Test API CleanRouletteChain() ...");
        iCode = CleanRouletteChain(&pCloneRouletteChainCloneEFC);
        printRouletteChain(pCloneRouletteChainCloneEFC);
        {
            iCode = CleanRouletteChain(&pCloneRouletteChainB);
            printRouletteChain(pCloneRouletteChainB);

            iCode = CleanRouletteChain(&pCloneRouletteChainE);
            printRouletteChain(pCloneRouletteChainE);

            iCode = CleanRouletteChain(&pCloneRouletteChainCloneEF);
            printRouletteChain(pCloneRouletteChainCloneEF);

            iCode = CleanRouletteChain(&pCloneRouletteChainCloneEFC);
            printRouletteChain(pCloneRouletteChainCloneEFC);


        }



        //9
        LOG_INFO("Test API CleanRouletteChain() ...");
        iCode = CleanRouletteChain(&pCloneRouletteChainG);
        printRouletteChain(pCloneRouletteChainG);



    }



    LogDestory();
}
