/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      BoggleBoard.h                                               *
 * Description:   Header file that contains the class used for storing a      *
 *                Boggle Board                                                *
 *****************************************************************************/
#ifndef __BOGGLE_BOARD_H__
#define __BOGGLE_BOARD_H__

#include <vector>
#include <iostream>

#include <boost/multi_array.hpp>

class BoggleBoard {
    public:
        typedef boost::multi_array<char, 2> MultiArrayType;
        BoggleBoard(const std::vector<char> & _boggleData);

        MultiArrayType::const_reference operator[](
                MultiArrayType::index _row) const;

        std::vector<std::string> getAllWordsFromCell() const;

    private:
        unsigned int sideSize_;
        MultiArrayType boggleBoardData_;

        friend std::ostream & operator<<(std::ostream & _outputStream,
                const BoggleBoard & _boggleBoard);
};

#endif /* __BOGGLE_BOARD_H__ */
