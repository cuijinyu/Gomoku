/********************************************************************************
** Form generated from reading UI file 'doubled.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLED_H
#define UI_DOUBLED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doubled
{
public:
    QPushButton *containueBtn;
    QPushButton *stopBtn;
    QPushButton *backBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;

    void setupUi(QDialog *doubled)
    {
        if (doubled->objectName().isEmpty())
            doubled->setObjectName(QStringLiteral("doubled"));
        doubled->resize(1280, 800);
        doubled->setMinimumSize(QSize(1280, 800));
        doubled->setMaximumSize(QSize(1280, 800));
        doubled->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:3px;\n"
"	background-color:rgb(170, 85, 0);\n"
"	color:white;\n"
"	font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(170, 170, 0)\n"
"}\n"
"QDialog\n"
"{\n"
"	background:url(:/new/prefix1/chess.jpg)\n"
"}"));
        containueBtn = new QPushButton(doubled);
        containueBtn->setObjectName(QStringLiteral("containueBtn"));
        containueBtn->setGeometry(QRect(1020, 370, 171, 51));
        stopBtn = new QPushButton(doubled);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setGeometry(QRect(1020, 470, 171, 51));
        backBtn = new QPushButton(doubled);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setGeometry(QRect(1020, 570, 171, 51));
        backBtn->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(doubled);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 291, 801));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("background:url(\"D:/project/untitled22/a7fc1fd01feeae0ab7ff0ed70dcfb45c.png\");\n"
""));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 28pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(label_3, 0, Qt::AlignHCenter);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(doubled);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1000, 80, 241, 191));
        label_4->setStyleSheet(QString::fromUtf8("font-size:160px;\n"
"font: 48pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color:black;\n"
""));

        retranslateUi(doubled);

        QMetaObject::connectSlotsByName(doubled);
    } // setupUi

    void retranslateUi(QDialog *doubled)
    {
        doubled->setWindowTitle(QApplication::translate("doubled", "Dialog", Q_NULLPTR));
        containueBtn->setText(QApplication::translate("doubled", "\347\273\247\347\273\255", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("doubled", "\346\232\202\345\201\234", Q_NULLPTR));
        backBtn->setText(QApplication::translate("doubled", "\346\202\224\346\243\213", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        label_4->setText(QApplication::translate("doubled", "\344\272\224\345\255\220\346\243\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class doubled: public Ui_doubled {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLED_H
