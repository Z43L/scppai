#include "lenguage.hpp"

PlayMap lenguage::getPlayscriptingMap() { return playscripting_map; }
PlayMap lenguage::getOrdenerPlayscriptingMap() { return ordener_playscripting_map; }

int lenguage::operatorToInt(Operator op)
{
    switch (op)
    {
    case Operator::ADD:
        return 3;
    case Operator::SUBTRACT:
        return 4;
    case Operator::MULTIPLY:
        return 5;
    case Operator::DIVIDE:
        return 6;
    case Operator::MODULO:
        return 7;
    case Operator::EQUALS:
        return 8;
    case Operator::NOT_EQUALS:
        return 9;
    case Operator::GREATER_THAN:
        return 10;
    case Operator::LESS_THAN:
        return 11;
    case Operator::GREATER_THAN_OR_EQUAL:
        return 12;
    case Operator::LESS_THAN_OR_EQUAL:
        return 13;
    case Operator::AND:
        return 14;
    case Operator::OR:
        return 15;
    case Operator::NOT:
        return 16;
    default:
        return -1; // Valor predeterminado para operadores no reconocidos
    }
}

std::string lenguage::OperatorToString(Operator op)
{
    switch (op)
    {
    case Operator::ADD:
        return "3";
    case Operator::SUBTRACT:
        return "4";
    case Operator::MULTIPLY:
        return "5";
    case Operator::DIVIDE:
        return "6";
    case Operator::MODULO:
        return "7";
    case Operator::EQUALS:
        return "8";
    case Operator::NOT_EQUALS:
        return "9";
    case Operator::GREATER_THAN:
        return "10";
    case Operator::LESS_THAN:
        return "11";
    case Operator::GREATER_THAN_OR_EQUAL:
        return "12";
    case Operator::LESS_THAN_OR_EQUAL:
        return "13";
    case Operator::AND:
        return "14";
    case Operator::OR:
        return "15";
    case Operator::NOT:
        return "16";
    default:
        return "";
    }
}

PlayMap lenguage::setOrdenerPlayscriptingMap(const std::string &tipe, const PlayMap &new_map_param)
{
    PlayMap new_map = new_map_param;
    if (new_map.empty()) {
        new_map = PlayMap{
            {"LOOP", Playscripting::LOOP},
            {"CONDITIONAL", Playscripting::CONDITIONAL},
            {"FUNCTION", Playscripting::FUNCTION},
            {"VARIABLE", Playscripting::VARIABLE},
            {"CLASS", Playscripting::CLASS},
            {"INTERFACE", Playscripting::INTERFACE},
            {"ENUM", Playscripting::ENUM},
            {"NAMESPACE", Playscripting::NAMESPACE},
            {"MODULE", Playscripting::MODULE},
            {"IMPORT", Playscripting::IMPORT},
            {"EXPORT", Playscripting::EXPORT},
            {"ASINCHRONOUS", Playscripting::ASINCHRONOUS},
            {"SYNCHRONOUS", Playscripting::SYNCHRONOUS},
            {"STATIC", Playscripting::STATIC},
            {"DYNAMIC", Playscripting::DYNAMIC},
            {"SOCKET", Playscripting::SOCKET},
            {"READ_CSV", Playscripting::READ_CSV},
            {"WRITE_CSV", Playscripting::WRITE_CSV},
            {"JSON", Playscripting::JSON},
            {"XML", Playscripting::XML},
            {"DATABASE", Playscripting::DATABASE},
            {"FILE_IO", Playscripting::FILE_IO},
            {"NETWORK", Playscripting::NETWORK}
        };
    }

    PlayMap result = new_map;

    const std::vector<std::pair<std::string, Playscripting>> shorthands = {
        {"function", Playscripting::FUNCTION},
        {"var", Playscripting::VARIABLE},
        {"class", Playscripting::CLASS},
        {"interface", Playscripting::INTERFACE},
        {"enum", Playscripting::ENUM},
        {"namespace", Playscripting::NAMESPACE},
        {"module", Playscripting::MODULE},
        {"import", Playscripting::IMPORT},
        {"export", Playscripting::EXPORT},
        {"async", Playscripting::ASINCHRONOUS},
        {"sync", Playscripting::SYNCHRONOUS},
        {"static", Playscripting::STATIC},
        {"dynamic", Playscripting::DYNAMIC},
        {"socket", Playscripting::SOCKET},
        {"read_csv", Playscripting::READ_CSV},
        {"write_csv", Playscripting::WRITE_CSV},
        {"json", Playscripting::JSON},
        {"xml", Playscripting::XML},
        {"database", Playscripting::DATABASE},
        {"file_io", Playscripting::FILE_IO},
        {"network", Playscripting::NETWORK}
    };

    for (const auto &p : shorthands) {
        if (result.find(p.first) == result.end()) {
            result.emplace(p.first, p.second);
        }
    }

    return result;
}
