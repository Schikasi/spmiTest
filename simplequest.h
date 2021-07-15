#ifndef SIMPLEQUEST_H
#define SIMPLEQUEST_H

#include <BaseClasses/basequest.h>
#include <QObject>
#include <QVector>

class SimpleQuest : public BaseQuest
{
    Q_OBJECT
public:
    SimpleQuest(quint16 id, QString &text, QVector<const BaseAnswer*> &answers);
    quint16 GetCountAnswers() const;

    // BaseQuest interface
public:
    virtual QuestType GetType() const override;
    virtual QString GetText() const override;
    virtual const BaseAnswer *GetAnswer(quint16 num) const override;
private:
    QString text;
    QVector<const BaseAnswer*> answers;

};

#endif // SIMPLEQUEST_H
