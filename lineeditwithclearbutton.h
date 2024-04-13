/*
 * 日期: 2024/04/07
 * 描述: 自定义的 QLineEdit，功能主要是：
 * 1. 添加动态显示的 Clear Button；
 * 2. （暂未实现）限制输入内容，如只可以是英文、数字、下划线, 可能可以是括号等
 */

#ifndef LINEEDITWITHCLEARBUTTON_H
#define LINEEDITWITHCLEARBUTTON_H

#include <QObject>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QKeyEvent>

class LineEditWithClearButton : public QLineEdit
{
    Q_OBJECT

private:
    QPushButton* mp_btnClear;  // "member pointer" to "button clear"
    QHBoxLayout* mp_hBoxLayout;

public:
    explicit LineEditWithClearButton(QWidget *parent = nullptr);  // QWidget 作为 Parent
    explicit LineEditWithClearButton(const QString text, QWidget *parent = 0);
    explicit LineEditWithClearButton(const QIcon icon, QWidget *parent = 0);
    explicit LineEditWithClearButton(const QIcon icon, const QString text, QWidget *parent = 0);
    ~LineEditWithClearButton();

    virtual void setBtnSize(QSize size = QSize(0,0)) const;
    virtual void setBtnSize(int w, int h) const;
    virtual void setBtnIcon(const QIcon &icon) const;
    virtual void setBtnIconSize(const QSize &size) const;

protected:
    void showEvent(QShowEvent*);
    void keyPressEvent(QKeyEvent*);

private:
    void init();

private slots:
    void sl_btnVisible(QString);  // control btn_clear visible based on content

signals:
    void si_sendText(QString);  // signal, send text of this line edit
};

#endif // LINEEDITWITHCLEARBUTTON_H
