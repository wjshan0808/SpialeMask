#include "SpialeMaskGUI.h"
#include "ui_SpialeMaskGUI.h"
#include <QDebug>


/*!
 * 程序类
*/
CSpialeMaskGUI::CSpialeMaskGUI(QWidget* pParent)
    : QMainWindow(pParent)
    , m_pGui(new Ui::CSpialeMaskGUI)
{
    /*构建*/
    Constructor();
}
CSpialeMaskGUI::~CSpialeMaskGUI()
{
    /*析构*/
    Deconstructor();
}






/*!
 * @brief 点击事件槽
 * @param iEvent 事件
*/
void CSpialeMaskGUI::slotTitleBarClicked(int iEvent)
{
    CTitleBar::ClickEvent enEvent = (CTitleBar::ClickEvent)iEvent;


    if(false)
    {
    }
    /*配置界面*/
    else if(CTitleBar::Setting == enEvent)
    {
        m_pGui->oStackedWidget->setCurrentWidget(&m_oSetting);
    }
    /*帮助界面*/
    else if(CTitleBar::Help == enEvent)
    {
        m_pGui->oStackedWidget->setCurrentWidget(&m_oHelp);
    }
    else { }
}
/*!
 * 大小改变事件
*/
void CSpialeMaskGUI::resizeEvent(QResizeEvent* pEvent)
{
    Q_UNUSED(pEvent);

    /**/
    Q_EMIT signalMaximizedChanged(Qt::WindowMaximized == windowState());
}


/*设置TitleBar*/
void CSpialeMaskGUI::setupTitleBar()
{
    connect(m_pGui->oTitleBar, SIGNAL(signalTitleBarClicked(int)), this, SLOT(slotTitleBarClicked(int)));
    m_pGui->oTitleBar->Setup(QString::fromUtf8(":/Style/FontAwesome.ico")
                             , QString::fromUtf8("Spiale Mask"));
}
/*设置TrcBar*/
void CSpialeMaskGUI::setupTrcBar()
{
    m_pGui->oTrcBar->Setup(this);
}
/*设置程序*/
void CSpialeMaskGUI::setupThis()
{
    /*界面*/
    {
        m_pGui->setupUi(this);
        m_pGui->oStackedWidget->addWidget(&m_oSetting);
        m_pGui->oStackedWidget->addWidget(&m_oHelp);
        m_pGui->oStackedWidget->setCurrentIndex(0x00);
    }

    /*无边框标识*/
    {
        setWindowFlags(Qt::FramelessWindowHint);
    }

    /*底部视图*/
    {
        addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, &m_oViewer);
    }
}

/*构建*/
void CSpialeMaskGUI::Constructor()
{
    /*设置程序*/
    setupThis();
    /*设置TrcBar*/
    setupTrcBar();
    /*设置TitleBar*/
    setupTitleBar();
}
/*析构*/
void CSpialeMaskGUI::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}

