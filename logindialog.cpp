#include "logindialog.h"
#include "global.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->regsiter, &QPushButton::clicked, this, &LoginDialog::switchRegister);
    ui->login_hint->setProperty("state", "normal");
    repolish(ui->login_hint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
