#include "server.h"

server::server(QObject *parent):QTcpServer(parent){

}

int server::count()
{
    return m_list.count();
}

void server::close()
{
    foreach (QTcpSocket *socket, m_list) {
        socket->close();
    }

    qDeleteAll(m_list);
    m_list.clear();
    emit changed();
    QTcpServer::close();
}

void server::readyRead()
{
    //Bağlı olan herhangi bir istemciden veri (mesaj) geldiğinde tetiklenir.
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) {
        return;
    }

    QByteArray data = socket->readAll();

    foreach (QTcpSocket *socket, m_list) {
        socket->write(data);//final
    }
}

void server::disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());

    if( !socket) return;

    m_list.removeAll(socket);
    disconnect(socket, &QTcpSocket::readyRead, this, &server::readyRead);
    disconnect(socket, &QTcpSocket::disconnected, this,&server::disconnected);
    socket->deleteLater();
    emit changed();
}

QString server::message() const
{
    return m_message;
}

void server::setMessage(const QString &newMessage)
{
    m_message = newMessage;
}

void server::incomingConnection(qintptr handle)
{
    //Sunucuya yeni bir istemci bağlandığında otomatik çalışır
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    if (!socket->waitForConnected()) {
        delete socket;
        return;
    }

    m_list.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &server::readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &server::disconnected);
    emit changed();
    socket->write(m_message.toLatin1());
}
