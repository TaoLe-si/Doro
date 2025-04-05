//
// Created by 25843 on 2025/4/4.
//

#include <iostream>
#include "Parser.h"
#include "Error.h"

Parser::Parser(std::vector<Token*>& list) {
    mList = list;
    mCurrent = 0;
    mCurrentToken = mList[mCurrent];
};
Node* Parser::factor() {
    if (mCurrentToken -> mType == TokenType::INTEGER) {
        Node* node = new Integer(mCurrentToken);
        consume(TokenType::INTEGER);
        return node;
    }
    if (mCurrentToken -> mType == TokenType::FLOAT) {
        Node* node = new Float(mCurrentToken);
        consume(TokenType::FLOAT);
        return node;
    }
    if (mCurrentToken -> mType == TokenType::LPAREN) {
        Token* temp = mCurrentToken;
        consume(TokenType::LPAREN);
        Node* node_left = expr();
        consume(TokenType::RPAREN);
        return node_left;
    }
}
Node* Parser::term() {
    Node* node = factor();
    while (match(TokenType::MUL, TokenType::DIV)) {
        Token* temp = mCurrentToken;
        if (mCurrentToken -> mType == TokenType::MUL) {
            consume(TokenType::MUL);
        }
        if (mCurrentToken -> mType == TokenType::DIV) {
            consume(TokenType::DIV);
        }
        node = new BinOp(node, temp, factor());
    }
    return node;
}
Node* Parser::expr() {
    Node* node = term();
    while (match(TokenType::PLUS, TokenType::MINUS)) {
        Token* temp = mCurrentToken;
        if (mCurrentToken -> mType == TokenType::PLUS) {
            consume(TokenType::PLUS);
        }
        if (mCurrentToken -> mType == TokenType::MINUS) {
            consume(TokenType::MINUS);
        }
        node = new BinOp(node, temp, term());
    }
    return node;
}
void Parser::consume(TokenType type) {
    if (mCurrentToken -> mType != type) {
        Error::e(("error type: " + mCurrentToken->mValue).c_str());
    }
    mCurrent += 1;
    mCurrentToken = mList[mCurrent];
}
bool Parser::match(TokenType type1, TokenType type2) {
    if (mCurrentToken -> mType == type1 || mCurrentToken -> mType == type2) {
        return true;
    }
    return false;
}

Node *Parser::parse() {
    return expr();
}
