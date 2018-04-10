#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QObject>
#include <QStringList>
#include <QString>

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


void MainWindow::on_Solve_clicked()
{
    QFile Input("info.txt");
    if(!Input.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this,"Info","File not open");

    QTextStream out(&Input);
    QString r = ui->NOR->text();
    QString c = ui->NOC->text();
    QString path = ui->MazePath->text();
    out << r << " " << c << " " << path;
    Input.flush();
    Input.close();

    if(ui->MD->isChecked())
    {
        QString programcpp = "manhattan.exe";
        QProcess *myProcesscpp = new QProcess();
        myProcesscpp->execute(programcpp);
    }

    if(ui->ED->isChecked())
    {
        QString programcpp = "eucledian.exe";
        QProcess *myProcesscpp = new QProcess();
        myProcesscpp->execute(programcpp);
    }

    if(ui->CD->isChecked())
    {
        QString programcpp = "chebyshev.exe";
        QProcess *myProcesscpp = new QProcess();
        myProcesscpp->execute(programcpp);
    }

    QString programpy = "drawMaze.exe";
    QProcess *myProcesspy = new QProcess();
    myProcesspy->execute(programpy);

    hide(); //skriva prvi
    secWindow = new SecondWindow(this);
    secWindow->show();
}

void MainWindow::on_OpenFileMaze_clicked()
{
    QString FileMaze = QFileDialog::getOpenFileName(this,"Open file");
    ui->MazePath->setText(FileMaze);
}
