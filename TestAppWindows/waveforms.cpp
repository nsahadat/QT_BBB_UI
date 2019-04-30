#include "waveforms.h"
#include "ui_waveforms.h"




Waveforms::Waveforms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Waveforms)
{
    ui->setupUi(this);
//    commonmTDS *cmTDS;
    findPort();
    sd = new sensdata(source, this);
    setupPlot();
    sd->sensdata :: setPortTDS();  //data 0; command 1; model 2
    sd->setPortdatacmdmodel(0);

    QDir dir;
    //qDebug() << dir.currentPath();
    if (!dir.exists(dir.currentPath() + "/TDS"))
    {
        dir.mkdir("TDS");
    }
    wavefilename = dir.currentPath() + "/TDS/wave.txt";

    OpenFile();
    // connect signals and slots
    connect(sd, SIGNAL(newData()), this, SLOT(SaveData()));
    connect(sd, SIGNAL(newData()), this, SLOT(PlotGraph()));


}

Waveforms::~Waveforms()
{
    datafile.close();
    delete ui;
}



void Waveforms::on_ButtonExit_clicked()
{
    close();
}


void Waveforms::setupPlot(void)
{

  ui->customPlot->addGraph()->setName("X"); // blue line
  ui->customPlot->graph(0)->setPen(QPen(QColor(0, 0, 255)));
  ui->customPlot->addGraph()->setName("Y"); // red line
  ui->customPlot->graph(1)->setPen(QPen(QColor(255, 0, 0)));
  ui->customPlot->addGraph()->setName("Z"); // green line
  ui->customPlot->graph(2)->setPen(QPen(QColor(0, 255, 0)));

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  ui->customPlot->xAxis->setTicker(timeTicker);
  ui->customPlot->axisRect()->setupFullAxesBox();
  //ui->customPlot->yAxis->setRange(-32767, 32767);

  // label axis
  ui->customPlot->xAxis->setLabel("Time (s)");
  //ui->customPlot->yAxis->setLabel("Data");

  // legend
    QFont legendFont = font();
    legendFont.setPointSize(8);
    ui->customPlot->legend->setFont(legendFont);
//  ui->customPlot->legend->setSelectedFont(legendFont);
//  ui->customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items
    ui->customPlot->legend->setVisible(true);
//    ui->customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

  dataTimer.start(10); // Interval 0 means to refresh as fast as possible
}


void Waveforms::PlotGraph(void)
{
    sd->reqData();

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    //connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    //dataTimer.start(0); // Interval 0 means to refresh as fast as possible
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds

      // add data to lines:
      ui->customPlot->graph(0)->addData(key, sd->senData [cw + 0]);
      ui->customPlot->graph(1)->addData(key, sd->senData [cw + 1]);
      ui->customPlot->graph(2)->addData(key, sd->senData [cw + 2]);


      // rescale value (vertical) axis to fit the current data:
      ui->customPlot->graph(0)->rescaleValueAxis(true);
      ui->customPlot->graph(1)->rescaleValueAxis(true);
      ui->customPlot->graph(2)->rescaleValueAxis(true);

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
}

void Waveforms:: ClearGraph(void)
{

    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->graph(1)->data()->clear();
    ui->customPlot->graph(2)->data()->clear();

   // ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
}

void Waveforms:: ChooseGraph(bool checked)
{

    if (checked)
    {
        disconnect(&dataTimer, SIGNAL(timeout()), this, SLOT(ClearGraph()));
        connect(&dataTimer, SIGNAL(timeout()), sd, SLOT(reqData()));

    }

    else
    {
        disconnect(&dataTimer, SIGNAL(timeout()), sd, SLOT(reqData()));
        connect(&dataTimer, SIGNAL(timeout()), this, SLOT(ClearGraph()));
    }

}



void Waveforms::on_checkBoxS1_clicked(bool checked)
{

    ChooseGraph(checked);
    cw = 0;

}


void Waveforms::on_checkBoxS2_clicked(bool checked)
{
    ChooseGraph(checked);
    cw = 3;
}

void Waveforms::on_checkBoxS3_clicked(bool checked)
{
   ChooseGraph(checked);
   cw = 6;
}

void Waveforms::on_checkBoxS4_clicked(bool checked)
{
    ChooseGraph(checked);
    cw = 9;
}

void Waveforms::on_checkBoxS5_clicked(bool checked)
{
    ChooseGraph(checked);
    cw = 12;
}

void Waveforms::on_checkBoxS6_clicked(bool checked)
{
    ChooseGraph(checked);
    cw = 15;
}

void Waveforms::on_checkBoxS7_clicked(bool checked)
{
    ChooseGraph(checked);
    cw = 18;

}

void Waveforms::OpenFile(void)
{
    datafile.open(wavefilename.toUtf8().constData());
}

void Waveforms::SaveData(void)
{
    sd->reqData();

    for (uint8_t i = 0; i < SENS_PKT_SIZE; i++)
    {
        datafile << sd->senData [i] << " ";

    }

    datafile << "\n";
}

void Waveforms::findPort(void)
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    //QSerialPort serialPort;

    for (QSerialPortInfo port : serialPorts)
    {

        if (port.productIdentifier() == 60000)
        {
            source = QString("%1").arg(port.portName());
         //   qDebug() << "mTDS found" << endl;

        }

    }

}

