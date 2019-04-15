#include <string>
#include "include/array.h"
#include "include/glob_array.h"

extern glob_array global_array;

using namespace std;

array::array(string newname, string newsize)
{
    arr_name=newname;
    arr_size=newsize;
}

void array::run()
{
    global_array.declare_array(arr_name,arr_size);
}