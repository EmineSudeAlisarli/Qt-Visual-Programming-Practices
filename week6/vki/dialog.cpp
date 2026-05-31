#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hesapla()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::hesapla()
{
    QDate d_tarihi = ui->dateEdit->date();
    int yas = QDate::currentDate().year()-d_tarihi.year();
    QString yas_2 = QString::number(yas);

    double boy = ui->doubleSpinBox_2->value();
    int kilo = ui->spinBox->value();

    double sonuc = (kilo/(boy*boy));
    QString sonuc_2 = QString::number(sonuc);
    QString metin;

    if(sonuc<18.5){
        QMessageBox::information(this,"SONUÇ","<font color ='red' > Zayif </font>, / Yas : "+ yas_2);
    } else if(sonuc<=24.9){
        QMessageBox::information(this,"SONUÇ","Normal kilolu , Yas : "+ yas_2);
    } else if(sonuc<=29.9){
        QMessageBox::information(this,"SONUÇ","<font color ='green' > Fazla kilolu </font>, / Yas : "+ yas_2);
    } else if(sonuc<=39.9){
        QMessageBox::information(this,"SONUÇ","<font color ='blue' > Obez </font>, / Yas : "+ yas_2);
    } else{
        QMessageBox::information(this,"SONUÇ","<font color ='blue' > Morbid Obez </font>, / Yas : "+ yas_2);
    }
}
