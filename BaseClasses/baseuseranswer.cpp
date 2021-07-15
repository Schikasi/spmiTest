#include "baseuseranswer.h"

BaseUserAnswer::BaseUserAnswer(quint16 questId, QObject *parent)
{
}

BaseUserAnswer::BaseUserAnswer(QObject *parent) : BaseUserAnswer(-1,parent)
{
}

quint16 BaseUserAnswer::GetQuestID() const
{
    return -1;
}
