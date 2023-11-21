#pragma once
#ifndef _C_SETTING_H_
#define _C_SETTING_H_

#include <QWidget>
#include <QObject>
#include <QEvent>


/*!
 * 设置界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CSetting;
}
QT_END_NAMESPACE

/*!
 * 设置类
*/
class CSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CSetting(QWidget* pParent = nullptr);
    ~CSetting();    

    /*!
     * @brief 菜单事件
    */
    enum MenuEvent : int
    {
        None,
        /*帮助*/
        A = 0x01,
        /*设置*/
        B = 0x02,
    };

Q_SIGNALS:
    /*!
     * @brief 菜单事件信号
     * @param iEvent 事件
    */
    void signalSettingMenuClicked(int iEvent);


public Q_SLOTS:
    /*!
     * @brief 按钮点击
     * @param bChecked 选中状态
    */
    void slotButtonClicked(bool bChecked);

protected:
    /*!
     * 事件过滤
    */
    bool eventFilter(QObject* pObject, QEvent* pEvent) Q_DECL_OVERRIDE;

private:
    /*构建*/
    void Constructor();
    /*析构*/
    void Deconstructor();

private:
    /*UI对象*/
    Ui::CSetting* m_pGui = nullptr;
};

#endif /* !_C_SETTING_H_ */

