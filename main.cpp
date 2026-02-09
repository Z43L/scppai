#include "src/lexer/lexer.hpp"
#include "main.hpp"


int main(int ac, char** av) {
    if (ac < 2) {
        std::cout << "No input provided." << std::endl;
        return 1;
    }
    std::string input = av[1];
    Token token(TokenType::Identifier, input);
    std::cout << "Token Type: " << static_cast<int>(token.getType()) << std::endl;
    std::cout << "Token Value: " << token.getValue() << std::endl;
    return 0;
}