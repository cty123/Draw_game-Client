#ifndef GAMESOCKET_H
#define GAMESOCKET_H

#include <QtCore/QObject>
#include <QWebSocket>
#include <QPoint>

class GameSocket : public QObject
{
    Q_OBJECT
public:
    explicit GameSocket(const QUrl &url, QObject *parent = Q_NULLPTR);
    void connect_server();
    void create_room();
    void join_room();
    void start_game();
    void leave_room();
    void send_msg();

signals:
    void receive_draw(QPoint, QPoint);

public slots:
    void draw(QPoint point_start, QPoint point_end);

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
};

#endif // GAMESOCKET_H
