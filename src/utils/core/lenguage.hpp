#ifndef LENGUAGE_HPP
#define LENGUAGE_HPP

#include <string>
#include <unordered_map>
#include "../../lexer/lexer.hpp"
#include "../../jit/interprete.hpp"

enum class Operator
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    EQUALS,
    NOT_EQUALS,
    GREATER_THAN,
    LESS_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN_OR_EQUAL,
    AND,
    OR,
    NOT
};

enum class Playscripting
{
    LOOP = 1,
    CONDITIONAL = 2,
    FUNCTION = 3,
    VARIABLE = 4,
    CLASS = 5,
    INTERFACE = 6,
    ENUM = 7,
    NAMESPACE = 8,
    MODULE = 9,
    IMPORT = 10,
    EXPORT = 11,
    ASINCHRONOUS = 12,
    SYNCHRONOUS = 13,
    STATIC = 14,
    DYNAMIC = 15,
    SOCKET = 16,
    READ_CSV = 17,
    WRITE_CSV = 18,
    JSON = 19,
    XML = 20,
    DATABASE = 21,
    FILE_IO = 22,
    NETWORK = 23,
    THREADING = 24,
    ERROR_HANDLING = 25,
    TORCH = 26,
    TENSOR = 27,
    CUDA = 28
};

using PlayMap = std::unordered_map<std::string, Playscripting>;
using OpMap = std::unordered_map<std::string, Operator>;

class lenguage
{
private:
    int vocales;
    bool loop;
    bool condicional;
    std::string value;
    Token token;
    TokenType tokenType;
    Operator ope;
    Playscripting playscripting;
    PlayMap playscripting_map;
    PlayMap ordener_playscripting_map;

public:
    lenguage(int vocales, bool loop, const Token &tokenArg, const TokenType &tokenTypeArg, bool condicional, Operator opeArg, Playscripting playscriptingArg)
        : vocales(vocales), loop(loop), condicional(condicional), value(""), token(tokenArg), tokenType(tokenTypeArg), ope(opeArg), playscripting(playscriptingArg)
    {
        // keep default initialization minimal
    }
    ~lenguage() {};
    int getVocales() const { return vocales; }
    bool isLoop() const { return loop; }
    bool isCondicional() const { return condicional; }
    Operator getOperator() const { return ope; }
    Playscripting getPlayscripting() const { return playscripting; }
    PlayMap getPlayscriptingMap();
    PlayMap getOrdenerPlayscriptingMap();
    PlayMap setPlayscriptingMap(const PlayMap &new_map);
    PlayMap setOrdenerPlayscriptingMap(const std::string &tipe, const PlayMap &new_map);
    Playscripting setOrdenerPlayscriptingMap(std::string key, Playscripting value, Operator op);
    std::string OperatorToString(Operator op);
    int operatorToInt(Operator op);
    int *numeberIndexOperator(TokenType::Type op, Playscripting value);
    int playscriptingToInt(Playscripting value);
};

#endif
