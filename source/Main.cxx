/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 22, 2012                                               *
 * Filename:      Main.cxx                                                    *
 * Description:   Main program for executing the Boggle solver                *
 *****************************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <boost/program_options.hpp>

#include "BoggleBoard.h"
#include "Trie/Trie.h"

namespace {
    namespace ProgramOptions = boost::program_options;

    typedef std::string String;
    typedef std::vector<char> CharVector;
    typedef std::ifstream InputFileStream;
}

bool parseProgramOptions(int & _argCount, char** _argVector,
        ProgramOptions::variables_map & _variablesMap) {
    ProgramOptions::options_description optionsDescription("Allowed options");

    optionsDescription.add_options()("help", "Produce the help message")(
            "boardFile", ProgramOptions::value<String>(),
            "Set the file path that contains the boggle board")(
            "dictionaryFile", ProgramOptions::value<String>(),
            "Set the file path that contains the boggle ");

    if (_argCount != 3 || _variablesMap.count("help")) {
        std::cout << optionsDescription << std::endl;
        return false;
    }

    ProgramOptions::positional_options_description positionalOptionsDescription;
    positionalOptionsDescription.add("boardFile", 1).add("dictionaryFile", 1);

    ProgramOptions::store(
            ProgramOptions::command_line_parser(_argCount, _argVector).options(
                    optionsDescription).positional(positionalOptionsDescription).run(),
            _variablesMap);
    ProgramOptions::notify(_variablesMap);

    return true;
}

bool readBoggleFileIntoCharVector(const String & _boggleFileName,
        CharVector & _boggleData) {
    InputFileStream boggleFileStream(_boggleFileName.c_str());
    if (!boggleFileStream.is_open()) {
        return false;
    }

    char curChar;
    while (boggleFileStream >> curChar) {
        _boggleData.push_back(curChar);
    }

    return true;
}

int main(int _argCount, char** _argVector) {
    ProgramOptions::variables_map variablesMap;
    if (!parseProgramOptions(_argCount, _argVector, variablesMap)) {
        return 1;
    }

    std::cout << "Board File: " << variablesMap["boardFile"].as<String>()
            << std::endl;
    std::cout << "Dictionary File: "
            << variablesMap["dictionaryFile"].as<String>() << std::endl;


    CharVector boggleData;
    if (!readBoggleFileIntoCharVector(variablesMap["boardFile"].as<String>(),
        boggleData)) {
        return 2;
    }

    BoggleBoard boggleBoard(boggleData);
    std::cout << boggleBoard << std::endl;

    Trie mainTrie;
    mainTrie.insertWord("blah");
    mainTrie.hasWord("blah");

    return 0;
}
