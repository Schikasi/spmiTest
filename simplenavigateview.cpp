#include "simplenavigateview.h"
#include "ui_simplenavigateview.h"

SimpleNavigateView::SimpleNavigateView(buttons b,int countPages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleNavigateView)
{
    ui->setupUi(this);
    ui->horizontalLayout->setAlignment(Qt::AlignCenter);

    if(b&prev){
        prevPB = new QPushButton("<-",this);

        prevPB->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
        prevPB->setShortcut(QKeySequence(Qt::Key_Left));
        ui->horizontalLayout->addWidget(prevPB);
        connect(prevPB, &QPushButton::clicked,this,&SimpleNavigateView::PreviousQuestion);

    }
    if(b&pages){
        pagesG = new QButtonGroup(this);
        for (int i = 0; i < countPages ; ++i ) {
            QPushButton *page =  new QPushButton(this);
            page->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
            page->setCheckable(true);
            page->setChecked(i==0);
            page->setAutoExclusive(true);
            ui->horizontalLayout->addWidget(page);
            pagesG->addButton(page,i);
        }
        connect(pagesG, &QButtonGroup::idClicked,this,&SimpleNavigateView::ChangeQuestion);
    }
    if(b&next){
        nextPB = new QPushButton("->",this);
        nextPB->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
        nextPB->setShortcut(QKeySequence(Qt::Key_Right));
        ui->horizontalLayout->addWidget(nextPB);
        connect(nextPB, &QPushButton::clicked,this,&SimpleNavigateView::NextQuestion);
    }
    if(pagesG != nullptr){
        if(prevPB !=nullptr){
            connect(prevPB,&QPushButton::clicked,
                    pagesG,[&](){
                int i = pagesG->checkedId()-1;
                if(i>=0)
                    pagesG->button(i)->setChecked(true);
            });
        }
        if(nextPB !=nullptr){
            connect(nextPB,&QPushButton::clicked,
                    pagesG,[&](){
                int i = pagesG->checkedId()+1;
                if(pagesG->button(i)!=nullptr)
                    pagesG->button(i)->setChecked(true);
            });
        }
    }
}

SimpleNavigateView::~SimpleNavigateView()
{
    delete ui;
}
