#include "card4queryresult.h"
#include "ui_card4queryresult.h"


Card4QueryResult::Card4QueryResult(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Card4QueryResult)
{
    ui->setupUi(this);

    switchMode(READING);
}

Card4QueryResult::~Card4QueryResult()
{
    delete ui;
}

void Card4QueryResult::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }

void Card4QueryResult::on_btn_edit_clicked()
{
    switchMode(EDITING);
}


void Card4QueryResult::on_btn_delete_clicked()
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "确实要删除吗?", QMessageBox::Yes|QMessageBox::No);
    if (btn == QMessageBox::Yes) {
        //...
    }
}


void Card4QueryResult::on_btn_save_clicked()
{
    // TODO Save...
    qDebug() << "SAVING";
    switchMode(READING);
}


void Card4QueryResult::on_btn_cancel_clicked()
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "要保存吗?", QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel);
    if (btn == QMessageBox::Ok)
    {
        ui->btn_save->click();
    }
    if(btn == QMessageBox::No)
    {
        switchMode(READING);
    }
}

void Card4QueryResult::switchMode(bool b)
{
    ui->btn_edit->setVisible(!b);
    ui->btn_delete->setVisible(!b);
    ui->btn_save->setVisible(b);
    ui->btn_cancel->setVisible(b);

    // EDITING 状态下才能 Enable
    ui->le_name->setEnabled(b);
    ui->cb_project->setEnabled(b);
    ui->cb_type->setEnabled(b);
    ui->te_content->setEnabled(b);
}
