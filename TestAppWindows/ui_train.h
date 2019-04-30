/********************************************************************************
** Form generated from reading UI file 'train.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAIN_H
#define UI_TRAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Train
{
public:
    QLabel *TPic;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonStart;
    QPushButton *ButtonCollect;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progBarAll;
    QProgressBar *progBarEach;
    QPushButton *ButtonExit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *status;
    QPushButton *ButtonTransfer;
    QPushButton *ButtonTrain;

    void setupUi(QDialog *Train)
    {
        if (Train->objectName().isEmpty())
            Train->setObjectName(QString::fromUtf8("Train"));
        Train->resize(480, 250);
        TPic = new QLabel(Train);
        TPic->setObjectName(QString::fromUtf8("TPic"));
        TPic->setGeometry(QRect(40, 70, 220, 150));
        horizontalLayoutWidget = new QWidget(Train);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 461, 47));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonStart = new QPushButton(horizontalLayoutWidget);
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

        ButtonCollect = new QPushButton(horizontalLayoutWidget);
        ButtonCollect->setObjectName(QString::fromUtf8("ButtonCollect"));
        sizePolicy.setHeightForWidth(ButtonCollect->sizePolicy().hasHeightForWidth());
        ButtonCollect->setSizePolicy(sizePolicy);
        ButtonCollect->setFont(font);

        horizontalLayout->addWidget(ButtonCollect);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        progBarAll = new QProgressBar(horizontalLayoutWidget);
        progBarAll->setObjectName(QString::fromUtf8("progBarAll"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progBarAll->sizePolicy().hasHeightForWidth());
        progBarAll->setSizePolicy(sizePolicy1);
        progBarAll->setFont(font);
        progBarAll->setValue(24);

        verticalLayout_2->addWidget(progBarAll);

        progBarEach = new QProgressBar(horizontalLayoutWidget);
        progBarEach->setObjectName(QString::fromUtf8("progBarEach"));
        sizePolicy1.setHeightForWidth(progBarEach->sizePolicy().hasHeightForWidth());
        progBarEach->setSizePolicy(sizePolicy1);
        progBarEach->setFont(font);
        progBarEach->setValue(24);

        verticalLayout_2->addWidget(progBarEach);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        ButtonExit = new QPushButton(horizontalLayoutWidget);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        sizePolicy.setHeightForWidth(ButtonExit->sizePolicy().hasHeightForWidth());
        ButtonExit->setSizePolicy(sizePolicy);
        ButtonExit->setFont(font);

        horizontalLayout->addWidget(ButtonExit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        layoutWidget = new QWidget(Train);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 70, 161, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        status = new QLineEdit(layoutWidget);
        status->setObjectName(QString::fromUtf8("status"));
        sizePolicy1.setHeightForWidth(status->sizePolicy().hasHeightForWidth());
        status->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(status);

        ButtonTransfer = new QPushButton(layoutWidget);
        ButtonTransfer->setObjectName(QString::fromUtf8("ButtonTransfer"));
        sizePolicy.setHeightForWidth(ButtonTransfer->sizePolicy().hasHeightForWidth());
        ButtonTransfer->setSizePolicy(sizePolicy);
        ButtonTransfer->setFont(font);

        verticalLayout->addWidget(ButtonTransfer);

        ButtonTrain = new QPushButton(layoutWidget);
        ButtonTrain->setObjectName(QString::fromUtf8("ButtonTrain"));
        sizePolicy.setHeightForWidth(ButtonTrain->sizePolicy().hasHeightForWidth());
        ButtonTrain->setSizePolicy(sizePolicy);
        ButtonTrain->setFont(font);

        verticalLayout->addWidget(ButtonTrain);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Train);

        QMetaObject::connectSlotsByName(Train);
    } // setupUi

    void retranslateUi(QDialog *Train)
    {
        Train->setWindowTitle(QApplication::translate("Train", "TRAINING", 0, QApplication::UnicodeUTF8));
        TPic->setText(QString());
        ButtonStart->setText(QApplication::translate("Train", "START", 0, QApplication::UnicodeUTF8));
        ButtonCollect->setText(QApplication::translate("Train", "COLLECT", 0, QApplication::UnicodeUTF8));
        ButtonExit->setText(QApplication::translate("Train", "EXIT", 0, QApplication::UnicodeUTF8));
        ButtonTransfer->setText(QApplication::translate("Train", "TRANSFER", 0, QApplication::UnicodeUTF8));
        ButtonTrain->setText(QApplication::translate("Train", "TRAIN", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Train: public Ui_Train {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAIN_H
