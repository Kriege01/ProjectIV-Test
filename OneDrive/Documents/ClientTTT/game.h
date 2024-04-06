#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QTcpSocket>

class window_play;

class GAME
{
public:
    GAME();

    QString displayRules();
    QVector<QPair<QString, int>> getScoreboardData();
    QString getSortedScoreboard();
    void sendRematch(QTcpSocket* socket, QByteArray& data);
    void send(QTcpSocket* socket, QByteArray& data, int i, int j);
    void startTimerToHideLabel(window_play *windowPlay);
    // New methods for user authentication
    void sendRegistration(QTcpSocket* socket, const QString& username, const QString& password);
    void sendLogin(QTcpSocket* socket, const QString& username, const QString& password);
    void handleServerResponse(QTcpSocket* socket);
};

#endif // GAME_H
