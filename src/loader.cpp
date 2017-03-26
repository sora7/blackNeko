#include "loader.h"

Loader::Loader(QUrl url, QObject *parent) : QObject(parent)
{
    connect(&m_WebCtrl,
            SIGNAL(finished(QNetworkReply*)),
            this,
            SLOT(fileDownloaded(QNetworkReply*)));

    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:45.9) Gecko/20100101 Goanna/3.2 Firefox/45.9 PaleMoon/27.2.0");
    m_WebCtrl.get(request);
}

Loader::~Loader()
{
}

QByteArray Loader::downloadedData() const
{
    return m_DownloadedData;
}

QString Loader::getHtml() const
{
    const int UNICODE = 106;

    QString htmlText;
    htmlText = QTextCodec::codecForMib(UNICODE)->toUnicode(m_DownloadedData);
    return htmlText;
}

void Loader::fileDownloaded(QNetworkReply *pReply)
{
    m_DownloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}
