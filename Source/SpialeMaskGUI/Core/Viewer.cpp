#include "Viewer.h"
#include "ui_Viewer.h"
#include <QString>
#include <QFile>


/*!
 * 视图类
*/
CViewer::CViewer(QWidget* pParent)
    : QDockWidget(pParent)
    , m_pGui(new Ui::CViewer)
{
    /*构建*/
    Constructor();
}
CViewer::~CViewer()
{
    /*析构*/
    Deconstructor();
}




/*构建*/
void CViewer::Constructor()
{
    /**/
    m_pGui->setupUi(this);

    /*自定义标题栏
    QWidget* pTitleBarOld = titleBarWidget();
    {
        setTitleBarWidget(new QWidget());
        delete pTitleBarOld;
    }*/


    /*样式*/
    {
        QFile oViewer(QString::fromUtf8(":/Style/Css/Viewer.css"));
        if(oViewer.open(QFile::ReadOnly))
        {
            setStyleSheet(QString(oViewer.readAll()));
            oViewer.close();
        }
    }
}
/*析构*/
void CViewer::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}

