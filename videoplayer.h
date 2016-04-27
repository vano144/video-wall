#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>

class Video_Player : public QMainWindow
{
    Q_OBJECT
public:
    explicit Video_Player(QWidget *parent = 0);
    int i=0;
    QGridLayout* lal;
    void AddVideo(QString path);
signals:

public slots:
};

#endif // VIDEOPLAYER_H
