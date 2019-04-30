/********************************************************************************
** Form generated from reading UI file 'waveforms.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORMS_H
#define UI_WAVEFORMS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Waveforms
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topLay;
    QCheckBox *checkBoxS1;
    QCheckBox *checkBoxS2;
    QCheckBox *checkBoxS3;
    QCheckBox *checkBoxS4;
    QCheckBox *checkBoxS5;
    QCheckBox *checkBoxS6;
    QCheckBox *checkBoxS7;
    QPushButton *ButtonExit;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Waveforms)
    {
        if (Waveforms->objectName().isEmpty())
            Waveforms->setObjectName(QString::fromUtf8("Waveforms"));
        Waveforms->resize(480, 250);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Waveforms->sizePolicy().hasHeightForWidth());
        Waveforms->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Waveforms);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topLay = new QHBoxLayout();
        topLay->setSpacing(1);
        topLay->setObjectName(QString::fromUtf8("topLay"));
        checkBoxS1 = new QCheckBox(Waveforms);
        checkBoxS1->setObjectName(QString::fromUtf8("checkBoxS1"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBoxS1->sizePolicy().hasHeightForWidth());
        checkBoxS1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkBoxS1->setFont(font);

        topLay->addWidget(checkBoxS1);

        checkBoxS2 = new QCheckBox(Waveforms);
        checkBoxS2->setObjectName(QString::fromUtf8("checkBoxS2"));
        sizePolicy1.setHeightForWidth(checkBoxS2->sizePolicy().hasHeightForWidth());
        checkBoxS2->setSizePolicy(sizePolicy1);
        checkBoxS2->setFont(font);

        topLay->addWidget(checkBoxS2);

        checkBoxS3 = new QCheckBox(Waveforms);
        checkBoxS3->setObjectName(QString::fromUtf8("checkBoxS3"));
        sizePolicy1.setHeightForWidth(checkBoxS3->sizePolicy().hasHeightForWidth());
        checkBoxS3->setSizePolicy(sizePolicy1);
        checkBoxS3->setFont(font);

        topLay->addWidget(checkBoxS3);

        checkBoxS4 = new QCheckBox(Waveforms);
        checkBoxS4->setObjectName(QString::fromUtf8("checkBoxS4"));
        sizePolicy1.setHeightForWidth(checkBoxS4->sizePolicy().hasHeightForWidth());
        checkBoxS4->setSizePolicy(sizePolicy1);
        checkBoxS4->setFont(font);

        topLay->addWidget(checkBoxS4);

        checkBoxS5 = new QCheckBox(Waveforms);
        checkBoxS5->setObjectName(QString::fromUtf8("checkBoxS5"));
        sizePolicy1.setHeightForWidth(checkBoxS5->sizePolicy().hasHeightForWidth());
        checkBoxS5->setSizePolicy(sizePolicy1);
        checkBoxS5->setFont(font);

        topLay->addWidget(checkBoxS5);

        checkBoxS6 = new QCheckBox(Waveforms);
        checkBoxS6->setObjectName(QString::fromUtf8("checkBoxS6"));
        sizePolicy1.setHeightForWidth(checkBoxS6->sizePolicy().hasHeightForWidth());
        checkBoxS6->setSizePolicy(sizePolicy1);
        checkBoxS6->setFont(font);

        topLay->addWidget(checkBoxS6);

        checkBoxS7 = new QCheckBox(Waveforms);
        checkBoxS7->setObjectName(QString::fromUtf8("checkBoxS7"));
        sizePolicy1.setHeightForWidth(checkBoxS7->sizePolicy().hasHeightForWidth());
        checkBoxS7->setSizePolicy(sizePolicy1);
        checkBoxS7->setFont(font);

        topLay->addWidget(checkBoxS7);

        ButtonExit = new QPushButton(Waveforms);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy1.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy1);
        ButtonExit->setFont(font);

        topLay->addWidget(ButtonExit);


        verticalLayout->addLayout(topLay);

        customPlot = new QCustomPlot(Waveforms);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setAutoFillBackground(true);

        verticalLayout->addWidget(customPlot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        retranslateUi(Waveforms);

        QMetaObject::connectSlotsByName(Waveforms);
    } // setupUi

    void retranslateUi(QDialog *Waveforms)
    {
        Waveforms->setWindowTitle(QApplication::translate("Waveforms", "WAVEFORM", 0, QApplication::UnicodeUTF8));
        checkBoxS1->setText(QApplication::translate("Waveforms", "S1", 0, QApplication::UnicodeUTF8));
        checkBoxS2->setText(QApplication::translate("Waveforms", "S2", 0, QApplication::UnicodeUTF8));
        checkBoxS3->setText(QApplication::translate("Waveforms", "S3", 0, QApplication::UnicodeUTF8));
        checkBoxS4->setText(QApplication::translate("Waveforms", "S4", 0, QApplication::UnicodeUTF8));
        checkBoxS5->setText(QApplication::translate("Waveforms", "S5", 0, QApplication::UnicodeUTF8));
        checkBoxS6->setText(QApplication::translate("Waveforms", "S6", 0, QApplication::UnicodeUTF8));
        checkBoxS7->setText(QApplication::translate("Waveforms", "S7", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("Waveforms", "EXIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Waveforms: public Ui_Waveforms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORMS_H
