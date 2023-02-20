#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include "qaudiooutput.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtWidgets>
class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

class MyAudio : public QAudioOutput
{
    Q_OBJECT
public:
    explicit MyAudio(QAudioOutput *parent = nullptr);
public slots:
    void changeSound(int) ;
};


class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent = nullptr);
protected:
    QMediaPlayer* m_pmp;
    QVideoWidget* pvw;
    MyAudio* audio;
    QVBoxLayout* m_pvbxМainLayout ;
private:
    QPushButton* m_pcmdPlay;
    QPushButton* m_pcmdStop;
    QSlider* m_psldPosition;
    QLabel* m_plblCurrent;
    QLabel* m_plblRemain;

    QString msecsToString(qint64 n);
private slots:
    void slotOpen() ;
    void slotPlay();
    void slotSetSliderPosition(qint64);
    void slotSetMediaPosition (int n);
    void slotSetDuration(qint64);
    void slotStatusChanged(QMediaPlayer::PlaybackState state);
};
#endif // VIDEOPLAYER_H
