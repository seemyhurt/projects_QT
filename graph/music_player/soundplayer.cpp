#include "soundplayer.h"
#include <QDial>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QTime>
#include <QFileDialog>
#include <QStyle>

SoundPlayer::SoundPlayer(QWidget *parent)
    : QWidget{parent}
{
    QPushButton* pcmdOpen =  new QPushButton("&Open");
    QDial* pdiaVolume = new QDial;

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

    connect(pcmdOpen, &QPushButton::clicked, this, &SoundPlayer::slotOpen);
    connect(m_pcmdPlay, &QPushButton::clicked, this, &SoundPlayer::slotPlay);

    connect(m_pcmdStop, &QPushButton::clicked, m_pmp, &QMediaPlayer::stop);
    connect(pdiaVolume, &QDial::valueChanged, m_pmp, &QMediaPlayer::setVolume);
    connect(m_psldPosition, &QSlider::sliderMoved, this, &SoundPlayer::slotSetMediaPosition);

    connect(m_pmp, &QMediaPlayer::positionChanged, this, &SoundPlayer::slotSetSliderPosition);
    connect(m_pmp, &QMediaPlayer::durationChanged, this, &SoundPlayer::slotSetDuration);
    connect(m_pmp, &QMediaPlayer::stateChanged, this, &SoundPlayer::slotStatusChanged);

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
    m_pvbxМainLayout->addLayout(phbxPlayControls);
    m_pvbxМainLayout->addLayout(phbxTimeControls);
    setLayout(m_pvbxМainLayout);
}
void SoundPlayer::slotOpen()
{
    QString strFile = QFileDialog::getOpenFileName(this, "Open File");
    if (!strFile.isEmpty())
    {
        m_pmp->setMedia(QUrl::fromLocalFile(strFile));
        m_pcmdPlay->setEnabled(true);
        m_pcmdStop->setEnabled(true);
    }
};
void SoundPlayer::slotPlay()
{
    switch(m_pmp->state()){
    case QMediaPlayer::PlayingState:
    {
        m_pmp->pause();
        break;
    }
    default:
        m_pmp->play();
        break;
    }
};
void SoundPlayer::slotStatusChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PlayingState:
    {
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    }
    default:
    {
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
    }
};

void SoundPlayer::slotSetMediaPosition(int n)
{
    m_pmp->setPosition(n);
};

QString SoundPlayer::msecsToString(qint64 n)
{
    int nHours = (n / (60 * 60 * 1000));
    int nМinutes = ((n % (60 * 60 * 1000) ) / (60 * 1000));
    int nSeconds = ((n % (60 * 1000)) / 1000);
    return QTime(nHours, nМinutes, nSeconds).toString ("hh:mm:ss");
};

void SoundPlayer::slotSetDuration(qint64 n)
{
    m_psldPosition->setRange(0, n);
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
};

void SoundPlayer::slotSetSliderPosition(qint64 n){
    m_psldPosition->setValue(n);

    m_plblCurrent->setText(msecsToString(n));
    int nDuration = m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration-n) );
}
