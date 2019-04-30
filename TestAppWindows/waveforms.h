#ifndef WAVEFORMS_H
#define WAVEFORMS_H

#include <QDialog>

#include <QTimer>
#include "qcustomplot.h"
#include "sensdata.h"
//#include <QFile>
#include <fstream>
#include <iostream>
#include <QDir>


using namespace std;

namespace Ui {
class Waveforms;
}

class Waveforms : public QDialog
{
    Q_OBJECT

public:

    uint8_t cw;
 //   QTextStream out;
    ofstream datafile;
    QString source;

    explicit Waveforms(QWidget *parent = 0);
    ~Waveforms();
    void setupPlot(void);


private slots:
    void on_ButtonExit_clicked();
    void PlotGraph(void);
    void ClearGraph(void);
    void SaveData(void);


    void on_checkBoxS1_clicked(bool checked);

    void on_checkBoxS2_clicked(bool checked);

    void on_checkBoxS3_clicked(bool checked);

    void on_checkBoxS4_clicked(bool checked);

    void on_checkBoxS5_clicked(bool checked);

    void on_checkBoxS6_clicked(bool checked);

    void on_checkBoxS7_clicked(bool checked);


private:
    Ui::Waveforms *ui;
    QTimer dataTimer;
    sensdata *sd;
    QString wavefilename;
    void OpenFile(void);
    void ChooseGraph(bool checked);
    void findPort(void);
};

#endif // WAVEFORMS_H
