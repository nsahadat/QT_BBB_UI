#ifndef TRAIN_H
#define TRAIN_H

#include <QDialog>
#include "sensdata.h"
#include "svm.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <armadillo>
#include <QDir>
#include <QString>
#include <ctype.h>
#include <stdlib.h>

#define Malloc(type,n) (type *)malloc((n)*sizeof(type))

using namespace std;
using namespace arma;

namespace Ui {
class Train;
}

class Train : public QDialog
{
    Q_OBJECT

public:
    explicit Train(QWidget *parent = 0);
    ~Train();
     QString source;
     ofstream datafileout;
     uint8_t command=0;
     uint8_t round = 0;
     int dataCounter = 0;
     mat cdata;
     mat proj1, proj2, proj3, proj4;
     mat cfeature;
     char trbuff[1236];

     //SVM Variables
     struct svm_parameter param;		// set by parse_command_line
     struct svm_problem prob;		// set by read_problem
     struct svm_model *model;
     struct svm_node *x_space;
     int cross_validation;
     int nr_fold;
     char *line = NULL;
     int max_line_len;

     // SVM functions
     void read_problem(const char *filename);
     char* readline(FILE *input);
     void mTDS_train(const char *input_file_name,  const char *model_file_name, const char *Bfile, const char *Coefffile, const char *SVfile, const char *nSVfile);
     void svm_save_W_b(const char *Bfile, const char *Coefffile, const char *SVfile, const char *nSVfile, const svm_model *model);
     void exit_input_error(int line_num);
     void CalW(void);


private slots:
    void on_ButtonStart_clicked();

    void on_ButtonExit_clicked();

    void SaveData(void);

    void changePic(void);

    void on_ButtonCollect_clicked();

    void on_ButtonTrain_clicked();

    void on_ButtonTransfer_clicked();
    void modelreceived();

private:
    Ui::Train *ui;

    sensdata *sd;
    QString trainfilename;
    int pktsent = 0;
    union FU {
        float f;
        char fBuff[sizeof(float)];
    }fu;

    void OpenFile(char *filename);
    void findPort(void);
    void removeEMF(void);
    void genOutputFile(int pos, char *inputFile, char *outputFile);
    void formatTrainingData(char *inputFile1, char *inputFile2, char *inputFile3, char *inputFile4, char *inputFile5, char *inputFile6, char *inputFile7, char *outputFile);
    void loadBuffer(void);

signals:
    void dataSaved();
};

#endif // TRAIN_H
