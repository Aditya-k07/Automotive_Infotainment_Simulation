#include <QtTest/QtTest>
#include <QSignalSpy>
#include "MediaController.h"

class TestMediaController : public QObject
{
    Q_OBJECT

private slots:
    // ── Initialization ─────────────────────────────────────────────
    void testInitialValues();

    // ── Play / Pause ───────────────────────────────────────────────
    void testPlayPauseToggle();
    void testPlayPauseEmitsSignal();

    // ── Track Navigation ───────────────────────────────────────────
    void testNextTrack();
    void testNextTrackWrapsAround();
    void testPrevTrackAtStart();
    void testPrevTrackRestartsIfBeyond3Sec();

    // ── Volume ─────────────────────────────────────────────────────
    void testSetVolume();
    void testSetVolumeClampLow();
    void testSetVolumeClampHigh();

    // ── Seek ───────────────────────────────────────────────────────
    void testSeekTo();
    void testSeekClampLow();
    void testSeekClampHigh();

    // ── Track Info ─────────────────────────────────────────────────
    void testTrackInfo();
    void testTotalTracks();

    // ── Playback Progress ──────────────────────────────────────────
    void testProgressAdvances();

    // ── Auto-Advance to Next Track ─────────────────────────────────
    void testAutoAdvanceAtEndOfTrack();
};

// ───────────────────────────────────────────────────────────────────
void TestMediaController::testInitialValues()
{
    MediaController ctrl;
    QCOMPARE(ctrl.isPlaying(), false);
    QCOMPARE(ctrl.trackIndex(), 0);
    QCOMPARE(ctrl.volume(), 70);
    QCOMPARE(ctrl.trackProgress(), 0.0);
    QCOMPARE(ctrl.elapsedSec(), 0);
}

void TestMediaController::testPlayPauseToggle()
{
    MediaController ctrl;
    ctrl.playPause();
    QCOMPARE(ctrl.isPlaying(), true);
    ctrl.playPause();
    QCOMPARE(ctrl.isPlaying(), false);
}

void TestMediaController::testPlayPauseEmitsSignal()
{
    MediaController ctrl;
    QSignalSpy spy(&ctrl, &MediaController::isPlayingChanged);
    ctrl.playPause();
    QCOMPARE(spy.count(), 1);
}

void TestMediaController::testNextTrack()
{
    MediaController ctrl;
    QCOMPARE(ctrl.trackIndex(), 0);
    ctrl.nextTrack();
    QCOMPARE(ctrl.trackIndex(), 1);
    ctrl.nextTrack();
    QCOMPARE(ctrl.trackIndex(), 2);
}

void TestMediaController::testNextTrackWrapsAround()
{
    MediaController ctrl;
    int total = ctrl.totalTracks();
    for (int i = 0; i < total; ++i)
        ctrl.nextTrack();
    QCOMPARE(ctrl.trackIndex(), 0); // wrapped around
}

void TestMediaController::testPrevTrackAtStart()
{
    MediaController ctrl;
    // At track 0, elapsed = 0 → should wrap to last track
    ctrl.prevTrack();
    QCOMPARE(ctrl.trackIndex(), ctrl.totalTracks() - 1);
}

void TestMediaController::testPrevTrackRestartsIfBeyond3Sec()
{
    MediaController ctrl;
    ctrl.nextTrack(); // go to track 1
    // Simulate being more than 3s into the track
    ctrl.seekTo(0.5); // halfway through
    // elapsed should be > 3 now for a 187s track
    ctrl.prevTrack();
    // Should restart same track (index stays 1), not go back to 0
    QCOMPARE(ctrl.trackIndex(), 1);
    QCOMPARE(ctrl.trackProgress(), 0.0);
}

void TestMediaController::testSetVolume()
{
    MediaController ctrl;
    QSignalSpy spy(&ctrl, &MediaController::volumeChanged);
    ctrl.setVolume(50);
    QCOMPARE(ctrl.volume(), 50);
    QCOMPARE(spy.count(), 1);
}

void TestMediaController::testSetVolumeClampLow()
{
    MediaController ctrl;
    ctrl.setVolume(-10);
    QCOMPARE(ctrl.volume(), 0);
}

void TestMediaController::testSetVolumeClampHigh()
{
    MediaController ctrl;
    ctrl.setVolume(200);
    QCOMPARE(ctrl.volume(), 100);
}

void TestMediaController::testSeekTo()
{
    MediaController ctrl;
    QSignalSpy spy(&ctrl, &MediaController::trackProgressChanged);
    ctrl.seekTo(0.5);
    QCOMPARE(ctrl.trackProgress(), 0.5);
    QVERIFY(spy.count() >= 1);
    // elapsed should be roughly half of track 0 duration (214s)
    QCOMPARE(ctrl.elapsedSec(), 107);
}

void TestMediaController::testSeekClampLow()
{
    MediaController ctrl;
    ctrl.seekTo(-1.0);
    QCOMPARE(ctrl.trackProgress(), 0.0);
}

void TestMediaController::testSeekClampHigh()
{
    MediaController ctrl;
    ctrl.seekTo(5.0);
    QCOMPARE(ctrl.trackProgress(), 1.0);
}

void TestMediaController::testTrackInfo()
{
    MediaController ctrl;
    // First track is "Neon Highways"
    QCOMPARE(ctrl.trackTitle(), QString("Neon Highways"));
    QCOMPARE(ctrl.artistName(), QString("Synthwave Collective"));
    QCOMPARE(ctrl.albumName(), QString("Retro Drive"));
    QCOMPARE(ctrl.trackDuration(), 214);
}

void TestMediaController::testTotalTracks()
{
    MediaController ctrl;
    QCOMPARE(ctrl.totalTracks(), 5);
}

void TestMediaController::testProgressAdvances()
{
    MediaController ctrl;
    ctrl.playPause(); // start playing
    QTest::qWait(2500); // wait ~2.5 seconds
    QVERIFY(ctrl.trackProgress() > 0.0);
    QVERIFY(ctrl.elapsedSec() >= 2);
    ctrl.playPause(); // stop
}

void TestMediaController::testAutoAdvanceAtEndOfTrack()
{
    MediaController ctrl;
    // Seek near the end of track 0 (214s)
    ctrl.seekTo(0.99); // ~211.8s
    ctrl.playPause(); // start playing
    // Needs ~3 seconds to wrap. Wait 5s.
    QTest::qWait(5000); 
    // Should have advanced to track 1
    QVERIFY(ctrl.trackIndex() >= 1);
    ctrl.playPause(); // stop
}

QTEST_MAIN(TestMediaController)
#include "tst_mediacontroller.moc"
