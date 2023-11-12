#include "TrcBar.h"
#include "ui_TrcBar.h"
#include <QDebug>
#include <QStyle>
#include <QString>


/*!
 * TopRightCorner栏类
*/
CTrcBar::CTrcBar(QWidget* pParent)
    : QWidget(pParent)
    , m_pGui(new Ui::CTrcBar)
{
    /*构建*/
    Constructor();
}
CTrcBar::~CTrcBar()
{
    /*析构*/
    Deconstructor();
}



/*!
 * @brief 设置
 * @param pOperator 操作对象
*/
void CTrcBar::Setup(QWidget* pOperator)
{
    m_pOperator = pOperator;
}


/*!
 * @brief 按钮点击
 * @param bChecked 选中状态
*/
void CTrcBar::slotButtonClicked(bool bChecked)
{
    Q_UNUSED(bChecked);

    /*发送者*/
    const QPushButton* pBtn = qobject_cast<const QPushButton*>(sender());
    if(Q_NULLPTR == pBtn)
    {
        return;
    }

    /*执行者*/
    if(Q_NULLPTR == m_pOperator)
    {
        return;
    }

    /*最小化按钮*/
    if(m_pGui->btnMin == pBtn)
    {
        m_pOperator->showMinimized();
    }
    /*最大化按钮*/
    else if(m_pGui->btnMax == pBtn)
    {
        /*已正常状态*/
        if(Qt::WindowNoState == m_pOperator->windowState())
        {
            m_pGui->btnMax->setToolTip(QString::fromUtf8("正常化"));
            m_pGui->btnMax->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarNormalButton));
            m_pOperator->showMaximized();
        }
        /*已最大状态*/
        else if(Qt::WindowMaximized == m_pOperator->windowState())
        {
            m_pGui->btnMax->setToolTip(QString::fromUtf8("最大化"));
            m_pGui->btnMax->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarMaxButton));
            m_pOperator->showNormal();
        }
        else { }
    }
    /*关闭按钮*/
    else if(m_pGui->btnClose == pBtn)
    {
        m_pOperator->close();
    }
    else { }
}


/*构建*/
void CTrcBar::Constructor()
{
    /**/
    m_pGui->setupUi(this);

    /*最小化按钮*/
    {
        m_pGui->btnMin->setText(QString::fromUtf8(""));
        m_pGui->btnMin->setToolTip(QString::fromUtf8("最小化"));
        m_pGui->btnMin->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarMinButton));
        connect(m_pGui->btnMin, &QPushButton::clicked, this, &CTrcBar::slotButtonClicked);
    }
    /*最大化按钮*/
    {
        m_pGui->btnMax->setText(QString::fromUtf8(""));
        m_pGui->btnMax->setToolTip(QString::fromUtf8("最大化"));
        m_pGui->btnMax->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarMaxButton));
        connect(m_pGui->btnMax, &QPushButton::clicked, this, &CTrcBar::slotButtonClicked);
    }
    /*关闭按钮*/
    {
        m_pGui->btnClose->setText(QString::fromUtf8(""));
        m_pGui->btnClose->setToolTip(QString::fromUtf8("关闭"));
        m_pGui->btnClose->setIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarCloseButton));
        connect(m_pGui->btnClose, &QPushButton::clicked, this, &CTrcBar::slotButtonClicked);
    }

}
/*析构*/
void CTrcBar::Deconstructor()
{

    /*UI对象*/
    if(nullptr != m_pGui)
    {
        delete m_pGui;
    }
}


