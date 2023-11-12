#include "Gui.h"


/*!
 * 程序主界面
*/
CGui::CGui(QWidget* pParent)
    : QWidget(pParent)
{
}
CGui::~CGui()
{
}


/*!
 * 窗体最大改变槽
 * @param bMaximized 最大状态
*/
void CGui::slotMaximizedChanged(bool bMaximized)
{
    /*移除移动*/
    if(bMaximized)
    {
        CMovable::Instance()->Remove(&m_oSpialeMaskGUI);
    }
    /*注册移动*/
    else
    {
        CMovable::Instance()->Install(&m_oSpialeMaskGUI);
    }
}

/*!
 * 设置程序界面
*/
void CGui::Setup(int iArg, char* szArg[])
{
    Q_UNUSED(iArg);
    Q_UNUSED(szArg);

    /**/
    {
        connect(&m_oSpialeMaskGUI, &CSpialeMaskGUI::signalMaximizedChanged, this, &CGui::slotMaximizedChanged);
    }

    /*可移动*/
    {
        CMovable::Instance()->Install(&m_oSpialeMaskGUI);
    }

    /*显示*/
    m_oSpialeMaskGUI.show();
}

