#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnStart_clicked()
{
    //sunucu dinleme moduna girer
    qint16 port= static_cast<qint16>(ui->spinBox->value());
    server.setMessage(ui->lineEdit->text()+"\r\n");
    if (!server.listen(QHostAddress::Any,port))//IP leri kabul eder
    {
        QMessageBox::critical(this,"Sunucu Baglantı Hatası",server.errorString());
        return;
    }
    ui->lbl_durum->setText("Sunucu Dinliyor");
    enableButtons();
}

void Dialog::on_btnStop_clicked()
{
    server.close();
    ui->lbl_durum->setText("Sunucu kapandı");
    enableButtons();
}

void Dialog::next()
{
    int i = ui->stackedWidget->currentIndex();
    i++;
    if (i>ui->stackedWidget->count()) i=ui->stackedWidget->count()-1;

    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::back()
{
    int i = ui->stackedWidget->currentIndex();
    i--;
    if(i<0) i = 0;
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::changed()
{
    ui->lbl_durum->setText(QString("Aktif olarak %0 client baglı").arg(server.count()));
}

void Dialog::enableButtons()
{
    //sunucudaki bağlantı sayısı değişince lbl_durum güncellenir
    ui->btnStart->setEnabled(!server.isListening());
    ui->btnStop->setEnabled(server.isListening());

    // tek sayfa ise
    if (ui->stackedWidget->count()<=1)
    {
        btnBack->setEnabled(false);
        btnNext->setEnabled(false);
        return;
    }
    // ilk sayfa ise
    if (ui->stackedWidget->currentIndex()==0)
    {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }
    // son sayfa ise
    if (ui->stackedWidget->currentIndex()==ui->stackedWidget->count()-1)
    {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
        return;
    }
}

void Dialog::init()
{
    btnBack = new QPushButton("BACK", this);
    btnNext = new QPushButton("NEXT", this);

    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnBack, &QPushButton::clicked, this, &Dialog::back);
    connect(btnNext, &QPushButton::clicked, this, &Dialog::next);

    enableButtons();
}

