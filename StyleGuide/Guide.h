//at most 85 letters per line 
/***********************************************************************************
This file is part of Project ***
    (brief description on the Project)
For the latest info, see  WEBSITE_ADDRESS

Copyright 2016 Yhgenomics

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***********************************************************************************/

/***********************************************************************************
* Description   : overview of this file
* Creator       : Ke Yang(keyang@yhgenomics.com)
* Date          : 2016/2/16
* Modifed       : When      | Who       | What
                  2016/2/17 | Ke Yang   | Add function A
                  2016/2/17 | Ke Yang   | Refactor the Class add new interfaces
***********************************************************************************/

#ifndef GUIDE_H_ 
#define GUIDE_H_

// Order of includes
// 1. Related header
// 2. C library
// 3. C++ library
// 3. Other libraries' .h
// 4. Your project's .h
#include "stdio.h"
#include <iostream>
#include <functional>
#include <memory>
#include "Nonmembers.h"

// no direct using namespace
// do use aliases
using std::cin;
using std::cout;
using std::function;
using std::unique_ptr;

using InputStream = std::istream;
using MyInt       = int;

namespace StyleGuide
{
    // @Description : (What is this class? It's function)
    //                (important base knowledges such as)
    //                F = m*a               
    //                ...
    //                ...             
    // @Example     : (on how to use this class)
    //                {
    //                   ...
    //                   auto        state    = GetStateFromOtherPlace();
    //                   auto        flag     = GetFlagFromOtherPlace();
    //                   ClassStyle  testItem = new ClassStyle( state , flag);
    //                   auto        exitCode = testItem.CallFunction();
    //                   ...
    //                }
    // @Note        : (what should make attention!)
    //                the exitCode 0 means success, otherwise -1.
    //                the state will be checked based on the design documents of 
    //                [ProjectName] Ver.12345 2016/1/16 by Ke Yang 
    //                ... 
    class ClassStyle
    {
    public:
        
        // Description this function is for
        // @param   : inputOne stands for....
        // @param   : inputTwo stands for...
        // @output  : none
        // @example : how to use it             
        // use explicit will avoid both implicit conversions and C++11's list initialization syntax 
        //           the function:
        //              void Function( ClassStyle );
        //           will not work with this call:   
        //              Function( { 12, 34 } ); // error cause the explicit syntax         
        explicit ClassStyle( int intpuOne, int inputTwo )
        {
        }

        // Description this function is for
        // @param   : inputOne stands for....
        // @output  : none
        // @example : how to use it     
        void Init( int intpuOne , int inputTwo );
        
        // Getter for ...        
        // @remark  : ....
        MyInt   SkyHeight()                     { return sky_height;      }

        // Setter for ...
        // @param   : inputOne stands for....
        // @remark  : ....
        bool    SkyHeight( MyInt inputOne )     { sky_height = inputOne;  }

        // Getter for ...        
        // @remark  : ....
        MyInt   LightSpeed()                    { return light_speed;     }

        // Setter for ...
        // @param   : inputOne stands for....
        // @remark  : always check the output flag
        bool    LightSpeed( MyInt inputOne)     { light_speed = inputOne; }

        // Use smart pointer
        // Getter for ...        
        // @remark  : ....
        unique_ptr<int> PointerTest()
        {
            if ( nullptr == pointer_test )
            {
                unique_ptr<int> out( new int );
                pointer_test = std::move( out );
            }
            return std::move( pointer_test );
        }

        // Setter for ...        
        // @remark  : ....
        void PointerTest(unique_ptr<int> inputOne)
        {
            pointer_test = std::move( inputOne );
        }

        // Description this function is for
        // @param   : meaning
        // @output  : exit code
        // @example : how to use it
        // parameter order is: inputs, then outputs.     
        int     CallFunction( int intputOne );

    protected:

    private:

        //Description
        function< MyInt( bool testFlag ) > SomeFunction;

        // Description
        MyInt                   sky_height;
        
        // Description
        MyInt                   light_speed;

        // refer to have single, fixed owners for dynamically allocated objects. 
        // Prefer to transfer ownership with smart pointers.
        std::unique_ptr<int>    pointer_test;

    };
}

#endif // !GUIDE_H_