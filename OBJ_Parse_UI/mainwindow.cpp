#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modeltest.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
//    QFile file(fileName);
//    currentFile = fileName;
//    if (!file.open(QIODevice::ReadOnly | QFile::Text))
//    {
//        QMessageBox::warning(this,"..","File not opened.");
//        return;
//    }
//    QTextStream inputStream(&file);
    model.importModel(fileName);
    //QString text = in.readAll();
    //ui->textEdit->setText(text);
    //file.close();
}



void MainWindow::on_runTestButton_clicked()
{
    ModelTest tests;
//    QStringList testNames;
//    testNames << "testNotNumberInputModel01";
    QTest::qExec(&tests/*, testNames*/);
}

void MainWindow::on_saveButton_clicked()
{
    model.exportModel();
}
