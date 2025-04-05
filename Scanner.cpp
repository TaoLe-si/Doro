//
// Created by 25843 on 2025/4/4.
//

#include <cstring>
#include "Scanner.h"

Scanner::Scanner(std::string& s) {
    mSource = s;
    mCurrent = 0;
};
std::vector<Token*> Scanner::scan() {
    const char* s = mSource.c_str();
    char str = s[mCurrent];
    std::string tem_str;
    tem_str.push_back(str);
    while(mCurrent < strlen(s)) {
        str = s[mCurrent];
        tem_str = "";
        tem_str.push_back(str);
        if (str >= '0' && str <= '9') {
            long long former = mCurrent;
            long long latter = consumeInt();
            std::string integer;
            integer.push_back(s[former]);
            while (former < latter) {
                former += 1;
                integer.push_back(s[former]);
            }
            if (consumeDot() == '.') {
                former = mCurrent;
                latter = consumeInt();
                integer.push_back(s[former]);
                while (former < latter) {
                    former += 1;
                    integer.push_back(s[former]);
                }
                mCurrent += 1;
                mList.push_back(new Token(TokenType::FLOAT, integer));
                continue;
            }
            mList.push_back(new Token(TokenType::INTEGER, integer));
        }
        if (str >= 'a' && str <= 'z') {
            long long former = mCurrent;
            long long latter = consumeAlpha();
            std::string alpha;
            alpha.push_back(s[former]);
            while (former < latter) {
                former += 1;
                alpha.push_back(s[former]);
            }
            mCurrent += 1;
            if (alpha == "true") {
                mList.push_back(new Token(TokenType::TRUE, alpha));
                continue;
            }
            if (alpha == "false") {
                mList.push_back(new Token(TokenType::FALSE, alpha));
                continue;
            }
            mList.push_back(new Token(TokenType::STRING, alpha));
        }
        if (str == '+') {
            mList.push_back(new Token(TokenType::PLUS, tem_str));
        }
        if (str == '!') {
            mList.push_back(new Token(TokenType::BANG, tem_str));
        }
        if (str == '-') {
            mList.push_back(new Token(TokenType::MINUS, tem_str));
        }
        if (str == '*') {
            mList.push_back(new Token(TokenType::MUL, tem_str));
        }
        if (str == '(') {
            mList.push_back(new Token(TokenType::LPAREN, tem_str));
        }
        if (str == ')') {
            mList.push_back(new Token(TokenType::RPAREN, tem_str));
        }
        if (str == '/') {
            if (match('/')) {
                consume('\n');
                continue;
            }
            mList.push_back(new Token(TokenType::DIV, tem_str));
        }
        mCurrent += 1;
    }
    tem_str = "";
    str = s[mCurrent];
    tem_str.push_back(str);
    mList.push_back(new Token(TokenType::END, tem_str));
    return mList;
}
void Scanner::consume(char tokenChar) {
    const char* s = mSource.c_str();
    while(s[mCurrent] != tokenChar) {
        mCurrent += 1;
    }
}
bool Scanner::match(char tokenChar) {
    if (advance() == tokenChar) {
        return true;
    }
    return false;
}
char Scanner::advance() {
    const char* s = mSource.c_str();
    if (mCurrent >= strlen(s) - 1) return char();
    return mSource.c_str()[mCurrent + 1];
}
long long Scanner::consumeInt() {
    const char* s = mSource.c_str();
    while (s[mCurrent + 1] >= '0' && s[mCurrent + 1] <= '9') {
        mCurrent += 1;
    }
    return mCurrent;
}
long long Scanner::consumeAlpha() {
    const char* s = mSource.c_str();
    while (s[mCurrent + 1] >= 'a' && s[mCurrent + 1] <= 'z') {
        mCurrent += 1;
    }
    return mCurrent;
}
char Scanner::consumeDot() {
    const char* s = mSource.c_str();
    if (s[mCurrent + 1] == '.') {
        mCurrent += 1;
        return '.';
    } else {
        return char();
    }
}
