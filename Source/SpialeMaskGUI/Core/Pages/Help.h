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

