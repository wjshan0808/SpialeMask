
#include "testSpialeMask.cpp"


void testSpialeAPI()
{
    LogRegist(LogArchiveExample);


    //
    int iCode = 0x00;
    Spiale* pSpiale = NULL;


    LOG_INFO("=== P0 ===");
    {
        LOG_INFO("Test API NewSpiale() ...");
        iCode = NewSpiale(&pSpiale);
        printSpiale(pSpiale);

        LOG_INFO("Test API NullifySpiale(%d) ...", APP_STATE_FALSE);
        iCode = NullifySpiale(pSpiale, APP_STATE_FALSE);
        printSpiale(pSpiale);

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpiale);
            printSpiale(pSpiale);
        }
    }


    LOG_INFO("=== P1 ===");


    Spiale* pSpialeA = NULL;
    Spiale* pCloneSpialeA = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeA);
        {
            const char* sz[] = { "a" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API AppendRouletteChain2Spiale(a) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeA, pRouletteChain);
        }
        printSpiale(pSpialeA);

        LOG_INFO("Test API CloneSpiale(a) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeA, pSpialeA);
            printSpiale(pCloneSpialeA);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(a) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeA, &(pSpialeA->m_pCurrent));
            printSpiale(pSpialeA);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeA, &(pCloneSpialeA->m_pCurrent));
            printSpiale(pCloneSpialeA);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeA);
            printSpiale(pSpialeA);

            iCode = DeleteSpiale(&pCloneSpialeA);
            printSpiale(pCloneSpialeA);
        }
    }

    Spiale* pSpialeB = NULL;
    Spiale* pCloneSpialeB = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeB);
        {
            const char* sz[] = { "b" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API JoinRouletteChain2Spiale(b) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeB, pRouletteChain);
        }
        printSpiale(pSpialeB);

        LOG_INFO("Test API CloneSpiale(b) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeB, pSpialeB);
            printSpiale(pCloneSpialeB);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(b) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeB, &(pSpialeB->m_pCurrent));
            printSpiale(pSpialeB);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeB, &(pCloneSpialeB->m_pCurrent));
            printSpiale(pCloneSpialeB);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeB);
            printSpiale(pSpialeB);

            iCode = DeleteSpiale(&pCloneSpialeB);
            printSpiale(pCloneSpialeB);
        }
    }


    LOG_INFO("=== P2 ===");


    Spiale* pSpialeCD = NULL;
    Spiale* pCloneSpialeCD = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeCD);
        {
            const char* sz[] = { "c" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API JoinRouletteChain2Spiale(c) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeCD, pRouletteChain);

            const char* sz2[] = { "d" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API JoinRouletteChain2Spiale(d) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeCD, pRouletteChain);
        }
        printSpiale(pSpialeCD);

        LOG_INFO("Test API CloneSpiale(c,d) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeCD, pSpialeCD);
            printSpiale(pCloneSpialeCD);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(c) ...");
        {
            RouletteChain* pRouletteChain = pSpialeCD->m_pCurrent;
            iCode = RemoveRouletteChainFromSpiale(pSpialeCD, &(pRouletteChain));
            printSpiale(pSpialeCD);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeCD, &(pCloneSpialeCD->m_pCurrent));
            printSpiale(pCloneSpialeCD);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(d) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeCD, &(pSpialeCD->m_pCurrent));
            printSpiale(pSpialeCD);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeCD, &(pCloneSpialeCD->m_pCurrent));
            printSpiale(pCloneSpialeCD);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeCD);
            printSpiale(pSpialeCD);

            iCode = DeleteSpiale(&pCloneSpialeCD);
            printSpiale(pCloneSpialeCD);
        }
    }


    Spiale* pSpialeEF = NULL;
    Spiale* pCloneSpialeEF = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeEF);
        {
            const char* sz[] = { "e" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API AppendRouletteChain2Spiale(e) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeEF, pRouletteChain);

            const char* sz2[] = { "f" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API JoinRouletteChain2Spiale(f) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeEF, pRouletteChain);
        }
        printSpiale(pSpialeEF);

        LOG_INFO("Test API CloneSpiale(e,f) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeEF, pSpialeEF);
            printSpiale(pCloneSpialeEF);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(e) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeEF, &(pSpialeEF->m_pCurrent));
            printSpiale(pSpialeEF);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeEF, &(pCloneSpialeEF->m_pCurrent));
            printSpiale(pCloneSpialeEF);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(f) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeEF, &(pSpialeEF->m_pCurrent));
            printSpiale(pSpialeEF);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeEF, &(pCloneSpialeEF->m_pCurrent));
            printSpiale(pCloneSpialeEF);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeEF);
            printSpiale(pSpialeEF);

            iCode = DeleteSpiale(&pCloneSpialeEF);
            printSpiale(pCloneSpialeEF);
        }
    }


    Spiale* pSpialeGH = NULL;
    Spiale* pCloneSpialeGH = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeGH);
        {
            const char* sz[] = { "g" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API JoinRouletteChain2Spiale(g) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeGH, pRouletteChain);

            const char* sz2[] = { "h" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API AppendRouletteChain2Spiale(h) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeGH, pRouletteChain);
        }
        printSpiale(pSpialeGH);

        LOG_INFO("Test API CloneSpiale(g,h) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeGH, pSpialeGH);
            printSpiale(pCloneSpialeGH);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(g) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeGH, &(pSpialeGH->m_pCurrent));
            printSpiale(pSpialeGH);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeGH, &(pCloneSpialeGH->m_pCurrent));
            printSpiale(pCloneSpialeGH);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(h) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeGH, &(pSpialeGH->m_pCurrent));
            printSpiale(pSpialeGH);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeGH, &(pCloneSpialeGH->m_pCurrent));
            printSpiale(pCloneSpialeGH);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeGH);
            printSpiale(pSpialeGH);

            iCode = DeleteSpiale(&pCloneSpialeGH);
            printSpiale(pCloneSpialeGH);
        }
    }



    Spiale* pSpialeIJ = NULL;
    Spiale* pCloneSpialeIJ = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeIJ);
        {
            const char* sz[] = { "i" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API AppendRouletteChain2Spiale(i) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeIJ, pRouletteChain);

            const char* sz2[] = { "j" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API AppendRouletteChain2Spiale(j) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeIJ, pRouletteChain);
        }
        printSpiale(pSpialeIJ);

        LOG_INFO("Test API CloneSpiale(i,j) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeIJ, pSpialeIJ);
            printSpiale(pCloneSpialeIJ);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(i) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeIJ, &(pSpialeIJ->m_pCurrent));
            printSpiale(pSpialeIJ);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeIJ, &(pCloneSpialeIJ->m_pCurrent));
            printSpiale(pCloneSpialeIJ);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(j) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeIJ, &(pSpialeIJ->m_pCurrent));
            printSpiale(pSpialeIJ);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeIJ, &(pCloneSpialeIJ->m_pCurrent));
            printSpiale(pCloneSpialeIJ);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeIJ);
            printSpiale(pSpialeIJ);

            iCode = DeleteSpiale(&pCloneSpialeIJ);
            printSpiale(pCloneSpialeIJ);
        }
    }



    LOG_INFO("=== P3 ===");



    Spiale* pSpialeKLM = NULL;
    Spiale* pCloneSpialeKLM = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeKLM);
        {
            const char* sz[] = { "k" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API AppendRouletteChain2Spiale(k) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeKLM, pRouletteChain);

            const char* sz2[] = { "m" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API AppendRouletteChain2Spiale(m) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeKLM, pRouletteChain);

            const char* sz3[] = { "l" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz3) / sizeof(sz3[0x00]), sz3);
            LOG_INFO("Test API AppendRouletteChain2Spiale(l) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeKLM, pRouletteChain);
        }
        printSpiale(pSpialeKLM);

        LOG_INFO("Test API CloneSpiale(k,m,l) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeKLM, pSpialeKLM);
            printSpiale(pCloneSpialeKLM);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(k) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeKLM, &(pSpialeKLM->m_pCurrent));
            printSpiale(pSpialeKLM);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeKLM, &(pCloneSpialeKLM->m_pCurrent));
            printSpiale(pCloneSpialeKLM);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(l) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeKLM, &(pSpialeKLM->m_pCurrent));
            printSpiale(pSpialeKLM);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeKLM, &(pCloneSpialeKLM->m_pCurrent));
            printSpiale(pCloneSpialeKLM);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(m) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeKLM, &(pSpialeKLM->m_pCurrent));
            printSpiale(pSpialeKLM);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeKLM, &(pCloneSpialeKLM->m_pCurrent));
            printSpiale(pCloneSpialeKLM);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeKLM);
            printSpiale(pSpialeKLM);

            iCode = DeleteSpiale(&pCloneSpialeKLM);
            printSpiale(pCloneSpialeKLM);
        }
    }


    Spiale* pSpialeNOP = NULL;
    Spiale* pCloneSpialeNOP = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeNOP);
        {
            const char* sz[] = { "n" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API JoinRouletteChain2Spiale(n) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeNOP, pRouletteChain);

            const char* sz2[] = { "o" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            LOG_INFO("Test API JoinRouletteChain2Spiale(o) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeNOP, pRouletteChain);

            const char* sz3[] = { "p" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz3) / sizeof(sz3[0x00]), sz3);
            LOG_INFO("Test API JoinRouletteChain2Spiale(p) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeNOP, pRouletteChain);
        }
        printSpiale(pSpialeNOP);

        LOG_INFO("Test API CloneSpiale(n,o,p) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeNOP, pSpialeNOP);
            printSpiale(pCloneSpialeNOP);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(n) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeNOP, &(pSpialeNOP->m_pCurrent));
            printSpiale(pSpialeNOP);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeNOP, &(pCloneSpialeNOP->m_pCurrent));
            printSpiale(pCloneSpialeNOP);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(o) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeNOP, &(pSpialeNOP->m_pCurrent));
            printSpiale(pSpialeNOP);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeNOP, &(pCloneSpialeNOP->m_pCurrent));
            printSpiale(pCloneSpialeNOP);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(p) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeNOP, &(pSpialeNOP->m_pCurrent));
            printSpiale(pSpialeNOP);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeNOP, &(pCloneSpialeNOP->m_pCurrent));
            printSpiale(pCloneSpialeNOP);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeNOP);
            printSpiale(pSpialeNOP);

            iCode = DeleteSpiale(&pCloneSpialeNOP);
            printSpiale(pCloneSpialeNOP);
        }
    }



    Spiale* pSpialeQRS = NULL;
    Spiale* pCloneSpialeQRS = NULL;
    {
        RouletteChain* pRouletteChain = NULL;
        iCode = NewSpiale(&pSpialeQRS);
        {
            const char* sz[] = { "q" };
            iCode = MoldingRouletteChain(&pRouletteChain, sizeof(sz) / sizeof(sz[0x00]), sz);
            LOG_INFO("Test API AppendRouletteChain2Spiale(q) ...");
            iCode = AppendRouletteChain2Spiale(pSpialeQRS, pRouletteChain);

            {
                RouletteChain* pRouletteChainR = NULL;
                const char* sz2[] = { "r" };
                iCode = MoldingRouletteChain(&pRouletteChainR, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
                RouletteChain* pRouletteChainS = NULL;
                const char* sz3[] = { "s" };
                iCode = MoldingRouletteChain(&pRouletteChainS, sizeof(sz3) / sizeof(sz3[0x00]), sz3);
                iCode = JoinRouletteChain(pRouletteChainR, pRouletteChainS);

                LOG_INFO("Test API JoinRouletteChain2Spiale(r,s) ...");
                iCode = JoinRouletteChain2Spiale(pSpialeQRS, pRouletteChainR);
            }
        }
        printSpiale(pSpialeQRS);

        LOG_INFO("Test API CloneSpiale(q,r,s) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeQRS, pSpialeQRS);
            printSpiale(pCloneSpialeQRS);
        }


        LOG_INFO("Test API RemoveRouletteChainFromSpiale(q) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeQRS, &(pSpialeQRS->m_pCurrent));
            printSpiale(pSpialeQRS);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeQRS, &(pCloneSpialeQRS->m_pCurrent));
            printSpiale(pCloneSpialeQRS);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(s) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeQRS, &(pSpialeQRS->m_pCurrent));
            printSpiale(pSpialeQRS);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeQRS, &(pCloneSpialeQRS->m_pCurrent));
            printSpiale(pCloneSpialeQRS);
        }

        LOG_INFO("Test API RemoveRouletteChainFromSpiale(r) ...");
        {
            iCode = RemoveRouletteChainFromSpiale(pSpialeQRS, &(pSpialeQRS->m_pCurrent));
            printSpiale(pSpialeQRS);

            iCode = RemoveRouletteChainFromSpiale(pCloneSpialeQRS, &(pCloneSpialeQRS->m_pCurrent));
            printSpiale(pCloneSpialeQRS);
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeQRS);
            printSpiale(pSpialeQRS);

            iCode = DeleteSpiale(&pCloneSpialeQRS);
            printSpiale(pCloneSpialeQRS);
        }
    }



    Spiale* pSpialeTUVW = NULL;
    Spiale* pCloneSpialeTUVW = NULL;
    {
        iCode = NewSpiale(&pSpialeTUVW);
        {
            RouletteChain* pRouletteChainT = NULL;
            const char* sz[] = { "t","y" };
            iCode = MoldingRouletteChain(&pRouletteChainT, sizeof(sz) / sizeof(sz[0x00]), sz);
            RouletteChain* pRouletteChainU = NULL;
            const char* sz2[] = { "u","x" };
            iCode = MoldingRouletteChain(&pRouletteChainU, sizeof(sz2) / sizeof(sz2[0x00]), sz2);
            iCode = JoinRouletteChain(pRouletteChainT, pRouletteChainU);

            LOG_INFO("Test API JoinRouletteChain2Spiale(t,u) ...");
            iCode = JoinRouletteChain2Spiale(pSpialeTUVW, pRouletteChainT);

            LOG_INFO("======= 2 ======");
            printSpiale(pSpialeTUVW);

            {
                RouletteChain* pRouletteChainV = NULL;
                const char* sz3[] = { "v","9" };
                iCode = MoldingRouletteChain(&pRouletteChainV, sizeof(sz3) / sizeof(sz3[0x00]), sz3);
                RouletteChain* pRouletteChainW = NULL;
                const char* sz4[] = { "w","z" };
                iCode = MoldingRouletteChain(&pRouletteChainW, sizeof(sz4) / sizeof(sz4[0x00]), sz4);
                InsertRouletteChain(pRouletteChainV, pRouletteChainW);

                LOG_INFO("Test API JoinRouletteChain2Spiale(v,w) ...");
                iCode = JoinRouletteChain2Spiale(pSpialeTUVW, pRouletteChainV);
            }
        }
        LOG_INFO("======= 4 ======");
        printSpiale(pSpialeTUVW);

        LOG_INFO("Test API CloneSpiale(t,u,v,w) ...");
        {
            iCode = CloneSpiale(&pCloneSpialeTUVW, pSpialeTUVW);
            printSpiale(pCloneSpialeTUVW);
        }


        LOG_INFO("Test API MeasureSpiale() ...");
        {
            size_t uiMeasure = 0x00;
            iCode = MeasureSpiale(pSpialeTUVW, &uiMeasure, APP_STATE_FALSE);
            LOG_INFO("MeasureSpiale(%zu)", uiMeasure);

            LOG_INFO("Test API SpinSpiale() ...");
            {
                char* sz = (char*)calloc(uiMeasure, sizeof(char));
                do{
                    iCode = SpinSpiale(pSpialeTUVW, sz, uiMeasure, APP_STATE_FALSE);
                    LOG_INFO("SpinSpiale(%zu, %s)", iCode, sz);
                } while(APP_FLAG_SM_SPIN_OVER != iCode);
                free(sz);
            }
        }

        LOG_INFO("Test API DeleteSpiale() ...");
        {
            iCode = DeleteSpiale(&pSpialeTUVW);
            printSpiale(pSpialeTUVW);

            iCode = DeleteSpiale(&pCloneSpialeTUVW);
            printSpiale(pCloneSpialeTUVW);
        }
    }


    LogDestory();
}
