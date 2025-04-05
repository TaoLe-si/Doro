//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_INTERPRETER_H
#define DORO_INTERPRETER_H


#include "Node.h"

class Interpreter {
public:
    explicit Interpreter(Node* tree);

    static std::string visit_Integer(Node* node);
    static std::string visit_Float(Node* node);
    static std::string visit_BinOp(Node* node);
    static std::string visit(Node* node);
    std::string interpret();
private:
    Node* mTree;
};


#endif //DORO_INTERPRETER_H
