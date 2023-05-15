#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ipAddress = "8.8.8.8"; // Destination IP address
    QStringList arguments;
    arguments << ipAddress; // Send 4 ping packets to the destination IP

    QProcess pingProcess;
    pingProcess.start("ping", arguments); // Start the ping process

    if (!pingProcess.waitForFinished()) {
        qDebug() << "Ping process execution failed.";
        return 1;
    }

    QString pingResult = pingProcess.readAllStandardOutput(); // Read the output of the ping process
    qDebug() << "Ping result:" << pingResult;

    return a.exec();
}
