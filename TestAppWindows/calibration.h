#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QDialog>
#include "qcustomplot.h"
#include "sensdata.h"
#include <fstream>
#include <iostream>
#include <armadillo>
#include <QDir>

using namespace std;
using namespace arma;

namespace Ui {
class Calibration;
}

class Calibration : public QDialog
{
    Q_OBJECT

public:

    explicit Calibration(QWidget *parent = 0);
    ~Calibration();
    QString source;
    ofstream datafileout;
    mat cdata, cal_projected , cal_error;


private slots:

    void on_ButtonStart_clicked();

    void on_ButtonExit_clicked();

    void SaveData(void);

    void on_comboBox_activated(int index);

    void calibrate(void);

private:
    Ui::Calibration *ui;
   // QTimer dataTimer;
    sensdata *sd;
    int dataCounter = 0;
    QString calfilename;

    void setupCalPlot(void);
    void OpenFile(void);
    void findPort(void);

signals:
    void dataSaved();

};

#endif // CALIBRATION_H
