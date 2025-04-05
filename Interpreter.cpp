//
// Created by 25843 on 2025/4/4.
//

#include <iostream>
#include "Interpreter.h"

Interpreter::Interpreter(Node *tree) {
    mTree = tree;
}

std::string Interpreter::interpret() {
    return visit(mTree);
}

std::string Interpreter::visit_BinOp(Node *node) {
    auto operation = dynamic_cast<BinOp *>(node);
    if (operation -> mToken -> mType == TokenType::PLUS) {
        return std::to_string(std::stof(visit(operation -> mLeft_node)) + std::stof(visit(operation -> mRight_node)));
    }
    if (operation -> mToken -> mType == TokenType::MINUS) {
        return std::to_string(std::stof(visit(operation -> mLeft_node)) - std::stof(visit(operation -> mRight_node)));
    }
    if (operation -> mToken -> mType == TokenType::MUL) {
        return std::to_string(std::stof(visit(operation -> mLeft_node)) * std::stof(visit(operation -> mRight_node)));
    }
    if (operation -> mToken -> mType == TokenType::DIV) {
        return std::to_string(std::stof(visit(operation -> mLeft_node)) / std::stof(visit(operation -> mRight_node)));
    }
}

std::string Interpreter::visit_Integer(Node *node) {
    auto temp = dynamic_cast<Integer *>(node);
    return temp -> mValue;
}

std::string Interpreter::visit_Float(Node *node) {
    auto temp = dynamic_cast<Float *>(node);
    return temp -> mValue;
}

std::string Interpreter::visit(Node *node) {
    if (node -> getType() == "node::BinOp") {
        return visit_BinOp(node);
    }
    if (node -> getType() == "node::Integer") {
        return visit_Integer(node);
    }
    if (node -> getType() == "node::Float") {
        return visit_Float(node);
    }
}


