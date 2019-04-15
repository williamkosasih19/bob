/* To add alternate flow pass the alt_op pointer to the determine function
the add_alt op should be extracted from inside the class
*/

#include "include/operation.h"
#include "include/n_if.h"
#include "include/glob_variable.h"
#include <string>

using namespace std;

extern glob_variable global_variable;

n_if::n_if(string new_param_a, int new_mode , string new_param_c)
{
    param_a=new_param_a;
    param_c=new_param_c;
    mode=new_mode;
    alt_op= new operation;
}
void n_if::run()
{
    int whichs=0;
    int nparam_a=global_variable.find_variable(param_a);
    int nparam_c=global_variable.find_variable(param_c);
    switch(mode)
    {
        case 0:
            if(nparam_a<nparam_c)
                whichs=0;
            else
                whichs=1;
        break;
        case 1:
            if(nparam_a==nparam_c)
                whichs=0;
            else
                whichs=1;
        break;
        case 2:
            if(nparam_a>nparam_c)
                whichs=0;
            else
                whichs=1;
        break;
    }
    switch(whichs)
    {
        case 0:
            for(int i=0; i<op_ctr;i++)
                    {
                        op_list[i]->run();
                    }
        break;
        case 1:
                        alt_op->run();
        break;

    }
}
