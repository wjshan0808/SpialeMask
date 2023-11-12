#include "Setting.h"
#include "ui_Setting.h"


/*!
 * 设置类
*/
CSetting::CSetting(QWidget* pParent)
    : QWidget(pParent)
    , m_pGui(new Ui::CSetting)
{
    /*构建*/
    Constructor();
}
CSetting::~CSetting()
{
    /*析构*/
    Deconstructor();
}



/*构建*/
void CSetting::Constructor()
{
    /**/
    m_pGui->setupUi(this);

    /**/

}
/*析构*/
void CSetting::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}

