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
        typedef boost::multi_array<char, 2> ArrayType;
        BoggleBoard(const std::vector<char> & _boggleData);

    private:
        unsigned int sideSize_;
        ArrayType boggleBoardData_;

        friend std::ostream & operator<<(std::ostream & _outputStream,
                const BoggleBoard & _boggleBoard);
};

#endif /* __BOGGLE_BOARD_H__ */
