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

void Dialog::on_rb_lisans_clicked()
{
    ui->gb_sinif->setEnabled(true);
    ui->gb_ders1->setEnabled(true);
    ui->gb_durum->setEnabled(false);
    ui->gb_ders2->setEnabled(false);
}


void Dialog::on_rb_lisansustu_clicked()
{
    ui->gb_durum->setEnabled(true);
    ui->gb_ders2->setEnabled(true);
    ui->gb_sinif->setEnabled(false);
    ui->gb_ders1->setEnabled(false);
}


void Dialog::on_btn_yazdir_clicked()
{
    QString ad = ui->ln_ad->text();
    QString soyad = ui->ln_soyad->text();
    QString bolum = ui->ln_bolum->text();
    QString lisans;
    if(ui->rb_lisans->isChecked()){
        lisans = "lisans";
    }
    else{
        lisans = "lisansüstü";
    }
    QMessageBox::information(this,"Öğrenci Bilgileri","Ad: "+ad+"\nSoyad: "+soyad+"\nBolum: "+bolum+"\nSeviye: "+lisans);
}

void Dialog::on_btn_mezuniyet_clicked()
{
    if(ui->rb_lisans->isChecked()){
        if(ui->rb_4->isChecked() && ui->cb_turkdili->isChecked() && ui->cb_aiit->isChecked() && ui->cb_isg->isChecked()){
            QMessageBox::information(this,"Mezuniyet","lisans seviyesi");
        }
        else{
            QMessageBox::information(this,"Mezuniyet","olamaz");
        }
    }
    else if(ui->rb_lisansustu->isChecked()){
        if(ui->rb_tez->isChecked() && ui->cb_secmeli->isChecked() && ui->cb_seminer->isChecked() && ui->cb_tez->isChecked()){
            QMessageBox::information(this,"Mezuniyet","lisansüstü");
        }
        else{
            QMessageBox::information(this,"Mezuniyet","olamaz");
        }
    }
    else{
        QMessageBox::information(this,"mezuniyet","eksik bilgi");
    }
}

bool Dialog::mezuniyet()
{
    if(ui->rb_4->isChecked() && ui->cb_turkdili->isChecked() && ui->cb_aiit->isChecked() && ui->cb_isg->isChecked()){
        return true;
    }
    else{
        return false;
    }
}



