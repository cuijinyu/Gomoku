/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(472, 388);
        about->setStyleSheet(QLatin1String("#about{\n"
"background:url(:/new/prefix1/timg.jpg)\n"
"}"));
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 100, 361, 71));
        label->setStyleSheet(QString::fromUtf8("font: 25 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));
        label_2 = new QLabel(about);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 170, 231, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));
        label_3 = new QLabel(about);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 220, 161, 61));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));
        label_4 = new QLabel(about);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 30, 371, 91));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 38pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));
        label_5 = new QLabel(about);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 270, 161, 61));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));
        label_6 = new QLabel(about);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 320, 161, 61));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 30pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color:white"));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("about", "\345\264\224\346\231\213\347\221\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("about", "\346\275\230\351\234\207\345\256\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("about", "\350\260\242\345\205\211\346\230\216", Q_NULLPTR));
        label_4->setText(QApplication::translate("about", "\345\210\266\344\275\234\350\200\205\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("about", "\350\265\265\345\255\220\346\207\277", Q_NULLPTR));
        label_6->setText(QApplication::translate("about", "\351\203\235\345\234\243\346\235\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
