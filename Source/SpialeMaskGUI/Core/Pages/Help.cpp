#include "Help.h"
#include "ui_Help.h"
#include <QString>
#include <QFile>


/*!
 * 帮助类
*/
CHelp::CHelp(QWidget* pParent)
    : QWidget(pParent)
    , m_pGui(new Ui::CHelp)
{
    /*构建*/
    Constructor();
}
CHelp::~CHelp()
{
    /*析构*/
    Deconstructor();
}



/*构建*/
void CHelp::Constructor()
{
    /**/
    {
        m_pGui->setupUi(this);
    }

    /**/

    /*样式*/
    {
        QFile oHelp(QString::fromUtf8(":/Style/Css/Pages/Help.css"));
        if(oHelp.open(QFile::ReadOnly))
        {
            setStyleSheet(QString(oHelp.readAll()));
            oHelp.close();
        }
    }
}
/*析构*/
void CHelp::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}

