#include "button.h"

Button::Button(QWidget* parent):QPushButton(parent)
{

}
Button::Button(const QString& text,QWidget* parent):QPushButton(text,parent)
{

}

Button::Button(const QIcon& icon,const QString& text,QWidget* parent):QPushButton(icon,text,parent)
{

}
