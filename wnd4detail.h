#ifndef WND4DETAIL_H
#define WND4DETAIL_H

#include <QMainWindow>

namespace Ui {
class Wnd4Detail;
}

class Wnd4Detail : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wnd4Detail(QWidget *parent = nullptr);
    ~Wnd4Detail();

private:
    Ui::Wnd4Detail *ui;
};

#endif // WND4DETAIL_H
