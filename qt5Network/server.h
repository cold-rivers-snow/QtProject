#ifndef SERVER_H
#define SERVER_H
#include <QDialog>
#include <QtNetwork>
#include <QLabel>
#include <QPushButton>
#include <QTcpServer>
#include <QStringList>
#include <QNetworkSession>
#include <QMessageBox>
#include <QList>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
};


#endif // SERVER_H
