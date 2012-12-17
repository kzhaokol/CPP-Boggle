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
    return !nextTrieNodePointerMap_.empty();
}

bool TrieNode::hasNextLetter(const char _letter) const {
    return !(nextTrieNodePointerMap_.find(_letter)
            == nextTrieNodePointerMap_.end());

}

void TrieNode::addNextLetter(const char _letter, const char _isEndOfWord) {
    nextTrieNodePointerMap_.emplace(_letter,
            std::make_unique<TrieNode>(_letter, _isEndOfWord));
    return;
}

TrieNode * const TrieNode::getNextNodePointer(const char _letter) const {
    auto selectedTrieNodeItr = nextTrieNodePointerMap_.find(_letter);
    if (selectedTrieNodeItr != nextTrieNodePointerMap_.end()) {
        return (selectedTrieNodeItr->second).get();
    }
    return nullptr;
}
