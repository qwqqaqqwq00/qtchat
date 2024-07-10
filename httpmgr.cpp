#include "httpmgr.h"

HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr() {

    connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpRequest(QUrl url, QJsonObject jo, RequestId req_id, Modules m)
{
    QByteArray qb = QJsonDocument(jo).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(qb.length()));
    auto self = shared_from_this();
    QNetworkReply *reply = _manager.post(request, qb);
    connect(reply, &QNetworkReply::finished, [self, reply, req_id, m](){
        if(reply->error() != QNetworkReply::NoError){
            emit self->sig_http_finish(req_id, "", ERR_NETWORK, m);
            reply->deleteLater();
            return;
        }

        QString res = reply->readAll();
        emit self->sig_http_finish(req_id, res, SUCCESS, m);
        reply->deleteLater();
        return;
    });
}

void HttpMgr::slot_http_finish(RequestId id, QString s, ErrorCodes ec, Modules m)
{
    if(m == REGISTERMOD){
        // send signal to module
        emit sig_reg_mod_finish(id, s, ec);
    }
}
