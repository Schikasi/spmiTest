#include "BaseClasses/basequest.h"

quint16 BaseQuest::GetID() const
{
    return id;
}

BaseQuest::QuestType BaseQuest::GetType() const
{
    return Base;
}
