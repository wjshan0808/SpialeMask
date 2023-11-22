#pragma once
#ifndef _C_HELP_H_
#define _C_HELP_H_

#include <QWidget>


/*!
 * 帮助界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CHelp;
}
QT_END_NAMESPACE

/*!
 * 帮助类
*/
class CHelp : public QWidget
{
    Q_OBJECT

public:
    explicit CHelp(QWidget* pParent = nullptr);
    ~CHelp();

    /*!
     * @brief 菜单事件
    */
    enum MenuEvent : int
    {
        None,
        /*信息*/
        Info = 0x01,
        /*关于*/
        About = 0x02,
    };

Q_SIGNALS:
    /*!
     * @brief 菜单事件信号
     * @param iEvent 事件
    */
    void signalHelpMenuClicked(int iEvent);


public Q_SLOTS:
    /*!
     * @brief 按钮点击
     * @param bChecked 选中状态
    */
    void slotButtonClicked(bool bChecked);


private:
    /*构建*/
    void Constructor();
    /*析构*/
    void Deconstructor();

private:
    /*UI对象*/
    Ui::CHelp* m_pGui = nullptr;
};

#endif /* !_C_HELP_H_ */

