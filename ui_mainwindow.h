/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 600);
        MainWindow->setMinimumSize(QSize(400, 600));
        MainWindow->setMaximumSize(QSize(400, 600));
        MainWindow->setStyleSheet(QLatin1String("#centralWidget\n"
"{\n"
"	background-image:url(:/new/prefix1/timg.jpg);\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"QPushButton #pushButton_5:hover\n"
"{\n"
"	background-color:rgb(85, 255, 0)\n"
"}\n"
""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 351, 131));
        label->setStyleSheet(QString::fromUtf8("font-size:200px;\n"
"font: 72pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color:white;\n"
""));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 170, 151, 381));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(111, 0));
        pushButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:rgb(170, 255, 127)\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background-color:rgb(0, 255, 0)\n"
"}"));

        verticalLayout->addWidget(pushButton_5);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\346\234\272\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\217\214\344\272\272\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\201\224\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
