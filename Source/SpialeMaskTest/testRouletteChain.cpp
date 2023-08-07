
#include "SpialeMask.h"
#include "Core/RouletteChain.h"

#include <string.h>
#include <stdlib.h>


void testRouletteChain()
{
    LogRegist(LogArchiveExample);

    RouletteChain* pRouletteChain = NULL;
    LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = DeleteRouletteChain(NULL);
        LOG_INFO("ia = %d.", ia);

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = DeleteRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);

    }

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = DeleteRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        {
            AppendCogChain2Roulette(pRouletteChain->m_pRoulette, "a");

            RouletteChain* pRouletteChainBackward = pRouletteChain;
            do
            {
                CogChain* pCogChainBackward = pRouletteChainBackward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainBackward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainBackward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainBackward->m_pCog->m_usIdentity, pCogChainBackward->m_pCog->m_szContent);

                    pCogChainBackward = pCogChainBackward->m_pBackward;
                }while (pCogChainBackward!= pRouletteChainBackward->m_pRoulette->m_pAnchor);

                pRouletteChainBackward = pRouletteChainBackward->m_pBackward;
            }while (pRouletteChainBackward!= pRouletteChain);
        }

        ia = CleanRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        {
            AppendCogChain2Roulette(pRouletteChain->m_pRoulette, "b");

            RouletteChain* pRouletteChainBackward = pRouletteChain;
            do
            {
                CogChain* pCogChainBackward = pRouletteChainBackward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainBackward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainBackward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainBackward->m_pCog->m_usIdentity, pCogChainBackward->m_pCog->m_szContent);

                    pCogChainBackward = pCogChainBackward->m_pBackward;
                }while (pCogChainBackward!= pRouletteChainBackward->m_pRoulette->m_pAnchor);

                pRouletteChainBackward = pRouletteChainBackward->m_pBackward;
            }while (pRouletteChainBackward!= pRouletteChain);


            RouletteChain* pCloneRouletteChain = NULL;
            ia = CloneRouletteChain(&pCloneRouletteChain, pRouletteChain);
            LOG_INFO("Forward = %p, %d, Backward = %p.", pCloneRouletteChain->m_pForward, pCloneRouletteChain->m_pRoulette->m_usIdentity, pCloneRouletteChain->m_pBackward);
            LOG_INFO("pCloneRouletteChain = %p, &pCloneRouletteChain = %p, *pCloneRouletteChain = %p.", pCloneRouletteChain, &pCloneRouletteChain, *pCloneRouletteChain);

            uiCount = 0x00;
            CountRouletteChain(pCloneRouletteChain, &uiCount);
            LOG_INFO("Count = %zu.", uiCount);

            {

                RouletteChain* pRouletteChainForward = pCloneRouletteChain;
                do
                {
                    CogChain* pCogChainForward = pRouletteChainForward->m_pRoulette->m_pCurrent;
                    uiCount = 0x00;
                    CountCogChain(pCogChainForward, &uiCount);
                    LOG_INFO("%d %d.", pRouletteChainForward->m_pRoulette->m_usIdentity, uiCount);

                    do
                    {

                        LOG_INFO("%d, %s.", pCogChainForward->m_pCog->m_usIdentity, pCogChainForward->m_pCog->m_szContent);

                        pCogChainForward = pCogChainForward->m_pForward;
                    }while (pCogChainForward!= pRouletteChainForward->m_pRoulette->m_pAnchor);

                    pRouletteChainForward = pRouletteChainForward->m_pForward;
                }while (pRouletteChainForward!= pCloneRouletteChain);
            }

            ia = CleanRouletteChain(&pCloneRouletteChain);
            LOG_INFO("ia = %d.", ia);
            LOG_INFO("pCloneRouletteChain = %p, &pCloneRouletteChain = %p.", pCloneRouletteChain, &pCloneRouletteChain);

        }

        ia = DeleteRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        AppendCogChain2Roulette(pRouletteChain->m_pRoulette, "c");

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);


        RouletteChain* peRouletteChain = NULL;
         ia = NewRouletteChain(&peRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", peRouletteChain->m_pForward, peRouletteChain->m_pRoulette->m_usIdentity, peRouletteChain->m_pBackward);
        LOG_INFO("peRouletteChain = %p, &peRouletteChain = %p, *peRouletteChain = %p.", peRouletteChain, &peRouletteChain, *peRouletteChain);

        AppendCogChain2Roulette(peRouletteChain->m_pRoulette, "d");

        InsertRouletteChain(pRouletteChain, peRouletteChain);

        uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);


        {
            RouletteChain* pRouletteChainBackward = pRouletteChain;
            do
            {
                CogChain* pCogChainBackward = pRouletteChainBackward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainBackward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainBackward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainBackward->m_pCog->m_usIdentity, pCogChainBackward->m_pCog->m_szContent);

                    pCogChainBackward = pCogChainBackward->m_pBackward;
                }while (pCogChainBackward!= pRouletteChainBackward->m_pRoulette->m_pAnchor);

                pRouletteChainBackward = pRouletteChainBackward->m_pBackward;
            }while (pRouletteChainBackward!= pRouletteChain);


            RouletteChain* pRouletteChainForward = pRouletteChain;
            do
            {
                CogChain* pCogChainForward = pRouletteChainForward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainForward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainForward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainForward->m_pCog->m_usIdentity, pCogChainForward->m_pCog->m_szContent);

                    pCogChainForward = pCogChainForward->m_pForward;
                }while (pCogChainForward!= pRouletteChainForward->m_pRoulette->m_pAnchor);

                pRouletteChainForward = pRouletteChainForward->m_pForward;
            }while (pRouletteChainForward!= pRouletteChain);
        }

        ia = CleanRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }


    /*2*/
    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        AppendCogChain2Roulette(pRouletteChain->m_pRoulette, "e");

        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);


        RouletteChain* peRouletteChain = NULL;
         ia = CloneRouletteChain(&peRouletteChain, pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", peRouletteChain->m_pForward, peRouletteChain->m_pRoulette->m_usIdentity, peRouletteChain->m_pBackward);
        LOG_INFO("peRouletteChain = %p, &peRouletteChain = %p, *epRouletteChain = %p.", peRouletteChain, &peRouletteChain, *peRouletteChain);

        AppendCogChain2Roulette(peRouletteChain->m_pRoulette, "f");

        JoinRouletteChain(pRouletteChain, peRouletteChain);

        uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);



        {
            RouletteChain* pRouletteChainBackward = pRouletteChain;
            do
            {
                CogChain* pCogChainBackward = pRouletteChainBackward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainBackward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainBackward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainBackward->m_pCog->m_usIdentity, pCogChainBackward->m_pCog->m_szContent);

                    pCogChainBackward = pCogChainBackward->m_pBackward;
                }while (pCogChainBackward!= pRouletteChainBackward->m_pRoulette->m_pAnchor);

                pRouletteChainBackward = pRouletteChainBackward->m_pBackward;
            }while (pRouletteChainBackward!= pRouletteChain);


            RouletteChain* pRouletteChainForward = pRouletteChain;
            do
            {
                CogChain* pCogChainForward = pRouletteChainForward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainForward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainForward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainForward->m_pCog->m_usIdentity, pCogChainForward->m_pCog->m_szContent);

                    pCogChainForward = pCogChainForward->m_pForward;
                }while (pCogChainForward!= pRouletteChainForward->m_pRoulette->m_pAnchor);

                pRouletteChainForward = pRouletteChainForward->m_pForward;
            }while (pRouletteChainForward!= pRouletteChain);
        }

        ia = CleanRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }


    //3
    LOG_DEBUG("\r\n");
    {
        int ia = NewRouletteChain(&pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", pRouletteChain->m_pForward, pRouletteChain->m_pRoulette->m_usIdentity, pRouletteChain->m_pBackward);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p, *pRouletteChain = %p.", pRouletteChain, &pRouletteChain, *pRouletteChain);

        AppendCogChain2Roulette(pRouletteChain->m_pRoulette, "g");
        size_t uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        RouletteChain* peRouletteChain = NULL;
         ia = CloneRouletteChain(&peRouletteChain, pRouletteChain);

        InsertRouletteChain(pRouletteChain, peRouletteChain);

        AppendCogChain2Roulette(peRouletteChain->m_pRoulette, "h");
        LOG_INFO("Forward = %p, %d, Backward = %p.", peRouletteChain->m_pForward, peRouletteChain->m_pRoulette->m_usIdentity, peRouletteChain->m_pBackward);
        LOG_INFO("peRouletteChain = %p, &peRouletteChain = %p, *peRouletteChain = %p.", peRouletteChain, &peRouletteChain, *peRouletteChain);

        uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        {
            RouletteChain* pnRouletteChain = NULL;
             ia = NewRouletteChain(&pnRouletteChain);
            LOG_INFO("Forward = %p, %d, Backward = %p.", pnRouletteChain->m_pForward, pnRouletteChain->m_pRoulette->m_usIdentity, pnRouletteChain->m_pBackward);
            LOG_INFO("pnRouletteChain = %p, &pnRouletteChain = %p, *pnRouletteChain = %p.", pnRouletteChain, &pnRouletteChain, *pnRouletteChain);

            AppendCogChain2Roulette(pnRouletteChain->m_pRoulette, "i");
            JoinRouletteChain(pRouletteChain, pnRouletteChain);

            uiCount = 0x00;
            CountRouletteChain(pRouletteChain, &uiCount);
            LOG_INFO("Count = %zu.", uiCount);
        }

        ia = CloneRouletteChain(&peRouletteChain, pRouletteChain);
        LOG_INFO("Forward = %p, %d, Backward = %p.", peRouletteChain->m_pForward, peRouletteChain->m_pRoulette->m_usIdentity, peRouletteChain->m_pBackward);
        LOG_INFO("peRouletteChain = %p, &peRouletteChain = %p, *pRouletteChain = %p.", peRouletteChain, &peRouletteChain, *peRouletteChain);

        AppendCogChain2Roulette(peRouletteChain->m_pRoulette, "j");
        AppendCogChain2Roulette(peRouletteChain->m_pRoulette, "k");
        JoinRouletteChain(pRouletteChain, peRouletteChain);

        uiCount = 0x00;
        CountRouletteChain(pRouletteChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);


        {
            RouletteChain* pRouletteChainBackward = pRouletteChain;
            do
            {
                CogChain* pCogChainBackward = pRouletteChainBackward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainBackward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainBackward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainBackward->m_pCog->m_usIdentity, pCogChainBackward->m_pCog->m_szContent);

                    pCogChainBackward = pCogChainBackward->m_pBackward;
                }while (pCogChainBackward!= pRouletteChainBackward->m_pRoulette->m_pAnchor);

                pRouletteChainBackward = pRouletteChainBackward->m_pBackward;
            }while (pRouletteChainBackward!= pRouletteChain);


            RouletteChain* pRouletteChainForward = pRouletteChain;
            do
            {
                CogChain* pCogChainForward = pRouletteChainForward->m_pRoulette->m_pCurrent;
                uiCount = 0x00;
                CountCogChain(pCogChainForward, &uiCount);
                LOG_INFO("%d %d.", pRouletteChainForward->m_pRoulette->m_usIdentity, uiCount);

                do
                {

                    LOG_INFO("%d, %s.", pCogChainForward->m_pCog->m_usIdentity, pCogChainForward->m_pCog->m_szContent);

                    pCogChainForward = pCogChainForward->m_pForward;
                }while (pCogChainForward!= pRouletteChainForward->m_pRoulette->m_pAnchor);

                pRouletteChainForward = pRouletteChainForward->m_pForward;
            }while (pRouletteChainForward!= pRouletteChain);
        }
        ia = CleanRouletteChain(&pRouletteChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRouletteChain = %p, &pRouletteChain = %p.", pRouletteChain, &pRouletteChain);
    }



    LogDestory();
}
