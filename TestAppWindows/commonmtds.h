#ifndef COMMONTDS_H
#define COMMONTDS_H
#include <QSerialPortInfo>

class commonmTDS
{
public:
    QString source;

    void findPort(void)
    {
        QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
        //QSerialPort serialPort;

        for (QSerialPortInfo port : serialPorts)
        {

            if (port.productIdentifier() == 60000)
            {
                source = QString("%1").arg(port.portName());
                qDebug() << "mTDS found" << endl;

            }

        }

    }
};




#endif // COMMONTDS_H
