#ifndef SIMPLETEST_H
#define SIMPLETEST_H

#include <QFile>
#include <QObject>
#include <QVector>
#include <QVariant>
#include <memory>
#include <QXmlStreamReader>

#include <BaseClasses/basequest.h>
#include <BaseClasses/basetest.h>

class XMLTest: public BaseTest
{
    Q_OBJECT
public:
    XMLTest(QFile *XmlFile = nullptr);

    // BaseTest interface
public:
    virtual void Start() override;
    virtual void Complete() override;
    virtual BaseTestReport *GetReport() override;
    virtual const BaseQuest *CurrentQuest() const override;
    virtual qint16 CurrentQuestIndex() const override;
    virtual void SetCurrentQuest(qint16 index) override;
    virtual BaseUserAnswer *GetCurrentUserAnswer() override;
    virtual int GetCountQuests() const override;
private:
    qint16 index = -1;
    QVector<const BaseQuest *> questions;
    QVector<BaseUserAnswer *> userAnswers;
    BaseTestReport *report = nullptr;

    const BaseQuest *ReadQuestion(QXmlStreamReader &reader);
    const BaseAnswer *ReadAnswer(QXmlStreamReader &reader);

};

#endif // SIMPLETEST_H
