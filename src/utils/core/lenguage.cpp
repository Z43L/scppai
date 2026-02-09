#include "lenguage.hpp"

std::unordered_map<std::string, Playscripting> lenguage::getPlayscriptingMap()  { return playscripting_map; }
std::unordered_map<std::string, Playscripting, Operator> lenguage::getOrdenerPlayscriptingMap()  { return ordener_playscripting_map; }
std::unordered_map<std::string, Playscripting, Operator> setOrdenerPlayscriptingMap(std::unordered_map<std::string, Playscripting, Operator> new_map){
        if (new_map.empty()) {
            return std::unordered_map<std::string, Playscripting, Operator>();
        }
        std::unordered_map<std::string, Playscripting, Operator> result;

        if(new_map.find("LOOP") != new_map.end())
        {
            result["LOOP"] = new_map["LOOP"];

        }
        if (new_map.find("CONDITIONAL") != new_map.end()) {
            result["CONDITIONAL"] = new_map["CONDITIONAL"];
        }
        if (new_map.find("FUNCTION") != new_map.end()) {
            result["FUNCTION"] = new_map["FUNCTION"];
        }
        if (new_map.find("VARIABLE") != new_map.end()) {
            result["VARIABLE"] = new_map["VARIABLE"];
        }
        if (new_map.find("CLASS") != new_map.end()) {
            result["CLASS"] = new_map["CLASS"];
        }
        if (new_map.find("INTERFACE") != new_map.end()) {
            result["INTERFACE"] = new_map["INTERFACE"];
        }
        if (new_map.find("ENUM") != new_map.end()) {
            result["ENUM"] = new_map["ENUM"];
        }
        if (new_map.find("NAMESPACE") != new_map.end()) {              
            result["NAMESPACE"] = new_map["NAMESPACE"];
        }
        if (new_map.find("MODULE") != new_map.end()) {
            result["MODULE"] = new_map["MODULE"];
        }
        if (new_map.find("IMPORT") != new_map.end()) {            
            result["IMPORT"] = new_map["IMPORT"];
        }    
        if (new_map.find("EXPORT") != new_map.end()) {
            result["EXPORT"] = new_map["EXPORT"];
        }
        if (new_map.find("ASINCHRONOUS") != new_map.end()) {
            result["ASINCHRONOUS"] = new_map["ASINCHRONOUS"];
        }
        if (new_map.find("SYNCHRONOUS") != new_map.end()) {
            result["SYNCHRONOUS"] = new_map["SYNCHRONOUS"];
        }
        if (new_map.find("STATIC") != new_map.end()) {
            result["STATIC"] = new_map["STATIC"];
        }
        if (new_map.find("DYNAMIC") != new_map.end()) {
            result["DYNAMIC"] = new_map["DYNAMIC"];
        }
        if (new_map.find("SOCKET") != new_map.end()) {
            result["SOCKET"] = new_map["SOCKET"];
        }
        if (new_map.find("READ_CSV") != new_map.end()) {
            result["READ_CSV"] = new_map["READ_CSV"];
        }
        if (new_map.find("WRITE_CSV") != new_map.end()) {
            result["WRITE_CSV"] = new_map["WRITE_CSV"];
        }
        if (new_map.find("JSON") != new_map.end()) {
            result["JSON"] = new_map["JSON"];
        }
        if (new_map.find("XML") != new_map.end()) {
            result["XML"] = new_map["XML"];
        }
        if (new_map.find("DATABASE") != new_map.end()) {
            result["DATABASE"] = new_map["DATABASE"];
        }
        if (new_map.find("FILE_IO") != new_map.end()) {
            result["FILE_IO"] = new_map["FILE_IO"];
        }
        if (new_map.find("NETWORK") != new_map.end()) {
            result["NETWORK"] = new_map["NETWORK"];
        }
        if (new_map.find("THREADING") != new_map.end()) {
            result["THREADING"] = new_map["THREADING"];
        }
        if (new_map.find("ERROR_HANDLING") != new_map.end()) {
            result["ERROR_HANDLING"] = new_map["ERROR_HANDLING"];
        }
        if (new_map.find("TORCH") != new_map.end()) {
            result["TORCH"] = new_map["TORCH"];
        }
        if (new_map.find("TENSOR") != new_map.end()) {
            result["TENSOR"] = new_map["TENSOR"];
        }
        if (new_map.find("CUDA") != new_map.end()) {
            result["CUDA"] = new_map["CUDA"];
        }
        return result;
    }
        
        
        
       
std::unordered_map<std::string, Playscripting, Operator> lenguage::setOrdenerPlayscriptingMap(std::unordered_map<std::string, Playscripting, Operator> new_map) {
        ordener_playscripting_map = new_map;
        return ordener_playscripting_map;
    }
