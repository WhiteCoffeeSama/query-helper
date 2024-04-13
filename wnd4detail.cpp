#include "wnd4detail.h"
#include "ui_wnd4detail.h"

Wnd4Detail::Wnd4Detail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wnd4Detail)
{
    ui->setupUi(this);
}

Wnd4Detail::~Wnd4Detail()
{
    delete ui;
}
