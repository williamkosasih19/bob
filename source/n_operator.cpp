/* n_operator.cpp                                                                   *
 * This file contains the definition of class n_operator                            *
 * which will handle (strictly) integer operations on variables                     *
 * DEPRECATED - all of the current operations are handled by s_operator             *
 * kept for compability with earlier codes - will crash if invalid integer is used  */

#include "include/n_operator.h"
#include "include/glob_variable.h"
#include <string>

using namespace std;

extern glob_variable global_variable;

n_operator::n_operator(int new_type, string new_variable, int new_effector)
{
    type=new_type;
    variable=new_variable;
    effector=new_effector;
}
void n_operator::run()
{
    int current=global_variable.find_variable(variable);
    switch(type)
    {
        case 0:
            global_variable.set_variable(current+effector,variable);
        break;
        case 1:
            global_variable.set_variable(current-effector,variable);
        break;
        case 2:
            global_variable.set_variable(current*effector,variable);
        break;
        case 3:
            global_variable.set_variable(current/effector,variable);
        break;
        case 4:
            global_variable.set_variable(effector,variable);
        break;
    }
    
}