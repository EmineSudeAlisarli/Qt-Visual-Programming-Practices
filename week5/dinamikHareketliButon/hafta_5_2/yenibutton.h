#ifndef YENIBUTTON_H
#define YENIBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

class yeniButton : public QPushButton
{
    Q_OBJECT
public:
    yeniButton(QWidget* parent);
    bool tiklandimi;

public slots:
    void tikla();
};

#endif // YENIBUTTON_H
