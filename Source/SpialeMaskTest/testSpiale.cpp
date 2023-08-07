
#include "SpialeMask.h"
#include "Core/Spiale.h"

#include <string.h>
#include <stdlib.h>


void testSpiale()
{
    LogRegist(LogArchiveExample);

    Spiale* pSpiale = NULL;
    LOG_INFO("pSpiale = %p, &pSpiale = %p.", pSpiale, &pSpiale);

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = DeleteSpiale(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = DeleteSpiale(&pSpiale);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pSpiale = %p, &pSpiale = %p.", pSpiale, &pSpiale);

    }

    /**/
    LOG_DEBUG("\r\n");
    {
        int ia = NewSpiale(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = NewSpiale(&pSpiale);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pSpiale->m_pCurrent, pSpiale->m_uiCount, pSpiale->m_pAnchor, pSpiale->m_usIdentity);
        LOG_INFO("pSpiale = %p, &pSpiale = %p, *pSpiale = %p.", pSpiale, &pSpiale, *pSpiale);

        ia = DeleteSpiale(&pSpiale);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pSpiale = %p, &pSpiale = %p.", pSpiale, &pSpiale);
    }

    LOG_DEBUG("\r\n");
    {
        int ia = NewSpiale(&pSpiale);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCurrent = %p, %d, pAnchor = %p, %d.", pSpiale->m_pCurrent, pSpiale->m_uiCount, pSpiale->m_pAnchor, pSpiale->m_usIdentity);
        LOG_INFO("pSpiale = %p, &pSpiale = %p, *pSpiale = %p.", pSpiale, &pSpiale, *pSpiale);

        {
            Spiale* pCloneSpiale = NULL;
            ia = CloneSpiale(&pCloneSpiale, pSpiale);
            LOG_INFO("ia = %d.", ia);
            //LOG_INFO("pCloneCurrent = %p, %d, pCloneAnchor = %p, %d.", pCloneSpiale->m_pCurrent, pCloneSpiale->m_uiCount, pCloneSpiale->m_pAnchor, pCloneSpiale->m_usIdentity);
            //LOG_INFO("pCloneSpiale = %p, &pCloneSpiale = %p, *pCloneSpiale = %p.", pCloneSpiale, &pCloneSpiale, *pCloneSpiale);

            ia = DeleteSpiale(&pCloneSpiale);
            LOG_INFO("ia = %d.", ia);
            LOG_INFO("pCloneSpiale = %p, &pCloneSpiale = %p.", pCloneSpiale, &pCloneSpiale);
        }

        ia = DeleteSpiale(&pSpiale);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pSpiale = %p, &pSpiale = %p.", pSpiale, &pSpiale);
    }

    LogDestory();
}
