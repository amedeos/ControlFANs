#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 470);

    setupMenuBar();
    hideGroup();
    disableHwmon();
    disableFan();
    disablePwm();
    disablePushButton();
    enableHwmon();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMenuBar() {
    // setup menu bar
    ui->actionQuit->setShortcut(QKeySequence::Quit);
    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

void MainWindow::hideGroup() {
    // disable all groups
    ui->fangroupBox->hide();
    ui->fanDatagroupBox->hide();
    ui->pwmDatagroupBox->hide();
}

void MainWindow::disableHwmon(){
    // disable all hwmon radio buttons
    ui->hwmon0radioButton->setCheckable(false);
    ui->hwmon0radioButton->setDisabled(true);
    ui->hwmon1radioButton->setCheckable(false);
    ui->hwmon1radioButton->setDisabled(true);
    ui->hwmon2radioButton->setCheckable(false);
    ui->hwmon2radioButton->setDisabled(true);
    ui->hwmon3radioButton->setCheckable(false);
    ui->hwmon3radioButton->setDisabled(true);
    ui->hwmon4radioButton->setCheckable(false);
    ui->hwmon4radioButton->setDisabled(true);
    ui->hwmon5radioButton->setCheckable(false);
    ui->hwmon5radioButton->setDisabled(true);
}

void MainWindow::disableFan(){
    // disable all fans
    ui->fan1radioButton->setCheckable(false);
    ui->fan1radioButton->setDisabled(true);
    ui->fan2radioButton->setCheckable(false);
    ui->fan2radioButton->setDisabled(true);
    ui->fan3radioButton->setCheckable(false);
    ui->fan3radioButton->setDisabled(true);
    ui->fan4radioButton->setCheckable(false);
    ui->fan4radioButton->setDisabled(true);
    ui->fan5radioButton->setCheckable(false);
    ui->fan5radioButton->setDisabled(true);
    ui->fan6radioButton->setCheckable(false);
    ui->fan6radioButton->setDisabled(true);
    ui->fan7radioButton->setCheckable(false);
    ui->fan7radioButton->setDisabled(true);
    ui->fan8radioButton->setCheckable(false);
    ui->fan8radioButton->setDisabled(true);
    ui->fan9radioButton->setCheckable(false);
    ui->fan9radioButton->setDisabled(true);
    ui->fan10radioButton->setCheckable(false);
    ui->fan10radioButton->setDisabled(true);
}

void MainWindow::disablePwm() {
    // disable all pwm data
    ui->pwmPwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint1PwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint1TemplineEdit->setDisabled(true);
    ui->pwmAutoPoint2PwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint2TemplineEdit->setDisabled(true);
    ui->pwmAutoPoint3PwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint3TemplineEdit->setDisabled(true);
    ui->pwmAutoPoint4PwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint4TemplineEdit->setDisabled(true);
    ui->pwmAutoPoint5PwmlineEdit->setDisabled(true);
    ui->pwmAutoPoint5TemplineEdit->setDisabled(true);
}

void MainWindow::disablePushButton() {
    // disable all push button
    ui->savepushButton->setDisabled(true);
    ui->calcelpushButton->setDisabled(true);
    ui->editpushButton->setDisabled(true);
}

void MainWindow::enableHwmon(){
    // enable all available hwmon
    QString strSysClass = "/sys/class/hwmon";

    QDir hwmon0Dir = strSysClass + "/hwmon0";
    if (hwmon0Dir.exists()) {
        ui->hwmon0radioButton->setCheckable(true);
        ui->hwmon0radioButton->setDisabled(false);
    }

    QDir hwmon1Dir = strSysClass + "/hwmon1";
    if (hwmon1Dir.exists()) {
        ui->hwmon1radioButton->setCheckable(true);
        ui->hwmon1radioButton->setDisabled(false);
    }

    QDir hwmon2Dir = strSysClass + "/hwmon2";
    if (hwmon2Dir.exists()) {
        ui->hwmon2radioButton->setCheckable(true);
        ui->hwmon2radioButton->setDisabled(false);
    }

    QDir hwmon3Dir = strSysClass + "/hwmon3";
    if (hwmon3Dir.exists()) {
        ui->hwmon3radioButton->setCheckable(true);
        ui->hwmon3radioButton->setDisabled(false);
    }

    QDir hwmon4Dir = strSysClass + "/hwmon4";
    if (hwmon4Dir.exists()) {
        ui->hwmon4radioButton->setCheckable(true);
        ui->hwmon4radioButton->setDisabled(false);
    }

    QDir hwmon5Dir = strSysClass + "/hwmon5";
    if (hwmon5Dir.exists()) {
        ui->hwmon5radioButton->setCheckable(true);
        ui->hwmon5radioButton->setDisabled(false);
    }
}

void MainWindow::enableFan(QString hwmonDir) {
    ui->fangroupBox->show();

    QFile fan1_input( hwmonDir + "/fan1_input");
    if (fan1_input.exists()) {
        ui->fan1radioButton->setCheckable(true);
        ui->fan1radioButton->setDisabled(false);
    }

    QFile fan2_input( hwmonDir + "/fan2_input");
    if (fan2_input.exists()) {
        ui->fan2radioButton->setCheckable(true);
        ui->fan2radioButton->setDisabled(false);
    }

    QFile fan3_input( hwmonDir + "/fan3_input");
    if (fan3_input.exists()) {
        ui->fan3radioButton->setCheckable(true);
        ui->fan3radioButton->setDisabled(false);
    }

    QFile fan4_input( hwmonDir + "/fan4_input");
    if (fan4_input.exists()) {
        ui->fan4radioButton->setCheckable(true);
        ui->fan4radioButton->setDisabled(false);
    }

    QFile fan5_input( hwmonDir + "/fan5_input");
    if (fan5_input.exists()) {
        ui->fan5radioButton->setCheckable(true);
        ui->fan5radioButton->setDisabled(false);
    }

    QFile fan6_input( hwmonDir + "/fan6_input");
    if (fan6_input.exists()) {
        ui->fan6radioButton->setCheckable(true);
        ui->fan6radioButton->setDisabled(false);
    }

    QFile fan7_input( hwmonDir + "/fan7_input");
    if (fan7_input.exists()) {
        ui->fan7radioButton->setCheckable(true);
        ui->fan7radioButton->setDisabled(false);
    }

    QFile fan8_input( hwmonDir + "/fan8_input");
    if (fan8_input.exists()) {
        ui->fan8radioButton->setCheckable(true);
        ui->fan8radioButton->setDisabled(false);
    }

    QFile fan9_input( hwmonDir + "/fan9_input");
    if (fan9_input.exists()) {
        ui->fan9radioButton->setCheckable(true);
        ui->fan9radioButton->setDisabled(false);
    }

    QFile fan10_input( hwmonDir + "/fan10_input");
    if (fan10_input.exists()) {
        ui->fan10radioButton->setCheckable(true);
        ui->fan10radioButton->setDisabled(false);
    }
}

void MainWindow::on_hwmon0radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon0";

    disableFan();
    enableFan(strSysClass);
}

void MainWindow::on_hwmon1radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon1";

    disableFan();
    enableFan(strSysClass);
}

void MainWindow::on_hwmon2radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon2";

    disableFan();
    enableFan(strSysClass);
}

void MainWindow::on_hwmon3radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon3";

    disableFan();
    enableFan(strSysClass);
}

void MainWindow::on_hwmon4radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon4";

    disableFan();
    enableFan(strSysClass);
}

void MainWindow::on_hwmon5radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon5";

    disableFan();
    enableFan(strSysClass);
}
