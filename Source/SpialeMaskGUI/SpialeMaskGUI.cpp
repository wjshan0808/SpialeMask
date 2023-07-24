#include "SpialeMaskGUI.h"
#include "ui_SpialeMaskGUI.h"

#include "SpialeMask.h"

/*!
 * 程序主类
*/
CSpialeMaskGUI::CSpialeMaskGUI(QWidget* pParent) :
    QWidget(pParent)
    , m_pUI(new Ui::CSpialeMaskGUI)
{
    m_pUI->setupUi(this);

    /*检测插件*/
    SpialeMaskCheck();
}
CSpialeMaskGUI::~CSpialeMaskGUI()
{
    Deconstructor();
}




/*!
 * 插件检测事件槽
*/
void CSpialeMaskGUI::onSpialeMaskChecked()
{
    this->setWindowTitle(QString(" %1 ...").arg(foo(1,2)));
}
/*!
 * 插件检测
*/
void CSpialeMaskGUI::SpialeMaskCheck()
{
    m_pbtnCheck = new QPushButton(this);
    m_pbtnCheck->setText("Check");
    m_pbtnCheck->setGeometry(0, 0, 80, 60);
    connect(m_pbtnCheck, SIGNAL(clicked()), this, SLOT(onSpialeMaskChecked()));

}

/*!
 * 资源析构
*/
void CSpialeMaskGUI::Deconstructor()
{
    /*检测按钮*/
    if(nullptr != m_pbtnCheck)
    {
        delete m_pbtnCheck;
    }
    /*UI对象*/
    if(nullptr != m_pUI)
    {
        delete m_pUI;
    }
}
