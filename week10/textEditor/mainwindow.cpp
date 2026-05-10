#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- DOSYA AÇMA İŞLEMİ ---
void MainWindow::on_actionNew_2_triggered()
{
    ui->textEdit->clear();
    ui->statusbar->showMessage("Yeni Dosya");
}
void MainWindow::on_actionOpen_2_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Hata", "Dosya açılamadı.");
        return;
    }

    QTextStream myStream(&file);
    QString text = myStream.readAll();
    ui->textEdit->setText(text);
    ui->statusbar->showMessage(fileName);
    file.close();
}
void MainWindow::on_actionSave_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save file");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Hata", "Dosya kaydedilemedi.");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    ui->statusbar->showMessage(fileName);
    out << text;
    file.flush();
    file.close();
}
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

// --- EDİT (DÜZENLEME) İŞLEMLERİ ---
void MainWindow::on_actionCopy_triggered() {
    ui->textEdit->copy();
}
void MainWindow::on_actionCut_triggered() {
    ui->textEdit->cut();
}
void MainWindow::on_actionPAste_triggered() {
    ui->textEdit->paste();
}
void MainWindow::on_actionSelect_All_triggered() {
    ui->textEdit->selectAll();
}
void MainWindow::on_actionSelect_None_triggered() {
    QTextCursor cursor = ui->textEdit->textCursor();
    //cursor.clearSelection(); Buda çalışır
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}

// --- VİEW İŞLEMLERİ ---
void MainWindow::on_actionToolbar_Top_triggered()
{
    addToolBar(Qt::TopToolBarArea, ui->toolBar);
}
void MainWindow::on_actionToolbar_Buttom_triggered()
{
    addToolBar(Qt::BottomToolBarArea, ui->toolBar);
}
void MainWindow::on_actionToolbar_Right_2_triggered()
{
    addToolBar(Qt::RightToolBarArea, ui->toolBar);
}
void MainWindow::on_actionToolbar_Left_triggered()
{
    addToolBar(Qt::LeftToolBarArea, ui->toolBar);
}
void MainWindow::on_actionToolbar_Floatable_triggered()
{
    ui->toolBar->setFloatable(false);
}
void MainWindow::on_actionToolbar_Movable_triggered()
{
    ui->toolBar->setMovable(false);
}

// --- FORMS (FORMLAR) İŞLEMLERİ ---
void MainWindow::on_actionOpen_Form_triggered()
{
    form *ikinciEkran = new form(this);
    ikinciEkran->setWindowTitle("MainWindow");
    ikinciEkran->show();
}
