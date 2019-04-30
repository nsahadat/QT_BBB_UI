#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showStat(void);

private slots:
   // void on_ButtonClick_clicked();

    void on_Buttonwaveform_clicked();

    void on_statButton_clicked();

    void on_ButtonCal_clicked();

    void on_ButtonTrain_clicked();

    void on_ButtonTest_clicked();

    void on_ButtonPWC_clicked();

    void on_ButtonExit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
