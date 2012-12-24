###############################################################################
# Project:       Boggle                                                       #
# Author:        Kevin Zhao (kzhao)                                           #
# Date:          July 5, 2012                                                 #
# Filename:      Makefile                                                     #
# Description:   Makefile for creating Boggle solver executable               #
###############################################################################
CXX = g++ -std=c++11
CXX_FLAGS = -Wall -Werror

BOOST_LIBS = -lboost_program_options

LINK_COMPILE = $(CXX) $(CXX_FLAGS)

REGULAR_COMPILE = $(CXX) $(CXX_FLAGS) -c

all: executable

executable: bin/Main.o bin/BoggleBoard.o bin/Trie.o bin/TrieNode.o
	$(LINK_COMPILE) $^ -o bin/Boggle $(BOOST_LIBS)
	
bin/Main.o: source/Main.cxx
	$(REGULAR_COMPILE) $^ -o $@
	
bin/BoggleBoard.o: source/BoggleBoard.cxx
	$(REGULAR_COMPILE) $^ -o $@
	
bin/Trie.o: source/Trie/Trie.cxx
	$(REGULAR_COMPILE) $^ -o $@
	
bin/TrieNode.o: source/Trie/TrieNode.cxx
	$(REGULAR_COMPILE) $^ -o $@ 
	
clean:
	rm -r bin/*