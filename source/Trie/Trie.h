/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      Trie.h                                                      *
 * Description:   Header file for a Trie                                      *
 *****************************************************************************/
#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>

#include "TrieNode.h"


class Trie {
    public:
        Trie();
        void insertWord(const std::string & _word);
        bool hasWord(const std::string & _word);

    private:
        TrieNode root_;
};

#endif /* __TRIE_H__ */
