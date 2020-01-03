#ifndef CLIENT_H
#define CLIENT_H
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
#include <QAbstractSocket>
#include <QComboBox>
#include <QLineEdit>
#include <QDialogButtonBox>

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void sessionOpened();
    void requestNewFortune();
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();


private:
    QLabel *hostLabel,*portLabel,*statusLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QPushButton *getFortuneButton,*quitButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket *tcpSocket;
    QString currentFortune;
    quint16 blocksize;
    QNetworkSession *networkSession;
};


#endif // CLIENT_H
