#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QString>
#include <QMessageBox>

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

private:
    Ui::MainWindow *ui;

    // init methods
    void setupMenuBar();
    void hideGroup();
    void disableHwmon();
    void disableFan();
    void disablePwm();
    void disablePushButton();
    void enableHwmon();
    void enableFan(QString hwmonDir);
};
#endif // MAINWINDOW_H
