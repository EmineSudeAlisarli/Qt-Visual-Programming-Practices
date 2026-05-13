#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr)); //sayinin her tuşa basıldığında yeniden oluşmaması için
    gizli_sayi=std::rand()%7 + 1;
    qDebug() << gizli_sayi;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnTahmin_clicked()
{
    tahmin_sayi=ui->spinBox->value(); //spin box'dan değeri alıyoruz
    if (gizli_sayi==tahmin_sayi)
    {
        ui->label->setText("<Tebrikler sayıyı doğru tahmin ettiniz>");
    }
    else
    {
        ui->label->setText("!Malesef, tekrar deneyiniz!");
    }
}

void Dialog::on_btnYenidenBaslat_clicked()
{
    ui->spinBox->clear();
    ui->label->clear();
}
