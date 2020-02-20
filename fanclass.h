#ifndef FANCLASS_H
#define FANCLASS_H

#include <QObject>
#include <QString>
#include <QRegularExpression>

class fanClass : public QObject
{
    Q_OBJECT
public:
    explicit fanClass(QObject *parent = nullptr);
    //explicit fanClass(const QString& strHwmon, QObject *parent = nullptr);
    //~fanClass();

    void setHwmon(const QString& strHwmon );
    void setFan(const QString& strFan );
    QString getHwmon() const;
    QString getFan() const;
    QString getPwm() const;
    int getFanAlarm() const;
    int getFanBeep() const;
    int getFanInput() const;
    int getFanMin() const;
    int getFanPulses() const;
    int getFanTarget() const;
    int getFanTolerance() const;
    int getPwmPwm() const;
    int getPwmAutoPoint1Pwm() const;
    int getPwmAutoPoint1Temp() const;
signals:

public slots:
private:
    QString m_strHwmon;
    QString m_strFan;
    QString m_strPwm;
    int getFanData(const QString& strFan, const QString& strFanFile) const;
};

#endif // FANCLASS_H
