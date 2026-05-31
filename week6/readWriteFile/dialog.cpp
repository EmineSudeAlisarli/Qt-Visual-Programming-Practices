#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_kaydedildimi = false;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_yeni_clicked()
{
    if (!m_kaydedildimi && !ui->plnMetin->toPlainText().isEmpty())
    {
        QMessageBox::StandardButton cevap;
        cevap = QMessageBox::question(this, "Uyarı",
                                      "Kaydedilmemiş değişiklikler var. Devam edilsin mi?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (cevap == QMessageBox::No) return;
    }
    ui->plnMetin->clear();
    m_kaydedildimi = false;
}

void Dialog::kaydet()
{
    QFile file("Myfile.txt");
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"HATA",file.errorString());
        return;
    }
    else{
        QTextStream stream(&file);
        stream << ui->plnMetin->toPlainText();
        file.close();
        m_kaydedildimi=true;
    }
}

void Dialog::oku()
{
    QFile file("Myfile.txt");
    if(!file.exists()) return;
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"HATA",file.errorString());
        return;
    }
    else{
        QTextStream stream(&file);
        ui->plnMetin->setPlainText(stream.readAll());
        file.close();
    }
}

void Dialog::on_btn_oku_clicked()
{
    oku();
}

void Dialog::on_btn_kaydet_clicked()
{
    kaydet();
}

void Dialog::on_plnMetin_textChanged()
{
    m_kaydedildimi = false;
}
