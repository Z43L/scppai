#include "interprete.hpp"

void interprete::tokenize() {
            while (true) {
                Token token = lexer.nextToken();
                if (token.getType() == TokenType::Type::EndOfFile) {
                    break;
                }
                else if(token.getType() == TokenType::Type::Identifier) {
                    tokens[token.getValue()] = token.getType();
                    
                }
                else if(token.getType() == TokenType::Type::Keyword) {
                    tokens[token.getValue()] = token.getType();
                }
                else if(token.getType() == TokenType::Type::Operator) {
                    tokens[token.getValue()] = token.getType();
                }
                else if(token.getType() == TokenType::Type::Punctuation) {
                    tokens[token.getValue()] = token.getType();
                }
                else {
                    setSalidaStatus(1);
                }

            }
        }
