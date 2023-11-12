#pragma once
#ifndef _C_GUI_H_
#define _C_GUI_H_


#include "Kit/Movable.h"
#include "../Core/SpialeMaskGUI.h"
#include <QWidget>



/*!
 * 程序界面
*/
class CGui : public QWidget
{
    Q_OBJECT

public:
    explicit CGui(QWidget* pParent = nullptr);
    ~CGui();


public Q_SLOTS:
    /*!
     * 窗体最大改变槽
     * @param bMaximized 最大状态
    */
    void slotMaximizedChanged(bool bMaximized);

public:
    /*!
     * 设置程序界面
    */
    void Setup(int iArg, char* szArg[]);


private:
    /*程序界面*/
    CSpialeMaskGUI m_oSpialeMaskGUI;

};

#endif /* !_C_GUI_H_ */

