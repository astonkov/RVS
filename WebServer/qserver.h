#ifndef QSERVER_H
#define QSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>

class QServer : public QTcpServer
{
    Q_OBJECT
public:
    QServer();
    ~QServer();
    void incomingConnection(qintptr handle);
signals:

public slots:
    void onReadyRead();
    void onDisconnected();

};

#endif // QSERVER_H
