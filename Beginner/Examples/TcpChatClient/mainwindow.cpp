#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_socket, &QTcpSocket::connected, this, &MainWindow::connected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &MainWindow::disconnected);
    connect(&m_socket, &QTcpSocket::readyRead, this, &MainWindow::readyRead);
    //Qt 5
    //connect(&socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&Client::error); //Explain
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &MainWindow::error);

    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);

    m_model.setStringList(m_list);
    ui->listView->setModel(&m_model);
}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_btnConnect_clicked(){
    if (m_socket.isOpen()) m_socket.close();

    m_name = QInputDialog::getText(this, "Name", "What is your name?", QLineEdit::EchoMode::Normal, m_name);

    bool ok;
    quint16 port = static_cast<quint16>(ui->txtPort->text().toInt(&ok));
    if(!ok){
        QMessageBox::critical(this, "Error", "Please Enter a Number");
        return;
    }
    m_socket.connectToHost(ui->txtServer->text(), port);

    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);

    if (!m_socket.waitForConnected(3000)) {
        on_btnDisconnect_clicked();
        QMessageBox::critical(this,"Error","Could not connect to server!");
        return;
    }
}

void MainWindow::on_btnDisconnect_clicked(){
    m_socket.close();
    disconnected();
}


void MainWindow::on_btnSend_clicked(){
    if (!m_socket.isOpen()) return;

    QByteArray message;
    message.append(m_name.toUtf8());
    message.append(" ");
    message.append(ui->txtMessage->text().toUtf8());

    m_socket.write(message);
    ui->txtMessage->setText("");
}

void MainWindow::connected(){
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(true);
    ui->btnSend->setEnabled(true);
}

void MainWindow::disconnected(){
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
}

void MainWindow::readyRead(){
    auto data = m_socket.readAll();
    QString message(data);
    m_list.append(message);
    m_model.setStringList(m_list);
    ui->listView->scrollToBottom();
}

void MainWindow::error(QAbstractSocket::SocketError socketError){
    qInfo() << "Error: " << socketError << " " << m_socket.errorString();
    QMessageBox::critical(this, "Error", m_socket.errorString());
}

