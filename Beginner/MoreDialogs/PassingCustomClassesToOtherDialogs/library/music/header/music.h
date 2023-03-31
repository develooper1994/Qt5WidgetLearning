#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QString>
#include <QDate>

// Date-class is ready
class Music
{
private:
    QString m_album;
    QString m_artist;
    QString m_notes;
    QDate m_release;

public:
    Music();

    QString album() const;
    void setAlbum(const QString &newAlbum);
    QString artist() const;
    void setArtist(const QString &newArtist);
    QString notes() const;
    void setNotes(const QString &newNotes);
    QDate release() const;
    void setRelease(const QDate &newRelease);
};

#endif // MUSIC_H
