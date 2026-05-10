#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnYaz_clicked()
{
    QDate tarih1 = QDateTime::currentDateTime().date();
    QTime saat1 = QDateTime::currentDateTime().time();

    QString tarih2 = tarih1.toString();
    QString saat2 = saat1.toString();

    QMessageBox::information(this,"Mesaj","Butona tıklanma zamanı: "+tarih2 +"\nButona tıklanma saati: "+saat2,"OK");

    //Debug ekranına yazdırmak için
    //qInfo()<<tarih2;
    //qInfo()<<saat2;
}

