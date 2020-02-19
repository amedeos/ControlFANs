#ifndef FANCLASS_H
#define FANCLASS_H

#include <QObject>
#include <QString>

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
    int getFanAlarm() const;
    int getFanInput() const;
signals:

public slots:
private:
    QString m_strHwmon;
    QString m_strFan;
    int getFanData(const QString& strFanFile) const;
};

#endif // FANCLASS_H
