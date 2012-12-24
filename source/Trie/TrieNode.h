/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      TrieNode.h                                                  *
 * Description:   Source file for a Trie Node                                 *
 *****************************************************************************/
#ifndef __TRIE_NODE_H__
#define __TRIE_NODE_H__

#include <memory>
#include <unordered_map>

class TrieNode {
    public:
        typedef std::unique_ptr<TrieNode> UniquePointer;
        typedef std::unordered_map<char, const TrieNode::UniquePointer> NextPointerMap;

        TrieNode();
        TrieNode(const char _letter, const bool _isEndOfWord);

        char getLetter() const;

        bool isEndOfWord() const;
        void setEndOfWord(const bool _isEndOfWord);

        bool hasNextLetters() const;
        bool hasNextLetter(const char _letter) const;
        void addNextLetter(const char _letter, const bool _isEndOfWord);

        TrieNode * const getNextNodePointer(const char _letter) const;

    private:
        char letter_;
        bool isEndOfWord_;
        TrieNode::NextPointerMap nextTrieNodePointerMap_;
};

#endif /* __TRIE_NODE_H__ */
