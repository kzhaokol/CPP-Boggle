/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      Trie.cxx                                                    *
 * Description:   Header file that contains the class used for storing a      *
 *                Boggle Board                                                *
 *****************************************************************************/
#include <iostream>

#include "Trie.h"

Trie::Trie() :
                root_('\0', false) {

}

void Trie::insertWord(const std::string & _word) {
    TrieNode * currentTrieNodePointer(&root_);
    for (const char & letter : _word) {
        currentTrieNodePointer->addNextLetter(letter, false);
        currentTrieNodePointer = currentTrieNodePointer->getNextNodePointer(
                letter);
    }
    currentTrieNodePointer->setEndOfWord(true);
    return;
}

bool Trie::hasWord(const std::string & _word) {
    TrieNode * currentTrieNodePointer(&root_);

    for (const char & letter : _word) {
        currentTrieNodePointer = currentTrieNodePointer->getNextNodePointer(
                letter);
        if (currentTrieNodePointer == nullptr) {
            return false;
        }
    }
    return currentTrieNodePointer->isEndOfWord();
}
