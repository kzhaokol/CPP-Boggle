/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      Trie.cxx                                                    *
 * Description:   Header file that contains the class used for storing a      *
 *                Boggle Board                                                *
 *****************************************************************************/
#include <boost/make_shared.hpp>

#
#include "Trie.h"

namespace {
    typedef std::string String;
    TrieNode nullTrieNode;
}

Trie::Trie() :
                root_('\0', false) {

}

void Trie::insertWord(const std::string & _word) {
    TrieNode & currentTrieNode(root_);
    for (std::string::const_iterator charIterator = _word.begin();
            charIterator < _word.end(); charIterator++) {
        currentTrieNode.addNextLetter(*charIterator);
        currentTrieNode = currentTrieNode.getNextNode(*charIterator);

    }
    currentTrieNode.setEndOfWord(true);
    return;
}

bool Trie::hasWord(const std::string & _word) {
    TrieNode & currentTrieNode(root_);

    for (std::string::const_iterator charIterator = _word.begin();
            charIterator < _word.end(); charIterator++) {
        currentTrieNode = currentTrieNode.getNextNode(*charIterator);
        std::cout << "Has Word " << (*charIterator) << std::endl;
        std::cout << currentTrieNode.getLetter() << std::endl;
        if ((currentTrieNode.getLetter() == '\0')
                && (currentTrieNode.isEndOfWord())) {
            return false;
        }
    }
    if (currentTrieNode.isEndOfWord()) {
        return true;
    }
    return false;
}
