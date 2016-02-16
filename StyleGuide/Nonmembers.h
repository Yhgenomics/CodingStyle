/***********************************************************************************
Every file should contain license boilerplate, choose one.
* Copyright (c) 2015 Yhgenomics. All rights reserved.
* Description   : overview
* Creator       : Ke Yang(keyang@yhgenomics.com)
* Date          : 2016/2/16
* Modifed       : When      | Who       | What
2016/2/17 | Ke Yang   | Add function A
2016/2/17 | Ke Yang   | Refactor the Class add new interfaces
***********************************************************************************/

#ifndef NONMEMBERS_H_ // [question] or the <PROJECT>_<PATH>_<FILE>_H_
#define NONMEMBERS_H_

// Order of includes
// 1. Related header
// 2. C library
// 3. C++ library
// 3. Other libraries' .h
// 4. Your project's .h
#include <iostream>

// no direct using namespace [question] or except std
using std::cin;
using std::cout;

//[question] Prefer placing nonmember functions in a namespace
namespace StyleGuide
{
    namespace GeneralMath
    {
        // Description
        void add();

        // Use trailing return types only where using the ordinary syntax 
        // (leading return types) is impractical or much less readable.
        template <class T , class U> auto add( T t , U u ) -> decltype( t + u );
    }

}

#endif // !GUIDE_H_