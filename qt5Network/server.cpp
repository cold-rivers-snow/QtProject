#include "server.h"

Server::Server(QWidget *parent)
    : QDialog(parent)
{
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen())
    {
        QMessageBox::critical(this,tr("Fortune Server"),tr("Unable to start the server: %1.").arg(tcpServer->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();
    for(int i = 0;i < ipAddressList.size();i++)
    {
        if(ipAddressList.at(i) != QHostAddress::LocalHost && ipAddressList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressList.at(i).toString();
            break;
        }
    }

    if(ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }
    statusLabel->setText(tr("The server is running on\n\nIP:%1\nport:%2\n\nRun the Fortune Client example now.").arg(ipAddress).arg(tcpServer->serverPort()));

    fortunes << tr("You've been leading a dog's life.Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent.They only think they are.");

    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendFortune()));


}

Server::~Server()
{

}

void Server::sendFortune()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);

    out << (quint16)0;
    out << fortunes.at(qrand() % fortunes.size());
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();

}

