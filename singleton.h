#ifndef SINGLETON_H
#define SINGLETON_H

/******************************************
**
** @file        singleton.h
** @brief
**
** @author      QwQSilver
** @date        2024/07/08
** @history
**
******************************************/
#include "global.h"

template<typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>&) = delete;
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }

    ~Singleton(){

    }
};

#endif // SINGLETON_H
