#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>

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
    void on_btn_hatirla_clicked();
    void on_cmb_renkSec_currentTextChanged(const QString &arg1);
    void geri_yukle();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
