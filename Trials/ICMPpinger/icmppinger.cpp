#include "icmppinger.h"

#include <QtEndian>
#include <QCoreApplication>

IcmpPinger::IcmpPinger(QObject *parent)
    : QObject(parent), socket(new QUdpSocket(this))
{
    connect(socket, &QUdpSocket::readyRead, this, &IcmpPinger::readPendingDatagrams);
}

void IcmpPinger::ping(const QString &ipAddress)
{
    targetIpAddress = ipAddress;
    socket->bind();

    // ICMP ping isteği için başlık yapısını doldurun
    fillIcmpHeader();

    // ICMP paketini oluşturun
    QByteArray data(reinterpret_cast<const char*>(&icmpHeader), sizeof(IcmpHeader));

    // Hedef IP adresine ICMP ping isteği gönderin
    QHostAddress address(targetIpAddress);
    socket->writeDatagram(data, address, 0);
}

void IcmpPinger::readPendingDatagrams()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray response;
        response.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(response.data(), response.size(), &sender, &senderPort);

        // ICMP ping yanıtını analiz edin
        if (response[20] == 0) {
            emit pingResponseReceived(true);
        } else {
            emit pingResponseReceived(false);
        }
        break; // Sadece ilk yanıtı alın ve döngüden çıkın
    }
}

void IcmpPinger::fillIcmpHeader()
{
    icmpHeader.type = 8;  // ICMP ping isteği için tip (8: Echo Request)
    icmpHeader.code = 0;  // ICMP ping isteği için kod
    icmpHeader.checksum = 0; // Başlangıçta kontrol toplamını sıfırla
    icmpHeader.identifier = qToBigEndian(static_cast<quint16>(QCoreApplication::applicationPid())); // PID'i tanımlayıcı olarak kullan
    icmpHeader.sequenceNumber = qToBigEndian(sequenceNumber++); // Sıra numarasını artır

    // Kontrol toplamını hesapla
    quint32 sum = 0;
    quint16* ptr = reinterpret_cast<quint16*>(&icmpHeader);
    for (int i = 0; i < sizeof(IcmpHeader) / 2; ++i) {
        sum += qToBigEndian(ptr[i]);
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    icmpHeader.checksum = qToBigEndian(static_cast<quint16>(~sum));
}
