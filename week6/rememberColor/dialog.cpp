#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    geri_yukle();//en son kaydettiğim neyse onunla çalıştır
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_hatirla_clicked()
{
    // QSetting ile seçili rengin index numarası diske kaydedilir.
    // Uygulama kapansa bile bu değer kaybolmaz.
    QSettings settings("NEU Gorsel","hafta 6");
    settings.setValue("MyDegisken",ui->cmb_renkSec->currentIndex());
    ui->btn_hatirla->setStyleSheet("color:green");
}

void Dialog::on_cmb_renkSec_currentTextChanged(const QString &arg1)
{
    this->setStyleSheet("background-color:"+arg1);
    ui->btn_hatirla->setStyleSheet("color:red");
}

void Dialog::geri_yukle()
{
    QSettings settings("NEU Gorsel","hafta 6");
    QVariant value = settings.value("MyDegisken", 0);
    int index = value.toInt();

    if (index >= 0 && index < ui->cmb_renkSec->count())
        ui->cmb_renkSec->setCurrentIndex(index);

    QString renk = ui->cmb_renkSec->currentText();
    this->setStyleSheet("background-color:" + renk);
}

