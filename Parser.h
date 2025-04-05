//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_PARSER_H
#define DORO_PARSER_H


#include <vector>
#include "TokenType.h"
#include "Token.h"
#include "Node.h"

class Parser {
public:
    explicit Parser(std::vector<Token*>& list);
    Node* primary();
    Node* factor();
    Node* unary();
    Node* term();
    Node* parse();
    Node* equality();
    Node* comparison();
    void consume(TokenType type);
    bool match(TokenType type1, TokenType type2);
    bool match(TokenType type1, TokenType type2, TokenType type3, TokenType type4);
private:
    std::vector<Token*> mList;
    long long mCurrent;
    Token* mCurrentToken;
};

#endif //DORO_PARSER_H
