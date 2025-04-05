//
// Created by 25843 on 2025/4/4.
//

#include "Node.h"

BinOp::BinOp(Node *left, Token *token, Node *right) {
    mLeft_node = left;
    mToken = token;
    mRight_node = right;
}

std::string BinOp::getType() const {
    return "node::BinOp";
}

Integer::Integer(Token *token) {
    mToken = token;
    mValue = mToken -> mValue;
}

std::string Integer::getType() const {
    return "node::Integer";
}

void Node::visit() {

}

std::string Node::getType() const {
    return "node::root";
}

Float::Float(Token *token) {
    mToken = token;
    mValue = mToken -> mValue;
}

std::string Float::getType() const {
    return "node::Float";
}
