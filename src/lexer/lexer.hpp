
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

enum class RelevationPlayscripting {
    LOOP,
    CONDITIONAL,
    FUNCTION,
    VARIABLE,
    CLASS,
    INTERFACE,
    ENUM,
    NAMESPACE,
    MODULE,
    IMPORT,
    EXPORT,
    ASINCHRONOUS,
    SYNCHRONOUS,
    STATIC,
    DYNAMIC,
    SOCKET,
    READ_CSV,
    WRITE_CSV,
    JSON,
    XML,
    DATABASE,
    FILE_IO,
    NETWORK,
    THREADING,
    ERROR_HANDLING,
    TORCH,
    TENSOR,
    CUDA,

};


enum class TokenType {
    Identifier,
    Number,
    String,
    Keyword,
    Operator,
    Punctuation,
    EndOfFile
};

class Token {
    private:
        TokenType type;
        std::string value;
        
        std::unordered_map<std::string, TokenType> map;
    public:
        Token(TokenType type, const std::string& value) : type(type), value(value) {}
        ~Token() {}
        TokenType getType() const { return type; }
        std::string getValue() const { return value; }
        TokenType getType();
        TokenType   Token::load_token_map(TokenType tipe) const;
        std::unordered_map<std::string, TokenType> token_map(TokenType type, const std::string& value);
        std::unordered_map<std::string, TokenType> getTokenMap() const { return map; }
        std::unordered_map<std::string, TokenType> setTokenMap(const std::unordered_map<std::string, TokenType>& new_map);
        std::unordered_map<std::string, TokenType>   Token::load_token_map(std::unordered_map<std::string, TokenType>  tipe);
        std::unordered_map<std::string, TokenType> setvalue(std::unordered_map<std::string, TokenType> new_map) ;
        std::unordered_map<std::string, TokenType> punctuation = {
                {";", TokenType::Punctuation},
                {",", TokenType::Punctuation},
                {"(", TokenType::Punctuation},
                {")", TokenType::Punctuation},
                {"{", TokenType::Punctuation},
                {"}", TokenType::Punctuation}
            };
        std::unordered_map<std::string, TokenType> operators = {
                {"+", TokenType::Operator},
                {"-", TokenType::Operator},
                {"*", TokenType::Operator},
                {"/", TokenType::Operator},
                {"=", TokenType::Operator}
        };
        std::unordered_map<std::string, TokenType> keywords = {
                {"if", TokenType::Keyword},
                {"else", TokenType::Keyword},
                {"while", TokenType::Keyword},
                {"for", TokenType::Keyword},
                {"return", TokenType::Keyword}  
        };

    };


    class Lexer {
    private:
        std::string input;
        size_t position;
        size_t read_position;
        char current_char;
        bool is_end_of_file;
        bool is_loop;
        RelevationPlayscripting current_play;
    public:
        Lexer(const std::string& input) : input(input), position(0), read_position(0), current_char(0), is_end_of_file(false), is_loop(false){};
        void readChar();
        Token nextToken();
        void skipWhitespace();
        Token readIdentifier();
        Token readNumber();
        Token readString();
        bool isLetter(char ch) const;
    };