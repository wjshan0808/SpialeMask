#pragma once
#ifndef _C_MOVABLE_H_
#define _C_MOVABLE_H_

#include <QObject>
#include <QEvent>
#include <QMap>
#include <QPoint>
#include <QString>


/*!
 * 可移动类
*/
class CMovable : public QObject
{
    Q_OBJECT

public:
    explicit CMovable(QObject* pParent = nullptr);
    ~CMovable();

public:
    /*!
     * 静态对象实例
    */
    static CMovable* Instance();


public:
    /*!
     * 安装对象
    */
    void Install(QObject* pObject);
    /*!
     * 移除对象
    */
    void Remove(QObject* pObject);


protected:
    /*!
     * 事件过滤器
    */
    bool eventFilter(QObject* pObject, QEvent* pEvent) override;


private:
    /*移动性*/
    bool m_bMovable;
    /*偏移点*/
    QPoint m_oOffsetPoint;

private:
    /*可移动对象集合*/
    QMap<QString, QObject*> m_mapMovalbe;

};

#endif /* !_C_MOVABLE_H_ */

