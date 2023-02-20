#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
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


class SoundPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SoundPlayer(QWidget *parent = nullptr);
protected:
    QMediaPlayer* m_pmp;
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

#endif // SOUNDPLAYER_H
