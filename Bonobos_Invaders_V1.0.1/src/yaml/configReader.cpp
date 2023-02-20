//
// Created by alexis on 20/12/2021.
//

#include "game/yaml/configReader.h"

std::map<std::string, std::string> reader::configMapReader() {
    std::ifstream ifs;
    std::map<std::string, std::string> configMap;
    //lit le fichier de configuration
    ifs.open ( "../files/config.yaml", std::ios_base::in);
    if (!ifs)
        exit(1);
    while (true)
    {
        if (ifs.eof ()) break;
        std::string key;
        std::string value;
        char points;
        //Gere la syntaxe du format Yaml
        ifs>>key;
        ifs>>points;
        ifs>>value;
        //remplie la map
        configMap[key]=value;
    }
    return configMap;
}