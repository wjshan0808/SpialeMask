#include "Movable.h"
#include <QMouseEvent>


/*!
 * 全局静态对象Movable
*/
Q_GLOBAL_STATIC_WITH_ARGS(CMovable, Singleton, (Q_NULLPTR));

/*!
 * 可移动类
*/
CMovable::CMovable(QObject* pParent)
    : QObject(pParent)
    //
    , m_bMovable(false)
{
}
CMovable::~CMovable()
{
}

/*!
 * 静态对象实例
*/
CMovable* CMovable::Instance()
{
    return Singleton();
}


/*!
 * 安装
 * @param pObject 移动对象
*/
void CMovable::Install(QObject* pObject)
{
    /*检测NULL*/
    if(Q_NULLPTR == pObject)
    {
        return;
    }

    /*对象已安装*/
    if(m_mapMovalbe.contains(pObject->objectName()))
    {
        return;
    }

    /*安装对象*/
    {
        m_mapMovalbe.insert(pObject->objectName(), pObject);
        pObject->installEventFilter(this);
    }
}
/*!
 * 移除
 * @param pObject 移动对象
*/
void CMovable::Remove(QObject* pObject)
{
    /*检测NULL*/
    if(Q_NULLPTR == pObject)
    {
        return;
    }

    /*对象未安装*/
    if(!m_mapMovalbe.contains(pObject->objectName()))
    {
        return;
    }

    /*移除对象*/
    {
        pObject->removeEventFilter(this);
        m_mapMovalbe.remove(pObject->objectName());
    }
}


/*!
 * 事件过滤
*/
bool CMovable::eventFilter(QObject* pObject, QEvent* pEvent)
{
    /*鼠标事件*/
    QMouseEvent* pMouseEvent = dynamic_cast<QMouseEvent*>(pEvent);
    if(Q_NULLPTR == pMouseEvent)
    {
        return QObject::eventFilter(pObject, pEvent);
    }

    /*对象已安装*/
    if(m_mapMovalbe.contains(pObject->objectName()))
    {
        if(QEvent::MouseMove == pMouseEvent->type())
        {
            /*移动对象*/
            if(m_bMovable)
            {
                pObject->setProperty("pos", pMouseEvent->globalPos() - m_oOffsetPoint);
            }
        }
        else if(QEvent::MouseButtonPress == pMouseEvent->type())
        {
            /*获取偏移点*/
            if(Qt::LeftButton == (pMouseEvent->buttons() & Qt::LeftButton))
            {
                m_bMovable = true;
                m_oOffsetPoint = pMouseEvent->globalPos() - pObject->property("pos").toPoint();
            }
        }
        else if(QEvent::MouseButtonRelease == pMouseEvent->type())
        {
            m_bMovable = false;
        }
        else { }

        /*事件过滤*/
        return true;
    }

    /*事件延续*/
    return QObject::eventFilter(pObject, pEvent);
}


