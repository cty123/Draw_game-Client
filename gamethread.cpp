#include "gamethread.h"

GameThread::GameThread(QObject *parent) : QThread(parent)
{

}

void GameThread::run(){

}

void GameThread::send_draw_info(QVariant startX, QVariant startY, QVariant endX, QVariant endY)
{
    /*
    QJsonObject jsonObj{
        {"user", user},
        {"game", "game"},
        {"startX", startX.toInt()},
        {"startY", startY.toInt()},
        {"endX", endX.toInt()},
        {"endY", endY.toInt()}
    };
    QJsonDocument doc(jsonObj);
    QString string(doc.toJson(QJsonDocument::Compact));
    */
}
