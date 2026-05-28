#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(duzenle()));
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Dialog::temizle);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::duzenle()
{
    QString yazi = ui->lineEdit->text();
    ui->text->setText(yazi);

    QFont font = ui->font_box->currentFont();
    int size = ui->size_box->value();
    if(size>0){
        font.setPointSize(size);
    }

    if(ui->bold->isChecked()){
        font.setBold(true);
    } else {
        font.setBold(false);
    }

    if(ui->italik->isChecked()) {
        font.setItalic(true);
    } else {
        font.setItalic(false);
    }

    QString renk = ui->color_box->currentText();
    QPalette palet = ui->text->palette();
    palet.setColor(QPalette::WindowText, QColor(renk));
    ui->text->setPalette(palet);

    ui->text->setFont(font);
}

void Dialog::temizle()
{
    ui->lineEdit->clear();
    ui->text->clear();
}

/*void Dialog::on_pushButton_clicked()
{
    QString yazi = ui->lineEdit->text();
    ui->text->setText(yazi);

    QFont font = ui->font_box->currentFont();
    int size = ui->size_box->value();
    if(size>0){
        font.setPointSize(size);
    }

    if(ui->bold->isChecked()){
        font.setBold(true);
    } else {
        font.setBold(false);
    }

    if(ui->italik->isChecked()) {
        font.setItalic(true);
    } else {
        font.setItalic(false);
    }

    QString renk = ui->color_box->currentText();
    QPalette palet = ui->text->palette();
    palet.setColor(QPalette::WindowText, QColor(renk));
    ui->text->setPalette(palet);

    ui->text->setFont(font);
}*/

