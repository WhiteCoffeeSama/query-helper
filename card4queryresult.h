/*
 * 日期: 2024/04/07
 * 描述: 一个 Card，主要为了查询结果而实现，功能主要是：
 * 1. 可以是 Reading 模式，也可以是 Editing 模式
 * 2. 根据不同模式切换按钮；
 */


#ifndef CARD4QUERYRESULT_H
#define CARD4QUERYRESULT_H

#include <QFrame>
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>
#include <QMessageBox>

namespace Ui {
class Card4QueryResult;
}

class Card4QueryResult : public QFrame
{
    Q_OBJECT

public:
    explicit Card4QueryResult(QWidget *parent = nullptr);
    ~Card4QueryResult();

    void paintEvent(QPaintEvent *);

private:
    void switchMode(bool);

private slots:
    void on_btn_edit_clicked();

    void on_btn_delete_clicked();

    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

public:
    static const bool EDITING = true;
    static const bool READING = false;

private:
    Ui::Card4QueryResult *ui;
};

#endif // CARD4QUERYRESULT_H
