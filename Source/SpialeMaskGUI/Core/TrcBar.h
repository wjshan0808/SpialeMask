#pragma once
#ifndef _C_TRC_BAR_H_
#define _C_TRC_BAR_H_

#include <QWidget>


/*!
 * TopRightCorner栏界面类
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class CTrcBar;
}
QT_END_NAMESPACE

/*!
 * TopRightCorner栏类
*/
class CTrcBar : public QWidget
{
    Q_OBJECT

public:
    explicit CTrcBar(QWidget* pParent = nullptr);
    ~CTrcBar();



public:
    /*!
     * @brief 设置
     * @param pOperator 操作对象
    */
    void Setup(QWidget* pOperator);


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
    /*操作对象*/
    QWidget* m_pOperator = nullptr;
    /*UI对象*/
    Ui::CTrcBar* m_pGui = nullptr;
};

#endif /* !_C_TRC_BAR_H_ */
