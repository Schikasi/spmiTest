#include "testreportwidget.h"
#include "ui_testreportwidget.h"

#include <QLabel>

TestReportWidget::TestReportWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestReportWidget)
{
    ui->setupUi(this);
}

TestReportWidget::~TestReportWidget()
{
    delete ui;
}

void TestReportWidget::SetReport(BaseTestReport *report)
{
    this->report = dynamic_cast<SimpleTestReport*>(report);
}

void TestReportWidget::ShowReport(){
    QLabel* label = new QLabel(this);
    label->setWordWrap(true);
    label->setText(report->ToPlainText());
    label->setAlignment(Qt::AlignCenter);
    ui->verticalLayout->addWidget(label,0,Qt::AlignCenter);
}
