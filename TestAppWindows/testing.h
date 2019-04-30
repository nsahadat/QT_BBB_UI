#ifndef TESTING_H
#define TESTING_H

#include <QDialog>
#include "sensdata.h"
#include <QDir>

namespace Ui {
class Testing;
}

class Testing : public QDialog
{
    Q_OBJECT

public:
    explicit Testing(QWidget *parent = 0);
    ~Testing();

    QString source;


private slots:
    void on_ButtonStart_clicked();

    void on_ButtonExit_clicked();

    void ShowCmd(void);

private:
    Ui::Testing *ui;

    sensdata *sd;

    QString trainfilename;

    void findPort(void);
};

#endif // TESTING_H
