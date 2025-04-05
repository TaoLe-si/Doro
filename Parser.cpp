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

Node* Parser::primary() {
    if (mCurrentToken -> mType == TokenType::TRUE) {
        Node* node = new Bool(mCurrentToken);
        consume(TokenType::TRUE);
        return node;
    }
    if (mCurrentToken -> mType == TokenType::FALSE) {
        Node* node = new Bool(mCurrentToken);
        consume(TokenType::FALSE);
        return node;
    }
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
        Node* node_left = parse();
        consume(TokenType::RPAREN);
        return node_left;
    }
}
Node* Parser::unary() {
    if (match(TokenType::BANG, TokenType::MINUS)) {
        Token* temp = mCurrentToken;
        consume(mCurrentToken -> mType);
        Node* node = new UnaryOp(temp, unary());
        return node;
    }
    return primary();
}
Node* Parser::factor() {
    Node* node = unary();
    while (match(TokenType::MUL, TokenType::DIV)) {
        Token* temp = mCurrentToken;
        consume(mCurrentToken -> mType);
        node = new BinOp(node, temp, unary());
    }
    return node;
}
Node* Parser::term() {
    Node* node = factor();
    while (match(TokenType::PLUS, TokenType::MINUS)) {
        Token* temp = mCurrentToken;
        consume(mCurrentToken -> mType);
        node = new BinOp(node, temp, factor());
    }
    return node;
}
Node *Parser::comparison() {
    Node* node = term();
    while (match(TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL)) {
        Token* temp = mCurrentToken;
        consume(mCurrentToken -> mType);
        node = new BinOp(node, temp, term());
    }
    return node;
}
Node *Parser::equality() {
    Node* node = comparison();
    while (match(TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL)) {
        Token* temp = mCurrentToken;
        consume(mCurrentToken -> mType);
        node = new BinOp(node, temp, comparison());
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
bool Parser::match(TokenType type1, TokenType type2, TokenType type3, TokenType type4) {
    if (mCurrentToken -> mType == type1 || mCurrentToken -> mType == type2 || mCurrentToken -> mType == type3 || mCurrentToken -> mType == type4) {
        return true;
    }
    return false;
}
Node *Parser::parse() {
    return equality();
}


