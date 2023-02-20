/**
 * @file    configReader.h
 * @author  Alexis MARIOTTI
 * @date    Janvier 2021
 * @version 1.0
 * @brief   Gestion de la lecture du fichier de configuration
 **/

#include <fstream>
#include <map>
#include <iostream>

#ifndef S102_READER_H
#define S102_READER_H


namespace reader {
    /**
     * @brief Renvoie le dictionaire assossié au fichier de config
     * @return std::map<std::string, std::string>
     * @fn configMapReader()
     */
    std::map<std::string, std::string> configMapReader();
};


#endif //S102_READER_H
