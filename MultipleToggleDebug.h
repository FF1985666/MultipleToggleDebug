


//Multiple toggle switches for QDebug.

#ifndef MULTIPLETOGGLEDEBUG_H
#define MULTIPLETOGGLEDEBUG_H
#include <QString>
#include <QVariant>
#include <QDebug>


#define DEBUG_POS QString("_________________________FUN: ") + __FUNCTION__ + " LINE: " + QString::number(__LINE__)

#define TOGGLE_BLACKLIST \
"loadData," \
//"debugtoolboxcode,"


#define dbg MultipleToggleDebug2().start()<<DEBUG_POS

class MultipleToggleDebug2
{
public:
    MultipleToggleDebug2(){
    }
    MultipleToggleDebug2& start(){
        step=0;
        codePos="";
        return *this;
    }
    template<typename T>
    MultipleToggleDebug2 &operator<<(const T &value)
    {
        QString msg=qvariant_cast<QString>(QVariant(value));
        if(step==0){
          codePos=msg;
          step+=1;
          return *this;
        }
        if(step==1 ){
            if( list.contains(msg))
            {
                m_shouldStop=true;
            }else {
                m_shouldStop=false;
            }
        }
        step+=1;

        if (m_shouldStop) {
            return *this;
        }
        if(step==2){
            qDebug().noquote()<< "\033[31m"+QVariant( value).toString() +"\033[0m "+ codePos+"";
        }else{
            qDebug().noquote()<<value;
        }
        return *this;
    }

private:

    QStringList list= QString(
                TOGGLE_BLACKLIST
                ).split(",");
    bool m_shouldStop;
    int  step=0;
    QString codePos="";
};

#endif // MULTIPLETOGGLEDEBUG_H
