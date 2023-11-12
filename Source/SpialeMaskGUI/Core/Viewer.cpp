#include "Viewer.h"
#include "ui_Viewer.h"


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

