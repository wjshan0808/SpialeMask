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


public:
    /*!
     * 设置程序界面
    */
    void Setup(int iArg, char* szArg[]);


private:
    /*程序主界面*/
    CSpialeMaskGUI m_oSpialeMaskGUI;

};

#endif /* !_C_GUI_H_ */

