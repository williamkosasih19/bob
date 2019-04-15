/* push.cpp                                                   *
 * this file contains the definition of class push            *
 * which will push an integer into a certain address in array */

#include <string>
#include "include/push.h"
#include "include/glob_array.h"

extern glob_array global_array;

using namespace std;

push::push(string newname, string newindex, string newvalue)
{
    arr_name=newname;
    arr_index=newindex;
    arr_value=newvalue;
}

void push::run()
{
    global_array.add_value(arr_name,arr_index,arr_value);
}