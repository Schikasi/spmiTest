#ifndef SIMPLETESTREPORT_H
#define SIMPLETESTREPORT_H

#include "BaseClasses/basetestreport.h"
#include <QObject>

class SimpleTestReport : public BaseTestReport
{
    Q_OBJECT
public:
    SimpleTestReport();
    // BaseTestReport interface
public:
    virtual QString ToPlainText() override;
    virtual void SetCountTrueAnswers(int i)override;
    virtual void SetCountAnswers(int i)override;
private:
    int countTrueAnswers;
    int countAnswers;
};

#endif // SIMPLETESTREPORT_H
