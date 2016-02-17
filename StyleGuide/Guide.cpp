//line 85 letters most
/***********************************************************************************
* This file is part of Project ***
(brief description on the Project)
* For the latest info, see  WEBSITE_ADDRESS
* Copyright (c) 2015 Yhgenomics. All rights reserved.
* [license begin here] [question]Choose one.
***********************************************************************************/

/***********************************************************************************
* Description   : overview
* Creator       : Ke Yang(keyang@yhgenomics.com)
* Date          : 2016/2/16
* Modifed       : When      | Who       | What
2016/2/17 | Ke Yang   | Add function A
2016/2/17 | Ke Yang   | Refactor the Class add new interfaces
***********************************************************************************/

// Order of includes
// 1. Related header
// 2. C library
// 3. C++ library
// 3. Other libraries' .h
// 4. Your project's .h
#include "Guide.h"

#include <vector>
#include "Nonmembers.h"

using std::vector;

namespace StyleGuide
{
    // Description
    // Tricky part about the implements
    void ClassStyle::Init( int intpuOne , int inputTwo )
    {
        // Use lambda expressions where appropriate. Avoid default lambda captures 
        // when capturing this or if the lambda will escape the current scope.
        SomeFunction = [ &intpuOne ] ( bool flag )
        {
            if ( flag )
            {
                return intpuOne + 1;
            }
        };
    }

    // Description
    // Tricky part about the implements
    int StyleGuide::ClassStyle::CallFunction( int inputOne )
    {
        // meaning of the local variables
        int localVarialbes = inputOne + 1;

        // use 0 for integers,
        int zeroInt = 0;

        // 0.0 for reals
        double zerodouble = 0.0;

        // nullptr (or NULL) for pointers
        int* nullPointer = nullptr;

        // and '\0' for chars.
        char EmptryString[ 2 ] = { '\0', '\0' };

        // ues braced initializer list
        vector< int > localVector = { 1, 2, 3, 4, 5 };

        // Description on i if it's not simple
        for ( int i = 0; i < localVarialbes; ++i )
        {
            if ( 0 == i % 2 )
            {
                i += 3;
            }
        }

        // Important Description if needed
        for ( auto item : localVector )
        {
            // do something with item 
            // [question] no add or delete on item
        }

        // Important Description if needed
        for ( auto const& item : localVector )
        {
            //[question] todo comment format
            // [TODO]
            // @role 
            // @deadline
            // @issue
            // such as:
            // [TODO]
            // @role    : Test Group
            // @deadline: 2016/2/18
            // @issue   : done the perfomace test and point out the bottleneck
        }

        // conditions
        bool condition = true;
        
        if ( condition )
        {
            // do something
        }
        else if ( condition )
        {
            // do something
        }
        else
        {
            // do something
        }

        int conditionTest = 1;
        
        if ( 0 == conditionTest )
        {

        }

        // [question]Switch only for simple stable functions
        // other wise refactor with state or strategy pattern
        // or just put them into a map< conditions, actions >
        switch ( conditionTest )
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
            default:
                break;
        }

        return 0;
    }
}
