/* prins.cpp     *
 * prints string */

#include "include/prins.h"
#include <iostream>
#include <string>

using namespace std;

extern bool fault;

prins::prins(string new_to_print, int new_mode)
{
    to_print=new_to_print;
    mode=new_mode;
}
void prins::run()
{
    if(fault)
        return;
    switch(mode)
    {
        case 0:
            cout<<to_print;
        break;
        case 1:
            cout<<to_print<<endl;
        break;
    }
}
