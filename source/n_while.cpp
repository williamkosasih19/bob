#include "include/n_while.h"
#include "include/glob_variable.h"
#include "include/loop.h"
#include <string>

using namespace std;

extern glob_variable global_variable;
extern loop** ploop_array;
extern int n_loops;
extern bool fault;

n_while::n_while(int new_mode,string new_var_kill_switch,string new_var_target) // 0= less than, 1=greater than
{
    mode=new_mode;
    var_kill_switch=new_var_kill_switch;
    var_target=new_var_target;
}
void n_while::run()
{
    ploop_array[++n_loops]=this;
    int kill_switch=global_variable.find_variable(var_kill_switch);
    int target=global_variable.find_variable(var_target);
    switch(mode)
    {
        case 0:
            while(kill_switch<target)
            {
                if(sig_break)
                    break;
                for(int i=0;i<op_ctr;i++)
                {
                    if(sig_break)
                        break;
                    op_list[i]->run();
                }
                    
                kill_switch=global_variable.find_variable(var_kill_switch);
                target=global_variable.find_variable(var_target);
                if(fault)
                    return;
            }
        break;
        case 1:
            while(kill_switch>target)
            {
                if(sig_break)
                    break;
                for(int i=0;i<op_ctr;i++)
                {
                    if(sig_break)
                        break;
                    op_list[i]->run();
                }
                kill_switch=global_variable.find_variable(var_kill_switch);
                target=global_variable.find_variable(var_target);
                if(fault)
                    return;
            }
        break;
    }
    sig_break=false;
    n_loops--;
    
}