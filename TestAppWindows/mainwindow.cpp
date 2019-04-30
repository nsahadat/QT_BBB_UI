#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waveforms.h"
#include "calibration.h"
#include "train.h"
#include "testing.h"
#include "pwc.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showStat();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStat(void)
{

    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    for (QSerialPortInfo port : serialPorts)
    {

        if (port.productIdentifier() == 60000)
        {
            ui->TextDisp->setText(QString("mTDS connected: %1").arg(port.portName()));
        }
        else
        {
            ui->TextDisp->setText(QString("mTDS not found"));
        }

    }

    if(serialPorts.isEmpty())
    {
        ui->TextDisp->setText(QString("mTDS not connected"));
    }

}

void MainWindow::on_Buttonwaveform_clicked()
{
    Waveforms waveformdial;
    waveformdial.setModal(true);
    waveformdial.exec();

}

void MainWindow::on_statButton_clicked()
{
    showStat();
}

void MainWindow::on_ButtonCal_clicked()
{
    Calibration calb;
    calb.setModal(true);
    calb.exec();
}

void MainWindow::on_ButtonTrain_clicked()
{
    Train train;
    train.setModal(true);
    train.exec();
}

void MainWindow::on_ButtonTest_clicked()
{
    Testing test;
    test.setModal(true);
    test.exec();
}

void MainWindow::on_ButtonPWC_clicked()
{
    PWC pwcdrive;
    pwcdrive.setModal(true);
    pwcdrive.exec();
}

void MainWindow::on_ButtonExit_clicked()
{
    close();
}
