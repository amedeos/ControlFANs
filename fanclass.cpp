#include "fanclass.h"
#include <QFile>
#include <QFileInfo>

fanClass::fanClass(QObject *parent)
    : QObject(parent)
{
    //QString m_strHwmon = "";
}

void fanClass::setHwmon(const QString &strHwmon) {
    m_strHwmon = strHwmon;
    fanClass::setFan("");
}

void fanClass::setHwmon(const QString &strHwmon, const QString &strHwmonNum)
{
    fanClass::setHwmonNum(strHwmonNum);
    fanClass::setHwmon(strHwmon + "/" + strHwmonNum);
}

void fanClass::setHwmonNum(const QString &strHwmonNum)
{
    m_strHwmonNum = strHwmonNum;
}

void fanClass::setFan(const QString &strFan) {
    m_strFan = strFan;
    m_strPwm = strFan;
    m_strPwm.replace(QRegularExpression("fan"), "pwm");
}

QString fanClass::getHwmon() const {
    return m_strHwmon;
}

QString fanClass::getHwmonNum() const
{
    return m_strHwmonNum;
}

QString fanClass::getHwmonDevicePath() const
{
    QFileInfo dev(m_strHwmon + "/device");
    return dev.canonicalFilePath()+"/hwmon/hwmon[[:print:]]*";
}

QString fanClass::getHwmonName() const {
    QFile fan_file(m_strHwmon + "/name");
    QString name;
    if( fan_file.open(QIODevice::ReadOnly) ) {
        name = fan_file.readAll().trimmed();
        fan_file.close();
    }

    return name;
}

QString fanClass::getFan() const {
    return m_strFan;
}

QString fanClass::getPwm() const {
    return m_strPwm;
}

int fanClass::getFanData(const QString &strFan, const QString &strFanFile) const {
    QFile fan_file(m_strHwmon + "/" + strFan + strFanFile);

    int i = 0;
    if( fan_file.open(QIODevice::ReadOnly) ) {
        i = fan_file.readAll().trimmed().toInt();
    } else {
        return -1;
    }
    fan_file.close();
    return i;
}

int fanClass::setFanData(const QString &strFan, const QString &strFanFile, const int i) {
    QFile fan_file(m_strHwmon + "/" + strFan + strFanFile);
    QTextStream out(&fan_file);

    if ( fan_file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        QString s = QString::number(i) + "\n";
        out << s;
    } else {
        return -1;
    }
    fan_file.close();
    return 0;
}

int fanClass::getFanAlarm() const {
    return getFanData(getFan(), "_alarm");
}

int fanClass::getFanBeep() const {
    return getFanData(getFan(), "_beep");
}

int fanClass::getFanInput() const {
    return getFanData(getFan(), "_input");
}

int fanClass::getFanMin() const {
    return getFanData(getFan(), "_min");
}

int fanClass::getFanPulses() const {
    return getFanData(getFan(), "_pulses");
}

int fanClass::getFanTarget() const {
    return getFanData(getFan(), "_target");
}

int fanClass::getFanTolerance() const {
    return getFanData(getFan(), "_tolerance");
}

int fanClass::getPwmPwm() {
    m_intPwmPwm = getFanData(getPwm(), "");
    return m_intPwmPwm;
}

int fanClass::getPwmAutoPoint1Pwm() {
    m_intPwmAutoPoint1Pwm = getFanData(getPwm(), "_auto_point1_pwm");
    return m_intPwmAutoPoint1Pwm;
}

int fanClass::getPwmAutoPoint1Temp() {
    m_intPwmAutoPoint1Temp = getFanData(getPwm(), "_auto_point1_temp");
    return m_intPwmAutoPoint1Temp;
}

int fanClass::getPwmAutoPoint2Pwm() {
    m_intPwmAutoPoint2Pwm = getFanData(getPwm(), "_auto_point2_pwm");
    return m_intPwmAutoPoint2Pwm;
}

int fanClass::getPwmAutoPoint2Temp() {
    m_intPwmAutoPoint2Temp = getFanData(getPwm(), "_auto_point2_temp");
    return m_intPwmAutoPoint2Temp;
}

int fanClass::getPwmAutoPoint3Pwm() {
    m_intPwmAutoPoint3Pwm = getFanData(getPwm(), "_auto_point3_pwm");
    return m_intPwmAutoPoint3Pwm;
}

int fanClass::getPwmAutoPoint3Temp() {
    m_intPwmAutoPoint3Temp = getFanData(getPwm(), "_auto_point3_temp");
    return m_intPwmAutoPoint3Temp;
}

int fanClass::getPwmAutoPoint4Pwm() {
    m_intPwmAutoPoint4Pwm = getFanData(getPwm(), "_auto_point4_pwm");
    return m_intPwmAutoPoint4Pwm;
}

int fanClass::getPwmAutoPoint4Temp() {
    m_intPwmAutoPoint4Temp = getFanData(getPwm(), "_auto_point4_temp");
    return m_intPwmAutoPoint4Temp;
}

int fanClass::getPwmAutoPoint5Pwm() {
    m_intPwmAutoPoint5Pwm = getFanData(getPwm(), "_auto_point5_pwm");
    return m_intPwmAutoPoint5Pwm;
}

int fanClass::getPwmAutoPoint5Temp() {
    m_intPwmAutoPoint5Temp = getFanData(getPwm(), "_auto_point5_temp");
    return m_intPwmAutoPoint5Temp;
}

bool fanClass::checkRangeData(const int imin, const int imax, const int i) const {
    // check
    if ( (i >= imin) && (i <= imax) ) {
        return true;
    }
    return false;
}

bool fanClass::checkPwmPwmData(const int i) const {
    // check pwm
    return checkRangeData(-1, 255, i);
}

bool fanClass::checkPwmTempData(const int i) const {
    // check temp data
    return checkRangeData(-1, 160000, i);
}

bool fanClass::setPwmPwm(const int i) {
    // set new value for pwm
    m_intPwmPwm = i;
    if (setFanData(getPwm(), "", i) == 0 ){
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint1Pwm(const int i) {
    m_intPwmAutoPoint1Pwm = i;
    if ( setFanData(getPwm(), "_auto_point1_pwm", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint2Pwm(const int i) {
    m_intPwmAutoPoint2Pwm = i;
    if ( setFanData(getPwm(), "_auto_point2_pwm", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint3Pwm(const int i) {
    m_intPwmAutoPoint3Pwm = i;
    if ( setFanData(getPwm(), "_auto_point3_pwm", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint4Pwm(const int i) {
    m_intPwmAutoPoint4Pwm = i;
    if ( setFanData(getPwm(), "_auto_point4_pwm", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint5Pwm(const int i) {
    m_intPwmAutoPoint5Pwm = i;
    if ( setFanData(getPwm(), "_auto_point5_pwm", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint1Temp(const int i) {
    m_intPwmAutoPoint1Temp = i;
    if ( setFanData(getPwm(), "_auto_point1_temp", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint2Temp(const int i) {
    m_intPwmAutoPoint2Temp = i;
    if ( setFanData(getPwm(), "_auto_point2_temp", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint3Temp(const int i) {
    m_intPwmAutoPoint3Temp = i;
    if ( setFanData(getPwm(), "_auto_point3_temp", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint4Temp(const int i) {
    m_intPwmAutoPoint4Temp = i;
    if ( setFanData(getPwm(), "_auto_point4_temp", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}

bool fanClass::setPwmAutoPoint5Temp(const int i) {
    m_intPwmAutoPoint5Temp = i;
    if ( setFanData(getPwm(), "_auto_point5_temp", i) == 0 ) {
        return true;
    } else {
        return false;
    }
}
