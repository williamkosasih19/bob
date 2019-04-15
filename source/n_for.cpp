/* n_for.cpp                                                 *
 * this file contains the class definition of n_for          *
 * the class will provide for function for the bob langauage *
 * copy pasted from n_while as it has similar functions      */

#include "include/n_for.h"
#include "include/glob_variable.h"
#include "include/loop.h"
#include <string>

using namespace std;

extern glob_variable global_variable;
extern loop** ploop_array;
extern int n_loops;
extern bool fault;

n_for::n_for(int new_effector,string new_var_kill_switch,string new_var_target) // 0= less than, 1=greater than
{
    effector=new_effector;
    var_kill_switch=new_var_kill_switch;
    var_target=new_var_target;
}
void n_for::run()
{
    ploop_array[++n_loops]=this;
    int kill_switch=global_variable.find_variable(var_kill_switch);
    int target=global_variable.find_variable(var_target);
    while(kill_switch!=target)
    {
        if(sig_break)
            break;
        kill_switch=global_variable.find_variable(var_kill_switch);
        target=global_variable.find_variable(var_target);
        for(int i=0;i<op_ctr;i++)
        {
            if(sig_break)
                break;
            op_list[i]->run();
        }      
        global_variable.set_variable(kill_switch+effector,var_kill_switch);
        if(fault)
            return;
    }
    sig_break=false;
    n_loops--;
    
}