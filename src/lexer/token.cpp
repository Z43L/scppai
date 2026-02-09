#include "lexer.hpp"

std::unordered_map<std::string, TokenType> Token::token_map(TokenType type, const std::string &value)
{
    std::unordered_map<std::string, TokenType> token_map;
    token_map.insert({value, type});
    return token_map;
}

std::unordered_map<std::string, TokenType> Token::load_token_map(std::unordered_map<std::string, TokenType> tipe)
{
    std::string example_value = "if";
    setvalue(Token::token_map(TokenType::Identifier, "if"));
    return tipe;
}

std::unordered_map<std::string, TokenType> Token::setvalue(std::unordered_map<std::string, TokenType> new_map)
{
    map = new_map;
    return map;
}

int Token::getTokenTypeInt(TokenType type)
{
    return static_cast<int>(type);
}