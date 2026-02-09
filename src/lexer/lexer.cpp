#include "lexer.hpp"
#include <cctype>

void Lexer::readChar()
{
    if (read_position >= input.size())
    {
        current_char = 0;
        is_end_of_file = true;
    }
    else
    {
        current_char = input[read_position];
    }
    position = read_position;
    read_position++;
}

void Lexer::skipWhitespace()
{
    while (!is_end_of_file && std::isspace(static_cast<unsigned char>(current_char)))
    {
        readChar();
    }
}

bool Lexer::isLetter(char ch) const
{
    return std::isalpha(static_cast<unsigned char>(ch)) || ch == '_';
}

Token Lexer::readIdentifier()
{
    size_t start = position;
    while (!is_end_of_file && (isLetter(current_char) || std::isdigit(static_cast<unsigned char>(current_char))))
    {
        readChar();
    }

    std::string value = input.substr(start, position - start);
    static const std::unordered_map<std::string, TokenType> keywords = {
        {"if", TokenType::Keyword},
        {"else", TokenType::Keyword},
        {"while", TokenType::Keyword},
        {"for", TokenType::Keyword},
        {"return", TokenType::Keyword}};

    auto it = keywords.find(value);
    if (it != keywords.end())
    {
        return Token(it->second, value);
    }
    return Token(TokenType::Identifier, value);
}

Token Lexer::readNumber()
{
    size_t start = position;
    while (!is_end_of_file && std::isdigit(static_cast<unsigned char>(current_char)))
    {
        readChar();
    }
    std::string value = input.substr(start, position - start);
    return Token(TokenType::Number, value);
}

Token Lexer::readString()
{
    readChar();
    size_t start = position;
    while (!is_end_of_file && current_char != '"')
    {
        readChar();
    }
    std::string value = input.substr(start, position - start);
    if (current_char == '"')
    {
        readChar();
    }
    return Token(TokenType::String, value);
}

Token Lexer::nextToken()
{
    if (position == 0 && read_position == 0 && current_char == 0)
    {
        readChar();
    }

    skipWhitespace();

    if (is_end_of_file || current_char == 0)
    {
        return Token(TokenType::EndOfFile, "");
    }

    if (isLetter(current_char))
    {
        return readIdentifier();
    }

    if (std::isdigit(static_cast<unsigned char>(current_char)))
    {
        return readNumber();
    }

    if (current_char == '"')
    {
        return readString();
    }

    char ch = current_char;
    readChar();

    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
        return Token(TokenType::Operator, std::string(1, ch));
    case ';':
    case ',':
    case '(':
    case ')':
    case '{':
    case '}':
        return Token(TokenType::Punctuation, std::string(1, ch));
    default:
        return Token(TokenType::EndOfFile, "");
    }
}
