
#include "SpialeMask.h"
#include "Core/Cog.h"

#include <string.h>
#include <stdlib.h>


void testCog()
{
    LogRegist(LogArchiveExample);

    Cog* pCog = NULL;
    LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);

    /**/
    {
        int ia = DeleteCog(NULL);
        LOG_INFO("ia = %d.", ia);

        ia = DeleteCog(&pCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);

    }

    /**/
    {
        char* a  = NULL ;

        int ia = NewCog(NULL, a);
        LOG_INFO("ia = %d.", ia);

        ia = NewCog(&pCog, a);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("ia = %d, %s, %d.", ia, pCog->m_szContent, pCog->m_uiLength);
        LOG_INFO("pCog = %p, &pCog = %p, *pCog = %p.", pCog, &pCog, *pCog);

        ia = DeleteCog(&pCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);
    }
    {
        char* a = "";

        int ia = NewCog(&pCog, a);
        LOG_INFO("ia = %d, %s, %d.", ia, pCog->m_szContent, pCog->m_uiLength);
        LOG_INFO("pCog = %p, &pCog = %p, *pCog = %p.", pCog, &pCog, *pCog);

        ia = DeleteCog(&pCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);
    }

    {
        char* a = "a";

        int ia = NewCog(&pCog, a);
        LOG_INFO("ia = %d, %s, %d.", ia, pCog->m_szContent, pCog->m_uiLength);
        LOG_INFO("pCog = %p, &pCog = %p, *pCog = %p.", pCog, &pCog, *pCog);

        ia = DeleteCog(&pCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);
    }

    {
        char a[] = "abcde";

        int ia = NewCog(&pCog, a);
        LOG_INFO("ia = %d, %s, %d.", ia, pCog->m_szContent, pCog->m_uiLength);
        LOG_INFO("pCog = %p, &pCog = %p, *pCog = %p.", pCog, &pCog, *pCog);

        //ia = DeleteCog(&pCog);
        //LOG_INFO("ia = %d.", ia);
        //LOG_INFO("pCog = %p, &pCog = %p, *pCog = %p.", pCog, &pCog, *pCog);
    }


    Cog* pCloneCog = NULL;

    /**/
    {
        int ia = CloneCog(NULL, NULL);
        LOG_INFO("ia = %d.", ia);

        ia = CloneCog(&pCloneCog, pCog);
        LOG_INFO("ia = %d, %s, %d.", ia, pCloneCog->m_szContent, pCloneCog->m_uiLength);
        LOG_INFO("pCloneCog = %p, &pCloneCog = %p, *pCloneCog = %p.", pCloneCog, &pCloneCog, *pCloneCog);


        char b[] = "abc";

        ia = UpdateCog(pCloneCog, b);
        LOG_INFO("ia = %d, %s, %d.", ia, pCloneCog->m_szContent, pCloneCog->m_uiLength);
        LOG_INFO("pCloneCog = %p, &pCloneCog = %p, *pCloneCog = %p.", pCloneCog, &pCloneCog, *pCloneCog);


        ia = DeleteCog(&pCloneCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCloneCog = %p, &pCloneCog = %p.", pCloneCog, &pCloneCog);

        ia = DeleteCog(&pCog);
        LOG_INFO("ia = %d.", ia);
        LOG_INFO("pCog = %p, &pCog = %p.", pCog, &pCog);
    }

    LogDestory();
}
