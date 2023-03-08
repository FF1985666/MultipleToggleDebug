﻿#ifndef MULTIPLETOGGLEDEBUG_H
#define MULTIPLETOGGLEDEBUG_H
#include <QString>
#include <QVariant>
#include <QDebug>

#define debugtoggle MultipleToggleDebug().start()
//#define debugmy Singleton<MyDebug>::Instance()->start()

class MultipleToggleDebug : public QDebug
{
public:

    MultipleToggleDebug() : QDebug(QtDebugMsg), m_shouldStop(false) {} //MyDebug(QtMsgType type) : QDebug(type), m_shouldStop(false) {}

    MultipleToggleDebug& start(){
        step=0;
        //qDebug().noquote()<<"aaa0";
        return *this;
    }
    template<typename T>
    MultipleToggleDebug &operator<<(const T &value)
    {
        //qDebug().noquote()<<"aaa-1";
        QString msg=qvariant_cast<QString>(QVariant(value));
        if(step==0 ){
            if( list.contains(msg))
            {
                m_shouldStop=false;
            }else {
                m_shouldStop=true;
            }
            step=1;
        }

        if (m_shouldStop) {
            //qDebug().noquote()<<"aaa";
            return *this;
        }

        //QDebug::operator<<(value);
        this->noquote()<<value;
        //qDebug().noquote()<<msg;
        return *this;
    }

private:

    QStringList list= QString(
                "1,"
                "2,"
                "3,"
                ).split(",");
    bool m_shouldStop;
    int  step=0;
};
#endif // MULTIPLETOGGLEDEBUG_H