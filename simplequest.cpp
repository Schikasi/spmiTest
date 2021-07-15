#include "simplequest.h"


SimpleQuest::SimpleQuest(quint16 id, QString &text, QVector<const BaseAnswer*> &answers):text(text),answers(answers)
{
    this->id = id;
}

quint16 SimpleQuest::GetCountAnswers() const
{
    answers.count();
}

BaseQuest::QuestType SimpleQuest::GetType() const
{
    return OneOfAny;
}

QString SimpleQuest::GetText() const
{
    return text;
}

const BaseAnswer *SimpleQuest::GetAnswer(quint16 num) const
{
    if(num>=answers.count()) throw nullptr; // Вставить ошибку!!!
    return answers.at(num);
}
