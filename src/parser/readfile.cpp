#include "parse.hpp"


std::string Parser::setvalue(std::string value)
{
    return value;
}
std::vector<std::string> Parser::getErrors() const
{
    return errors;
}

namespace
{
bool readFileToString(const std::string &filename, std::string &out)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }
    out.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    return true;
}

std::string tokenTypeToString(TokenType::Type type)
{
    switch (type)
    {
    case TokenType::Type::Identifier:
        return "Identifier";
    case TokenType::Type::Keyword:
        return "Keyword";
    case TokenType::Type::Operator:
        return "Operator";
    case TokenType::Type::Punctuation:
        return "Punctuation";
    case TokenType::Type::Number:
        return "Number";
    case TokenType::Type::String:
        return "String";
    case TokenType::Type::EndOfFile:
        return "EndOfFile";
    default:
        return "Unknown";
    }
}

TokenType::NodeContent makeNodeContent(const Token &token, int position)
{
    TokenType::NodeContent content{};
    const TokenType::Type type = token.getType();

    content.positionEjecution = position;
    content.value = token.getValue();
    content.type = tokenTypeToString(type);
    content.tokenTypeInt = static_cast<int>(type);
    content.context = nullptr;
    content.Type = type;
    content.NodeXType = TokenType::NodeType::Expression;
    content.PrincipalType = TokenType::PrincipalType::Variable;

    if (type == TokenType::Type::Keyword)
    {
        content.keywords = token.getValue();
    }
    else if (type == TokenType::Type::Operator)
    {
        content.operators = token.getValue();
        if (token.getValue() == "+")
        {
            content.OperatorType = TokenType::OperatorType::Plus;
        }
        else if (token.getValue() == "-")
        {
            content.OperatorType = TokenType::OperatorType::Minus;
        }
        else if (token.getValue() == "*")
        {
            content.OperatorType = TokenType::OperatorType::Multiply;
        }
        else if (token.getValue() == "/")
        {
            content.OperatorType = TokenType::OperatorType::Divide;
        }
        else if (token.getValue() == "=")
        {
            content.OperatorType = TokenType::OperatorType::Equal;
        }
    }
    else if (type == TokenType::Type::Punctuation)
    {
        content.punctuation = token.getValue();
    }
    else if (type == TokenType::Type::String)
    {
        content.ValueType = TokenType::ValueType::String;
    }
    else if (type == TokenType::Type::Number)
    {
        content.ValueType = TokenType::ValueType::Number;
    }

    return content;
}
}

std::vector<Token> Parser::readFiles(const std::string &filename)
{
    tokens.clear();
    compiler_maps.clear();

    if (filename.empty())
    {
        addError("Filename is empty.");
        return tokens;
    }

    std::string content;
    if (!readFileToString(filename, content))
    {
        addError("Failed to read file: " + filename);
        return tokens;
    }
    if (content.empty())
    {
        addError("File is empty: " + filename);
        return tokens;
    }

    input = content;
    Lexer lexer(content);

    int position = 0;
    auto &file_map = compiler_maps[filename];
    for (;;)
    {
        Token token = lexer.nextToken();
        if (token.getType() == TokenType::Type::EndOfFile)
        {
            break;
        }
        tokens.push_back(token);
        file_map[token.getValue()] = makeNodeContent(token, position);
        position++;
    }

    return tokens;
}

std::vector<Token> Parser::readFiles(const std::vector<std::string> &filenames)
{
    tokens.clear();
    compiler_maps.clear();
    input.clear();

    if (filenames.empty())
    {
        addError("Filenames list is empty.");
        return tokens;
    }

    for (const auto &filename : filenames)
    {
        if (filename.empty())
        {
            addError("Filename is empty.");
            continue;
        }

        std::string content;
        if (!readFileToString(filename, content))
        {
            addError("Failed to read file: " + filename);
            continue;
        }
        if (content.empty())
        {
            addError("File is empty: " + filename);
            continue;
        }

        if (!input.empty())
        {
            input.push_back('\n');
        }
        input += content;

        Lexer lexer(content);
        int position = 0;
        auto &file_map = compiler_maps[filename];
        for (;;)
        {
            Token token = lexer.nextToken();
            if (token.getType() == TokenType::Type::EndOfFile)
            {
                break;
            }
            tokens.push_back(token);
            file_map[token.getValue()] = makeNodeContent(token, position);
            position++;
        }
    }

    return tokens;
}

void Parser::addError(const std::string &error)
{
    errors.push_back(error);
}

void TokenType::parseStatement(Token &token, TokenType &type)
{
    if (type.getNodeTypeString(TokenType::NodeType::Statement) == "Statement")
    {
        if(token.getValue() == "if")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "while")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "for")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "return")
        {
            type.parseStatement(token, type);
        }
    }
}
void Parser::parseExpression(std::vector<Token> &tokens)
{
    if (tokens.empty())
    { 
        addError("No tokens to parse.");
        return;
    }
    while (position < tokens.size() && tokens[position].getType() != TokenType::Type::EndOfFile)
    {
        type.parseStatement(tokens[position], type);
        position++;
    }
}  
void Parser::parse()
{
    parseExpression(tokens);
}
