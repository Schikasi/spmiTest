#ifndef SIMPLEANSWER_H
#define SIMPLEANSWER_H

#include "BaseClasses/baseanswer.h"
#include <QObject>

class SimpleAnswer : public BaseAnswer
{
    Q_OBJECT
public:
    SimpleAnswer(qint16 id,QString  text, bool is_correct);
protected:
    QString text;
    bool is_correct;

    // BaseAnswer interface
public:
    virtual QString GetText() const override;
    virtual bool IsCorrect() const override;
};

#endif // SIMPLEANSWER_H
