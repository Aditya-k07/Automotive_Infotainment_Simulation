#include "MediaController.h"
#include <QtMath>

MediaController::MediaController(QObject *parent) : QObject(parent)
{
    m_playlist = {
        { "Neon Highways",    "Synthwave Collective", "Retro Drive",   214 },
        { "Midnight Cruise",  "Lo-Fi Pilots",         "Night Roads",   187 },
        { "Speed of Light",   "Electronica X",        "Velocity",      253 },
        { "Urban Drift",      "City Beats",           "Street Sounds", 198 },
        { "Pulse of the Road","Bass Protocol",        "Freeway EP",    231 },
    };

    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &MediaController::onTick);
}

QString MediaController::trackTitle()    const { return m_playlist[m_trackIndex].title; }
QString MediaController::artistName()    const { return m_playlist[m_trackIndex].artist; }
QString MediaController::albumName()     const { return m_playlist[m_trackIndex].album; }
int     MediaController::trackDuration() const { return m_playlist[m_trackIndex].durationSec; }

void MediaController::playPause()
{
    m_isPlaying = !m_isPlaying;
    if (m_isPlaying) startPlayback(); else stopPlayback();
    emit isPlayingChanged();
}

void MediaController::nextTrack()
{
    m_trackIndex = (m_trackIndex + 1) % m_playlist.size();
    m_elapsedSec = 0;
    m_trackProgress = 0.0;
    if (m_isPlaying) { stopPlayback(); startPlayback(); }
    emit trackChanged();
    emit trackProgressChanged();
}

void MediaController::prevTrack()
{
    if (m_elapsedSec > 3) {
        m_elapsedSec = 0;
        m_trackProgress = 0.0;
    } else {
        m_trackIndex = (m_trackIndex - 1 + m_playlist.size()) % m_playlist.size();
        m_elapsedSec = 0;
        m_trackProgress = 0.0;
    }
    if (m_isPlaying) { stopPlayback(); startPlayback(); }
    emit trackChanged();
    emit trackProgressChanged();
}

void MediaController::setVolume(int v)
{
    m_volume = qBound(0, v, 100);
    emit volumeChanged();
}

void MediaController::seekTo(double progress)
{
    progress = qBound(0.0, progress, 1.0);
    m_trackProgress = progress;
    m_elapsedSec = static_cast<int>(progress * m_playlist[m_trackIndex].durationSec);
    emit trackProgressChanged();
}

void MediaController::onTick()
{
    if (!m_isPlaying) return;
    m_elapsedSec++;
    int dur = m_playlist[m_trackIndex].durationSec;
    if (m_elapsedSec >= dur) {
        nextTrack();
        return;
    }
    m_trackProgress = static_cast<double>(m_elapsedSec) / dur;
    emit trackProgressChanged();
}

void MediaController::startPlayback() { m_timer.start(); }
void MediaController::stopPlayback()  { m_timer.stop(); }
