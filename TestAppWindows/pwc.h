#ifndef PWC_H
#define PWC_H

#include <QDialog>
#include "sensdata.h"
#include <QDir>
#include "PWC_Drive.h"

namespace Ui {
class PWC;
}

class PWC : public QDialog
{
    Q_OBJECT

public:
    explicit PWC(QWidget *parent = 0);
    ~PWC();

    QString source;


private slots:
    void on_ButtonExit_clicked();

    void ShowCmd(void);

    void on_ButtonStart_clicked();

    void on_ButtonStop_clicked();

private:
    Ui::PWC *ui;

    sensdata *sd;

    QString trainfilename;

    int PrevPosition;
    int currentspeed;
    bool latchpwc = false;

    void findPort(void);
    int speedchange (int currentspd);

};

#endif // PWC_H
