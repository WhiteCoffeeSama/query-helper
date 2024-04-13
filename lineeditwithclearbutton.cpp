#include "lineeditwithclearbutton.h"

// 构造函数、析构函数
LineEditWithClearButton::LineEditWithClearButton(QWidget *parent) : QLineEdit(parent)
{
    init();

    mp_btnClear->setIcon(QIcon(":/icon/x_icon.png"));  // 设置默认的按钮图片
}

LineEditWithClearButton::LineEditWithClearButton(const QString text, QWidget *parent) : QLineEdit(parent)
{
    init();
    mp_btnClear->setText(text);
}

LineEditWithClearButton::LineEditWithClearButton(const QIcon icon, QWidget *parent) : QLineEdit(parent)
{
    init();
    mp_btnClear->setIcon(icon);
}

LineEditWithClearButton::LineEditWithClearButton(const QIcon icon, const QString text, QWidget *parent) : QLineEdit(parent)
{
    init();
    mp_btnClear->setText(text);
    mp_btnClear->setIcon(icon);
}

LineEditWithClearButton::~LineEditWithClearButton()
{
    delete mp_btnClear;
}

// init
void LineEditWithClearButton::init()
{
    mp_btnClear = new QPushButton();
    mp_hBoxLayout = new QHBoxLayout();

    connect(mp_btnClear, SIGNAL(clicked()), this, SLOT(clear()));  // 清空输入栏
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(sl_btnVisible(QString)));  // 监听 text 变化

    mp_btnClear->setFocusPolicy(Qt::NoFocus);  // 不应该被单独聚焦, 否则容易误触
    mp_btnClear->setCursor(Qt::ArrowCursor);  // 设置鼠标图标
    mp_btnClear->setStyleSheet(
                "mp_btnClear{border: none;}, "
                "mp_btnClear:hover{border: none;}");

/*
添加伸展, 在布局器中增加一个伸缩量。
里面的参数表示 QSpacerItem 的个数，默认值为零，会将你放在layout中的空间压缩成默认的大小。

比如, 想一行放 3 个 btn, 空白部分分成 1:1:1:6, 则：
hBoxLayout->addStretch(1);  // -
hBoxLayout->addWidget(btn0);
hBoxLayout->addStretch(1);  // -
hBoxLayout->addWidget(btn1);
hBoxLayout->addStretch(1);  // -
hBoxLayout->addWidget(btn2);
hBoxLayout->addStretch(6);  // ------
*/
    mp_hBoxLayout->addStretch();
    mp_hBoxLayout->addWidget(mp_btnClear);
    mp_hBoxLayout->setAlignment(Qt::AlignRight);  // 右侧
    mp_hBoxLayout->setContentsMargins(0, 0, 2, 0);  // Left, Top, Right, Buttom

    this->setLayout(mp_hBoxLayout);
    this->setTextMargins(0, 0, this->height() + 1, 0);  // 设定输入文本区域, 从最左侧到 btn 的最左(?)

    mp_btnClear->setVisible(false);  // 默认不可见
}

// 设置 btn 属性
void LineEditWithClearButton::setBtnSize(QSize size) const
{
    if(size.height() == 0 || size.width() == 0)  // 如果是 empty or zero size, 则设置默认 size
    {
        size = QSize(this->height() - 6, this->height() - 6);
    }
    mp_btnClear->setFixedSize(size);
}

void LineEditWithClearButton::setBtnSize(int w, int h) const
{
    if(w == 0 || h == 0)
    {
        w = h = this->height() - 6;
    }
    mp_btnClear->setFixedSize(w, h);
}

void LineEditWithClearButton::setBtnIcon(const QIcon &icon) const
{
    mp_btnClear->setIcon(icon);
}

void LineEditWithClearButton::setBtnIconSize(const QSize &size) const
{
    mp_btnClear->setIconSize(size);
}

/**
 * 函数名: showEvent
 * 描述: 重写 showEvent, 从而设置按钮大小
 * 参数:
 *   e (QShowEvent*): 事件
 * 返回值:
 *   void
 */
void LineEditWithClearButton::showEvent(QShowEvent* e)
{

    if(e == NULL)
    {
        return;
    }
    setBtnSize();
}

/**
 * 函数名: keyPressEvent
 * 描述: 重写 keyPressEvent, 从而相应按键
 * 参数:
 *   e (QKeyEvent*): 事件
 * 返回值:
 *   void
 */
void LineEditWithClearButton::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
    {
        emit si_sendText(this->text());
        return;
    }
    QLineEdit::keyPressEvent(e);  // parent 的 event
}

void LineEditWithClearButton::sl_btnVisible(QString s)
{
    mp_btnClear->setVisible(!s.isEmpty());
}

