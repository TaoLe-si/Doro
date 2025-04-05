//
// Created by 25843 on 2025/4/4.
//

#include "Token.h"
Token::Token(TokenType t, std::string& c) {
    mType = t;
    mValue = c;
};