#include "gamesocket.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

GameSocket::GameSocket(const QUrl &url, QObject *parent) : QObject(parent), m_url(url)
{
    qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &GameSocket::onConnected);
    m_webSocket.open(QUrl(m_url));
}

void GameSocket::connect_server()
{

}

void GameSocket::create_room()
{
    QJsonObject json;
    json.insert("type", "create_room");
    json.insert("room_name", "test");
    QJsonDocument doc(json);
    m_webSocket.sendTextMessage(doc.toJson(QJsonDocument::Indented));
}

void GameSocket::join_room()
{
    QJsonObject json;
    json.insert("type", "join_room");
    json.insert("room_name", "test");
    QJsonDocument doc(json);
    m_webSocket.sendTextMessage(doc.toJson(QJsonDocument::Indented));
}

void GameSocket::start_game()
{
    QJsonObject json;
    json.insert("type", "start");
    json.insert("room_name", "test");
    QJsonDocument doc(json);
    m_webSocket.sendTextMessage(doc.toJson(QJsonDocument::Indented));
}

void GameSocket::draw(QPoint point_start, QPoint point_end)
{
    QJsonObject json;
    json.insert("type", "draw");
    json.insert("room_name", "test");
    json.insert("start_x", point_start.x());
    json.insert("start_x", point_start.y());
    json.insert("end_x", point_end.x());
    json.insert("end_y", point_end.y());
    QJsonDocument doc(json);
    m_webSocket.sendTextMessage(doc.toJson(QJsonDocument::Indented));
}

void GameSocket::onConnected()
{
    qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &GameSocket::onTextMessageReceived);
}

void GameSocket::onTextMessageReceived(QString message)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QString type = jsonObject["res"].toString();
    qDebug() << "Message: "<< message << endl <<"Message type:" << type;

    if (!type.compare("draw")) {
        QPoint start(jsonObject["start_x"].toInt(), jsonObject["start_y"].toInt());
        QPoint end(jsonObject["end_x"].toInt(), jsonObject["end_y"].toInt());
        emit receive_draw(start, end);
    }

}


