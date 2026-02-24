#pragma once
#include <QObject>
#include <QTimer>
#include <QStringList>
#include <QtQml/qqml.h>

struct Track {
    QString title;
    QString artist;
    QString album;
    int     durationSec;
};

class MediaController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString trackTitle    READ trackTitle    NOTIFY trackChanged)
    Q_PROPERTY(QString artistName    READ artistName    NOTIFY trackChanged)
    Q_PROPERTY(QString albumName     READ albumName     NOTIFY trackChanged)
    Q_PROPERTY(int     trackIndex    READ trackIndex    NOTIFY trackChanged)
    Q_PROPERTY(int     totalTracks   READ totalTracks   CONSTANT)
    Q_PROPERTY(bool    isPlaying     READ isPlaying     NOTIFY isPlayingChanged)
    Q_PROPERTY(int     volume        READ volume        NOTIFY volumeChanged)
    Q_PROPERTY(double  trackProgress READ trackProgress NOTIFY trackProgressChanged)
    Q_PROPERTY(int     trackDuration READ trackDuration NOTIFY trackChanged)
    Q_PROPERTY(int     elapsedSec    READ elapsedSec    NOTIFY trackProgressChanged)

public:
    explicit MediaController(QObject *parent = nullptr);

    QString trackTitle()   const;
    QString artistName()   const;
    QString albumName()    const;
    int     trackIndex()   const { return m_trackIndex; }
    int     totalTracks()  const { return m_playlist.size(); }
    bool    isPlaying()    const { return m_isPlaying; }
    int     volume()       const { return m_volume; }
    double  trackProgress()const { return m_trackProgress; }
    int     trackDuration()const;
    int     elapsedSec()   const { return m_elapsedSec; }

public slots:
    void playPause();
    void nextTrack();
    void prevTrack();
    void setVolume(int v);
    void seekTo(double progress);

signals:
    void trackChanged();
    void isPlayingChanged();
    void volumeChanged();
    void trackProgressChanged();

private slots:
    void onTick();

private:
    void startPlayback();
    void stopPlayback();

    QList<Track> m_playlist;
    int     m_trackIndex    = 0;
    bool    m_isPlaying     = false;
    int     m_volume        = 70;
    double  m_trackProgress = 0.0;
    int     m_elapsedSec    = 0;
    QTimer  m_timer;
};
