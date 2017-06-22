#ifndef BUTTON_H
#define BUTTON_H
#include <qpushbutton.h>

class Button:public QPushButton
{
    Q_OBJECT
    public:
        explicit Button(QWidget * parent = 0);
        Button(const QString& text,QWidget* parent = 0);
        Button(const QIcon& icon,const QString& text,QWidget* parent = 0 );
};

#endif // BUTTON_H
