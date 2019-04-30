#include "sensdata.h"


sensdata::sensdata(QString port, QObject *parent) : QObject(parent)
{
    firstPkt = true;
    source = port;
}

sensdata::~sensdata(){
    serialPort->close();
    delete serialPort;
}




// define global functions

void sensdata :: modSensData(uint8_t *rawData, int16_t *senData)
{
    uint8_t s = 0;
    for (uint8_t v = 0; v < NUM_BYTES_PER_PKT; v = v + 2)
    {

        *(senData + s) = (int16_t) (*(rawData +v ) << 8) | (uint8_t)*(rawData + v + 1);
        s++;
    }
}

void sensdata :: setPortTDS(void)
{
    serialPort = new QSerialPort(this);
    serialPort->setPortName(source);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
 //   serialPort->setReadBufferSize(NUM_BYTES_PER_PKT);

    if (!serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Failed to open port error" << endl;
    }
    //debugging

}

void sensdata :: setPortdatacmdmodel(int cmd)
{
    if (cmd == 1)
    {
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readData()));
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readModel()));
        connect(serialPort, SIGNAL(readyRead()),this, SLOT(readCmd()));
    }
    else if (cmd == 0)
    {
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readCmd()));
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readModel()));
        connect(serialPort, SIGNAL(readyRead()),this, SLOT(readData()));
    }
    else if (cmd == 2)
    {
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readCmd()));
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readData()));
        connect(serialPort, SIGNAL(readyRead()),this, SLOT(readModel()));
    }
    else if (cmd == 3)
    {
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readCmd()));
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readData()));
        disconnect(serialPort, SIGNAL(readyRead()),this, SLOT(readModel()));
        connect(serialPort, SIGNAL(readyRead()),this, SLOT(readCharacters()));
    }

}

void sensdata :: readCharacters()
{

    msg = serialPort->readAll();
    serialPort->clear(QSerialPort::Output);
    serialPort->clear(QSerialPort::Input);
    //qDebug() << "it's here";
    //qDebug()<<QString("packet read = %1").arg(msg.size());

    QString str;
    str.append(msg);
    qDebug()<< str;

}


void sensdata :: readData()
{
    uint8_t s = 0;

    QByteArray pktData = serialPort->readAll();
    serialPort->clear(QSerialPort::Output);
    serialPort->clear(QSerialPort::Input);


    //qDebug()<<QString("packet read = %1").arg(pktData.size())<< endl;

//    for (int i = 0; i<pktData.size(); i++)
//    {
//        qDebug()<< pktData[i];
//    }


    if (pktData.size() == NUM_BYTES_PER_PKT)
    {

        for (uint8_t v = 0; v < NUM_BYTES_PER_PKT; v = v + 2)
        {

            *(senData+ s) = (int16_t) (pktData[v]  << 8) | (uint8_t)(pktData[v+1]);

            s++;

        }

      emit newData();

    }



}

void sensdata :: readModel()
{

    QByteArray pktData = serialPort->readAll();
    serialPort->clear(QSerialPort::Output);
    serialPort->clear(QSerialPort::Input);


    qDebug()<<QString("packet read = %1").arg(pktData.size())<< endl;

//    for (int i = 0; i<pktData.size(); i++)
//    {
//        qDebug()<< pktData[i];
//    }


    if (pktData.size() == MODEL_PKT_SIZE+1)
    {


        pktModel = pktData;
        emit newModel();
    }

}

void sensdata :: readCmd()
{


    QByteArray pktData = serialPort->readAll();
    serialPort->clear(QSerialPort::Output);
    serialPort->clear(QSerialPort::Input);


    //qDebug()<<QString("packet read = %1").arg(pktData.size())<< endl;


    if (pktData.size() == CMD_PKT_SIZE)
    {
        for ( uint8_t s = 0;s<CMD_PKT_SIZE; s++)
        {
            *(senCmd+ s) = (int8_t) pktData[s];
        }
        emit newData();

    }



}

void sensdata :: reqData()
{

    serialPort->write(&reqPktData, 1);


    //qDebug() << "it's here" << endl;
}

void sensdata :: writeData(char *reqPktData, int size)
{

    serialPort->write(reqPktData,size);


    //qDebug() << "it's here" << endl;
}

void sensdata :: reqCmd()
{

    serialPort->write(&reqPktCmd, 1);


    //qDebug() << "it's here" << endl;
}

void sensdata :: reqModel(void)
{

    serialPort->write(&reqPktModel, 1);


    //qDebug() << "it's here" << endl;
}



void sensdata :: closePort(void)
{
    serialPort->close();
    delete serialPort;
}


