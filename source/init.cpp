/* init.cpp                                           *
 * this file initializes global variables and objects */

#include <fstream>
#include "include/param.h"
#include "include/operation.h"
#include "include/glob_variable.h"
#include "include/loop.h"
#include "include/glob_array.h"

using namespace std;

ifstream* input_stream;
operation* p_operation_main;
glob_variable global_variable;
loop** ploop_array= new loop*[MAX_BRANCH];
//loop* ploop_array[MAX_BRANCH];
glob_array global_array;
int n_loops=-1;
bool fault=false;