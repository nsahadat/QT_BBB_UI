/********************************************************************************
** Form generated from reading UI file 'pwc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWC_H
#define UI_PWC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PWC
{
public:
    QLabel *TestPic;
    QSlider *SliderX;
    QSlider *SliderY;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonStart;
    QLineEdit *Info;
    QPushButton *ButtonStop;
    QPushButton *ButtonExit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *CBTL;
    QCheckBox *CBHuL;
    QCheckBox *CBTuLHR;
    QCheckBox *CBTRHFB;
    QCheckBox *CBTLHR;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBoxLT;
    QSpinBox *spinBoxRT;
    QSpinBox *spinBoxFT;
    QSpinBox *spinBoxBT;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *PWC)
    {
        if (PWC->objectName().isEmpty())
            PWC->setObjectName(QString::fromUtf8("PWC"));
        PWC->resize(480, 250);
        TestPic = new QLabel(PWC);
        TestPic->setObjectName(QString::fromUtf8("TestPic"));
        TestPic->setGeometry(QRect(30, 80, 220, 150));
        TestPic->setAutoFillBackground(true);
        SliderX = new QSlider(PWC);
        SliderX->setObjectName(QString::fromUtf8("SliderX"));
        SliderX->setGeometry(QRect(300, 80, 150, 22));
        SliderX->setMinimum(-90);
        SliderX->setMaximum(90);
        SliderX->setOrientation(Qt::Horizontal);
        SliderY = new QSlider(PWC);
        SliderY->setObjectName(QString::fromUtf8("SliderY"));
        SliderY->setGeometry(QRect(260, 80, 22, 150));
        SliderY->setMinimum(-90);
        SliderY->setMaximum(90);
        SliderY->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(PWC);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 9, 461, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonStart = new QPushButton(layoutWidget);
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

        horizontalLayout->addWidget(ButtonStart);

        Info = new QLineEdit(layoutWidget);
        Info->setObjectName(QString::fromUtf8("Info"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Info->sizePolicy().hasHeightForWidth());
        Info->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Info);

        ButtonStop = new QPushButton(layoutWidget);
        ButtonStop->setObjectName(QString::fromUtf8("ButtonStop"));
        sizePolicy.setHeightForWidth(ButtonStop->sizePolicy().hasHeightForWidth());
        ButtonStop->setSizePolicy(sizePolicy);
        ButtonStop->setFont(font);

        horizontalLayout->addWidget(ButtonStop);

        ButtonExit = new QPushButton(layoutWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy);
        ButtonExit->setFont(font);

        horizontalLayout->addWidget(ButtonExit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayoutWidget = new QWidget(PWC);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 461, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        CBTL = new QCheckBox(horizontalLayoutWidget);
        CBTL->setObjectName(QString::fromUtf8("CBTL"));
        sizePolicy.setHeightForWidth(CBTL->sizePolicy().hasHeightForWidth());
        CBTL->setSizePolicy(sizePolicy);
        CBTL->setFont(font);

        horizontalLayout_2->addWidget(CBTL);

        CBHuL = new QCheckBox(horizontalLayoutWidget);
        CBHuL->setObjectName(QString::fromUtf8("CBHuL"));
        sizePolicy.setHeightForWidth(CBHuL->sizePolicy().hasHeightForWidth());
        CBHuL->setSizePolicy(sizePolicy);
        CBHuL->setFont(font);

        horizontalLayout_2->addWidget(CBHuL);

        CBTuLHR = new QCheckBox(horizontalLayoutWidget);
        CBTuLHR->setObjectName(QString::fromUtf8("CBTuLHR"));
        sizePolicy.setHeightForWidth(CBTuLHR->sizePolicy().hasHeightForWidth());
        CBTuLHR->setSizePolicy(sizePolicy);
        CBTuLHR->setFont(font);

        horizontalLayout_2->addWidget(CBTuLHR);

        CBTRHFB = new QCheckBox(horizontalLayoutWidget);
        CBTRHFB->setObjectName(QString::fromUtf8("CBTRHFB"));
        sizePolicy.setHeightForWidth(CBTRHFB->sizePolicy().hasHeightForWidth());
        CBTRHFB->setSizePolicy(sizePolicy);
        CBTRHFB->setFont(font);

        horizontalLayout_2->addWidget(CBTRHFB);

        CBTLHR = new QCheckBox(horizontalLayoutWidget);
        CBTLHR->setObjectName(QString::fromUtf8("CBTLHR"));
        sizePolicy.setHeightForWidth(CBTLHR->sizePolicy().hasHeightForWidth());
        CBTLHR->setSizePolicy(sizePolicy);
        CBTLHR->setFont(font);

        horizontalLayout_2->addWidget(CBTLHR);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayoutWidget_2 = new QWidget(PWC);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(290, 110, 181, 113));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        spinBoxLT = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxLT->setObjectName(QString::fromUtf8("spinBoxLT"));
        sizePolicy.setHeightForWidth(spinBoxLT->sizePolicy().hasHeightForWidth());
        spinBoxLT->setSizePolicy(sizePolicy);
        spinBoxLT->setMinimum(-30);
        spinBoxLT->setMaximum(0);
        spinBoxLT->setValue(-15);

        verticalLayout->addWidget(spinBoxLT);

        spinBoxRT = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxRT->setObjectName(QString::fromUtf8("spinBoxRT"));
        sizePolicy.setHeightForWidth(spinBoxRT->sizePolicy().hasHeightForWidth());
        spinBoxRT->setSizePolicy(sizePolicy);
        spinBoxRT->setMinimum(0);
        spinBoxRT->setMaximum(30);
        spinBoxRT->setValue(15);

        verticalLayout->addWidget(spinBoxRT);

        spinBoxFT = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxFT->setObjectName(QString::fromUtf8("spinBoxFT"));
        sizePolicy.setHeightForWidth(spinBoxFT->sizePolicy().hasHeightForWidth());
        spinBoxFT->setSizePolicy(sizePolicy);
        spinBoxFT->setMinimum(0);
        spinBoxFT->setMaximum(30);
        spinBoxFT->setValue(20);

        verticalLayout->addWidget(spinBoxFT);

        spinBoxBT = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxBT->setObjectName(QString::fromUtf8("spinBoxBT"));
        sizePolicy.setHeightForWidth(spinBoxBT->sizePolicy().hasHeightForWidth());
        spinBoxBT->setSizePolicy(sizePolicy);
        spinBoxBT->setMinimum(-30);
        spinBoxBT->setMaximum(0);
        spinBoxBT->setValue(-20);

        verticalLayout->addWidget(spinBoxBT);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PWC);

        QMetaObject::connectSlotsByName(PWC);
    } // setupUi

    void retranslateUi(QDialog *PWC)
    {
        PWC->setWindowTitle(QApplication::translate("PWC", "Dialog", 0, QApplication::UnicodeUTF8));
        TestPic->setText(QString());
        ButtonStart->setText(QApplication::translate("PWC", "START", 0, QApplication::UnicodeUTF8));
        ButtonStop->setText(QApplication::translate("PWC", "STOP", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("PWC", "EXIT", 0, QApplication::UnicodeUTF8));
        CBTL->setText(QApplication::translate("PWC", "T(l)", 0, QApplication::UnicodeUTF8));
        CBHuL->setText(QApplication::translate("PWC", "H(sl)", 0, QApplication::UnicodeUTF8));
        CBTuLHR->setText(QApplication::translate("PWC", "T(ul)H(r)", 0, QApplication::UnicodeUTF8));
        CBTRHFB->setText(QApplication::translate("PWC", "T(r)H(fb)", 0, QApplication::UnicodeUTF8));
        CBTLHR->setText(QApplication::translate("PWC", "T(l)H(r)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PWC", "Left Angle", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PWC", "Right Angle", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PWC", "Forw Angle", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PWC", "Back Angle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PWC: public Ui_PWC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWC_H
