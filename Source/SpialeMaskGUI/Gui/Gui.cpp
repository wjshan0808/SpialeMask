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
 * 设置程序界面
*/
void CGui::Setup(int iArg, char* szArg[])
{
    Q_UNUSED(iArg);
    Q_UNUSED(szArg);


    /*可移动*/
    {
        CMovable::Instance()->Install(&m_oSpialeMaskGUI);
    }

    /*无边框标识*/
    {
        m_oSpialeMaskGUI.setWindowFlags(Qt::FramelessWindowHint);
    }

    /*显示*/
    m_oSpialeMaskGUI.show();
}

