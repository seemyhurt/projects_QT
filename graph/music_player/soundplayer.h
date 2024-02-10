#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QMediaPlayer>
#include <QWidget>
#include <QAudioOutput>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;


class SoundPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SoundPlayer(QWidget *parent = nullptr);

protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout* m_pvbxМainLayout;

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
    void slotStatusChanged(QMediaPlayer::State state);
};

#endif // SOUNDPLAYER_H
