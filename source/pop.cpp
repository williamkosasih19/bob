/* pop.cpp                                                      *
 * this file contains the definition of the class pop           *
 * which will extract the content of a value withhin its array  */
#include <string>
#include "include/pop.h"
#include "include/glob_array.h"

extern glob_array global_array;

using namespace std;

pop::pop(string newname, string newindex, string newvar)
{
    arr_name=newname;
    arr_index=newindex;
    var_name=newvar;
}

void pop::run()
{
    global_array.get_value(arr_name,arr_index,var_name);
}