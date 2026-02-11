#include "src/lexer/lexer.hpp"
#include "main.hpp"


int main(int ac, char** av) {
    if (ac < 2) {
        std::cout << "No input provided." << std::endl;
        return 1;
    }
    std::string input = av[1];
    Lexer lexer(input);
    Parser parser ({}, 0, input, lexer);
    std::vector<Token> tokens = parser.readFiles(input);
    parser.parse();
    int tokenCount = tokens.size();

    std::cout <<"Total tokens: " << tokenCount << std::endl;
    return 0;
}
