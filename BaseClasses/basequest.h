#ifndef BASEQUEST_H
#define BASEQUEST_H

#include "baseanswer.h"

#include <QObject>
#include <QString>

class BaseQuest: public QObject
{
    Q_OBJECT
public:
    enum QuestType{
        Error = -1,
        Base = 0,
        OneOfAny = 1
    };    
    Q_ENUM(QuestType);

    virtual quint16 GetID() const;
    virtual QString GetText() const = 0;
    virtual const BaseAnswer *GetAnswer(quint16 num) const  = 0;
    virtual QuestType GetType() const;
protected:
    quint16 id;
};

#endif // BASEQUEST_H
