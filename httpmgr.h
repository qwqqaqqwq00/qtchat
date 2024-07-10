#ifndef HTTPMGR_H
#define HTTPMGR_H

/******************************************
**
** @file        httpmgr.h
** @brief
**
** @author      QwQSilver
** @date        2024/07/08
** @history
**
******************************************/
#include "singleton.h"
#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QDebug>

class HttpMgr: public QObject, public Singleton<HttpMgr>, public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
private:
    ~HttpMgr();
public:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    void PostHttpRequest(QUrl url, QJsonObject jo, RequestId req_id, Modules m);

    QNetworkAccessManager _manager;
private slots:
    void slot_http_finish(RequestId id, QString s, ErrorCodes ec, Modules m);

signals:
    void sig_http_finish(RequestId id, QString s, ErrorCodes ec, Modules m);
    void sig_reg_mod_finish(RequestId id, QString s, ErrorCodes ec);
};

#endif // HTTPMGR_H
