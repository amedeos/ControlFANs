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
