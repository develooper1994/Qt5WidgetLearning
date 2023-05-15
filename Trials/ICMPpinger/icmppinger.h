#ifndef ICMPPINGER_H
#define ICMPPINGER_H

#include <QObject>

#include <QtNetwork/QUdpSocket>
#include <QHostAddress>
#include <QDebug>

class IcmpPinger : public QObject
{
    Q_OBJECT
public:
    explicit IcmpPinger(QObject* parent = nullptr);

    void ping(const QString& ipAddress);

signals:
    void pingResponseReceived(bool success);

private slots:
    void readPendingDatagrams();

private:
    // ICMP başlık yapısı
    struct IcmpHeader {
        quint8 type;          // Tip
        quint8 code;          // Kod
        quint16 checksum;     // Kontrol toplamı
        quint16 identifier;   // Tanımlayıcı
        quint16 sequenceNumber; // Sıra numarası
    };

    void fillIcmpHeader();

    QString targetIpAddress;
    QUdpSocket* socket;
    IcmpHeader icmpHeader;
    quint16 sequenceNumber = 1;
};


#endif // ICMPPINGER_H
