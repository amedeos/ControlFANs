#ifndef FANCLASS_H
#define FANCLASS_H

#include <QObject>
#include <QString>
#include <QRegularExpression>
#include <QTextStream>
#include <QMessageBox>

class fanClass : public QObject
{
    Q_OBJECT
public:
    explicit fanClass(QObject *parent = nullptr);
    //explicit fanClass(const QString& strHwmon, QObject *parent = nullptr);
    //~fanClass();

    void setHwmon(const QString& strHwmon );
    void setHwmon(const QString& strHwmon, const QString& strHwmonNum );
    void setHwmonNum(const QString& strHwmonNum );
    void setFan(const QString& strFan );
    QString getHwmon() const;
    QString getHwmonNum() const;
    QString getHwmonName() const;
    QString getHwmonDevicePath() const;
    QString getFan() const;
    QString getPwm() const;
    int getFanAlarm() const;
    int getFanBeep() const;
    int getFanInput() const;
    int getFanMin() const;
    int getFanPulses() const;
    int getFanTarget() const;
    int getFanTolerance() const;
    int getPwmPwm();
    int getPwmAutoPoint1Pwm();
    int getPwmAutoPoint1Temp();
    int getPwmAutoPoint2Pwm();
    int getPwmAutoPoint2Temp();
    int getPwmAutoPoint3Pwm();
    int getPwmAutoPoint3Temp();
    int getPwmAutoPoint4Pwm();
    int getPwmAutoPoint4Temp();
    int getPwmAutoPoint5Pwm();
    int getPwmAutoPoint5Temp();
    bool checkPwmPwmData(const int i) const;
    bool checkPwmTempData(const int i) const;
    bool setPwmPwm(const int i);
    bool setPwmAutoPoint1Pwm(const int i);
    bool setPwmAutoPoint2Pwm(const int i);
    bool setPwmAutoPoint3Pwm(const int i);
    bool setPwmAutoPoint4Pwm(const int i);
    bool setPwmAutoPoint5Pwm(const int i);
    bool setPwmAutoPoint1Temp(const int i);
    bool setPwmAutoPoint2Temp(const int i);
    bool setPwmAutoPoint3Temp(const int i);
    bool setPwmAutoPoint4Temp(const int i);
    bool setPwmAutoPoint5Temp(const int i);
signals:

public slots:
private:
    QString m_strHwmon;
    QString m_strHwmonNum;
    QString m_strFan;
    QString m_strPwm;
    int m_intPwmPwm;
    int m_intPwmAutoPoint1Pwm;
    int m_intPwmAutoPoint2Pwm;
    int m_intPwmAutoPoint3Pwm;
    int m_intPwmAutoPoint4Pwm;
    int m_intPwmAutoPoint5Pwm;
    int m_intPwmAutoPoint1Temp;
    int m_intPwmAutoPoint2Temp;
    int m_intPwmAutoPoint3Temp;
    int m_intPwmAutoPoint4Temp;
    int m_intPwmAutoPoint5Temp;
    int getFanData(const QString& strFan, const QString& strFanFile) const;
    int setFanData(const QString& strFan, const QString& strFanFile, const int i);
    bool checkRangeData(const int imin, const int imax, const int i) const;
};

#endif // FANCLASS_H
