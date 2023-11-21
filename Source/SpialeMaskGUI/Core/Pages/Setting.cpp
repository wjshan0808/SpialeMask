#include "Setting.h"
#include "ui_Setting.h"
#include <QtDebug>
#include <QString>
#include <QFile>
#include <QIcon>
#include <QSize>
#include <QStyle>
#include <QMouseEvent>


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



/*!
 * @brief 按钮点击
 * @param bChecked 选中状态
*/
void CSetting::slotButtonClicked(bool bChecked)
{
    Q_UNUSED(bChecked);

    /*发送者*/
    QToolButton* pBtn = qobject_cast<QToolButton*>(sender());
    if(Q_NULLPTR == pBtn)
    {
        return;
    }

    /**/
    if(false)
    {
    }
    /*A按钮*/
    else if(m_pGui->btnA == pBtn)
    {
        Q_EMIT signalSettingMenuClicked(A);
    }
    /*B按钮*/
    else if(m_pGui->btnB == pBtn)
    {
        Q_EMIT signalSettingMenuClicked(B);
    }
    else { }

    /*按钮*/
    {
        QList<QToolButton*> lstButtons = findChildren<QToolButton*>();
        foreach(QToolButton* pItem, lstButtons)
        {
            if(pBtn == pItem)
            {
                pItem->setChecked(true);
                pItem->setIcon(QIcon(":/Style/Img/light.png"));
            }
            else
            {
                pItem->setChecked(false);
                pItem->setIcon(QIcon(":/Style/Img/gray.png"));
            }
            style()->polish(pItem);
        }
    }
}

/*!
 * 事件过滤
*/
bool CSetting::eventFilter(QObject* pObject, QEvent* pEvent)
{
    /*指定对象内*/
    if(m_pGui->oLeftSettingWidget == pObject->parent())
    {
        /*QToolButton对象*/
        if(pObject->inherits("QToolButton"))
        {
            QToolButton* pBtn = qobject_cast<QToolButton*>(pObject);
            if(QEvent::Leave == pEvent->type())
            {
                if(pBtn->isChecked())
                {
                    pBtn->setIcon(QIcon(":/Style/Img/light.png"));
                }
                else
                {
                    pBtn->setIcon(QIcon(":/Style/Img/gray.png"));
                }
            }
            else if(QEvent::Enter == pEvent->type())
            {
                pBtn->setIcon(QIcon(":/Style/Img/light.png"));
            }
            else { }

            /*事件过滤
            return true;*/
        }
    }

    /*事件延续*/
    return QObject::eventFilter(pObject, pEvent);
}

/*构建*/
void CSetting::Constructor()
{
    /**/
    {
        m_pGui->setupUi(this);
    }

    /*A按钮*/
    {
        m_pGui->btnA->setCheckable(true);
        m_pGui->btnA->setText(QString::fromUtf8("A按钮"));
        m_pGui->btnA->setToolTip(QString::fromUtf8("A"));
        m_pGui->btnA->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pGui->btnA->setIcon(QIcon(":/Style/Img/light.png"));
        m_pGui->btnA->setIconSize(QSize(30, 30));
        m_pGui->btnA->installEventFilter(this);
        connect(m_pGui->btnA, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    }

    /*B按钮*/
    {
        m_pGui->btnB->setCheckable(true);
        m_pGui->btnB->setText(QString::fromUtf8("B按钮"));
        m_pGui->btnB->setToolTip(QString::fromUtf8("B"));
        m_pGui->btnB->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pGui->btnB->setIcon(QIcon(":/Style/Img/gray.png"));
        m_pGui->btnB->setIconSize(QSize(30, 30));
        m_pGui->btnB->installEventFilter(this);
        connect(m_pGui->btnB, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    }

    /*默认选中A*/
    {
        QToolButton* pBtn = qobject_cast<QToolButton*>(m_pGui->verticalLayout->itemAt(0x00)->widget());
        if(Q_NULLPTR != pBtn)
        {
            pBtn->setChecked(true);
        }
    }

    /*样式*/
    {
        QFile oSetting(QString::fromUtf8(":/Style/Css/Pages/Setting.css"));
        if(oSetting.open(QFile::ReadOnly))
        {
            setStyleSheet(QString(oSetting.readAll()));
            oSetting.close();
        }
    }
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

