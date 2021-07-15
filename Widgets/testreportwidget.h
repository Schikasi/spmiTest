#ifndef TESTREPORTWIDGET_H
#define TESTREPORTWIDGET_H

#include <QWidget>
#include <simpletestreport.h>

namespace Ui {
class TestReportWidget;
}

class TestReportWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestReportWidget(QWidget *parent = nullptr);
    ~TestReportWidget();

    void SetReport(BaseTestReport* report);
    void ShowReport();
private:
    Ui::TestReportWidget *ui;
    SimpleTestReport *report;
};

#endif // TESTREPORTWIDGET_H
