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
}

QString fanClass::getHwmon() const {
    return m_strHwmon;
}

QString fanClass::getFan() const {
    return m_strFan;
}

int fanClass::getFanData(const QString &strFanFile) const {
    QFile fan_file(m_strHwmon + "/" + m_strFan + strFanFile);

    int i = 0;
    if( fan_file.open(QIODevice::ReadOnly) ) {
        i = fan_file.readAll().trimmed().toInt();
    }
    fan_file.close();
    return i;
}

int fanClass::getFanAlarm() const {
    return getFanData("_alarm");
}

int fanClass::getFanInput() const {
    return getFanData("_input");
}
