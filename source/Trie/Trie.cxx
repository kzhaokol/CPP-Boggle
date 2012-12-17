/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      Trie.cxx                                                    *
 * Description:   Header file that contains the class used for storing a      *
 *                Boggle Board                                                *
 *****************************************************************************/
#include <iostream>

#include "../Memory/SmartPointerUtility.h"
#include "Trie.h"

Trie::Trie() :
                root_('\0', false) {

}

void Trie::insertWord(const std::string & _word) {
    TrieNode & currentTrieNode(root_);
    for (std::string::const_iterator charIterator = _word.begin();
            charIterator < _word.end(); charIterator++) {
        currentTrieNode.addNextLetter(*charIterator, false);
        currentTrieNode = *(currentTrieNode.getNextNodePointer(*charIterator));

    }
    currentTrieNode.setEndOfWord(true);
    return;
}

bool Trie::hasWord(const std::string & _word) {
    TrieNode & currentTrieNode(root_);

    for (std::string::const_iterator charIterator = _word.begin();
            charIterator < _word.end(); charIterator++) {
        currentTrieNode = *(currentTrieNode.getNextNodePointer(*charIterator));
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
