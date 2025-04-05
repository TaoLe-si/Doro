//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_SCANNER_H
#define DORO_SCANNER_H


#include <string>
#include <vector>
#include "Token.h"

class Scanner {
public:
    explicit Scanner(std::string& s);
    std::vector<Token*> scan();
    void consume(char tokenChar);
    bool match(char tokenChar);
    char advance();
    long long consumeInt();
    long long consumeAlpha();
    char consumeDot();
private:
    std::string mSource;
    long long mCurrent;
    std::vector<Token*> mList;
};


#endif //DORO_SCANNER_H
