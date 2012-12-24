/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      BoggleBoard.cxx                                             *
 * Description:   Stores all the data for a Boggle Board                      *
 *****************************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

#include "BoggleBoard.h"

namespace {
    typedef std::string String;
    typedef std::vector<char> CharVector;
    typedef std::ostream OutputStream;
    typedef BoggleBoard::MultiArrayType::const_reference MultiArrayTypeConstReference;
    typedef BoggleBoard::MultiArrayType::index Index;
}

BoggleBoard::BoggleBoard(const CharVector & _boggleData) :
        sideSize_(std::sqrt(_boggleData.size())), boggleBoardData_(
                boost::extents[sideSize_][sideSize_]) {
    for (unsigned int curRow = 0; curRow < sideSize_; ++curRow) {
        for (unsigned int curCol = 0; curCol < sideSize_; ++curCol) {
            boggleBoardData_[curRow][curCol] = _boggleData[(curRow * sideSize_)
                    + curCol];
        }
    }
}

MultiArrayTypeConstReference BoggleBoard::operator[](Index _row) const {
    return boggleBoardData_[_row];

}

std::ostream & operator<<(OutputStream & _outputStream,
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
