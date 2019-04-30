#include "pwc.h"
#include "ui_pwc.h"

PWC::PWC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PWC)
{
    ui->setupUi(this);

    QDir dir;
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

    // driving function initialization
    init_GPIO();       // initilization of GPIO Pin


    //----------- PWC initialization-------------//
    init_DAC();
    init_pwc();           // analog output to make all of them +6V
  
}

PWC::~PWC()
{
    delete ui;
}

void PWC::on_ButtonExit_clicked()
{
    close();
}

void PWC::findPort(void)
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

void PWC::ShowCmd(void)
{

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

    ui->SliderX->setValue(sd->senCmd[1]);
    ui->SliderY->setValue(sd->senCmd[2]);

    // speedchange calling here
    if (sd->senCmd[0] == 1 || sd->senCmd[0] == 2 || sd->senCmd[0] == 3 || sd->senCmd[0] == 4)		// checking whether left/right/up/down
    {

        if (PrevPosition == sd->senCmd[0])
        {
            currentspeed = speedchange (currentspeed);
        }
        else
        {

        }
        PrevPosition = sd->senCmd[0];
    }
    else
    {
        PrevPosition = 0;
        currentspeed = 1;
    }


    // check the modes and do actions

    // unlatched tongue commands to drive the wheelchair

/*    if(ui->CBTuL->isChecked())
    {
        switch(sd->senCmd[0])
        {

        case 1:

            //pwc_right(currentspeed);			//pwc right
            pwc_right(currentspeed);
            break;

        case 2:

            pwc_left(currentspeed);				// pwc left
            break;

        case 3:

            pwc_forward(8);           // pwc forward
            break;

        case 4:
            pwc_backward(6);			// pwc backward
            break;

        case 5:
            init_pwc();
            break;

        case 6:
            init_pwc();
            break;

        case 0:

            init_pwc();
            break;

        default:

            init_pwc();				// pwc resting
            break;

        }
    }*/

    // Head motion unlatched driving
    if(ui->CBHuL->isChecked())
    {
        if (sd->senCmd[1]>ui->spinBoxRT->value())           // X rotation
        {
            pwc_left(5);				// pwc left
        }
        else if (sd->senCmd[1]<ui->spinBoxLT->value())           // X rotation
        {
            pwc_right(5);				// pwc right
        }
        else if (sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value())
        {
            init_pwc_latched();
        }

        if (sd->senCmd[2]>ui->spinBoxFT->value())           // Y rotation
        {
            pwc_forward(7);				// pwc forward
        }

        else if (sd->senCmd[2]<ui->spinBoxBT->value())           // Y rotation
        {
            pwc_backward(7);				// pwc backward
        }

        if ((sd->senCmd[2]<ui->spinBoxFT->value() && sd->senCmd[2]>ui->spinBoxBT->value()) & (sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value()))
        {
            init_pwc();				// pwc resting
        }


    }

    // Tongue motion latched driving
    if(ui->CBTL->isChecked())
    {
        if (latchpwc)
        {
            pwc_forward(7);				// pwc forward
            ui->Info->setText("Latched Driving");
        }
        // left right vector implementation
        if (sd->senCmd[0] == 1)
        {
            pwc_right(currentspeed);
        }
        else if (sd->senCmd[0] == 2)
        {
            pwc_left(currentspeed);
        }
        else if (sd->senCmd[0]==3)           // forward tongue command
        {
            pwc_forward(7);				// pwc forward
        }
        else if (sd->senCmd[0]==4)
        {
            //latchpwc = false;           // unlatching
            pwc_backward(6);            // backwarwd
        }
        else if (sd->senCmd[0]==5)
        {

            latchpwc = true;            // latching

        }
        else if (sd->senCmd[0]==6)
        {
            //init_pwc();				// pwc resting
            latchpwc = false;           // unlatching
            ui->Info->setText("unLatched Driving");
        }
        else if (sd->senCmd[0]==0)
        {
            init_pwc_latched();

        }



        // stopping mechanism

        if (!latchpwc & sd->senCmd[0]==0)
        {
            init_pwc();				// pwc resting
        }

    }

    //Tongue unlatched head rotation
    if (ui->CBTuLHR->isChecked())
    {
        if (sd->senCmd[1]>ui->spinBoxRT->value())           // X rotation
        {
            pwc_left(5);				// pwc left
        }
        else if (sd->senCmd[1]<ui->spinBoxLT->value())           // X rotation
        {
            pwc_right(5);				// pwc right
        }
        else if (sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value())
        {
            init_pwc_latched();
        }

        // forward and backward movements

        if (sd->senCmd[0]==3)           // forward tongue command
        {
            pwc_forward(7);				// pwc forward
        }

        else if (sd->senCmd[0]==4)           // backward tongue command
        {
            pwc_backward(6);				// pwc backward
        }
	else if (sd->senCmd[0]==1 || sd->senCmd[0]==2 || sd->senCmd[0]==5 || sd->senCmd[0]==6)		// testing
	{
	    init_FB_pwc();			// forward / backaward vector should be zero	
	}

        if ((sd->senCmd[0]==0) & (sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value()))
        {
            init_pwc();				// pwc resting
        }
    }

    // Tongue latched head rotation
    if (ui->CBTLHR->isChecked())
    {
        if (latchpwc)
        {
            pwc_forward(7);				// pwc forward
            ui->Info->setText("Latched Driving");
        }

        if (sd->senCmd[0]==3)           // forward tongue command
        {
            pwc_forward(7);				// pwc forward
        }
        else if (sd->senCmd[0]==4)
        {
            //latchpwc = false;           // unlatching
            pwc_backward(6);            // backwarwd
        }
        else if (sd->senCmd[0]==5)
        {
            latchpwc = true;            // latching
        }
        else if (sd->senCmd[0]==6)
        {
            init_pwc();				// pwc resting
            latchpwc = false;           // unlatching
            ui->Info->setText("unLatched Driving");
        }
	else if (sd->senCmd[0]==1 || sd->senCmd[0]==2)		// testing
	{
	    init_FB_pwc();			// forward / backaward vector should be zero
	}


        // left right rotation
        if (sd->senCmd[1]>ui->spinBoxRT->value())           // X rotation
        {
            pwc_left(5);				// pwc left
        }
        else if (sd->senCmd[1]<ui->spinBoxLT->value())           // X rotation
        {
            pwc_right(5);				// pwc right
        }
        else if (sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value())
        {
            init_pwc_latched();
        }

        // stoping wheelchair
        if ((sd->senCmd[1]<ui->spinBoxRT->value() && sd->senCmd[1]>ui->spinBoxLT->value()) & (!latchpwc) & (sd->senCmd[0]==0))
        {
            init_pwc();				// pwc resting
        }
    }

    // head latched tongue rotation
    if (ui->CBTRHFB->isChecked())
    {
        if (latchpwc)
        {
            pwc_forward(7);				// pwc forward
            ui->Info->setText("Latched Driving");
        }

        if ((sd->senCmd[2]>ui->spinBoxFT->value()) & (sd->senCmd[2]<ui->spinBoxFT->value()+30))           // forward head forward
        {
            pwc_forward(7);				// pwc forward
        }
        else if (sd->senCmd[2]<ui->spinBoxBT->value())      // head backward
        {
            //latchpwc = false;           // unlatching
            pwc_backward(6);            // backwarwd
        }
        if (sd->senCmd[2]>(ui->spinBoxFT->value()+30))      // use head orientation
        {
            latchpwc = true;            // latching
        }
        if (sd->senCmd[1]<(ui->spinBoxLT->value()-10))      // use head to stop
        {
            init_pwc();				// pwc resting
            latchpwc = false;           // unlatching
            ui->Info->setText("unLatched Driving");
        }

        // left right rotation
        if (sd->senCmd[0]==1)           // X rotation
        {
            pwc_right(5);				// pwc left
        }
        else if (sd->senCmd[0]==2)           // X rotation
        {
            pwc_left(5);				// pwc right
        }
        else
        {
            init_pwc_latched();
        }

        // stoping wheelchair
        if ((sd->senCmd[2]<ui->spinBoxFT->value() && sd->senCmd[2]>ui->spinBoxBT->value()) & (!latchpwc) & (sd->senCmd[0]==0))
        {
            init_pwc();				// pwc resting
        }
    }


    // qDebug() << "TC: " << sd->senCmd[0] << "Roll: " << sd->senCmd[1] << "Pitch: " << sd->senCmd[2] << "\n";


}


void PWC::on_ButtonStart_clicked()
{
    // connect signals and slots
    latchpwc = false;           // make it false to start any mode
    connect(sd, SIGNAL(newData()), this, SLOT(ShowCmd()));
    sd->reqCmd();

}

void PWC::on_ButtonStop_clicked()
{
    disconnect(sd, SIGNAL(newData()), this, SLOT(ShowCmd()));
}


//---------------speed change implementation-----------------//

int PWC::speedchange (int currentspd)
{
    if (currentspd<8 )
    {

        ++currentspd;

    }

    return currentspd;

}

