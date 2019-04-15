/* s_operator.cpp                                                       *
 * this file contains the definition of class s_operator                *
 * which will handle pretty much all the operations in the interpreter  *
 * tightly integrated to global_variable                                *
 * this replaces n_operator as it is proofed, won't crash program if    *
 * an invalid integer/variable named is used                            *
 * new codes should use this instead of n_operator                      */

#include "include/s_operator.h"
#include "include/glob_variable.h"
#include <string>

using namespace std;

extern glob_variable global_variable;

s_operator::s_operator(string new_param_a, string new_param_b, string new_param_c, int new_mode)
{
    param_a=new_param_a;
    param_b=new_param_b;
    param_c=new_param_c;
    mode=new_mode;
}
void s_operator::run()
{
    int nparam_b=global_variable.find_variable(param_b);
    int nparam_c=global_variable.find_variable(param_c);
    switch(mode)
    {
        case 0:
            global_variable.set_variable(nparam_b+nparam_c,param_a);
        break;
        case 1:
            global_variable.set_variable(nparam_b-nparam_c,param_a);
        break;
        case 2:
            global_variable.set_variable((int)(nparam_b*nparam_c),param_a);
        break;
        case 3:
            global_variable.set_variable(nparam_b/nparam_c,param_a);
        break;
        case 4:
             global_variable.set_variable(nparam_b,param_a);
        break;
        case 5:
            global_variable.set_variable(nparam_b%nparam_c,param_a);
        break;
    }
}
