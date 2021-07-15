#ifndef ANSWERMAKER_H
#define ANSWERMAKER_H

#include <QObject>
#include <QString>


class BaseAnswer: public QObject
{
    Q_OBJECT
public:
    BaseAnswer(quint16 id = -1);
    virtual quint16 GetID() const;
    virtual QString GetText() const = 0;
    virtual bool IsCorrect() const = 0;
protected:
    quint16 id;
};

#endif // ANSWERMAKER_H
