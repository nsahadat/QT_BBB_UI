/********************************************************************************
** Form generated from reading UI file 'calibration.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Calibration
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ButtonStart;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progBar;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonExit;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *calPlot;

    void setupUi(QDialog *Calibration)
    {
        if (Calibration->objectName().isEmpty())
            Calibration->setObjectName(QString::fromUtf8("Calibration"));
        Calibration->resize(480, 250);
        verticalLayoutWidget_3 = new QWidget(Calibration);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 461, 231));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ButtonStart = new QPushButton(verticalLayoutWidget_3);
        ButtonStart->setObjectName(QString::fromUtf8("ButtonStart"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonStart->sizePolicy().hasHeightForWidth());
        ButtonStart->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ButtonStart->setFont(font);

        horizontalLayout_4->addWidget(ButtonStart);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        progBar = new QProgressBar(verticalLayoutWidget_3);
        progBar->setObjectName(QString::fromUtf8("progBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progBar->sizePolicy().hasHeightForWidth());
        progBar->setSizePolicy(sizePolicy1);
        progBar->setFont(font);
        progBar->setValue(24);

        horizontalLayout_3->addWidget(progBar);


        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        comboBox = new QComboBox(verticalLayoutWidget_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        comboBox->setFont(font1);

        horizontalLayout_6->addWidget(comboBox);


        horizontalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonExit = new QPushButton(verticalLayoutWidget_3);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy);
        ButtonExit->setFont(font);

        horizontalLayout_2->addWidget(ButtonExit);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        calPlot = new QCustomPlot(verticalLayoutWidget_3);
        calPlot->setObjectName(QString::fromUtf8("calPlot"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        calPlot->setFont(font2);

        verticalLayout_2->addWidget(calPlot);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 4);

        retranslateUi(Calibration);

        QMetaObject::connectSlotsByName(Calibration);
    } // setupUi

    void retranslateUi(QDialog *Calibration)
    {
        Calibration->setWindowTitle(QApplication::translate("Calibration", "CALIBRATION", 0, QApplication::UnicodeUTF8));
        ButtonStart->setText(QApplication::translate("Calibration", "START", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("Calibration", "EXIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calibration: public Ui_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H
