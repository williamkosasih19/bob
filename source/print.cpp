/* print.cpp                                                        *
 * this is the definition of class print                            *
 * provides functionality of printing variables and/or integers     */

#include "include/print.h"
#include "include/glob_variable.h"
#include <iostream>
#include <string>

using namespace std;

extern glob_variable global_variable;
extern bool fault;

print::print(string new_varname)
{
    varname=new_varname;
    newline=0;
}
print::print(string new_varname, int new_newline)
{
    varname=new_varname;
    newline=new_newline;
}
void print::run()
{
    int temp=global_variable.find_variable(varname);
    if(fault)
        return;
    switch(newline)
    {
        
        case 0:
            cout<<temp;
        break;
        case 1:
            cout<<temp<<endl;
        break;
    }
}