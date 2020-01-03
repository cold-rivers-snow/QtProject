#include "client.h"

Client::Client(QWidget *parent)
    : QDialog(parent),networkSession(0)
{
    tcpSocket = new QTcpSocket(this);


    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readFortune()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(readFortune()));


}

Client::~Client()
{

}

void Client::requestNewFortune()
{
    getFortuneButton->setEnabled(false);
    blocksize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),portLineEdit->text().toInt());

}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this,tr("Fortune Client"),tr("The host was not found.Please check the host name and port settings"));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this,tr("Fortune Client"),tr("The connection was refused by the peer.Make sure the fortune server is running,and check that the host name and port settings are correct."));
        break;
    default:
        QMessageBox::information(this,tr("Fortune Client"),tr("The following error occurred:%1.").arg(tcpSocket->errorString()));
    }
    getFortuneButton->setEnabled(true);
}

void Client::readFortune()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream:Qt_5_2);
    if(blocksize == 0)
    {
        if(tcpSocket->bytesAvailable()() < (int)sizeof(quint16))
            return;
        in >> blocksize;
    }
    if(tcpSocket->bytesAvailable() < blocksize)
        return;
    QString nextFortune;
    in >> nextFortune;
    if (nextFortune == currentFortune)
    {
        QTimer::singleShot(0,this,SLOT(requestNewFortune()));
        return;
    }
    currentFortune = nextFortune;
    statusLabel->setText(currentFortune);
    getFortuneButton->setEnabled(true);
}

