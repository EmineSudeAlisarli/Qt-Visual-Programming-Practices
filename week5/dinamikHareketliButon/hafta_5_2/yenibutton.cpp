#include "yenibutton.h"

yeniButton::yeniButton(QWidget* parent):QPushButton(parent)//:: aitlik : miras alma
{
    tiklandimi = false;
    connect(this,SIGNAL(clicked()), this,SLOT(tikla()));
}

void yeniButton::tikla()
{
    tiklandimi =! tiklandimi;
}
