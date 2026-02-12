#include "while.hpp"
#include "../../jit/interprete.hpp"
std::vector<Token> interprete::executeWhile(std::vector<Token> tokenswhile, int i)
{
        std::vector<Token> new_token_map;
        int x = 0;
        while(tokenswhile.at(i).getType() != TokenType::Type::EndOfFile)
        {
                if(tokenswhile.at(i).getType() == TokenType::Type::Identifier && tokenswhile.at(i).getValue() == "if")
                {
                        auto result = interpreterIf(tokenswhile);
                        new_token_map.insert(new_token_map.end(), result.begin(), result.end());
                }
                if(tokenswhile.at(i).getType() == TokenType::Type::Identifier && tokenswhile.at(i).getValue() == "fuction")
                {
                        auto result = interpreterFuction(tokenswhile, i);
                        new_token_map.insert(new_token_map.end(), result.begin(), result.end());
                }
        }

        return new_token_map;
}