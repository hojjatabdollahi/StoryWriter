#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <nodes/Connection>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QtNodes::Connection * a;
}

MainWindow::~MainWindow()
{
    delete ui;
}
