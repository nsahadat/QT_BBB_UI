#ifndef SENSDATA_H
#define SENSDATA_H
#include <QSerialPort>
#include <QTimer>
#include <QDialog>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include <QVector>


// defines
#define NUM_BYTES_PER_PKT 42
#define SENS_PKT_SIZE 21
#define CMD_PKT_SIZE 3


#define MODEL_PKT_SIZE 208 //64 let's send it in 4 packets

class sensdata : public QObject
{
    Q_OBJECT

public:

    // variables
    //uint8_t rawData[NUM_BYTES_PER_PKT];

    int16_t senData[SENS_PKT_SIZE];
    int8_t senCmd[CMD_PKT_SIZE];
    QString source;

private:
    //QString *portname;
    QSerialPort *serialPort;
    const char reqPktData = 11;
    const char reqPktCmd = 22;
    const char reqPktModel = 33;
    bool firstPkt;

public:
    explicit sensdata(QString port, QObject *parent = nullptr);
    ~sensdata();

    void modSensData(uint8_t *rawData, int16_t *senData);
    void setPortTDS(void);
    void setPortdatacmdmodel(int cmd);
    void closePort(void);
    void writeData(char *reqPktData, int size);
    void reqModel(void);
    QByteArray pktModel;
    QByteArray msg;



public slots:
    void reqData();
    void reqCmd();

private slots:
    void readData();
    void readCmd();
    void readModel();
    void readCharacters();

signals:
    void newData();
    void newModel();

};

#endif // SENSDATA_H
