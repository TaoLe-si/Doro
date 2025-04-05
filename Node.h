//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_NODE_H
#define DORO_NODE_H


#include "Object.h"
#include "Token.h"

class Node: public Object {
public:
    void visit();
    virtual std::string getType() const;
};

class BinOp: public Node {
public:
    BinOp(Node* left, Token* token, Node* right);
    [[nodiscard]] std::string getType() const override;
public:
    Token* mToken;
    Node* mLeft_node;
    Node* mRight_node;
};

class Integer: public Node {
public:
    explicit Integer(Token* token);
    [[nodiscard]] std::string getType() const override;
public:
    Token* mToken;
    std::string mValue;
};

class Float: public Node {
public:
    explicit Float(Token* token);
    [[nodiscard]] std::string getType() const override;
public:
    Token* mToken;
    std::string mValue;
};
#endif //DORO_NODE_H
