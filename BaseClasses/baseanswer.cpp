#include "baseanswer.h"

BaseAnswer::BaseAnswer(quint16 id):id(id)
{
}

quint16 BaseAnswer::GetID() const
{
    return id;
}

