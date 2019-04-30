#include "calibration.h"
#include "ui_calibration.h"

Calibration::Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calibration)
{
    ui->setupUi(this);

    // graph of the four magnetometers for calibration
    ui->comboBox->addItem("MX1");
    ui->comboBox->addItem("MY1");
    ui->comboBox->addItem("MZ1");

    ui->comboBox->addItem("MX2");
    ui->comboBox->addItem("MY2");
    ui->comboBox->addItem("MZ2");

    ui->comboBox->addItem("MX3");
    ui->comboBox->addItem("MY3");
    ui->comboBox->addItem("MZ3");

    ui->comboBox->addItem("MX4");
    ui->comboBox->addItem("MY4");
    ui->comboBox->addItem("MZ4");

    // UI progressBar size
    ui->progBar->setMinimum(0);
    ui->progBar->setMaximum(1999);

    // setup the COM ports for the data collection
    findPort();
    sd = new sensdata(source, this);
    setupCalPlot();
    sd->sensdata :: setPortTDS();  //data 0; command 1; model 2
    sd->setPortdatacmdmodel(0);

    QDir dir;
 //   qDebug() << dir.currentPath();
    if (!dir.exists(dir.currentPath() + "/TDS"))
    {
        dir.mkdir("TDS");
    }
    calfilename = dir.currentPath() + "/TDS/calibration.txt";

    // connect signals and slots
    connect(sd, SIGNAL(newData()), this, SLOT(SaveData()));

}

Calibration::~Calibration()
{
    delete ui;
}

void Calibration::setupCalPlot(void)
{

  ui->calPlot->addGraph()->setName("Dat"); // blue line
  ui->calPlot->graph(0)->setPen(QPen(QColor(0, 0, 255)));
  ui->calPlot->addGraph()->setName("Prj"); // red line
  ui->calPlot->graph(1)->setPen(QPen(QColor(0, 255, 0)));
  ui->calPlot->addGraph()->setName("Err"); // green line
  ui->calPlot->graph(2)->setPen(QPen(QColor(255, 0, 0)));

//  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
//  timeTicker->setTimeFormat("%h:%m:%s");
//  ui->calPlot->xAxis->setTicker(timeTicker);
  ui->calPlot->axisRect()->setupFullAxesBox();
  ui->calPlot->xAxis->setRange(0, 1999);
  ui->calPlot->yAxis->setRange(-1, 1);

  // label axis
  ui->calPlot->xAxis->setLabel("index");
  //ui->customPlot->yAxis->setLabel("Data");

  // legend
    QFont legendFont = font();
    legendFont.setPointSize(8);
    ui->calPlot->legend->setFont(legendFont);
//  ui->customPlot->legend->setSelectedFont(legendFont);
//  ui->customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items
    ui->calPlot->legend->setVisible(true);
//    ui->customPlot->legend->setFillOrder(QCPLegend::foColumnsFirst);

  // make left and bottom axes transfer their ranges to right and top axes:
//  connect(ui->calPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->calPlot->xAxis2, SLOT(setRange(QCPRange)));
//  connect(ui->calPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->calPlot->yAxis2, SLOT(setRange(QCPRange)));

  //dataTimer.start(10); // Interval 0 means to refresh as fast as possible
}


void Calibration::on_ButtonStart_clicked()
{
    OpenFile();
    sd->reqData();
}

void Calibration::on_ButtonExit_clicked()
{
    close();
}

void Calibration::findPort(void)
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

void Calibration::OpenFile(void)
{
    datafileout.open(calfilename.toUtf8().constData());
}

void Calibration::SaveData(void)
{
   if (dataCounter < 2000)
   {
       sd->reqData();

       for (uint8_t i = 0; i < (SENS_PKT_SIZE - 6); i++)
       {
           datafileout << (float)(sd->senData [i])* 0.000305 << " ";

       }

       datafileout << "\n";

       ui->progBar->setValue(dataCounter);

       dataCounter++;
   }

   else
   {
        datafileout.close();
        calibrate();
        emit dataSaved();
   }

}


void Calibration::on_comboBox_activated(int index)
{
    ui->calPlot->graph(0)->data()->clear();
    ui->calPlot->graph(1)->data()->clear();
    ui->calPlot->graph(2)->data()->clear();


    for (int r = 0; r<2000; r++)
    {
        for (int c = 0; c<12; c++)
        {

            if (index == c)
            {


                // add data to lines:
                ui->calPlot->graph(0)->addData(r, cdata(r,index));
                ui->calPlot->graph(1)->addData(r, cal_projected(r,index));
                ui->calPlot->graph(2)->addData(r, cal_error(r,index));

            }

        }

        //    qDebug() << endl;
    }

    // rescale value (vertical) axis to fit the current data:
    ui->calPlot->graph(0)->rescaleValueAxis(true);
    //   ui->calPlot->graph(1)->rescaleValueAxis(true);
    //   ui->calPlot->graph(2)->rescaleValueAxis(true);

    // make key axis range scroll with the data (at a constant range size of 8):
    //  ui->calPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->calPlot->replot();

}


void Calibration::calibrate(void)
{
    QDir dir;

    //float calData[2000][15];//[15];
    //mat cdata(2000,15);
    cdata = zeros(2000,15);
    mat s1, s2, s3, s4, sref;
    mat xc;         // initialize sensor matrix where ones will be added
    mat xone;       // ones matrix
    mat proj1, proj2, proj3, proj4;

    xone = ones(2000,1); // ones matrix

    ifstream datafilein;
    datafilein.open(calfilename.toUtf8().constData());

    if (datafilein.is_open())
    {
        for (int r = 0; r<2000; r++)
        {
            for (int c = 0; c<15; c++)
            {
                datafilein >> cdata(r,c);
            }
        }
    }
    datafilein.close();

    //qDebug() << cdata(1999,14);

    s1 = cdata.cols(0,2);
    s2 = cdata.cols(3,5);
    s3 = cdata.cols(6,8);
    s4 = cdata.cols(9,11);
    sref = cdata.cols(12,14);

    xc = join_horiz(xone,sref);  // ones matrix added

    // calculate projection matrixes
    proj1 = solve(xc,s1);
    proj2 = solve(xc,s2);
    proj3 = solve(xc,s3);
    proj4 = solve(xc,s4);


    // save proj1
    datafileout.open((dir.currentPath() + "/TDS/proj1.txt").toUtf8().constData());
    datafileout << proj1;
    datafileout.close();

    // save proj2
    datafileout.open((dir.currentPath() + "/TDS/proj2.txt").toUtf8().constData());
    datafileout << proj2;
    datafileout.close();

    // save proj3
    datafileout.open((dir.currentPath() + "/TDS/proj3.txt").toUtf8().constData());
    datafileout << proj3;
    datafileout.close();

    //save proj4
    datafileout.open((dir.currentPath() + "/TDS/proj4.txt").toUtf8().constData());
    datafileout << proj4;
    datafileout.close();

    // find cal projected matrixes

    cal_projected = zeros(2000,12);
    cal_error = zeros(2000,12);


    cal_projected.cols(0,2) = sref*proj1.rows(1,3) + ones(2000,1)* proj1.row(0);
    cal_projected.cols(3,5) = sref*proj2.rows(1,3) + ones(2000,1)* proj2.row(0);
    cal_projected.cols(6,8) = sref*proj3.rows(1,3) + ones(2000,1)* proj3.row(0);
    cal_projected.cols(9,11) = sref*proj4.rows(1,3)+ ones(2000,1)* proj4.row(0);

    cal_error = cdata.cols(0,11) - cal_projected;


//    qDebug() << proj1.n_rows;
//    qDebug() << proj1.n_cols;
//    qDebug() << proj1(0,0) << " "<< proj1(0, 1)<< " " << proj1(0,2);


}
