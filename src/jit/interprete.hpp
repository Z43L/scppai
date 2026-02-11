#ifndef INTERPRETE_HPP
#define INTERPRETE_HPP

#include "../lexer/lexer.hpp"

class interprete {
    private:
        Lexer lexer;
        std::unordered_map<std::string, TokenType::Type> tokens;
        size_t current_token_index;
        size_t loop_counter;
        size_t salida_status;
    public:
        interprete(const std::string& input) : lexer(input), current_token_index(0) {}
        void tokenize();
        void interpret();
        int getSalidaStatus() const { return salida_status; }
        void setSalidaStatus(int status) { salida_status = status; }
};

#endif
