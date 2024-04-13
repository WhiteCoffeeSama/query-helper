#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->leInput, SIGNAL(si_sendText(QString)), this, SLOT(sl_rcvTextFromLineEdit(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sl_rcvTextFromLineEdit(QString s)
{
    qDebug() << s;
}
