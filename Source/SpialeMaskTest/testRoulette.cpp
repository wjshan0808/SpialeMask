
#include "SpialeMask.h"
#include "Core/Roulette.h"

#include <string.h>
#include <stdlib.h>


void testRoulette()
{
    LogRegist(LogArchiveExample);

    Roulette* pRoulette = NULL;
    LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = DeleteRoulette(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    }

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = NewRoulette(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        {
            Roulette* pCloneRoulette = NULL;
            ia = CloneRoulette(&pCloneRoulette, pRoulette);
            LOG_INFO("ia = %d.", ia);
            //LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneRoulette->m_pCurrent, pCloneRoulette->m_uiCount, pCloneRoulette->m_pAnchor, pCloneRoulette->m_usIdentity);
            //LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p, *pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette, *pCloneRoulette);

            ia = DeleteRoulette(&pCloneRoulette);
            LOG_INFO("ia = %d.", ia);
            LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette);
        }

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        {
            char a[] = "a";
            ia = AppendCogChain2Roulette(pRoulette, a);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            const CogChain* pBackword = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                pBackword = pBackword->m_pBackward;
            }
            while (pBackword != pRoulette->m_pAnchor);

            const CogChain* pForward = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                pForward = pForward->m_pForward;
            }
            while (pForward != pRoulette->m_pAnchor);
        }

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    }


    /*2*/
    LOG_DEBUG("\r\n");
    {
        int ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        {
            char a[] = "a";
            ia = AppendCogChain2Roulette(pRoulette, a);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            const CogChain* pBackword = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                pBackword = pBackword->m_pBackward;
            }
            while (pBackword != pRoulette->m_pAnchor);

            const CogChain* pForward = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                pForward = pForward->m_pForward;
            }
            while (pForward != pRoulette->m_pAnchor);

            LOG_DEBUG("\r\n");
            {
                Roulette* pCloneRoulette = NULL;
                ia = CloneRoulette(&pCloneRoulette, pRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneRoulette->m_pCurrent, pCloneRoulette->m_uiCount, pCloneRoulette->m_pAnchor, pCloneRoulette->m_usIdentity);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p, *pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette, *pCloneRoulette);

                {
                    const CogChain* pBackword = pRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                        pBackword = pBackword->m_pBackward;
                    }
                    while (pBackword != pRoulette->m_pAnchor);

                    const CogChain* pForward = pRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                        pForward = pForward->m_pForward;
                    }
                    while (pForward != pRoulette->m_pAnchor);
                }

                ia = DeleteRoulette(&pCloneRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette);
            }
        }

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    }


    /*2*/
    LOG_DEBUG("\r\n");
    Roulette* pCloneRoulette = NULL;
    {
        int ia = CloneRoulette(NULL, NULL);
        LOG_INFO("ia = %d.", ia);

        ia = CloneRoulette(&pCloneRoulette, pRoulette);
        LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette);


        ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        {
            char a[] = "a";
            ia = AppendCogChain2Roulette(pRoulette, a);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            char* b = "b";
            ia = AppendCogChain2Roulette(pRoulette, b);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            const CogChain* pBackword = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                pBackword = pBackword->m_pBackward;
            }
            while (pBackword != pRoulette->m_pAnchor);

            const CogChain* pForward = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                pForward = pForward->m_pForward;
            }
            while (pForward != pRoulette->m_pAnchor);

            LOG_DEBUG("\r\n");
            {
                Roulette* pCloneRoulette = NULL;
                ia = CloneRoulette(&pCloneRoulette, pRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneRoulette->m_pCurrent, pCloneRoulette->m_uiCount, pCloneRoulette->m_pAnchor, pCloneRoulette->m_usIdentity);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p, *pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette, *pCloneRoulette);

                {
                    const CogChain* pBackword = pCloneRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                        pBackword = pBackword->m_pBackward;
                    }
                    while (pBackword != pCloneRoulette->m_pAnchor);

                    const CogChain* pForward = pCloneRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                        pForward = pForward->m_pForward;
                    }
                    while (pForward != pCloneRoulette->m_pAnchor);
                }

                ia = DeleteRoulette(&pCloneRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette);
            }
        }

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    }

    /*3*/
    LOG_DEBUG("\r\n");
    {
        int ia = NewRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);
        LOG_INFO("pRoulette = %p, &pRoulette = %p, *pRoulette = %p.", pRoulette, &pRoulette, *pRoulette);

        {
            char a[] = "a";
            ia = AppendCogChain2Roulette(pRoulette, a);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            char* b = "b";
            ia = AppendCogChain2Roulette(pRoulette, b);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            char* c = "c";
            ia = AppendCogChain2Roulette(pRoulette, c);
            LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pRoulette->m_pCurrent, pRoulette->m_uiCount, pRoulette->m_pAnchor, pRoulette->m_usIdentity);

            const CogChain* pBackword = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                pBackword = pBackword->m_pBackward;
            }
            while (pBackword != pRoulette->m_pAnchor);

            const CogChain* pForward = pRoulette->m_pAnchor;
            do
            {
                LOG_INFO("Forward = %p, %s, Backward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                pForward = pForward->m_pForward;
            }
            while (pForward != pRoulette->m_pAnchor);

            LOG_DEBUG("\r\n");
            {
                Roulette* pCloneRoulette = NULL;
                ia = CloneRoulette(&pCloneRoulette, pRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneRoulette->m_pCurrent, pCloneRoulette->m_uiCount, pCloneRoulette->m_pAnchor, pCloneRoulette->m_usIdentity);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p, *pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette, *pCloneRoulette);

                {
                    char* d = "d";
                    ia = AppendCogChain2Roulette(pCloneRoulette, d);
                    LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneRoulette->m_pCurrent, pCloneRoulette->m_uiCount, pCloneRoulette->m_pAnchor, pCloneRoulette->m_usIdentity);
                }

                {
                    const CogChain* pBackword = pCloneRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward, pBackword->m_pCog->m_usIdentity);
                        pBackword = pBackword->m_pBackward;
                    }
                    while (pBackword != pCloneRoulette->m_pAnchor);

                    const CogChain* pForward = pCloneRoulette->m_pAnchor;
                    do
                    {
                        LOG_INFO("CloneForward = %p, %s, CloneBackward = %p, %d.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward, pForward->m_pCog->m_usIdentity);
                        pForward = pForward->m_pForward;
                    }
                    while (pForward != pCloneRoulette->m_pAnchor);
                }

                ia = DeleteRoulette(&pCloneRoulette);
                LOG_INFO("ia = %d.", ia);
                LOG_INFO("pCloneRoulette = %p, &pCloneRoulette = %p.", pCloneRoulette, &pCloneRoulette);
            }
        }

        ia = DeleteRoulette(&pRoulette);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pRoulette = %p, &pRoulette = %p.", pRoulette, &pRoulette);

    }

    LogDestory();
}
