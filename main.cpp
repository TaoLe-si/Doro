#include <iostream>
#include <vector>
#include <cstring>

#include "Alert.h"
#include "TokenType.h"
#include "Token.h"
#include "Parser.h"
#include "Scanner.h"
#include "Interpreter.h"


int main() {
    std::string source = "//1 + 2\n"
                         "143.5 + (4 + 8) * 9 / 4 + 2 - 9 * (12 + 12)";

    auto scanner = new Scanner(source);
    std::vector<Token*> tokenList = scanner -> scan();
    auto parser = new Parser(tokenList);
    for (auto i : tokenList) {
        //std::string s(i->mValue);
        //s.push_back(i->mValue);
        //std::cout << "@@@: " << i->mValue << std::endl;
        //Alert::make(s);
    }
    auto result = (new Interpreter(parser -> parse())) -> interpret();

    std::cout << result;


    return 0;
}
