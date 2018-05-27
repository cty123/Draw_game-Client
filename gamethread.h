#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QObject>
#include <QThread>
#include <QVariant>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtWebSockets/QWebSocket>
class GameThread : public QThread
{
    Q_OBJECT
public:
    explicit GameThread(QObject *parent = nullptr);
    void run();
    void send_draw_info(QVariant, QVariant, QVariant, QVariant);
signals:

public slots:

private:

};

#endif // GAMETHREAD_H
