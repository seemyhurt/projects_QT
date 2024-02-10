#include "videoplayer.h"
#include <QtWidgets>
#include "QVideoWidget"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget{parent}
{
    QPushButton* pcmdOpen =  new QPushButton("&Open");
    QDial* pdiaVolume = new QDial;

    pvw = new QVideoWidget;
    pvw->setMinimumSize(300, 300);

    m_pcmdPlay = new QPushButton;
    m_pcmdStop = new QPushButton;
    m_psldPosition = new QSlider;
    m_plblCurrent = new QLabel(msecsToString(0));
    m_plblRemain = new QLabel(msecsToString(0));

    m_pmp = new QMediaPlayer;
    m_pcmdPlay->setEnabled(false);
    m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    m_pcmdStop->setEnabled(false);
    m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    m_psldPosition->setRange(0, 0);
    m_psldPosition->setOrientation(Qt::Horizontal);


    pdiaVolume->setRange(0.0f, 100.0f);
    float nDefaultVolume = 50;
    m_pmp->setVolume(nDefaultVolume);
    pdiaVolume->setValue(nDefaultVolume);

    connect(pcmdOpen, &QPushButton::clicked, this, &VideoPlayer::slotOpen);
    connect(m_pcmdPlay, &QPushButton::clicked, this, &VideoPlayer::slotPlay);
    connect(m_pcmdStop, &QPushButton::clicked, m_pmp, &QMediaPlayer::stop);

    connect(pdiaVolume, &QDial::valueChanged, m_pmp, &QMediaPlayer::setVolume);
    connect(m_psldPosition, &QSlider::sliderMoved,this, &VideoPlayer::slotSetMediaPosition);

    connect(m_pmp, &QMediaPlayer::positionChanged, this, &VideoPlayer::slotSetSliderPosition);
    connect(m_pmp, &QMediaPlayer::durationChanged, this, &VideoPlayer::slotSetDuration);
    connect(m_pmp, &QMediaPlayer::stateChanged, this, &VideoPlayer::slotStatusChanged);

    //Layout setup
    QHBoxLayout* phbxPlayControls = new QHBoxLayout;
    phbxPlayControls->addWidget(pcmdOpen);
    phbxPlayControls->addWidget(m_pcmdPlay);
    phbxPlayControls->addWidget(m_pcmdStop);
    phbxPlayControls->addWidget(pdiaVolume);

    QHBoxLayout* phbxTimeControls = new QHBoxLayout;
    phbxTimeControls->addWidget(m_plblCurrent);
    phbxTimeControls->addWidget(m_psldPosition);
    phbxTimeControls->addWidget(m_plblRemain);

    m_pvbxМainLayout = new QVBoxLayout;
    m_pvbxМainLayout->addWidget(pvw);
    m_pvbxМainLayout->addLayout(phbxPlayControls);
    m_pvbxМainLayout->addLayout(phbxTimeControls);
    setLayout(m_pvbxМainLayout);
}
void VideoPlayer::slotOpen()
{
    QString strFile = QFileDialog::getOpenFileName(this, "Open File");
    if (!strFile.isEmpty()){
        m_pmp->setVideoOutput(pvw);
        m_pmp->setMedia(QUrl::fromLocalFile(strFile));
        m_pcmdPlay->setEnabled(true);
        m_pcmdStop->setEnabled(true);
        m_pmp->play();
    }
};
void VideoPlayer::slotPlay()
{
    switch(m_pmp->state()){
    case QMediaPlayer::PlayingState:{
        m_pmp->pause();
        break;
    }
    case QMediaPlayer::PausedState:{
        m_pmp->play();
        break;
    }
    case QMediaPlayer::StoppedState:
        m_pmp->play();
        break;
    default:
        break;
    }
};
void VideoPlayer::slotStatusChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PlayingState:{
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    }
    case QMediaPlayer::PausedState:{
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
    case QMediaPlayer::StoppedState:
        m_pcmdPlay->setEnabled(false);
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

        m_pcmdStop->setEnabled(false);
        m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

        m_psldPosition->setRange(0, 0);
        m_plblCurrent->setText(msecsToString(0));
        m_plblRemain->setText(msecsToString(0));
        break;
    default:
        break;
    }
};

void VideoPlayer::slotSetMediaPosition(int n)
{
    m_pmp->setPosition(n);
    m_pmp->play();

};

QString VideoPlayer::msecsToString(qint64 n)
{
    int nHours = (n/(60 * 60 * 1000));
    int nМinutes = ((n % (60 * 60 * 1000) ) / (60 * 1000));
    int nSeconds = ((n % (60 * 1000)) / 1000);
    return QTime(nHours, nМinutes, nSeconds) .toString ("hh:mm:ss");
};

void VideoPlayer:: slotSetDuration(qint64 n){
    m_psldPosition->setRange(0, n);
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
};

void VideoPlayer::slotSetSliderPosition(qint64 n){
    m_psldPosition->setValue(n);
    m_plblCurrent->setText(msecsToString(n));
    int nDuration = m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration-n) );
}
