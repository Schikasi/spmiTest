#ifndef BASETESTREPORT_H
#define BASETESTREPORT_H

#include <QObject>

class BaseTestReport : public QObject
{
    Q_OBJECT
public:
    explicit BaseTestReport(QObject *parent = nullptr);
    virtual void SetCountTrueAnswers(int i) = 0;
    virtual void SetCountAnswers(int i) = 0;

    virtual QString ToPlainText() = 0;

signals:

};

#endif // BASETESTREPORT_H
