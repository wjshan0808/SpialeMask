
#include "SpialeMask.h"
#include "Core/CogChain.h"

#include <string.h>
#include <stdlib.h>


void testCogChain()
{
    LogRegist(LogArchiveExample);

    CogChain* pCogChain = NULL;
    LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = DeleteCogChain(NULL);
        LOG_INFO("ia = %d.", ia);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = DeleteCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);

    }

    /**/
    LOG_DEBUG("\r\n");
    {
        char* a  = "a";

        int ia = NewCogChain(NULL, a);
        LOG_INFO("ia = %d.", ia);

        ia = NewCogChain(&pCogChain, a);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = DeleteCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }

    LOG_DEBUG("\r\n");
    {
        char* a = "b";

        int ia = NewCogChain(&pCogChain, a);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = CleanCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }

    LOG_DEBUG("\r\n");
    {
        char* a = "c";

        int ia = NewCogChain(&pCogChain, a);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        {
            CogChain* pCloneCogChain = NULL;

            ia = CloneCogChain(&pCloneCogChain, pCogChain);
            LOG_INFO("Forward = %p, %s, Backward = %p.", pCloneCogChain->m_pForward, pCloneCogChain->m_pCog->m_szContent, pCloneCogChain->m_pBackward);
            LOG_INFO("pCloneCogChain = %p, &pCloneCogChain = %p, *pCloneCogChain = %p.", pCloneCogChain, &pCloneCogChain, *pCloneCogChain);

            uiCount = 0x00;
            CountCogChain(pCloneCogChain, &uiCount);
            LOG_INFO("Count = %zu.", uiCount);

            ia = CleanCogChain(&pCloneCogChain);
            LOG_INFO("ia = %d.", ia);
            LOG_INFO("pCloneCogChain = %p, &pCloneCogChain = %p.", pCloneCogChain, &pCloneCogChain);

        }

        ia = DeleteCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }

    LOG_DEBUG("\r\n");
    {
        char a[] = "d";

        int ia = NewCogChain(&pCogChain, a);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        char e[] = "e";

        CogChain* peCogChain = NULL;
         ia = NewCogChain(&peCogChain, e);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *peCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        InsertCogChain(pCogChain, peCogChain);

        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        const CogChain* pBackword = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %s, Backward = %p.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward);
            pBackword = pBackword->m_pBackward;
        }
        while (pBackword != pCogChain);
        const CogChain* pForward = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %s, Backward = %p.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward);
            pForward = pForward->m_pForward;
        }
        while (pForward != pCogChain);

        ia = CleanCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }


    /*2*/
    LOG_DEBUG("\r\n");
    {
        char a[] = "dd";

        int ia = NewCogChain(&pCogChain, a);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);


        CogChain* peCogChain = NULL;
         ia = CloneCogChain(&peCogChain, pCogChain);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *epCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        InsertCogChain(pCogChain, peCogChain);

        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        const CogChain* pBackword = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %s, Backward = %p.", pBackword->m_pForward, pBackword->m_pCog->m_szContent, pBackword->m_pBackward);
            pBackword = pBackword->m_pBackward;
        }
        while (pBackword != pCogChain);
        const CogChain* pForward = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %s, Backward = %p.", pForward->m_pForward, pForward->m_pCog->m_szContent, pForward->m_pBackward);
            pForward = pForward->m_pForward;
        }
        while (pForward != pCogChain);

        ia = CleanCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }


    /*2*/
    LOG_DEBUG("\r\n");
    CogChain* pCloneCogChain = NULL;
    {
        int ia = CloneCogChain(NULL, NULL);
        LOG_INFO("ia = %d.", ia);

        ia = CloneCogChain(&pCloneCogChain, pCogChain);
        LOG_INFO("pCloneCogChain = %p, &pCloneCogChain = %p.", pCloneCogChain, &pCloneCogChain);


        char f[] = "f";
        ia = NewCogChain(&pCogChain, f);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        CogChain* peCogChain = NULL;
         ia = CloneCogChain(&peCogChain, pCogChain);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *peCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        InsertCogChain(pCogChain, peCogChain);

        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        ia = CloneCogChain(&peCogChain, pCogChain);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *peCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        {
            CogChain* pForward = pCogChain->m_pForward;

            pCogChain->m_pForward->m_pBackward = peCogChain;
            pCogChain->m_pForward = peCogChain->m_pForward;

            peCogChain->m_pForward->m_pBackward = pCogChain;
            peCogChain->m_pForward = pForward;
        }


        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        const CogChain* pBackword = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %d, Backward = %p.", pBackword->m_pForward, pBackword->m_pCog->m_usIdentity, pBackword->m_pBackward);
            pBackword = pBackword->m_pBackward;
        }
        while (pBackword != pCogChain);
        const CogChain* pForward = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %d, Backward = %p.", pForward->m_pForward, pForward->m_pCog->m_usIdentity, pForward->m_pBackward);
            pForward = pForward->m_pForward;
        }
        while (pForward != pCogChain);

        ia = CleanCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }

    /*3*/
    LOG_DEBUG("\r\n");
    {

        char f[] = "f";
        int ia = NewCogChain(&pCogChain, f);
        LOG_INFO("Forward = %p, %s, Backward = %p.", pCogChain->m_pForward, pCogChain->m_pCog->m_szContent, pCogChain->m_pBackward);
        LOG_INFO("pCogChain = %p, &pCogChain = %p, *pCogChain = %p.", pCogChain, &pCogChain, *pCogChain);

        size_t uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        CogChain* peCogChain = NULL;
         ia = CloneCogChain(&peCogChain, pCogChain);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *peCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        InsertCogChain(pCogChain, peCogChain);

        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        {
            char f2[] = "f2";

            CogChain* pnCogChain = NULL;
             ia = NewCogChain(&pnCogChain, f2);
            LOG_INFO("Forward = %p, %s, Backward = %p.", pnCogChain->m_pForward, pnCogChain->m_pCog->m_szContent, pnCogChain->m_pBackward);
            LOG_INFO("pnCogChain = %p, &pnCogChain = %p, *pnCogChain = %p.", pnCogChain, &pnCogChain, *pnCogChain);

            InsertCogChain(pCogChain, pnCogChain);

            uiCount = 0x00;
            CountCogChain(pCogChain, &uiCount);
            LOG_INFO("Count = %zu.", uiCount);
        }

        ia = CloneCogChain(&peCogChain, pCogChain);
        LOG_INFO("Forward = %p, %s, Backward = %p.", peCogChain->m_pForward, peCogChain->m_pCog->m_szContent, peCogChain->m_pBackward);
        LOG_INFO("peCogChain = %p, &peCogChain = %p, *pCogChain = %p.", peCogChain, &peCogChain, *peCogChain);

        JoinCogChain(pCogChain, peCogChain);

        uiCount = 0x00;
        CountCogChain(pCogChain, &uiCount);
        LOG_INFO("Count = %zu.", uiCount);

        const CogChain* pBackword = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %d, Backward = %p.", pBackword->m_pForward, pBackword->m_pCog->m_usIdentity, pBackword->m_pBackward);
            pBackword = pBackword->m_pBackward;
        }
        while (pBackword != pCogChain);
        const CogChain* pForward = pCogChain;
        do
        {
            LOG_INFO("Forward = %p, %d, Backward = %p.", pForward->m_pForward, pForward->m_pCog->m_usIdentity, pForward->m_pBackward);
            pForward = pForward->m_pForward;
        }
        while (pForward != pCogChain);

        ia = CleanCogChain(&pCogChain);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCogChain = %p, &pCogChain = %p.", pCogChain, &pCogChain);
    }

    LogDestory();
}
