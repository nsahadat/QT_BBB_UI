/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *Buttonwaveform;
    QPushButton *ButtonCal;
    QPushButton *ButtonTrain;
    QPushButton *ButtonTest;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonPC;
    QPushButton *ButtonPWC;
    QPushButton *ButtonPhone;
    QPushButton *ButtonHome;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ButtonExit;
    QLineEdit *TextDisp;
    QPushButton *statButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 250);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Buttonwaveform = new QPushButton(centralWidget);
        Buttonwaveform->setObjectName(QString::fromUtf8("Buttonwaveform"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Buttonwaveform->sizePolicy().hasHeightForWidth());
        Buttonwaveform->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Buttonwaveform->setFont(font);

        verticalLayout->addWidget(Buttonwaveform);

        ButtonCal = new QPushButton(centralWidget);
        ButtonCal->setObjectName(QString::fromUtf8("ButtonCal"));
        sizePolicy1.setHeightForWidth(ButtonCal->sizePolicy().hasHeightForWidth());
        ButtonCal->setSizePolicy(sizePolicy1);
        ButtonCal->setFont(font);

        verticalLayout->addWidget(ButtonCal);

        ButtonTrain = new QPushButton(centralWidget);
        ButtonTrain->setObjectName(QString::fromUtf8("ButtonTrain"));
        sizePolicy1.setHeightForWidth(ButtonTrain->sizePolicy().hasHeightForWidth());
        ButtonTrain->setSizePolicy(sizePolicy1);
        ButtonTrain->setFont(font);

        verticalLayout->addWidget(ButtonTrain);

        ButtonTest = new QPushButton(centralWidget);
        ButtonTest->setObjectName(QString::fromUtf8("ButtonTest"));
        sizePolicy1.setHeightForWidth(ButtonTest->sizePolicy().hasHeightForWidth());
        ButtonTest->setSizePolicy(sizePolicy1);
        ButtonTest->setFont(font);

        verticalLayout->addWidget(ButtonTest);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ButtonPC = new QPushButton(centralWidget);
        ButtonPC->setObjectName(QString::fromUtf8("ButtonPC"));
        sizePolicy1.setHeightForWidth(ButtonPC->sizePolicy().hasHeightForWidth());
        ButtonPC->setSizePolicy(sizePolicy1);
        ButtonPC->setFont(font);

        verticalLayout_2->addWidget(ButtonPC);

        ButtonPWC = new QPushButton(centralWidget);
        ButtonPWC->setObjectName(QString::fromUtf8("ButtonPWC"));
        sizePolicy1.setHeightForWidth(ButtonPWC->sizePolicy().hasHeightForWidth());
        ButtonPWC->setSizePolicy(sizePolicy1);
        ButtonPWC->setFont(font);

        verticalLayout_2->addWidget(ButtonPWC);

        ButtonPhone = new QPushButton(centralWidget);
        ButtonPhone->setObjectName(QString::fromUtf8("ButtonPhone"));
        sizePolicy1.setHeightForWidth(ButtonPhone->sizePolicy().hasHeightForWidth());
        ButtonPhone->setSizePolicy(sizePolicy1);
        ButtonPhone->setFont(font);

        verticalLayout_2->addWidget(ButtonPhone);

        ButtonHome = new QPushButton(centralWidget);
        ButtonHome->setObjectName(QString::fromUtf8("ButtonHome"));
        sizePolicy1.setHeightForWidth(ButtonHome->sizePolicy().hasHeightForWidth());
        ButtonHome->setSizePolicy(sizePolicy1);
        ButtonHome->setFont(font);

        verticalLayout_2->addWidget(ButtonHome);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ButtonExit = new QPushButton(centralWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy1.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy1);
        ButtonExit->setFont(font);

        verticalLayout_3->addWidget(ButtonExit);

        TextDisp = new QLineEdit(centralWidget);
        TextDisp->setObjectName(QString::fromUtf8("TextDisp"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TextDisp->sizePolicy().hasHeightForWidth());
        TextDisp->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(TextDisp);

        statButton = new QPushButton(centralWidget);
        statButton->setObjectName(QString::fromUtf8("statButton"));
        sizePolicy1.setHeightForWidth(statButton->sizePolicy().hasHeightForWidth());
        statButton->setSizePolicy(sizePolicy1);
        statButton->setFont(font);

        verticalLayout_3->addWidget(statButton);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "mTDS USER INTERFACE", 0, QApplication::UnicodeUTF8));
        Buttonwaveform->setText(QApplication::translate("MainWindow", "WAVEFORM", 0, QApplication::UnicodeUTF8));
        ButtonCal->setText(QApplication::translate("MainWindow", "CALIBRATION", 0, QApplication::UnicodeUTF8));
        ButtonTrain->setText(QApplication::translate("MainWindow", "TRAINING", 0, QApplication::UnicodeUTF8));
        ButtonTest->setText(QApplication::translate("MainWindow", "TESTING", 0, QApplication::UnicodeUTF8));
        ButtonPC->setText(QApplication::translate("MainWindow", "PC", 0, QApplication::UnicodeUTF8));
        ButtonPWC->setText(QApplication::translate("MainWindow", "PWC", 0, QApplication::UnicodeUTF8));
        ButtonPhone->setText(QApplication::translate("MainWindow", "PHONE", 0, QApplication::UnicodeUTF8));
        ButtonHome->setText(QApplication::translate("MainWindow", "HOME", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("MainWindow", "EXIT", 0, QApplication::UnicodeUTF8));
        statButton->setText(QApplication::translate("MainWindow", "STATUS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
