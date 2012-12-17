/******************************************************************************
 * Project:       Boggle                                                      *
 * Author:        Kevin Zhao (kzhao)                                          *
 * Date:          July 25, 2012                                               *
 * Filename:      SmartPointerUtility.h                                       *
 * Description:   Header file for smart pointer utility functions             *
 *****************************************************************************/
#ifndef __SMART_POINTER_UTILITY_H__
#define __SMART_POINTER_UTILITY_H__

#include <memory>

namespace std {
    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique(Args&& ...args ) {
        return std::unique_ptr<T>(new T( std::forward<Args>(args)... ));
    };
}

#endif /* __SMART_POINTER_UTILITY_H__ */
