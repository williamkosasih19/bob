/* var.cpp                                                              *
 * this file contains the definition of class var                       *
 * the class will issue a command to the global variable handler        *
 * (glob_variable) to add new variable                                  *
 * needed so that variable declaration is done during runtime and not   *
 * during interpretation time                                           */

#include <iostream>
#include <string>
#include "include/glob_variable.h"
#include "include/var.h"

extern glob_variable global_variable;

using namespace std;

var::var(string new_value, string new_name)
{
    value=new_value;
    name=new_name;
}

void var::run()
{
    global_variable.add_variable(global_variable.find_variable(value),name);
}