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

void Dialog::on_btn_temizle_clicked()
{
    QList<QString> list;
    list << "Konya" << "Ankara";
    list.append("İstanbul");
    foreach (QString s, list) {
        qDebug() << s;
        qDebug() << list.count();
    }
}

void Dialog::on_btn_FListele_clicked()
{
    QString secimler;
    QObjectList boxes = this->children();
    foreach(QObject *obj,boxes)
    {
        if(obj->inherits("QCheckBox"))
        {
            QCheckBox *box=qobject_cast<QCheckBox *>(obj);
            if (box->isChecked())
                secimler+=box->text()+ "\r\n";
        }
        ui->txt_filtreler->setText(secimler);
    }
}

QString Dialog::secimleriAl(QObject *obj)
{
    QString value="none";
    QList<QRadioButton *> lst=obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);
    foreach (QRadioButton *rdo,lst) {
        if (rdo->isChecked())
        {
            value=rdo->text();
            break;
        }
    }
    return value;
}

void Dialog::on_btn_altSecimler_clicked()
{
    QString vites=secimleriAl(ui->grb_vites);
    QString yakit=secimleriAl(ui->grb_yakit);
    QString yas=secimleriAl(ui->grb_yas);
    QString altSecimlerListesi;
    altSecimlerListesi+="vites: " + vites + "\r\n";
    altSecimlerListesi+="yakit: " + yakit + "\r\n";
    altSecimlerListesi+="yas: " + yas + "\r\n";
    QMessageBox::information(this,"Alt SecimListesi",altSecimlerListesi);
}
