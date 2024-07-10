#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    // ui->password->setEchoMode(QLineEdit::Password);
    // ui->confirmpw->setEchoMode(QLineEdit::Password);
    ui->login_hint->setProperty("state", "normal");
    repolish(ui->login_hint);
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish, this, &RegisterDialog::slot_reg_mod_finish);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_verifyButton_clicked()
{
    auto phone_number = ui->phonenumber->text();

    bool match = Phone_Num.match(phone_number).hasMatch();
    if(match){
        // send verify code
        qDebug("send verify code");
    }else{
        showTips(tr("电话号码不正确！"), false);
    }
}

void RegisterDialog::slot_reg_mod_finish(RequestId id, QString s, ErrorCodes ec)
{
    if(ec!=ErrorCodes::SUCCESS){
        showTips(tr("网络错误！"), false);
        return;
    }
    QJsonDocument jd = QJsonDocument::fromJson(s.toUtf8());
    if(jd.isNull()){
        showTips(tr("Json解析失败！"), false);
        return;
    }
    if(!jd.isObject()){
        showTips(tr("Json解析失败！"), false);
        return;
    }
    _handlers[id](jd.object());
    return;
}

void RegisterDialog::initHttpHandlers()
{
    _handlers.insert(RequestId::ID_GET_VERIFY_CODE, [this](const QJsonObject& jo){
        int ec = jo["error"].toInt();
        if(ec != ErrorCodes::SUCCESS){
            showTips(tr("参数错误！"), false);
            return;
        }
        auto phone_number = jo["phonenumber"].toString();
        showTips("验证码已发送！", true);
        qDebug() << "验证码已发送";
    });
}

void RegisterDialog::showTips(QString s, bool ok)
{
    if(ok){
        ui->login_hint->setProperty("state", "normal");
    }else{
        ui->login_hint->setProperty("state", "err");
    }
    ui->login_hint->setText(s);

    repolish(ui->login_hint);
}

