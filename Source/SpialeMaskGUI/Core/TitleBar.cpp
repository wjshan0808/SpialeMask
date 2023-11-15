#include "TitleBar.h"
#include "ui_TitleBar.h"
#include <QDebug>
#include <QStyle>
#include <QIcon>
#include <QPixmap>
#include <QSize>
#include <QFile>
#include <QList>
#include <QPushButton>


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
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
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

    /*按钮*/
    {
        QList<QPushButton*> lstButtons = findChildren<QPushButton*>();
        foreach(QPushButton* pItem, lstButtons)
        {
            pItem->setChecked(false);
        }
        pBtn->setChecked(true);
    }
}



/*构建*/
void CTitleBar::Constructor()
{
    /**/
    m_pGui->setupUi(this);

    /*配置按钮*/
    {
        m_pGui->btnSetting->setFlat(true);
        m_pGui->btnSetting->setCheckable(true);
        m_pGui->btnSetting->setText(QString::fromUtf8("配置"));
        m_pGui->btnSetting->setToolTip(QString::fromUtf8("配置"));
        connect(m_pGui->btnSetting, &QPushButton::clicked, this, &CTitleBar::slotButtonClicked);
    }

    /*帮助按钮*/
    {
        m_pGui->btnHelp->setFlat(true);
        m_pGui->btnHelp->setCheckable(true);
        m_pGui->btnHelp->setText(QString::fromUtf8("帮助"));
        m_pGui->btnHelp->setToolTip(QString::fromUtf8("帮助"));
        /*m_pGui->btnHelp->setIcon(qApp->style()->standardIcon(QStyle::));*/
        connect(m_pGui->btnHelp, &QPushButton::clicked, this, &CTitleBar::slotButtonClicked);
    }

    /*默认选中*/
    {
        QPushButton* pBtn = qobject_cast<QPushButton*>(m_pGui->horizontalLayout->itemAt(0x02)->widget());
        if(Q_NULLPTR != pBtn)
        {
            pBtn->setChecked(true);
        }
    }

    /*样式*/
    {
        QFile oTitleBar(QString::fromUtf8(":/Style/Css/TitleBar.css"));
        if(oTitleBar.open(QFile::ReadOnly))
        {
            setStyleSheet(QString(oTitleBar.readAll()));
            oTitleBar.close();
        }
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

