#include "simpleanswer.h"


SimpleAnswer::SimpleAnswer(qint16 id, QString text, bool is_correct):text(text),is_correct(is_correct)
{
    this->id= id;
}

QString SimpleAnswer::GetText() const
{
    return text;
}

bool SimpleAnswer::IsCorrect() const
{
    return is_correct;
}
