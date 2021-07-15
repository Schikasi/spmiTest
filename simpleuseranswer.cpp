#include "simpleuseranswer.h"



SimpleUserAnswer::SimpleUserAnswer(const BaseQuest *quest, QObject *obj):BaseUserAnswer(quest->GetID(),obj),quest(quest)
{

}

quint16 SimpleUserAnswer::GetQuestID() const
{
    return quest->GetID();
}

QString SimpleUserAnswer::GetText() const
{
    return selectedAnswer==nullptr?"":selectedAnswer->GetText();
}

bool SimpleUserAnswer::IsCorrect() const
{
    return selectedAnswer==nullptr?false:selectedAnswer->IsCorrect();
}

const BaseAnswer *SimpleUserAnswer::GetSelectedAnswer() const
{
    return selectedAnswer;
}

void SimpleUserAnswer::SetSelectedAnswer(const BaseAnswer *ans)
{
    selectedAnswer = ans;
}
