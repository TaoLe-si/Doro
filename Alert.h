//
// Created by 25843 on 2025/4/2.
//

#ifndef DORO_ALERT_H
#define DORO_ALERT_H


#include <string>
#include <iostream>

class Alert {
public:
    static void* make(std::string& str);
    static void* make(const char& str);
};


#endif //DORO_ALERT_H
