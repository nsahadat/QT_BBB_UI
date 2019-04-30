#include "testing.h"
#include "ui_testing.h"

Testing::Testing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testing)
{
    ui->setupUi(this);

    QDir dir;
 //   qDebug() << dir.currentPath();
    if (!dir.exists(dir.currentPath() + "/TDS"))
    {
        dir.mkdir("TDS");
    }
    trainfilename = dir.currentPath();


    // add the initial training pic
    QPixmap initial((trainfilename + "/IMG/initial.PNG").toUtf8().constData());
    ui->TestPic->setPixmap(initial);

    // setup the COM ports for the data collection
    findPort();
    sd = new sensdata(source, this);
    sd->sensdata :: setPortTDS();  //data 0; command 1; model 2
    sd->setPortdatacmdmodel(1);
    //sd->setPortdatacmdmodel(3);     // debugging characters read

    // connect signals and slots
    connect(sd, SIGNAL(newData()), this, SLOT(ShowCmd()));

}

Testing::~Testing()
{
    delete ui;
}

void Testing::on_ButtonStart_clicked()
{
    ui->Instruction->setText("Test Head and Tongue Commands");
    sd->reqCmd();
}

void Testing::on_ButtonExit_clicked()
{
    close();
}

void Testing::findPort(void)
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    //QSerialPort serialPort;

    for (QSerialPortInfo port : serialPorts)
    {

        if (port.productIdentifier() == 60000)
        {
            source = QString("%1").arg(port.portName());
        //    qDebug() << "mTDS found" << endl;

        }

    }

}

void Testing::ShowCmd(void)
{


//    QPixmap nc("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/nc.PNG");
//    QPixmap left("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/left.PNG");
//    QPixmap right("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/right.PNG");
//    QPixmap up("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/up.PNG");
//    QPixmap down("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/down.PNG");
//    QPixmap ls("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/ls.PNG");
//    QPixmap rs("D:/Google Drive/GATech/standalone TDS/QTApps/TestAppWindows/rs.PNG");


    QPixmap nc((trainfilename + "/IMG/nc.PNG").toUtf8().constData());
    QPixmap left((trainfilename + "/IMG/left.PNG").toUtf8().constData());
    QPixmap right((trainfilename + "/IMG/right.PNG").toUtf8().constData());
    QPixmap up((trainfilename + "/IMG/up.PNG").toUtf8().constData());
    QPixmap down((trainfilename + "/IMG/down.PNG").toUtf8().constData());
    QPixmap ls((trainfilename + "/IMG/ls.PNG").toUtf8().constData());
    QPixmap rs((trainfilename + "/IMG/rs.PNG").toUtf8().constData());

    sd->reqCmd();

    switch (sd->senCmd[0])
    {
    case 0:
        ui->TestPic->setPixmap(nc);
        break;
    case 1:
        ui->TestPic->setPixmap(left);
        break;
    case 2:
        ui->TestPic->setPixmap(right);
        break;
    case 3:
        ui->TestPic->setPixmap(up);
        break;
    case 4:
        ui->TestPic->setPixmap(down);
        break;
    case 5:
        ui->TestPic->setPixmap(ls);
        break;
    case 6:
        ui->TestPic->setPixmap(rs);
        break;
    }

     ui->SliderX->setValue((sd->senCmd[1]));
     ui->SliderY->setValue((-sd->senCmd[2]));

    // qDebug() << "TC: " << sd->senCmd[0] << "Roll: " << sd->senCmd[1] << "Pitch: " << sd->senCmd[2] << "\n";


}
