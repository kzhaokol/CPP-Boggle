/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      BoggleBoard.cxx                                             *
 * Description:   Stores all the data for a Boggle Board                      *
 *****************************************************************************/
#include <cmath>

#include "BoggleBoard.h"

BoggleBoard::BoggleBoard(const std::vector<char> & _boggleData) :
                sideSize_(std::sqrt(_boggleData.size())),
                boggleBoardData_(boost::extents[sideSize_][sideSize_]) {
    for (unsigned int curRow = 0; curRow < sideSize_; ++curRow) {
        for (unsigned int curCol = 0; curCol < sideSize_; ++curCol) {
            boggleBoardData_[curRow][curCol] = _boggleData[(curRow * sideSize_)
                    + curCol];
        }
    }
}

std::ostream & operator<<(std::ostream & _outputStream,
        const BoggleBoard & _boggleBoard) {
    for (unsigned int curRow = 0; curRow < _boggleBoard.sideSize_; ++curRow) {
        for (unsigned int curCol = 0; curCol < _boggleBoard.sideSize_;
                ++curCol) {
            _outputStream << _boggleBoard.boggleBoardData_[curRow][curCol]
                    << " ";
        }
        _outputStream << std::endl;
    }
    return _outputStream;
}
