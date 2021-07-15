#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include "simpletestview.h"
#include "simplenavigateview.h"

#include <QTextStream>
#include <qfile.h>
#include <textedit.h>
#include <QDebug>
#include <QLabel>
#include <Qt>
#include <QSizePolicy>

#include <Testing/question.h>

#include <Widgets/oneofwidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f("f.xml");
    f.open(QIODevice::ReadOnly);
    test = new XMLTest(&f);

    auto p = new SimpleTestView(test,this);
    ui->verticalLayout->addWidget(p);
    p->ShowPreview();


//    ui->horizontalLayout->setAlignment(Qt::AlignCenter);
//    test->Start();
//    ui->horizontalLayout->insertWidget(0,new OneOfWidget(this,test->CurrentQuest()));
//    QPushButton * startTestButton =  new QPushButton("Начать тест");
//    startTestButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
//            ui->verticalLayout->addWidget(startTestButton);
//            ui->verticalLayout->setAlignment(startTestButton,Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
