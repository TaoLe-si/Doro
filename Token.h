//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_TOKEN_H
#define DORO_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {
public:
    Token(TokenType t, std::string& c);
public:
    TokenType mType;
    std::string mValue;
};


#endif //DORO_TOKEN_H
