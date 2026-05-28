#include "ourwidget.h"
#include "ui_ourwidget.h"

ourWidget::ourWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ourWidget)
{
    ui->setupUi(this);
    //QPushButton *ourButton = new QPushButton(); Böyle kalırsa atası olmayan bir nesne olur kapatınca heapde yaşamaya devam eder
    //ekstra kontrolle silmem gerek

    QPushButton *ourButton = new QPushButton(this);//widgetı kapatınca onun ile oluşan tüm nesnelere kapanır bu şekilde

    //Font tanımlamazsak işletim sisteminin defaultunu kullanıyor
    QFont ourBtnFont("Times New Roman",50,QFont::Bold);
    ourButton->setFont(ourBtnFont);

    ourButton->setText("Tıklanabilir");
    ourButton->move(200,200);

    connect(ourButton,SIGNAL(clicked()),this,SLOT(ourButton_clicked()));
    ourButton->setStyleSheet("QPushButton {" "background-color:#2ecc71;"
                             "color:white;"
                             "border-radius: 10px;"
                             "border:2px solid #27ae60;" "}"
                             "QPushButton:hover {"
                             "background-color:#19DAF5;"
                             "}"
                             );

    //Dinamik label oluşturma
    QLabel *ourLabel = new QLabel(this);
    ourLabel->setText("İlk label");
    ourLabel->move(10,25);
    ourLabel->setFont(ourBtnFont);
    ourLabel->setAutoFillBackground(true);

    //Palet tanımlama
    QPalette ourLabelPalet;
    ourLabelPalet.setColor(QPalette::Window, Qt::blue);
    ourLabel->setPalette(ourLabelPalet);

    // StyleSheet ile (Alternatif):
    // ourLabel->setStyleSheet("background-color: red; color: white; border-radius: 5px;");
}

ourWidget::~ourWidget()
{
    delete ui;
}

QSize ourWidget::sizeHint() const
{
    return QSize(500,500);
}

void ourWidget::ourButton_clicked()
{
    QMessageBox::information(this,"Butonun Mesajı","Ben dinamik şekilde olusturuldum");
}
