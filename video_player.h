#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QDialog>

class video_player : public QWidget
{
    Q_OBJECT
public:
    explicit video_player(QWidget *parent = 0);
    int i;
    int j;
    int h;
    int w;
    void addVideo(QString path);
    void resize();
signals:

public slots:
};

#endif // VIDEO_PLAYER_H
