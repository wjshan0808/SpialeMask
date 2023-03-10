#pragma once
#ifndef _C_SPIALEMASK_GUI_H_
#define _C_SPIALEMASK_GUI_H_

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class CSpialeMaskGUI;
}
QT_END_NAMESPACE


/*
 * 程序主类
*/
class CSpialeMaskGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CSpialeMaskGUI(QWidget* pParent = nullptr);
    ~CSpialeMaskGUI();


protected Q_SLOTS:
    /*
     * 插件检测事件槽
    */
    void onSpialeMaskChecked();

private:
    /*
     * 插件检测
    */
    void SpialeMaskCheck();
    /*
     * 资源析构
    */
    void Deconstructor();

private:
    /*检测按钮*/
    QPushButton* m_pbtnCheck = nullptr;

private:
    /*UI对象*/
    Ui::CSpialeMaskGUI* m_pUI = nullptr;
};

#endif /* !_C_SPIALEMASK_GUI_H_ */

