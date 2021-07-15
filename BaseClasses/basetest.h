#ifndef BASETEST_H
#define BASETEST_H

#include "basequest.h"
#include "basetestreport.h"
#include "baseuseranswer.h"

#include <QObject>

class BaseTest : public QObject
{
    Q_OBJECT
public:
    explicit BaseTest(QObject *parent = nullptr);
    virtual void Start();
    virtual void Complete();

    virtual BaseTestReport *GetReport() = 0;
    virtual const BaseQuest *CurrentQuest() const = 0;
    virtual qint16 CurrentQuestIndex() const = 0;
    virtual void SetCurrentQuest(qint16 index);
    virtual BaseUserAnswer *GetCurrentUserAnswer() = 0;
    virtual int GetCountQuests() const = 0;

signals:
    void TestStarted();
    void CurrentQuestChanged(quint16);
    void TestCompleted();
};

#endif // BASETEST_H
