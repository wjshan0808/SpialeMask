

#include "testSpialeMask.cpp"


void testRouletteAPI()
{
    LogRegist(LogArchiveExample);


    //
    int iCode = 0x00;
    Roulette* pRoulette = NULL;


    LOG_INFO("=== P0 ===");
    {
        LOG_INFO("Test API NewRoulette() ...");
        iCode = NewRoulette(&pRoulette);
        printRoulette(pRoulette);

        LOG_INFO("Test API NullifyRoulette(%d) ...", APP_STATE_FALSE);
        iCode = NullifyRoulette(pRoulette, APP_STATE_FALSE);
        printRoulette(pRoulette);

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRoulette);
            printRoulette(pRoulette);
        }
    }


    LOG_INFO("=== P1 ===");


    Roulette* pRouletteA = NULL;
    Roulette* pCloneRouletteA = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteA);
        {
            iCode = NewCogChain(&pCogChain, "a");
            LOG_INFO("Test API AppendCogChain2Roulette(a) ...");
            iCode = AppendCogChain2Roulette(pRouletteA, pCogChain);
        }
        printRoulette(pRouletteA);

        LOG_INFO("Test API CloneRoulette(a) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteA, pRouletteA);
            printRoulette(pCloneRouletteA);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(a) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteA, &(pRouletteA->m_pCurrent));
            printRoulette(pRouletteA);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteA, &(pCloneRouletteA->m_pCurrent));
            printRoulette(pCloneRouletteA);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteA);
            printRoulette(pRouletteA);

            iCode = DeleteRoulette(&pCloneRouletteA);
            printRoulette(pCloneRouletteA);
        }
    }

    Roulette* pRouletteB = NULL;
    Roulette* pCloneRouletteB = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteB);
        {
            iCode = NewCogChain(&pCogChain, "b");
            LOG_INFO("Test API JoinCogChain2Roulette(b) ...");
            iCode = JoinCogChain2Roulette(pRouletteB, pCogChain);
        }
        printRoulette(pRouletteB);

        LOG_INFO("Test API CloneRoulette(b) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteB, pRouletteB);
            printRoulette(pCloneRouletteB);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(b) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteB, &(pRouletteB->m_pCurrent));
            printRoulette(pRouletteB);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteB, &(pCloneRouletteB->m_pCurrent));
            printRoulette(pCloneRouletteB);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteB);
            printRoulette(pRouletteB);

            iCode = DeleteRoulette(&pCloneRouletteB);
            printRoulette(pCloneRouletteB);
        }
    }


    LOG_INFO("=== P2 ===");


    Roulette* pRouletteCD = NULL;
    Roulette* pCloneRouletteCD = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteCD);
        {
            iCode = NewCogChain(&pCogChain, "c");
            LOG_INFO("Test API JoinCogChain2Roulette(c) ...");
            iCode = JoinCogChain2Roulette(pRouletteCD, pCogChain);

            iCode = NewCogChain(&pCogChain, "d");
            LOG_INFO("Test API JoinCogChain2Roulette(d) ...");
            iCode = JoinCogChain2Roulette(pRouletteCD, pCogChain);
        }
        printRoulette(pRouletteCD);

        LOG_INFO("Test API CloneRoulette(c,d) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteCD, pRouletteCD);
            printRoulette(pCloneRouletteCD);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(c) ...");
        {
            CogChain* pCogChain = pRouletteCD->m_pCurrent;
            iCode = RemoveCogChainFromRoulette(pRouletteCD, &(pCogChain));
            printRoulette(pRouletteCD);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteCD, &(pCloneRouletteCD->m_pCurrent));
            printRoulette(pCloneRouletteCD);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(d) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteCD, &(pRouletteCD->m_pCurrent));
            printRoulette(pRouletteCD);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteCD, &(pCloneRouletteCD->m_pCurrent));
            printRoulette(pCloneRouletteCD);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteCD);
            printRoulette(pRouletteCD);

            iCode = DeleteRoulette(&pCloneRouletteCD);
            printRoulette(pCloneRouletteCD);
        }
    }


    Roulette* pRouletteEF = NULL;
    Roulette* pCloneRouletteEF = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteEF);
        {
            iCode = NewCogChain(&pCogChain, "e");
            LOG_INFO("Test API AppendCogChain2Roulette(e) ...");
            iCode = AppendCogChain2Roulette(pRouletteEF, pCogChain);

            iCode = NewCogChain(&pCogChain, "f");
            LOG_INFO("Test API JoinCogChain2Roulette(f) ...");
            iCode = JoinCogChain2Roulette(pRouletteEF, pCogChain);
        }
        printRoulette(pRouletteEF);

        LOG_INFO("Test API CloneRoulette(e,f) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteEF, pRouletteEF);
            printRoulette(pCloneRouletteEF);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(e) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteEF, &(pRouletteEF->m_pCurrent));
            printRoulette(pRouletteEF);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteEF, &(pCloneRouletteEF->m_pCurrent));
            printRoulette(pCloneRouletteEF);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(f) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteEF, &(pRouletteEF->m_pCurrent));
            printRoulette(pRouletteEF);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteEF, &(pCloneRouletteEF->m_pCurrent));
            printRoulette(pCloneRouletteEF);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteEF);
            printRoulette(pRouletteEF);

            iCode = DeleteRoulette(&pCloneRouletteEF);
            printRoulette(pCloneRouletteEF);
        }
    }


    Roulette* pRouletteGH = NULL;
    Roulette* pCloneRouletteGH = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteGH);
        {
            iCode = NewCogChain(&pCogChain, "g");
            LOG_INFO("Test API JoinCogChain2Roulette(g) ...");
            iCode = JoinCogChain2Roulette(pRouletteGH, pCogChain);

            iCode = NewCogChain(&pCogChain, "h");
            LOG_INFO("Test API AppendCogChain2Roulette(h) ...");
            iCode = AppendCogChain2Roulette(pRouletteGH, pCogChain);
        }
        printRoulette(pRouletteGH);

        LOG_INFO("Test API CloneRoulette(g,h) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteGH, pRouletteGH);
            printRoulette(pCloneRouletteGH);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(g) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteGH, &(pRouletteGH->m_pCurrent));
            printRoulette(pRouletteGH);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteGH, &(pCloneRouletteGH->m_pCurrent));
            printRoulette(pCloneRouletteGH);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(h) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteGH, &(pRouletteGH->m_pCurrent));
            printRoulette(pRouletteGH);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteGH, &(pCloneRouletteGH->m_pCurrent));
            printRoulette(pCloneRouletteGH);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteGH);
            printRoulette(pRouletteGH);

            iCode = DeleteRoulette(&pCloneRouletteGH);
            printRoulette(pCloneRouletteGH);
        }
    }



    Roulette* pRouletteIJ = NULL;
    Roulette* pCloneRouletteIJ = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteIJ);
        {
            iCode = NewCogChain(&pCogChain, "i");
            LOG_INFO("Test API AppendCogChain2Roulette(i) ...");
            iCode = AppendCogChain2Roulette(pRouletteIJ, pCogChain);

            iCode = NewCogChain(&pCogChain, "j");
            LOG_INFO("Test API AppendCogChain2Roulette(j) ...");
            iCode = AppendCogChain2Roulette(pRouletteIJ, pCogChain);
        }
        printRoulette(pRouletteIJ);

        LOG_INFO("Test API CloneRoulette(i,j) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteIJ, pRouletteIJ);
            printRoulette(pCloneRouletteIJ);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(i) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteIJ, &(pRouletteIJ->m_pCurrent));
            printRoulette(pRouletteIJ);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteIJ, &(pCloneRouletteIJ->m_pCurrent));
            printRoulette(pCloneRouletteIJ);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(j) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteIJ, &(pRouletteIJ->m_pCurrent));
            printRoulette(pRouletteIJ);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteIJ, &(pCloneRouletteIJ->m_pCurrent));
            printRoulette(pCloneRouletteIJ);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteIJ);
            printRoulette(pRouletteIJ);

            iCode = DeleteRoulette(&pCloneRouletteIJ);
            printRoulette(pCloneRouletteIJ);
        }
    }



    LOG_INFO("=== P3 ===");



    Roulette* pRouletteKLM = NULL;
    Roulette* pCloneRouletteKLM = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteKLM);
        {
            iCode = NewCogChain(&pCogChain, "k");
            LOG_INFO("Test API AppendCogChain2Roulette(k) ...");
            iCode = AppendCogChain2Roulette(pRouletteKLM, pCogChain);

            iCode = NewCogChain(&pCogChain, "m");
            LOG_INFO("Test API AppendCogChain2Roulette(m) ...");
            iCode = AppendCogChain2Roulette(pRouletteKLM, pCogChain);

            iCode = NewCogChain(&pCogChain, "l");
            LOG_INFO("Test API AppendCogChain2Roulette(l) ...");
            iCode = AppendCogChain2Roulette(pRouletteKLM, pCogChain);
        }
        printRoulette(pRouletteKLM);

        LOG_INFO("Test API CloneRoulette(k,m,l) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteKLM, pRouletteKLM);
            printRoulette(pCloneRouletteKLM);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(k) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteKLM, &(pRouletteKLM->m_pCurrent));
            printRoulette(pRouletteKLM);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteKLM, &(pCloneRouletteKLM->m_pCurrent));
            printRoulette(pCloneRouletteKLM);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(l) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteKLM, &(pRouletteKLM->m_pCurrent));
            printRoulette(pRouletteKLM);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteKLM, &(pCloneRouletteKLM->m_pCurrent));
            printRoulette(pCloneRouletteKLM);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(m) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteKLM, &(pRouletteKLM->m_pCurrent));
            printRoulette(pRouletteKLM);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteKLM, &(pCloneRouletteKLM->m_pCurrent));
            printRoulette(pCloneRouletteKLM);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteKLM);
            printRoulette(pRouletteKLM);

            iCode = DeleteRoulette(&pCloneRouletteKLM);
            printRoulette(pCloneRouletteKLM);
        }
    }


    Roulette* pRouletteNOP = NULL;
    Roulette* pCloneRouletteNOP = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteNOP);
        {
            iCode = NewCogChain(&pCogChain, "n");
            LOG_INFO("Test API JoinCogChain2Roulette(n) ...");
            iCode = JoinCogChain2Roulette(pRouletteNOP, pCogChain);

            iCode = NewCogChain(&pCogChain, "o");
            LOG_INFO("Test API JoinCogChain2Roulette(o) ...");
            iCode = JoinCogChain2Roulette(pRouletteNOP, pCogChain);

            iCode = NewCogChain(&pCogChain, "p");
            LOG_INFO("Test API JoinCogChain2Roulette(p) ...");
            iCode = JoinCogChain2Roulette(pRouletteNOP, pCogChain);
        }
        printRoulette(pRouletteNOP);

        LOG_INFO("Test API CloneRoulette(n,o,p) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteNOP, pRouletteNOP);
            printRoulette(pCloneRouletteNOP);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(n) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteNOP, &(pRouletteNOP->m_pCurrent));
            printRoulette(pRouletteNOP);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteNOP, &(pCloneRouletteNOP->m_pCurrent));
            printRoulette(pCloneRouletteNOP);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(o) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteNOP, &(pRouletteNOP->m_pCurrent));
            printRoulette(pRouletteNOP);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteNOP, &(pCloneRouletteNOP->m_pCurrent));
            printRoulette(pCloneRouletteNOP);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(p) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteNOP, &(pRouletteNOP->m_pCurrent));
            printRoulette(pRouletteNOP);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteNOP, &(pCloneRouletteNOP->m_pCurrent));
            printRoulette(pCloneRouletteNOP);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteNOP);
            printRoulette(pRouletteNOP);

            iCode = DeleteRoulette(&pCloneRouletteNOP);
            printRoulette(pCloneRouletteNOP);
        }
    }



    Roulette* pRouletteQRS = NULL;
    Roulette* pCloneRouletteQRS = NULL;
    {
        CogChain* pCogChain = NULL;
        iCode = NewRoulette(&pRouletteQRS);
        {
            iCode = NewCogChain(&pCogChain, "q");
            LOG_INFO("Test API AppendCogChain2Roulette(q) ...");
            iCode = AppendCogChain2Roulette(pRouletteQRS, pCogChain);

            {
                CogChain* pCogChainR = NULL;
                iCode = NewCogChain(&pCogChainR, "r");
                CogChain* pCogChainS = NULL;
                iCode = NewCogChain(&pCogChainS, "s");
                iCode = JoinCogChain(pCogChainR, pCogChainS);

                LOG_INFO("Test API JoinCogChain2Roulette(r,s) ...");
                iCode = JoinCogChain2Roulette(pRouletteQRS, pCogChainR);
            }
        }
        printRoulette(pRouletteQRS);

        LOG_INFO("Test API CloneRoulette(q,r,s) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteQRS, pRouletteQRS);
            printRoulette(pCloneRouletteQRS);
        }


        LOG_INFO("Test API RemoveCogChainFromRoulette(q) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteQRS, &(pRouletteQRS->m_pCurrent));
            printRoulette(pRouletteQRS);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteQRS, &(pCloneRouletteQRS->m_pCurrent));
            printRoulette(pCloneRouletteQRS);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(s) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteQRS, &(pRouletteQRS->m_pCurrent));
            printRoulette(pRouletteQRS);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteQRS, &(pCloneRouletteQRS->m_pCurrent));
            printRoulette(pCloneRouletteQRS);
        }

        LOG_INFO("Test API RemoveCogChainFromRoulette(r) ...");
        {
            iCode = RemoveCogChainFromRoulette(pRouletteQRS, &(pRouletteQRS->m_pCurrent));
            printRoulette(pRouletteQRS);

            iCode = RemoveCogChainFromRoulette(pCloneRouletteQRS, &(pCloneRouletteQRS->m_pCurrent));
            printRoulette(pCloneRouletteQRS);
        }

        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteQRS);
            printRoulette(pRouletteQRS);

            iCode = DeleteRoulette(&pCloneRouletteQRS);
            printRoulette(pCloneRouletteQRS);
        }
    }



    Roulette* pRouletteTUVW = NULL;
    Roulette* pCloneRouletteTUVW = NULL;
    {
        iCode = NewRoulette(&pRouletteTUVW);
        {
            CogChain* pCogChainT = NULL;
            iCode = NewCogChain(&pCogChainT, "t");
            CogChain* pCogChainU = NULL;
            iCode = NewCogChain(&pCogChainU, "u");
            iCode = JoinCogChain(pCogChainT, pCogChainU);

            LOG_INFO("Test API JoinCogChain2Roulette(t,u) ...");
            iCode = JoinCogChain2Roulette(pRouletteTUVW, pCogChainT);

            LOG_INFO("======= 2 ======");
            printRoulette(pRouletteTUVW);

            {
                CogChain* pCogChainV = NULL;
                iCode = NewCogChain(&pCogChainV, "v");
                CogChain* pCogChainW = NULL;
                iCode = NewCogChain(&pCogChainW, "w");
                InsertCogChain(pCogChainV, pCogChainW);

                LOG_INFO("Test API JoinCogChain2Roulette(v,w) ...");
                iCode = JoinCogChain2Roulette(pRouletteTUVW, pCogChainV);
            }
        }
        LOG_INFO("======= 4 ======");
        printRoulette(pRouletteTUVW);

        LOG_INFO("Test API CloneRoulette(t,u,v,w) ...");
        {
            iCode = CloneRoulette(&pCloneRouletteTUVW, pRouletteTUVW);
            printRoulette(pCloneRouletteTUVW);
        }


        LOG_INFO("Test API DeleteRoulette() ...");
        {
            iCode = DeleteRoulette(&pRouletteTUVW);
            printRoulette(pRouletteTUVW);

            iCode = DeleteRoulette(&pCloneRouletteTUVW);
            printRoulette(pCloneRouletteTUVW);
        }
    }


    LogDestory();
}
