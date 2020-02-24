#include "mainwindow.h"
#include "ui_mainwindow.h"

fanClass g_fanDev;
QString g_hwmonDir;

QValidator *pwmValidator = new QIntValidator(0, 255, nullptr);
QValidator *tempValidator = new QIntValidator(0, 150000, nullptr);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    g_hwmonDir = "/sys/class/hwmon";

    setFixedSize(800, 470);

    setupMenuBar();
    hideGroup();
    disableHwmon();
    disableFan();
    disablePwm();
    disablePushButton();
    enableHwmon();
    setupSignalsAndSlots();
    setupPwmValidator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPwmValidator() {
    ui->pwmPwmlineEdit->setValidator(pwmValidator);
    ui->pwmAutoPoint1PwmlineEdit->setValidator(pwmValidator);
    ui->pwmAutoPoint2PwmlineEdit->setValidator(pwmValidator);
    ui->pwmAutoPoint3PwmlineEdit->setValidator(pwmValidator);
    ui->pwmAutoPoint4PwmlineEdit->setValidator(pwmValidator);
    ui->pwmAutoPoint5PwmlineEdit->setValidator(pwmValidator);

    ui->pwmAutoPoint1TemplineEdit->setValidator(tempValidator);
    ui->pwmAutoPoint2TemplineEdit->setValidator(tempValidator);
    ui->pwmAutoPoint3TemplineEdit->setValidator(tempValidator);
    ui->pwmAutoPoint4TemplineEdit->setValidator(tempValidator);
    ui->pwmAutoPoint5TemplineEdit->setValidator(tempValidator);
}

void MainWindow::setupSignalsAndSlots() {
    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

void MainWindow::setupMenuBar() {
    // setup menu bar
    ui->actionQuit->setShortcut(QKeySequence::Quit);
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

void MainWindow::enablePwm() {
    ui->pwmPwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint1PwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint1TemplineEdit->setDisabled(false);
    ui->pwmAutoPoint2PwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint2TemplineEdit->setDisabled(false);
    ui->pwmAutoPoint3PwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint3TemplineEdit->setDisabled(false);
    ui->pwmAutoPoint4PwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint4TemplineEdit->setDisabled(false);
    ui->pwmAutoPoint5PwmlineEdit->setDisabled(false);
    ui->pwmAutoPoint5TemplineEdit->setDisabled(false);
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

    // auto_point2_pwm
    i = g_fanDev.getPwmAutoPoint2Pwm();
    ui->pwmAutoPoint2PwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint2PwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint2PwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point2_temp
    i = g_fanDev.getPwmAutoPoint2Temp();
    ui->pwmAutoPoint2TemplineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint2TemplineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint2TemplineEdit->setStyleSheet(strLowValue);
    }

    // auto_point3_pwm
    i = g_fanDev.getPwmAutoPoint3Pwm();
    ui->pwmAutoPoint3PwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint3PwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint3PwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point3_temp
    i = g_fanDev.getPwmAutoPoint3Temp();
    ui->pwmAutoPoint3TemplineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint3TemplineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint3TemplineEdit->setStyleSheet(strLowValue);
    }

    // auto_point4_pwm
    i = g_fanDev.getPwmAutoPoint4Pwm();
    ui->pwmAutoPoint4PwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint4PwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint4PwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point4_temp
    i = g_fanDev.getPwmAutoPoint4Temp();
    ui->pwmAutoPoint4TemplineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint4TemplineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint4TemplineEdit->setStyleSheet(strLowValue);
    }

    // auto_point5_pwm
    i = g_fanDev.getPwmAutoPoint5Pwm();
    ui->pwmAutoPoint5PwmlineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint5PwmlineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint5PwmlineEdit->setStyleSheet(strLowValue);
    }

    // auto_point5_temp
    i = g_fanDev.getPwmAutoPoint5Temp();
    ui->pwmAutoPoint5TemplineEdit->setText(QString::number(i));
    if ( i > 0 ) {
        ui->pwmAutoPoint5TemplineEdit->setStyleSheet(strHighValue);
    } else {
        ui->pwmAutoPoint5TemplineEdit->setStyleSheet(strLowValue);
    }
}

void MainWindow::disablePushButton() {
    // disable all push button
    ui->savepushButton->setDisabled(true);
    ui->calcelpushButton->setDisabled(true);
    ui->editpushButton->setDisabled(true);
}

void MainWindow::enableEditButton() {
    ui->editpushButton->setDisabled(false);
}

void MainWindow::enableHwmon(){
    // enable all available hwmon

    QDir hwmon0Dir = g_hwmonDir + "/hwmon0";
    if (hwmon0Dir.exists()) {
        ui->hwmon0radioButton->setCheckable(true);
        ui->hwmon0radioButton->setDisabled(false);
    }

    QDir hwmon1Dir = g_hwmonDir + "/hwmon1";
    if (hwmon1Dir.exists()) {
        ui->hwmon1radioButton->setCheckable(true);
        ui->hwmon1radioButton->setDisabled(false);
    }

    QDir hwmon2Dir = g_hwmonDir + "/hwmon2";
    if (hwmon2Dir.exists()) {
        ui->hwmon2radioButton->setCheckable(true);
        ui->hwmon2radioButton->setDisabled(false);
    }

    QDir hwmon3Dir = g_hwmonDir + "/hwmon3";
    if (hwmon3Dir.exists()) {
        ui->hwmon3radioButton->setCheckable(true);
        ui->hwmon3radioButton->setDisabled(false);
    }

    QDir hwmon4Dir = g_hwmonDir + "/hwmon4";
    if (hwmon4Dir.exists()) {
        ui->hwmon4radioButton->setCheckable(true);
        ui->hwmon4radioButton->setDisabled(false);
    }

    QDir hwmon5Dir = g_hwmonDir + "/hwmon5";
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
    QString strSysClass = g_hwmonDir + "/hwmon0";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon1radioButton_clicked()
{
    QString strSysClass = g_hwmonDir + "/hwmon1";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon2radioButton_clicked()
{
    QString strSysClass = g_hwmonDir + "/hwmon2";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon3radioButton_clicked()
{
    QString strSysClass = g_hwmonDir + "/hwmon3";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon4radioButton_clicked()
{
    QString strSysClass = g_hwmonDir + "/hwmon4";

    initHwmon(strSysClass);
}

void MainWindow::on_hwmon5radioButton_clicked()
{
    QString strSysClass = g_hwmonDir + "/hwmon5";

    initHwmon(strSysClass);
}

void MainWindow::initFan(QString strFan) {
    g_fanDev.setFan(strFan);
    disablePwm();
    showFanGroup();
    setFanPwm();
    disablePushButton();
    enableEditButton();
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

void MainWindow::on_editpushButton_clicked()
{
    QString s_user = qEnvironmentVariable("USER");
    // TOCHANGE
    if ( s_user == "root" ) {
        enablePwm();
        ui->savepushButton->setDisabled(false);
        ui->calcelpushButton->setDisabled(false);
    } else {
        QMessageBox::information(this, "Super user required", "Run this program as root if you want to edit FAN / PWM data");
    }
}

void MainWindow::on_calcelpushButton_clicked()
{
    initFan(g_fanDev.getFan());
}

void MainWindow::savePwmPwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmPwmlineEdit->setText(QString::number(g_fanDev.getPwmPwm()));
    } else if ( (i != g_fanDev.getPwmPwm()) && ( i != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmPwm(i);
    }
}

void MainWindow::savePwmAutoPoint1Pwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmAutoPoint1PwmlineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint1Pwm()));
    } else if ( (i != g_fanDev.getPwmAutoPoint1Pwm()) && ( g_fanDev.getPwmAutoPoint1Pwm() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint1Pwm(i);
    }
}

void MainWindow::savePwmAutoPoint2Pwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmAutoPoint2PwmlineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint2Pwm()));
    } else if ( (i != g_fanDev.getPwmAutoPoint2Pwm()) && ( g_fanDev.getPwmAutoPoint2Pwm() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint2Pwm(i);
    }
}

void MainWindow::savePwmAutoPoint3Pwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmAutoPoint3PwmlineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint3Pwm()));
    } else if ( (i != g_fanDev.getPwmAutoPoint3Pwm()) && ( g_fanDev.getPwmAutoPoint3Pwm() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint3Pwm(i);
    }
}

void MainWindow::savePwmAutoPoint4Pwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmAutoPoint4PwmlineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint4Pwm()));
    } else if ( (i != g_fanDev.getPwmAutoPoint4Pwm()) && ( g_fanDev.getPwmAutoPoint4Pwm() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint4Pwm(i);
    }
}

void MainWindow::savePwmAutoPoint5Pwm(const int i)
{
    if ( g_fanDev.checkPwmPwmData( i ) == false) {
        QString sMsg = "PWM value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "PWM Data", sMsg );
        ui->pwmAutoPoint5PwmlineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint5Pwm()));
    } else if ( (i != g_fanDev.getPwmAutoPoint5Pwm()) && ( g_fanDev.getPwmAutoPoint5Pwm() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint5Pwm(i);
    }
}

void MainWindow::savePwmAutoPoint1Temp(const int i)
{
    if ( g_fanDev.checkPwmTempData( i ) == false) {
        QString sMsg = "Temperature value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "Temperature Data", sMsg );
        ui->pwmAutoPoint1TemplineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint1Temp()));
    } else if ( (i != g_fanDev.getPwmAutoPoint1Temp() ) && ( g_fanDev.getPwmAutoPoint1Temp() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint1Temp(i);
    }
}

void MainWindow::savePwmAutoPoint2Temp(const int i)
{
    if ( g_fanDev.checkPwmTempData( i ) == false) {
        QString sMsg = "Temperature value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "Temperature Data", sMsg );
        ui->pwmAutoPoint2TemplineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint2Temp()));
    } else if ( (i != g_fanDev.getPwmAutoPoint2Temp() ) && ( g_fanDev.getPwmAutoPoint2Temp() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint2Temp(i);
    }
}

void MainWindow::savePwmAutoPoint3Temp(const int i)
{
    if ( g_fanDev.checkPwmTempData( i ) == false) {
        QString sMsg = "Temperature value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "Temperature Data", sMsg );
        ui->pwmAutoPoint3TemplineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint3Temp()));
    } else if ( (i != g_fanDev.getPwmAutoPoint3Temp() ) && ( g_fanDev.getPwmAutoPoint3Temp() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint3Temp(i);
    }
}

void MainWindow::savePwmAutoPoint4Temp(const int i)
{
    if ( g_fanDev.checkPwmTempData( i ) == false) {
        QString sMsg = "Temperature value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "Temperature Data", sMsg );
        ui->pwmAutoPoint4TemplineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint4Temp()));
    } else if ( (i != g_fanDev.getPwmAutoPoint4Temp() ) && ( g_fanDev.getPwmAutoPoint4Temp() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint4Temp(i);
    }
}

void MainWindow::savePwmAutoPoint5Temp(const int i)
{
    if ( g_fanDev.checkPwmTempData( i ) == false) {
        QString sMsg = "Temperature value " + QString::number(i) + " is not allowed! Reset...";
        QMessageBox::warning(this, "Temperature Data", sMsg );
        ui->pwmAutoPoint5TemplineEdit->setText(QString::number(g_fanDev.getPwmAutoPoint5Temp()));
    } else if ( (i != g_fanDev.getPwmAutoPoint5Temp() ) && ( g_fanDev.getPwmAutoPoint5Temp() != -1 ) ) {
        // now we can set the new value
        g_fanDev.setPwmAutoPoint5Temp(i);
    }
}

void MainWindow::on_savepushButton_clicked()
{
    int i = ui->pwmPwmlineEdit->text().toInt();
    savePwmPwm(i);

    i = ui->pwmAutoPoint1PwmlineEdit->text().toInt();
    savePwmAutoPoint1Pwm(i);

    i = ui->pwmAutoPoint2PwmlineEdit->text().toInt();
    savePwmAutoPoint2Pwm(i);

    i = ui->pwmAutoPoint3PwmlineEdit->text().toInt();
    savePwmAutoPoint3Pwm(i);

    i = ui->pwmAutoPoint4PwmlineEdit->text().toInt();
    savePwmAutoPoint4Pwm(i);

    i = ui->pwmAutoPoint5PwmlineEdit->text().toInt();
    savePwmAutoPoint5Pwm(i);

    i = ui->pwmAutoPoint1TemplineEdit->text().toInt();
    savePwmAutoPoint1Temp(i);

    i = ui->pwmAutoPoint2TemplineEdit->text().toInt();
    savePwmAutoPoint2Temp(i);

    i = ui->pwmAutoPoint3TemplineEdit->text().toInt();
    savePwmAutoPoint3Temp(i);

    i = ui->pwmAutoPoint4TemplineEdit->text().toInt();
    savePwmAutoPoint4Temp(i);

    i = ui->pwmAutoPoint5TemplineEdit->text().toInt();
    savePwmAutoPoint5Temp(i);

    initFan(g_fanDev.getFan());
}
