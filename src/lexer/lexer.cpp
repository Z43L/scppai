#include "lexer.hpp"
Token::Token(TokenType type, const std::string& value) : type(type), value(value) {
    std::unordered_map<std::string, TokenType> token_map;
    token_map.insert({value, type});
    
}
Token::~Token() {}


std::unordered_map<std::string, TokenType> token_map(TokenType, const std::string& value)
{
    std::unordered_map<std::string, TokenType> token_map;
    token_map.insert({value, TokenType::Identifier});
    return token_map;
}

int main(int ac, char** av) {
    if (ac < 1) {
        std::cout << "No input provided." << std::endl;
        return 1;
    }
    std::string input(av[1]);
    Token token(TokenType::Identifier, input);
    std::cout << "Token Type: " << static_cast<int>(token.getType()) << std::endl;
    std::cout << "Token Value: " << token.getValue() << std::endl;
    return 0;
}