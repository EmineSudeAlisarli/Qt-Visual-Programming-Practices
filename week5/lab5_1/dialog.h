#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

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
    void on_rb_lisans_clicked();

    void on_rb_lisansustu_clicked();

    void on_btn_yazdir_clicked();

    void on_btn_mezuniyet_clicked();

    bool mezuniyet();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
