/********************************************************************************
** Form generated from reading UI file 'network.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_H
#define UI_NETWORK_H

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

class Ui_network
{
public:
    QPushButton *backBtn;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *network)
    {
        if (network->objectName().isEmpty())
            network->setObjectName(QStringLiteral("network"));
        network->resize(1280, 800);
        network->setMinimumSize(QSize(1280, 800));
        network->setMaximumSize(QSize(1280, 800));
        network->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        backBtn = new QPushButton(network);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setGeometry(QRect(1050, 490, 191, 61));
        backBtn->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(network);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1010, 90, 241, 191));
        label_4->setStyleSheet(QString::fromUtf8("font-size:160px;\n"
"font: 48pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color:black;\n"
""));
        verticalLayoutWidget = new QWidget(network);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 291, 801));
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


        retranslateUi(network);

        QMetaObject::connectSlotsByName(network);
    } // setupUi

    void retranslateUi(QDialog *network)
    {
        network->setWindowTitle(QApplication::translate("network", "Dialog", Q_NULLPTR));
        backBtn->setText(QApplication::translate("network", "\346\212\225\351\231\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("network", "\344\272\224\345\255\220\346\243\213", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class network: public Ui_network {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_H
