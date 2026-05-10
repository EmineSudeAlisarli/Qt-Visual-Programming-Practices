#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

using namespace std;
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
    int a = 0;
    //Debug ekranına yazdırıyor.
    qDebug()<<"Emine" << a;
    qInfo()<<"Sude" << a;
    cout<<"Emine"<<"Sude"<<endl;
    //Mesaj Penceresi
    QMessageBox::information(this,"Mesaj","bilgilendirme mesaji");
    //QMessageBox::warning(this,"Mesaj","bilgilendirme mesaji","OK","NO","Maybe");
    //QMessageBox::critical(this,"Mesaj","bilgilendirme mesaji","OK","NO","Maybe");
}

