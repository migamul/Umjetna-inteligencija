#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QDir>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QImage>

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap Pic("pic.png");
    //int width = ui->Image->width();
    //int height = ui->Image->height();
    //ui->Image->setPixmap(Pic.scaled(width,height,Qt::KeepAspectRatio));
    ui->Image->setPixmap(Pic);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
