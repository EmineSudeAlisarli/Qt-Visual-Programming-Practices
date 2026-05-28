#ifndef OURWIDGET_H
#define OURWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class ourWidget;
}
QT_END_NAMESPACE

class ourWidget : public QWidget
{
    Q_OBJECT

public:
    ourWidget(QWidget *parent = nullptr);
    ~ourWidget();
    QSize sizeHint() const;//Our widgetın bir fonksiyonunu kullanıcaz

private slots:
    void ourButton_clicked();

private:
    Ui::ourWidget *ui;
};
#endif // OURWIDGET_H
