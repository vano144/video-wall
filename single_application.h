#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QObject>
#include <QApplication>
#include <QSharedMemory>
#include <QMediaPlayer>
#include <QDialog>
#include <QGridLayout>
#include "video_player.h"


class Single_application : public QApplication
{
    Q_OBJECT
private:
        bool alreadyExists;
        QSharedMemory sharedMemory;
public:
    Single_application(int &argc, char *argv[], const QString uniqueKey);
    bool isalreadyExists();
    bool isMainApp();
    bool sendMessage(const QString &message);
    int status=0;
    video_player* ply;


    //    playlist = new QMediaPlaylist(player);
public slots:
        void checkForMessage();
signals:
        void messageAvailable(const QStringList& messages);
};

#endif // SINGLE_APPLICATION_H
