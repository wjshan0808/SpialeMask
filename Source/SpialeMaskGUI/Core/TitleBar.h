#pragma once
#ifndef _C_TITLE_BAR_H_
#define _C_TITLE_BAR_H_

#include <QWidget>
#include <QString>




/*!
 * 标题栏界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CTitleBar;
}
QT_END_NAMESPACE

/*!
 * 标题栏类
*/
class CTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit CTitleBar(QWidget* pParent = nullptr);
    ~CTitleBar();


    /*!
     * @brief 点击事件
    */
    enum ClickEvent : int
    {
        None,
        /*帮助*/
        Help = 0x01,
        /*设置*/
        Setting = 0x02,
    };


Q_SIGNALS:
    /*!
     * @brief 点击事件信号
     * @param iEvent 事件
    */
    void signalTitleBarClicked(int iEvent);


public:
    /*!
     * @brief 设置
     * @param strIcon 图标
     * @param strTitle 标题
    */
    void Setup(const QString& strIcon
               , const QString& strTitle);


protected Q_SLOTS:
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
    Ui::CTitleBar* m_pGui = nullptr;
};

#endif /* !_C_TITLE_BAR_H_ */
