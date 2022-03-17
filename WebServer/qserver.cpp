#include "qserver.h"
#include "sql.h"

QServer::QServer()
{
    if (listen(QHostAddress::LocalHost, 8080)){
            qDebug() << "Listening..." << serverPort() << serverAddress();
    }
    else {
            qDebug() << "Listening Error" << errorString();
    }
}

QServer::~QServer()
{

}

void QServer::incomingConnection(qintptr handle)
{
    QTcpSocket* socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this,SLOT(onDisconnected()));
}

void QServer::onReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray reseive_data = socket->readAll();
//    qDebug() << reseive_data << "\r\n";
    QStringList buf = QString(reseive_data).split('\n');
    QByteArray br = buf.takeLast().toUtf8();
    QJsonDocument JsonDoc = QJsonDocument::fromJson(br);
    QJsonObject obj = JsonDoc.object();
    if (!obj["number"].isNull()){
        int32_t a = obj["number"].toInt();
        if (a >= 0){
            QSqlQuery query = InsertDB(a);
            while (query.next()) {
                QByteArray messege_sql_return = query.value(0).toString().toUtf8();
                qDebug() << messege_sql_return;
                QString response = "HTTP/1.1 200 OK\r\n\r\n%1";
                socket->write(response.arg(messege_sql_return).toLatin1());
            }
        }
    }
    socket->disconnectFromHost();
}

void QServer::onDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
}

