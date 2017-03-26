#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Loader : public QObject
{
    Q_OBJECT
public:
    explicit Loader(QUrl url, QObject *parent = 0);
    virtual ~Loader();
    QByteArray downloadedData() const;
    QString getHtml() const;
signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};

#endif // LOADER_H
