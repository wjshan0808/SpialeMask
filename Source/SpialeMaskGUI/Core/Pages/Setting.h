#pragma once
#ifndef _C_SETTING_H_
#define _C_SETTING_H_

#include <QWidget>


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

