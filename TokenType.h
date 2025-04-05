//
// Created by 25843 on 2025/4/4.
//

#ifndef DORO_TOKENTYPE_H
#define DORO_TOKENTYPE_H
enum TokenType
{
    LPAREN, RPAREN, LBRACE, RBRACE,                     // ( ) { }
    COMMENT,                                            // //
    COMMA, DOT, MINUS, PLUS, SEMICOLON, DIV, MUL,       // , . - + ; / *

    BANG, BANG_EQUAL,                                   // ! !=
    EQUAL, EQUAL_EQUAL,                                 // = ==
    GREATER, GREATER_EQUAL,                             // > >=
    LESS, LESS_EQUAL,                                   // < <=

    IDENTIFIER, STRING, INTEGER, FLOAT,                 // identifier string integer float

    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,     // && class else false function for if null ||
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,       // print return super this true var while

    END                                                 // eof
};
#endif //DORO_TOKENTYPE_H
