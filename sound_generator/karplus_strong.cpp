#include "karplus_strong.h"
#include <QDataStream>

karplus_strong::karplus_strong()
{
    srand(time(0));
    duration = 3;
    freq = 100;
    sample_rate = 44100;
    name = "NoName.wav";
}

void karplus_strong::saveFile(QString input_name){
    name = input_name;
    QFile *file = new QFile(name);
    if (!file->open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(file);
    out.setByteOrder(QDataStream::LittleEndian);

    //Структура WAV-файла
    // chunk ID "RIFF"
    out.writeRawData("RIFF", 4);
    // chunk size (длина сэмпла + 36)
    out << quint32(lenSound + 36);
    // format (WAVE)
    out.writeRawData("WAVE", 4);
    // format chunk id
    out.writeRawData("fmt ", 4);
    // Subchunk1Size 16 для формата PCM.
    out << quint32(16);
    // Audio format для PCM = 1 (то есть, Линейное квантование).
    out << quint16(1);
    // Количество каналов. Моно = 1, Стерео = 2 и т.д.
    out << quint16(SPD_NUM_CHAN);
    // Частота дискретизации. 8000 Гц, 44100 Гц и т.д.
    out << quint32(sample_rate);
    // byte rate (sample rate * chan * sample size / 8)
    out << quint32(sample_rate * SPD_NUM_CHAN * sample_size / 8);
    // Количество байт для одного сэмпла, включая все каналы. num
    out << quint16(SPD_NUM_CHAN * sample_size / 8);
    // Так называемая точность звучания
    out << quint16(sample_size);
    // Subchunk2ID (data)
    out.writeRawData("data", 4);
    // Количество байт в области данных.
    out << quint32(lenSound);

    for (int i =0; i<lenSound; i++)
        out << sound[i];
    file->close();
}

void karplus_strong::ConvertFloatSamples (double * in, qint16 * out)
{
    // convert in format to out format !
    for (size_t i = 0, c = lenSound; i < c; ++i)
    {
        float v = in[i];
        if (v < 0.0f)
            v *= -float(std::numeric_limits<qint16>::lowest());
        else
            v *= float(std::numeric_limits<qint16>::max());
        out[i] = qint16(v);

    }
}

double karplus_strong::random(double a, double b)
{
     thread_local static std::mt19937 gen(std::random_device{}());
     using dist_type = typename std::conditional
        <
            std::is_integral<double>::value
            , std::uniform_int_distribution<double>
            , std::uniform_real_distribution<double>
        >::type;
    thread_local static dist_type dist;
    return dist(gen, typename dist_type::param_type{a, b});
}

void karplus_strong::slotSetFreq(int n){
    freq = n;
}

void karplus_strong::slotSetRate(int n){
    sample_rate = n;
}
void karplus_strong::slotSetDur(int n){
    duration = n;
}
void karplus_strong::slotSetName(const QString& str){
    name = str;
}
void karplus_strong::slotSave(){
    sample_size = sizeof(qint16)*8;
    SPD_NUM_CHAN = 1;

    int l_buff = int(sample_rate/freq);
    lenSound = int(sample_rate * duration);
    noise_buffer = new double[l_buff];
    temp_sound = new double[lenSound];
    sound = new qint16[lenSound];

    for (int i = 0; i<lenSound; i++){
        temp_sound[i] = 0.0;
    }
    for (int i = 0; i<l_buff; i++){
        noise_buffer[i] = random(-1.0, 1.0);
        temp_sound[i] = noise_buffer[i];
    }
    for (int i = l_buff; i<lenSound; i++){
        temp_sound[i] = 0.996 * ((temp_sound[i-l_buff] + temp_sound[i-l_buff-1]) * 0.5);
    }

    ConvertFloatSamples(temp_sound, sound);;
    saveFile(name);
    effect.setSource(QUrl::fromLocalFile(name));
}
void karplus_strong::slotPlay(){
    effect.setLoopCount(1);
    effect.setVolume(0.5f);
    effect.play();
}
