/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      Trie.cxx                                                    *
 * Description:   Header file that contains the class used for storing a      *
 *                Boggle Board                                                *
 *****************************************************************************/
#include <string>

#include "Trie.h"

namespace {
    typedef std::string String;
}

Trie::Trie() :
        root_('\0', false) {

}

void Trie::insertWord(const String & _word) {
    TrieNode * currentTrieNodePointer(&root_);
    for (const char & letter : _word) {
        currentTrieNodePointer->addNextLetter(letter, false);
        currentTrieNodePointer = currentTrieNodePointer->getNextNodePointer(
                letter);
    }
    currentTrieNodePointer->setEndOfWord(true);
    return;
}

bool Trie::hasWord(const String & _word) {
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

const TrieNode & Trie::getRootTrieNode() const {
    return root_;
}
