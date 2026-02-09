#include "interprete.hpp"

void interprete::tokenize() {
            while (true) {
                Token token = lexer.nextToken();
                if (token.getType() == TokenType::EndOfFile) {
                    break;
                }
                else if(token.getType() == TokenType::Identifier) {
                    tokens[token.getValue()] = token.getType();
                    
                }
                else if(token.getType() == TokenType::Keyword) {
                    tokens[token.getValue()] = token.getType();
                }
                else if(token.getType() == TokenType::Operator) {
                    tokens[token.getValue()] = token.getType();
                }
                else if(token.getType() == TokenType::Punctuation) {
                    tokens[token.getValue()] = token.getType();
                }
                else {
                    setSalidaStatus(1);
                }

            }
        }
