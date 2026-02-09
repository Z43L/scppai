#include <string>
#include <unordered_map>
#include "../../lexer/lexer.hpp"
#include "../../jit/interprete.hpp"

enum class Operator {
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

enum class Playscripting {
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
    CUDA
};

class lenguage {
    private:
        int vocales;
        bool loop;
        bool condicional;
        std::string value;
        Operator &ope;
        Playscripting &playscripting;
        std::unordered_map<std::string, Playscripting> playscripting_map;
        std::unordered_map<std::string, Playscripting, Operator> ordener_playscripting_map;
    public:
        lenguage(int vocales, bool loop, bool condicional, Operator &ope, Playscripting &playscripting) : vocales(vocales), loop(loop), condicional(condicional), ope(ope), playscripting(playscripting) {}
        int getVocales() const { return vocales; }
        bool isLoop() const { return loop; }
        bool isCondicional() const { return condicional; }
        Operator getOperator() const { return ope; }
        Playscripting getPlayscripting() const { return playscripting; }
        std::unordered_map<std::string, Playscripting> getPlayscriptingMap();
        std::unordered_map<std::string, Playscripting, Operator> getOrdenerPlayscriptingMap();
        std::unordered_map<std::string, Playscripting> setPlayscriptingMap(std::unordered_map<std::string, Playscripting> new_map);
        std::unordered_map<std::string, Playscripting, Operator> setOrdenerPlayscriptingMap(std::unordered_map<std::string, Playscripting, Operator> new_map);
        Playscripting setPlayscriptingMap(std::string key, Playscripting value) {
            playscripting_map[key] = value;
            return value;
        }
        Playscripting setOrdenerPlayscriptingMap(std::string key, Playscripting value, Operator op) {
           
        }

};
