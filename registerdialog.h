#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

/******************************************
**
** @file        registerdialog.h
** @brief
**
** @author      QwQSilver
** @date        2024/07/08
** @history
**
******************************************/
#include <QDialog>
#include "global.h"


namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_verifyButton_clicked();
    void slot_reg_mod_finish(RequestId id, QString s, ErrorCodes ec);

private:
    void initHttpHandlers();
    void showTips(QString s, bool ok);

    QRegularExpression Phone_Num = QRegularExpression("^[0-9]{11}");
    Ui::RegisterDialog *ui;
    QMap<RequestId, std::function<void(const QJsonObject&)>> _handlers;
};

#endif // REGISTERDIALOG_H
