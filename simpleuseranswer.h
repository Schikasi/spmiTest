#ifndef SIMPLEUSERANSWER_H
#define SIMPLEUSERANSWER_H

#include <BaseClasses/baseanswer.h>
#include <BaseClasses/basequest.h>
#include <BaseClasses/baseuseranswer.h>
#include <QObject>
#include <simpleanswer.h>

class SimpleUserAnswer : public BaseUserAnswer
{
    Q_OBJECT
public:
    SimpleUserAnswer(const BaseQuest *quest, QObject *obj = nullptr);


    // BaseUserAnswer interface
public:
    virtual quint16 GetQuestID() const override;
    virtual QString GetText() const override;
    virtual bool IsCorrect() const override;
    const BaseAnswer *GetSelectedAnswer() const;
    void SetSelectedAnswer(const BaseAnswer * ans);
private:
    const BaseQuest *quest = nullptr;
    const BaseAnswer *selectedAnswer = nullptr;
};

#endif // SIMPLEUSERANSWER_H
