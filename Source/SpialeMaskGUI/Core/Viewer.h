#pragma once
#ifndef _C_VIEWER_H_
#define _C_VIEWER_H_

#include <QWidget>
#include <QDockWidget>


/*!
 * 视图界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CViewer;
}
QT_END_NAMESPACE

/*!
 * 视图类
*/
class CViewer : public QDockWidget
{
    Q_OBJECT

public:
    explicit CViewer(QWidget* pParent = nullptr);
    ~CViewer();



public Q_SLOTS:


private:
    /*构建*/
    void Constructor();
    /*析构*/
    void Deconstructor();

private:
    /*UI对象*/
    Ui::CViewer* m_pGui = nullptr;
};

#endif /* !_C_VIEWER_H_ */

