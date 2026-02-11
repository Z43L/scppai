#include "lenguage.hpp"

int lenguage::playscriptingToInt(Playscripting value) {
    switch (value) {
        case Playscripting::LOOP: return 1;
        case Playscripting::CONDITIONAL: return 2;
        case Playscripting::FUNCTION: return 3;
        case Playscripting::VARIABLE: return 4;
        case Playscripting::CLASS: return 5;
        case Playscripting::INTERFACE: return 6;
        case Playscripting::ENUM: return 7;
        case Playscripting::NAMESPACE: return 8;
        case Playscripting::MODULE: return 9;
        case Playscripting::IMPORT: return 10;
        case Playscripting::EXPORT: return 11;
        case Playscripting::ASINCHRONOUS: return 12;
        case Playscripting::SYNCHRONOUS: return 13;
        case Playscripting::STATIC: return 14;
        case Playscripting::DYNAMIC: return 15;
        case Playscripting::SOCKET: return 16;
        case Playscripting::READ_CSV: return 17;
        case Playscripting::WRITE_CSV: return 18;
        case Playscripting::JSON: return 19;
        case Playscripting::XML: return 20;
        case Playscripting::DATABASE: return 21;
        case Playscripting::FILE_IO: return 22;
        case Playscripting::NETWORK: return 23;
        case Playscripting::THREADING: return 24;
        case Playscripting::ERROR_HANDLING: return 25;
        case Playscripting::TORCH: return 26;
        case Playscripting::TENSOR: return 27;
        case Playscripting::CUDA: return 28;

        
    }
    return -1; // Valor predeterminado para valores no reconocidos
}

int *lenguage::numeberIndexOperator(TokenType::Type op, Playscripting value) {
    int *index = new int[41];
    switch (op){
        case TokenType::Type::Operator: {
            
            index[0] = operatorToInt(Operator::ADD);
            index[1] = operatorToInt(Operator::SUBTRACT);
            index[2] = operatorToInt(Operator::MULTIPLY);
            index[3] = operatorToInt(Operator::DIVIDE);
            index[4] = operatorToInt(Operator::MODULO);
            index[5] = operatorToInt(Operator::EQUALS);
            index[6] = operatorToInt(Operator::NOT_EQUALS);
            index[7] = operatorToInt(Operator::GREATER_THAN);
            index[8] = operatorToInt(Operator::LESS_THAN);
            index[9] = operatorToInt(Operator::GREATER_THAN_OR_EQUAL);
            index[10] = operatorToInt(Operator::LESS_THAN_OR_EQUAL);
            index[11] = operatorToInt(Operator::AND);
            index[12] = operatorToInt(Operator::OR);
            index[13] = operatorToInt(Operator::NOT);
        

            
        }
    switch (value)
    {
    case Playscripting::CONDITIONAL:
        index[14] = operatorToInt(Operator::EQUALS);
        break;
    case Playscripting::MODULE:
        index[15] = operatorToInt(Operator::MODULO);
        break;
    case Playscripting::FUNCTION:
        index[16] = playscriptingToInt(Playscripting::FUNCTION);
        break;
    case Playscripting::VARIABLE:
        index[17] = playscriptingToInt(Playscripting::VARIABLE);
        break;
    case Playscripting::CLASS:
        index[18] = playscriptingToInt(Playscripting::CLASS);
        break;
    case Playscripting::INTERFACE:
        index[19] = playscriptingToInt(Playscripting::INTERFACE);
        break;
    case Playscripting::ENUM:
        index[20] = playscriptingToInt(Playscripting::ENUM);
        break;
    case Playscripting::NAMESPACE:
        index[21] = playscriptingToInt(Playscripting::NAMESPACE);
        break;
    case Playscripting::IMPORT:
        index[22] = playscriptingToInt(Playscripting::IMPORT);
        break;
    case Playscripting::EXPORT:
        index[23] = playscriptingToInt(Playscripting::EXPORT);
        break;
    case Playscripting::ASINCHRONOUS:
        index[24] = playscriptingToInt(Playscripting::ASINCHRONOUS);
        break;
    case Playscripting::SYNCHRONOUS:
        index[25] = playscriptingToInt(Playscripting::SYNCHRONOUS);
        break;
    case Playscripting::STATIC:
        index[26] = playscriptingToInt(Playscripting::STATIC);         
        break;
    case Playscripting::DYNAMIC:
        index[27] = playscriptingToInt(Playscripting::DYNAMIC);
        break;
    case Playscripting::SOCKET:
        index[28] = playscriptingToInt(Playscripting::SOCKET);
        break;
    case Playscripting::READ_CSV:
        index[29] = playscriptingToInt(Playscripting::READ_CSV);
        break;
    case Playscripting::WRITE_CSV:
        index[30] = playscriptingToInt(Playscripting::WRITE_CSV);
        break;
    case Playscripting::JSON:
        index[31] = playscriptingToInt(Playscripting::JSON);
        break;
    case Playscripting::XML:
        index[32] = playscriptingToInt(Playscripting::XML);
        break;
    case Playscripting::DATABASE:
        index[33] = playscriptingToInt(Playscripting::DATABASE);
        break;
    case Playscripting::FILE_IO:
        index[34] = playscriptingToInt(Playscripting::FILE_IO);
        break;
    case Playscripting::NETWORK:
        index[35] = playscriptingToInt(Playscripting::NETWORK);
        break;
    case Playscripting::THREADING:
        index[36] = playscriptingToInt(Playscripting::THREADING);
        break;
    case Playscripting::ERROR_HANDLING:
        index[37] = playscriptingToInt(Playscripting::ERROR_HANDLING);
        break;
    case Playscripting::TORCH:
        index[38] = playscriptingToInt(Playscripting::TORCH);
        break;
    case Playscripting::TENSOR:
        index[39] = playscriptingToInt(Playscripting::TENSOR);
        break;
    case Playscripting::CUDA:
        index[40] = playscriptingToInt(Playscripting::CUDA);
        break;

    default:
        return nullptr; // Retorna nullptr si el tipo de token no es un operador
    }}
    return index;
}
