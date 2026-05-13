#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug> //Debug ekranını kullanabilmek için

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnTahmin_clicked(); //Tahmin butonu slotu
    void on_btnYenidenBaslat_clicked(); //yeniden başlatma butonu slotu

private:
    Ui::Dialog *ui;
    int gizli_sayi; //tahmin edilicek sayi
    int tahmin_sayi; //tahmin ettiğimiz sayı
};
#endif // DIALOG_H
