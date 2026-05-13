#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //string
    connect(ui->btn_hesapla,&QPushButton::clicked,this,&Dialog::Hesapla);
    //function
    //connect(ui->btn_hesapla,SIGNAL(clicked()),this,SLOT(Hesapla()));

    connect(ui->btn_tmz,&QPushButton::clicked,this,&Dialog::Temizle);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Hesapla()
{
    if(ui->ln_ad->text() == "" || ui->ln_ders->text() == "" || ui->ln_fnl->text() == "" || ui->ln_vize->text() == ""){
        ui->textBrowser->setText("Eksik bilgi girdiniz.");
    }
    else{
        int gn;
        gn = ui->ln_vize->text().toInt() + ui->ln_fnl->text().toInt();
        gn = gn / 2;
        if(gn>60){
            ui->textBrowser->setText(ui->ln_ad->text()+" isimli öğrenci " + ui->ln_ders->text() + " isimli dersten geçmiştir. ");
        }
        else{
            ui->textBrowser->setText(ui->ln_ad->text()+" isimli öğrenci " + ui->ln_ders->text() + " isimli dersten kalmıştır. ");
        }
    }
}

void Dialog::Temizle()
{
    ui->textBrowser->clear();
}

// void Dialog::on_btn_tmz_clicked()
// {
//     ui->textBrowser->clear();
// }


// void Dialog::on_btn_hesapla_clicked()
// {
//     if(ui->ln_ad->text() == "" || ui->ln_ders->text() == "" || ui->ln_fnl->text() == "" || ui->ln_vize->text() == ""){
//         ui->textBrowser->setText("Eksik bilgi girdiniz.");
//     }
//     else{
//         int gn;
//         gn = ui->ln_vize->text().toInt() + ui->ln_fnl->text().toInt();
//         gn = gn / 2;
//         if(gn>60){
//             ui->textBrowser->setText(ui->ln_ad->text()+" isimli öğrenci " + ui->ln_ders->text() + " isimli dersten geçmiştir. ");
//         }
//         else{
//             ui->textBrowser->setText(ui->ln_ad->text()+" isimli öğrenci " + ui->ln_ders->text() + " isimli dersten kalmıştır. ");
//         }
//     }
// }

