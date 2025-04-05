//
// Created by 25843 on 2025/4/2.
//

#include "Alert.h"

void* Alert::make(std::string& str) {
    std::cout << str << std::endl;
}

void* Alert::make(const char& str) {
    std::cout << str << std::endl;
}