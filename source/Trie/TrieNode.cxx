/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      TrieNode.cxx                                                *
 * Description:   Header file for a Trie Node                                 *
 *****************************************************************************/
#include "../Memory/SmartPointerUtility.h"
#include "TrieNode.h"

TrieNode::TrieNode() :
                letter_('\0'),
                isEndOfWord_(false) {
}

TrieNode::TrieNode(const char _letter, const bool _isEndOfWord) :
                letter_(_letter),
                isEndOfWord_(_isEndOfWord) {
}

char TrieNode::getLetter() const {
    return letter_;
}

bool TrieNode::isEndOfWord() const {
    return isEndOfWord_;
}

void TrieNode::setEndOfWord(const bool _isEndOfWord) {
    isEndOfWord_ = _isEndOfWord;
    return;
}

bool TrieNode::hasNextLetters() const {
    return !nextTrieNodeMap_.empty();
}

bool TrieNode::hasNextLetter(const char _letter) const {
    return !(nextTrieNodeMap_.find(_letter) == nextTrieNodeMap_.end());

}

void TrieNode::addNextLetter(const char _letter, const char _isEndOfWord) {
    nextTrieNodeMap_.emplace(_letter,
            std::make_unique<TrieNode>(_letter, _isEndOfWord));
    return;
}

TrieNode * const TrieNode::getNextNodePointer(const char _letter) const {
    auto selectedTrieNodeItr = nextTrieNodeMap_.find(_letter);
    //std::cout << "GET NEXT NODE: " << (selectedTrieNode->second)->getLetter()
    //        << std::endl;
    if (selectedTrieNodeItr != nextTrieNodeMap_.end()) {
        return (selectedTrieNodeItr->second).get();
    }
    //std::cout << "HERE" << std::endl;
    return nullptr;
}
