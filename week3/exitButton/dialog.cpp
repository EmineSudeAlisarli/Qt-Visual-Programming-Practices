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

void Dialog::on_btnKapat_clicked()
{
    //pencereyi kapatmak için
    accept(); //exit(0)
}


void Dialog::on_btnYaz_clicked()
{
    QMessageBox::information(this,"Isim","Emine Sude","OK");
}

