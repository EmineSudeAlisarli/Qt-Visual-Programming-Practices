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

void Dialog::on_pushButton_clicked()
{
    int sayi = ui->lineEdit->text().toInt();
    for(int i = 2;i<sayi;i++){
        int kontrol = 0;
        for(int j = 2;j<i;j++){
            if(i%j == 0){
                kontrol = 1;
            }
        }
        if(kontrol == 0){
            ui->textBrowser->setText(ui->textBrowser->toPlainText()+QString::number(i)+"\n");
        }
    }
}

