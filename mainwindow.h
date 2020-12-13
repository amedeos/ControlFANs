#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QMessageBox>
#include <QColor>
#include <QValidator>
#include <QIntValidator>
#include <QMessageBox>
#include <QtGlobal>
#include <QProcess>
#include "fanclass.h"
#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    void on_hwmon6radioButton_clicked();

    void on_hwmon7radioButton_clicked();

    void on_hwmon8radioButton_clicked();

    void on_hwmon9radioButton_clicked();

    void on_hwmon10radioButton_clicked();

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

    void on_editpushButton_clicked();

    void on_calcelpushButton_clicked();

    void on_savepushButton_clicked();

    void on_createSystemDpushButton_clicked();

    void on_deleteSystemDpushButton_clicked();

private:
    Ui::MainWindow *ui;
    void aboutMessage();
    void setupMenuBar();
    void hideGroup();
    void hideFanGroup();
    void disableHwmon();
    void disableFan();
    void disablePwm();
    void enablePwm();
    void setFanPwm();
    void disablePushButton();
    void enableHwmon();
    void enableFan(QString hwmonDir);
    void showFanGroup();
    void initHwmon(QString strHwmon);
    void initHwmon();
    void initFan(QString strFan);
    void enableEditButton();
    void enableDeleteSystemDStanza();
    void setupSignalsAndSlots();
    void setupPwmValidator();
    void savePwmPwm(const int i);
    void savePwmAutoPoint1Pwm(const int i);
    void savePwmAutoPoint2Pwm(const int i);
    void savePwmAutoPoint3Pwm(const int i);
    void savePwmAutoPoint4Pwm(const int i);
    void savePwmAutoPoint5Pwm(const int i);
    void savePwmAutoPoint1Temp(const int i);
    void savePwmAutoPoint2Temp(const int i);
    void savePwmAutoPoint3Temp(const int i);
    void savePwmAutoPoint4Temp(const int i);
    void savePwmAutoPoint5Temp(const int i);
    void createSystemDStanza();
    QString createSystemDExexStart();
    void deleteSystemDStanza();
};
#endif // MAINWINDOW_H
