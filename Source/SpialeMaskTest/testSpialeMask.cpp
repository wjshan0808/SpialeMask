
#include "SpialeMask.h"
#include "Core/Cog.h"
#include "Core/CogChain.h"
#include "Core/Roulette.h"
#include "Core/RouletteChain.h"
#include "Core/Spiale.h"

#include <string.h>
#include <stdlib.h>


#ifndef _CPP_
#define _CPP_

void printCog(const Cog* pCog)
{
    if(NULL == pCog)
    {
        LOG_FATAL("%s pCog is NULL.", __func__);
    }
    else
    {
        LOG_INFO("pCog =%p, &pCog =%p, *pCog =%p.", pCog, &pCog, *pCog);
        LOG_DEBUG("Identity =%d, IsNullity =%i, Length =%zu, Content =%s."
                  , pCog->m_usIdentity, pCog->m_ucIsNullity, pCog->m_uiLength, pCog->m_szContent);
    }

    LOG_DEBUG("");
}

void printCogChain(const CogChain* pCogChain)
{
    if(NULL == pCogChain)
    {
        LOG_FATAL("%s pCogChain is NULL.", __func__);
    }
    else
    {
        LOG_DEBUG("\t     Cog== pBackword Start ==");

        const CogChain* pBackword = pCogChain;
        do
        {
            LOG_INFO("pBackword =%p, &pBackword =%p, *pBackword =%p.", pBackword, &pBackword, *pBackword);
            printCog(pBackword->m_pCog);

            pBackword = pBackword->m_pBackward;
        } while (pBackword != pCogChain);

        LOG_DEBUG("\t     Cog== pBackword End == pForward Start ==");

        const CogChain* pForward = pCogChain;
        do
        {
            LOG_INFO("pForward =%p, &pForward =%p, *pForward =%p.", pForward, &pForward, *pForward);
            printCog(pForward->m_pCog);

            pForward = pForward->m_pForward;
        } while (pForward != pCogChain);

        LOG_DEBUG("\t     Cog== pForward End ==");
    }

    LOG_DEBUG("");
}

void printRoulette(const Roulette* pRoulette)
{
    if(NULL == pRoulette)
    {
        LOG_FATAL("%s pRoulette is NULL.", __func__);
    }
    else
    {
        LOG_INFO("pRoulette =%p, &pRoulette =%p, *pRoulette =%p.", pRoulette, &pRoulette, *pRoulette);
        LOG_INFO("Identity =%d, IsNullity =%i, Count =%zu."
                  , pRoulette->m_usIdentity, pRoulette->m_ucIsNullity, pRoulette->m_uiCount);

        LOG_INFO("\t  CogChain== Current Start ==.");
        if(NULL == pRoulette->m_pCurrent)
        {
            LOG_ERROR("%s Current is NULL.", __func__);
        }
        else
        {
            printCogChain(pRoulette->m_pCurrent);
        }

        LOG_DEBUG("\t  CogChain== Current End == Anchor Start ==");

        if(NULL == pRoulette->m_pAnchor)
        {
            LOG_ERROR("%s Anchor is NULL.", __func__);
        }
        else
        {
            printCogChain(pRoulette->m_pAnchor);
        }

        LOG_DEBUG("\t  CogChain== Anchor End ==");
    }

    LOG_DEBUG("");
}

void printRouletteChain(const RouletteChain* pRouletteChain)
{
    if(NULL == pRouletteChain)
    {
        LOG_FATAL("%s pRouletteChain is NULL.", __func__);
    }
    else
    {
        LOG_DEBUG("\tRoulette== pBackword Start ==");

        const RouletteChain* pBackword = pRouletteChain;
        do
        {
            LOG_INFO("pBackword =%p, &pBackword =%p, *pBackword =%p.", pBackword, &pBackword, *pBackword);
            printRoulette(pBackword->m_pRoulette);

            pBackword = pBackword->m_pBackward;
        } while (pBackword != pRouletteChain);

        LOG_DEBUG("\tRoulette== pBackword End == pForward Start ==");

        const RouletteChain* pForward = pRouletteChain;
        do
        {
            LOG_INFO("pForward =%p, &pForward =%p, *pForward =%p.", pForward, &pForward, *pForward);
            printRoulette(pForward->m_pRoulette);

            pForward = pForward->m_pForward;
        } while (pForward != pRouletteChain);

        LOG_DEBUG("\tRoulette== pForward End ==");
    }

    LOG_DEBUG("");
}

void printSpiale(const Spiale* pSpiale)
{
    if(NULL == pSpiale)
    {
        LOG_FATAL("%s pSpiale is NULL.", __func__);
    }
    else
    {
        LOG_INFO("pSpiale =%p, &pSpiale =%p, *pSpiale =%p.", pSpiale, &pSpiale, *pSpiale);
        LOG_INFO("Identity =%d, IsNullity =%i, Count =%zu."
                  , pSpiale->m_usIdentity, pSpiale->m_ucIsNullity, pSpiale->m_uiCount);

        LOG_INFO("RouletteChain== Current Start ==.");
        if(NULL == pSpiale->m_pCurrent)
        {
            LOG_ERROR("%s Current is NULL.", __func__);
        }
        else
        {
            printRouletteChain(pSpiale->m_pCurrent);
        }

        LOG_DEBUG("RouletteChain== Current End == Anchor Start ==");

        if(NULL == pSpiale->m_pAnchor)
        {
            LOG_ERROR("%s Anchor is NULL.", __func__);
        }
        else
        {
            printRouletteChain(pSpiale->m_pAnchor);
        }

        LOG_DEBUG("RouletteChain== Anchor End ==");
    }

    LOG_DEBUG("");
}


#endif
