#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include "fanclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern fanClass g_fanDev;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hwmon0radioButton_clicked();

    void on_hwmon1radioButton_clicked();

    void on_hwmon2radioButton_clicked();

    void on_hwmon3radioButton_clicked();

    void on_hwmon4radioButton_clicked();

    void on_hwmon5radioButton_clicked();

    void on_fan1radioButton_clicked();

    void on_fan2radioButton_clicked();

    void on_fan3radioButton_clicked();

    void on_fan4radioButton_clicked();

    void on_fan5radioButton_clicked();

    void on_fan6radioButton_clicked();

    void on_fan7radioButton_clicked();

    void on_fan8radioButton_clicked();

    void on_fan9radioButton_clicked();

    void on_fan10radioButton_clicked();

private:
    Ui::MainWindow *ui;

    // init methods
    void setupMenuBar();
    void hideGroup();
    void hideFanGroup();
    void disableHwmon();
    void disableFan();
    void disablePwm();
    void setFanPwm();
    void disablePushButton();
    void enableHwmon();
    void enableFan(QString hwmonDir);
    void showFanGroup();
    void initHwmon(QString strHwmon);
    void initFan(QString strFan);
};
#endif // MAINWINDOW_H
