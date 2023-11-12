#include "TitleBar.h"
#include "ui_TitleBar.h"
#include <QDebug>
#include <QStyle>
#include <QIcon>
#include <QPixmap>
#include <QSize>


/*!
 * 标题栏类
*/
CTitleBar::CTitleBar(QWidget* pParent)
    : QWidget(pParent)
    , m_pGui(new Ui::CTitleBar)
{
    /*构建*/
    Constructor();
}
CTitleBar::~CTitleBar()
{
    /*析构*/
    Deconstructor();
}




/*!
 * @brief 设置
 * @param strIcon 图标
 * @param strTitle 标题
*/
void CTitleBar::Setup(const QString& strIcon
                      , const QString& strTitle)
{
    /*图标设置*/
    {
        QIcon oIcon(strIcon);
        m_pGui->lblIcon->setPixmap(oIcon.pixmap(oIcon.actualSize(QSize(0x18, 0x18))));
        //m_pGui->lblIcon->setPixmap(QPixmap(strIcon));
    }

    /*标题设置*/
    {
        m_pGui->lblTitle->setText(strTitle);
    }
}


/*!
 * @brief 按钮点击
 * @param bChecked 选中状态
*/
void CTitleBar::slotButtonClicked(bool bChecked)
{
    Q_UNUSED(bChecked);

    /*发送者*/
    const QPushButton* pBtn = qobject_cast<const QPushButton*>(sender());
    if(Q_NULLPTR == pBtn)
    {
        return;
    }

    /**/
    if(false)
    {
    }
    /*配置按钮*/
    else if(m_pGui->btnSetting == pBtn)
    {
        Q_EMIT signalTitleBarClicked(Setting);
    }
    /*帮助按钮*/
    else if(m_pGui->btnHelp == pBtn)
    {
        Q_EMIT signalTitleBarClicked(Help);
    }
    else { }
}



/*构建*/
void CTitleBar::Constructor()
{
    /**/
    m_pGui->setupUi(this);

    /*配置按钮*/
    {
        m_pGui->btnSetting->setText(QString::fromUtf8("配置"));
        m_pGui->btnSetting->setToolTip(QString::fromUtf8("配置"));
        //m_pGui->btnSetting->setIcon(qApp->style()->standardIcon(QStyle::));
        connect(m_pGui->btnSetting, &QPushButton::clicked, this, &CTitleBar::slotButtonClicked);
    }

    /*帮助按钮*/
    {
        m_pGui->btnHelp->setText(QString::fromUtf8(""));
        m_pGui->btnHelp->setToolTip(QString::fromUtf8("帮助"));
        m_pGui->btnHelp->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarContextHelpButton));
        connect(m_pGui->btnHelp, &QPushButton::clicked, this, &CTitleBar::slotButtonClicked);
    }

}
/*析构*/
void CTitleBar::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}

