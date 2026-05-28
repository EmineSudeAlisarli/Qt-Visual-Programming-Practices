#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

//Sunucu sınıfımız, Qt'nin hazır sunucu sınıfından miras alınarak özelleştirilmişti.
class server : public QTcpServer
{
    Q_OBJECT
public:
    server(QObject *parent = nullptr);
    int count();
    void close();

    QString message() const;
    void setMessage(const QString &newMessage);

signals:
    void changed();

public slots:
    void readyRead();
    void disconnected();

private:
    QString m_message;
    QList<QTcpSocket*> m_list; //Sunucuya bağlı tüm istemcilerin port numarasını tutar.

protected:
    void incomingConnection(qintptr handle) override;
};

#endif // SERVER_H
