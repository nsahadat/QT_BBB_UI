/********************************************************************************
** Form generated from reading UI file 'testing.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTING_H
#define UI_TESTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Testing
{
public:
    QLabel *TestPic;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonStart;
    QLineEdit *Instruction;
    QPushButton *ButtonExit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSlider *SliderY;
    QSlider *SliderX;

    void setupUi(QDialog *Testing)
    {
        if (Testing->objectName().isEmpty())
            Testing->setObjectName(QString::fromUtf8("Testing"));
        Testing->resize(480, 250);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Testing->setFont(font);
        TestPic = new QLabel(Testing);
        TestPic->setObjectName(QString::fromUtf8("TestPic"));
        TestPic->setGeometry(QRect(20, 70, 220, 150));
        TestPic->setAutoFillBackground(true);
        layoutWidget = new QWidget(Testing);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 451, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonStart = new QPushButton(layoutWidget);
        ButtonStart->setObjectName(QString::fromUtf8("ButtonStart"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonStart->sizePolicy().hasHeightForWidth());
        ButtonStart->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        ButtonStart->setFont(font1);

        horizontalLayout->addWidget(ButtonStart);

        Instruction = new QLineEdit(layoutWidget);
        Instruction->setObjectName(QString::fromUtf8("Instruction"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Instruction->sizePolicy().hasHeightForWidth());
        Instruction->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Instruction);

        ButtonExit = new QPushButton(layoutWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy);
        ButtonExit->setFont(font1);

        horizontalLayout->addWidget(ButtonExit);

        layoutWidget1 = new QWidget(Testing);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 80, 161, 131));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SliderY = new QSlider(layoutWidget1);
        SliderY->setObjectName(QString::fromUtf8("SliderY"));
        SliderY->setFont(font1);
        SliderY->setAutoFillBackground(true);
        SliderY->setMinimum(-80);
        SliderY->setMaximum(80);
        SliderY->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(SliderY);

        SliderX = new QSlider(layoutWidget1);
        SliderX->setObjectName(QString::fromUtf8("SliderX"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SliderX->sizePolicy().hasHeightForWidth());
        SliderX->setSizePolicy(sizePolicy2);
        SliderX->setFont(font1);
        SliderX->setAutoFillBackground(true);
        SliderX->setMinimum(-80);
        SliderX->setMaximum(80);
        SliderX->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(SliderX);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        retranslateUi(Testing);

        QMetaObject::connectSlotsByName(Testing);
    } // setupUi

    void retranslateUi(QDialog *Testing)
    {
        Testing->setWindowTitle(QApplication::translate("Testing", "TESTING", 0, QApplication::UnicodeUTF8));
        TestPic->setText(QString());
        ButtonStart->setText(QApplication::translate("Testing", "START", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("Testing", "EXIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Testing: public Ui_Testing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTING_H
