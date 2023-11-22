#include "Help.h"
#include "ui_Help.h"
#include <QString>
#include <QFile>
#include <QStyle>


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



/*!
 * @brief 按钮点击
 * @param bChecked 选中状态
*/
void CHelp::slotButtonClicked(bool bChecked)
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
    /*Info按钮*/
    else if(m_pGui->btnInfo == pBtn)
    {
        Q_EMIT signalHelpMenuClicked(Info);
    }
    /*About按钮*/
    else if(m_pGui->btnAbout == pBtn)
    {
        Q_EMIT signalHelpMenuClicked(About);
    }
    else { }

    /*按钮*/
    {
        QList<QPushButton*> lstButtons = findChildren<QPushButton*>();
        foreach(QPushButton* pItem, lstButtons)
        {
            if(pBtn == pItem)
            {
                pItem->setChecked(true);
            }
            else
            {
                pItem->setChecked(false);
            }
            style()->polish(pItem);
        }
    }
}



/*构建*/
void CHelp::Constructor()
{
    /**/
    {
        m_pGui->setupUi(this);
    }

    /*Info按钮*/
    {
        m_pGui->btnInfo->setCheckable(true);
        m_pGui->btnInfo->setText(QString::fromUtf8("信息"));
        m_pGui->btnInfo->setToolTip(QString::fromUtf8("信息"));
        connect(m_pGui->btnInfo, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    }

    /*B按钮*/
    {
        m_pGui->btnAbout->setCheckable(true);
        m_pGui->btnAbout->setText(QString::fromUtf8("关于"));
        m_pGui->btnAbout->setToolTip(QString::fromUtf8("关于"));
        connect(m_pGui->btnAbout, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    }

    /*默认选中A*/
    {
        QPushButton* pBtn = qobject_cast<QPushButton*>(m_pGui->verticalLayout->itemAt(0x00)->widget());
        if(Q_NULLPTR != pBtn)
        {
            pBtn->setChecked(true);
        }
    }

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

