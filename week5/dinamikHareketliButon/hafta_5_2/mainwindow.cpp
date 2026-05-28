#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer*zamanlayici = new QTimer(this);
    zamanlayici->start(1000);
    connect(zamanlayici,SIGNAL(timeout()),this,SLOT(degistir()));//sinavda bu tarz bir şey çıkar
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    yeniButton *button = new yeniButton(this);
    button->setGeometry(event->x(),event->y(),100,100);
    button->show();
    buttonlar.push_back(button);
    button->setText(QString::number(buttonlar.size()));
    ui->statusbar->showMessage("X: "+QString::number(event->x())+"Y: "+QString::number(event->y()));
}

void MainWindow::degistir()
{
    int sayisi=buttonlar.size();
    for(int i = 0;i<sayisi;i++){
        if(buttonlar[i]->tiklandimi){
            buttonlar[i]->setGeometry(buttonlar[i]->x()+50,
                                      buttonlar[i]->y()+50,
                                      buttonlar[i]->height()-10,
                                      buttonlar[i]->width()-10
                                      );
        }
    }
}
