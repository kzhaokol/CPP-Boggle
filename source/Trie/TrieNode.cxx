/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      TrieNode.cxx                                                *
 * Description:   Header file for a Trie Node                                 *
 *****************************************************************************/
#include "TrieNode.h"



TrieNode::TrieNode() :
                letter_('\0'),
                isEndOfWord_(true) {
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
}

bool TrieNode::hasNextLetters() const {
    return !nextTrieNodeMap_.empty();
}

bool TrieNode::hasNextLetter(const char _letter) const {
    if (nextTrieNodeMap_.find(_letter) == nextTrieNodeMap_.end()) {
        return false;
    }
    return true;
}

/**
void TrieNode::addNextLetter(const char _letter) {
    nextTrieNodeMap_.insert(
            std::make_pair<char, TrieNode::UniquePointer>(_letter,
                    std::make_shared<TrieNode>(_letter, false)));
    return;
}

TrieNode & TrieNode::getNextNode(const char _letter) const {
    const LetterKeyMap::const_iterator selectedTrieNode = nextTrieNodeMap_.find(
            _letter);
    std::cout << "GET NEXT NODE: " << (selectedTrieNode->second)->getLetter()
            << std::endl;
    if (selectedTrieNode != nextTrieNodeMap_.end()) {
        return *(selectedTrieNode->second);
    }
    std::cout << "HERE" << std::endl;
    return nullTrieNode;
}
**/
