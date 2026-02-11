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
std::unordered_map<std::string, TokenType::NodeContent>  TokenType::getTokenType(std::string value, TokenType::PrincipalType principaltype, TokenType::ExecutionContext context, TokenType::NodeContent content  , int i,TokenType type )
{
    std::unordered_map<std::string, TokenType::NodeContent> token_map;
    if(TokenType::getPrincipalTypeString(principaltype) == "var" || TokenType::getPrincipalTypeString(principaltype) == "function" || TokenType::getPrincipalTypeString(principaltype) == "class" || TokenType::getPrincipalTypeString(principaltype) == "#include" || TokenType::getPrincipalTypeString(principaltype) == "#define" || TokenType::getPrincipalTypeString(principaltype) == "export")
    {
        content.type.replace(0, content.type.size(), "Identifier");
        content.context = &context;
        context.variables.insert({ value, 0});
        token_map.insert({value, content});
    }
    else
    {
        if(getPuntuationString(value) == "(")
        {
            content.context = &context;
            content.positionEjecution = i- 1;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getPuntuationString(value) == ")")
        {
            content.context = &context;
            content.positionEjecution = i- 2;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getPuntuationString(value) == "{")
        {
            content.context = &context;
            content.positionEjecution = i- 3;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getPuntuationString(value) == "}")
        {
            content.context = &context;
            content.positionEjecution = i- 4;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getPuntuationString(value) == ";")
        {
            content.context = &context;
            content.positionEjecution = i- 5;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getPuntuationString(value) == ",")
        {
            content.context = &context;
            content.positionEjecution = i- 6;
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "Identifier")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.type.insert(0, "Identifier");
            if(value == "var" || value == "function" || value == "class" || value == "#include" || value == "#define" || value == "export")
            {
                content.PrincipalType = principaltype;
                if(value == "function")
                {
                    context.functions.insert({ value, 2});
                }
                if (value == "class")
                {
                    context.classes.insert({ value, 1});
                }
                if(value == "while")
                {
                    context.whileLoops.insert({ value, 3});
                }
                if(value == "for")
                {
                    context.forLoops.insert({ value, 4});
                }
                if(value == "if")
                {
                    context.ifStatements.insert({ value, 5});
                }
                if(value == "else if")
                {
                    context.elseIfStatements.insert({ value, 6});   
                }
            }
            content.tokenTypeInt = 0;
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "Operator")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.operators = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Operator");
            if(value == "+")
            {
                content.OperatorType = TokenType::OperatorType::Plus;
            }
            else if(value == "-")
            {
                content.OperatorType = TokenType::OperatorType::Minus;
            }
            else if(value == "*")
            {
                content.OperatorType = TokenType::OperatorType::Multiply;
            }
            else if(value == "/")
            {
                content.OperatorType = TokenType::OperatorType::Divide;
            }
            else if(value == "=")
            {
                content.OperatorType = TokenType::OperatorType::Equal;
            }
            else if(value == "+=")
            {   
                 content.OperatorType = TokenType::OperatorType::EqualPlus;
            }
            else if(value == "-=")
            {
                    content.OperatorType = TokenType::OperatorType::EqualMinus;
            }
            token_map.insert({value, content}); 
        }
        else if(getNodeTypeString(content.NodeXType) == "Keyword")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.keywords =value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Keyword");
            token_map.insert({value, content});
        }
        else if (getNodeTypeString(content.NodeXType) == "String")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.type.insert(0, "String");
            content.ValueType = TokenType::ValueType::String;
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "Number")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.type.insert(0, "Number");
            content.ValueType = TokenType::ValueType::Number;
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else
        {
            content.context = &context;
            content.positionEjecution = i;
            content.type.insert(0, "Unknown");
            context.variables.insert({ value, 0});

            token_map.insert({value, content});
        }
    }
    return token_map;
}
int isLetter(char ch)
{
    if (std::isalpha(static_cast<unsigned char>(ch)) || ch == '_') return 1;
    return 0;
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
        {"if", TokenType::Type::Keyword},
        {"else", TokenType::Type::Keyword},
        {"while", TokenType::Type::Keyword},
        {"for", TokenType::Type::Keyword},
        {"return", TokenType::Type::Keyword}};
    auto it = keywords.find(value);
    if (it != keywords.end())
    {
        return Token(it->second, value);
    }
    return Token(TokenType::Type::Identifier, value);
}

Token Lexer::readNumber()
{
    size_t start = position;
    while (!is_end_of_file && std::isdigit(static_cast<unsigned char>(current_char)))
    {
        readChar();
    }
    std::string value = input.substr(start, position - start);
    return Token(TokenType::Type::Number, value);
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
    return Token(TokenType::Type::String, value);
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
        return Token(TokenType::Type::EndOfFile, "");
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
        return Token(TokenType::Type::Operator, std::string(1, ch));
    case ';':
    case ',':
    case '(':
    case ')':
    case '{':
    case '}':
        return Token(TokenType::Type::Punctuation, std::string(1, ch));
    default:
        return Token(TokenType::Type::EndOfFile, "");
    }
}
