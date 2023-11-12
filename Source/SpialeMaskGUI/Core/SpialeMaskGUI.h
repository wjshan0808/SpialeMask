#pragma once
#ifndef _C_SPIALEMASK_GUI_H_
#define _C_SPIALEMASK_GUI_H_

#include "../Core/Pages/Help.h"
#include "../Core/Pages/Setting.h"
#include "../Core/Viewer.h"
#include <QWidget>
#include <QMainWindow>
#include <QResizeEvent>


/*!
 * 程序界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CSpialeMaskGUI;
}
QT_END_NAMESPACE

/*!
 * 程序类
*/
class CSpialeMaskGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSpialeMaskGUI(QWidget* pParent = nullptr);
    ~CSpialeMaskGUI();


Q_SIGNALS:
    /*!
     * 窗体最大改变信号
     * @param bMaximized 最大状态
    */
    void signalMaximizedChanged(bool bMaximized);


protected Q_SLOTS:
    /*!
     * @brief 点击事件槽
     * @param iEvent 事件
    */
    void slotTitleBarClicked(int iEvent);

protected:
    /*!
     * 大小改变事件
    */
    void resizeEvent(QResizeEvent* pEvent) Q_DECL_OVERRIDE;


private:
    /*构建*/
    void Constructor();
    /*析构*/
    void Deconstructor();

private:
    /*设置程序*/
    void setupThis();
    /*设置TrcBar*/
    void setupTrcBar();
    /*设置TitleBar*/
    void setupTitleBar();

private:
    /*设置界面*/
    CSetting m_oSetting;
    /*帮助界面*/
    CHelp m_oHelp;
    /*视图*/
    CViewer m_oViewer;
    /*UI对象*/
    Ui::CSpialeMaskGUI* m_pGui = nullptr;
};

#endif /* !_C_SPIALEMASK_GUI_H_ */

