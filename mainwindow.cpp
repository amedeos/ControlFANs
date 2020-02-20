#include "mainwindow.h"
#include "ui_mainwindow.h"

fanClass g_fanDev;

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

void MainWindow::setFanPwm() {
    // set all fan / pwm data
    int i = 0;
    QColor highValue = Qt::red;
    QColor lowValue = Qt::blue;
    QString strHighValue = "color: red;";
    QString strLowValue = "color: blue;";

    // alarm
    i = g_fanDev.getFanAlarm();
    ui->fanAlarmlcdNumber->display(i);
    if (i > 0 ) {
        ui->fanAlarmlcdNumber->setPalette(highValue);
    } else {
        ui->fanAlarmlcdNumber->setPalette(lowValue);
    }

    // beep
    i = g_fanDev.getFanBeep();
    ui->fanBeeplcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanBeeplcdNumber->setPalette(highValue);
    } else {
        ui->fanBeeplcdNumber->setPalette(lowValue);
    }

    // input
    i = g_fanDev.getFanInput();
    ui->fanInputlcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanInputlcdNumber->setPalette(highValue);
    } else {
        ui->fanInputlcdNumber->setPalette(lowValue);
    }


    // min
    i = g_fanDev.getFanMin();
    ui->fanMinlcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanMinlcdNumber->setPalette(highValue);
    } else {
        ui->fanMinlcdNumber->setPalette(lowValue);
    }

    // pulses
    i = g_fanDev.getFanPulses();
    ui->fanPulseslcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanPulseslcdNumber->setPalette(highValue);
    } else {
        ui->fanPulseslcdNumber->setPalette(lowValue);
    }

    // target
    i = g_fanDev.getFanTarget();
    ui->fanTargetlcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanTargetlcdNumber->setPalette(highValue);
    } else {
        ui->fanTargetlcdNumber->setPalette(lowValue);
    }

    // tolerance
    i = g_fanDev.getFanTolerance();
    ui->fanTolerancelcdNumber->display(i);
    if ( i > 0 ) {
        ui->fanTolerancelcdNumber->setPalette(highValue);
    } else {
        ui->fanTolerancelcdNumber->setPalette(lowValue);
    }

    ////////////////// PWM //////////////////
    i = g_fanDev.getPwmPwm();
    ui->pwmPwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmPwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmPwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point1_pwm
    i = g_fanDev.getPwmAutoPoint1Pwm();
    ui->pwmAutoPoint1PwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint1PwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint1PwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point1_temp
    i = g_fanDev.getPwmAutoPoint1Temp();
    ui->pwmAutoPoint1TemplineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint1TemplineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint1TemplineEdit->setStyleSheet(strLowValue);
    }
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

void MainWindow::showFanGroup() {
    ui->pwmDatagroupBox->show();
    ui->fanDatagroupBox->show();
}

void MainWindow::hideFanGroup() {
    ui->pwmDatagroupBox->hide();
    ui->fanDatagroupBox->hide();
}

void MainWindow::initHwmon(QString strHwmon) {
    g_fanDev.setHwmon(strHwmon);
    disableFan();
    disablePwm();
    hideFanGroup();
    enableFan(strHwmon);
}

void MainWindow::on_hwmon0radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon0";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon1radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon1";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon2radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon2";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon3radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon3";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon4radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon4";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon5radioButton_clicked()
{
    QString strSysClass = "/sys/class/hwmon/hwmon5";

    initHwmon(strSysClass);
}

void MainWindow::initFan(QString strFan) {
    g_fanDev.setFan(strFan);
    showFanGroup();
    setFanPwm();
}

void MainWindow::on_fan1radioButton_clicked()
{
    initFan("fan1");
}

void MainWindow::on_fan2radioButton_clicked()
{
    initFan("fan2");
}

void MainWindow::on_fan3radioButton_clicked()
{
    initFan("fan3");
}

void MainWindow::on_fan4radioButton_clicked()
{
    initFan("fan4");
}

void MainWindow::on_fan5radioButton_clicked()
{
    initFan("fan5");
}

void MainWindow::on_fan6radioButton_clicked()
{
    initFan("fan6");
}

void MainWindow::on_fan7radioButton_clicked()
{
    initFan("fan7");
}

void MainWindow::on_fan8radioButton_clicked()
{
    initFan("fan8");
}

void MainWindow::on_fan9radioButton_clicked()
{
    initFan("fan9");
}

void MainWindow::on_fan10radioButton_clicked()
{
    initFan("fan10");
}
