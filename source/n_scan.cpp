/* n_scan.cpp                                              *
 * provides scan functionality (cin>>) to variables stored *
 * in glob_variable                                        */

#include "include/n_scan.h"
#include "include/glob_variable.h"
#include <string>
#include <iostream>

using namespace std;

extern glob_variable global_variable;
extern bool fault;

n_scan::n_scan(string new_param_a)
{
    param_a=new_param_a;
}
void n_scan::run()
{
    if(fault)
        return;
    int temp_var;
    cin>>temp_var;
    global_variable.set_variable(temp_var,param_a);
}
