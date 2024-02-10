#ifndef KARPLUS_STRONG_H
#define KARPLUS_STRONG_H
#include <QString>
#include <QFile>
#include <random>
#include <QSoundEffect>
class karplus_strong : public QObject
{
    Q_OBJECT
private:
    qint32 sample_rate;
    double freq;
    qint16 sample_size;
    QString name;
    int SPD_NUM_CHAN;

    int lenSound;
    int duration;
    double * noise_buffer;
    double * temp_sound;
    qint16 * sound;
    QSoundEffect effect;
public:
    karplus_strong();
    void ConvertFloatSamples(double * in, qint16 * out);
    void saveFile(QString input_name);
    double calcFreq(float octave, float note);
    double Sine(int index, double frequency);
    double random(double a, double b);
public slots:
    void slotSetFreq(int);
    void slotSetRate(int);
    void slotSetDur(int);
    void slotSetName(const QString& str);
    void slotSave();
    void slotPlay();
};

#endif // KARPLUS_STRONG_H
