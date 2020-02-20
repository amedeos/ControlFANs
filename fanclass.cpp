#include "fanclass.h"
#include <QFile>

fanClass::fanClass(QObject *parent)
    : QObject(parent)
{
    //QString m_strHwmon = "";
}

void fanClass::setHwmon(const QString &strHwmon) {
    m_strHwmon = strHwmon;
    fanClass::setFan("");
}

void fanClass::setFan(const QString &strFan) {
    m_strFan = strFan;
    m_strPwm = strFan;
    m_strPwm.replace(QRegularExpression("fan"), "pwm");
}

QString fanClass::getHwmon() const {
    return m_strHwmon;
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
    }
    fan_file.close();
    return i;
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

int fanClass::getPwmPwm() const {
    return getFanData(getPwm(), "");
}

int fanClass::getPwmAutoPoint1Pwm() const {
    return getFanData(getPwm(), "_auto_point1_pwm");
}

int fanClass::getPwmAutoPoint1Temp() const {
    return getFanData(getPwm(), "_auto_point1_temp");
}
