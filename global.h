#ifndef GLOBAL_H
#define GLOBAL_H

/******************************************
**
** @file        global.h
** @brief
**
** @author      QwQSilver
** @date        2024/07/08
** @history
**
******************************************/
#include <QWidget>
#include <functional>
#include <QStyle>
#include <QRegularExpression>
#include <memory>
#include <iostream>
#include <mutex>

extern std::function<void(QWidget*)> repolish;

enum RequestId {
    ID_GET_VERIFY_CODE = 1001,
    ID_REG_USER = 1002,
};

enum Modules {
    REGISTERMOD = 0,
};

enum ErrorCodes {
    SUCCESS = 0,
    ERR_UNKNOWN = 1,
    ERR_JSON = 2,
    ERR_NETWORK = 3,
};


#endif // GLOBAL_H
