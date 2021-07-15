#ifndef BASEUSERANSWER_H
#define BASEUSERANSWER_H

#include <QObject>

class BaseUserAnswer : public QObject
{
    Q_OBJECT
public:
    explicit BaseUserAnswer(quint16 questId = -1, QObject *parent = nullptr);
    explicit BaseUserAnswer(QObject *parent = nullptr);
    virtual quint16 GetQuestID() const;
    virtual QString GetText() const = 0;
    virtual bool IsCorrect() const = 0;

signals:
};

#endif // BASEUSERANSWER_H
