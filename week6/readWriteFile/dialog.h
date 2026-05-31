#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
    void on_btn_yeni_clicked();
    void on_btn_oku_clicked();
    void on_btn_kaydet_clicked();
    void on_plnMetin_textChanged();

private:
    Ui::Dialog *ui;
    void kaydet();
    void oku();
    bool m_kaydedildimi;
};
#endif // DIALOG_H
