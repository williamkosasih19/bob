#ifndef N_FOR_H
#define N_FOR_H

#include <string>
#include "operation.h"
#include "loop.h"
class n_for : public loop
{
    private:
        int effector;
        std::string var_kill_switch;
        std::string var_target;
    public:
        n_for(int new_effector,std::string new_var_kill_switch,std::string new_var_target); // 0= less than, 1=greater than
        void run();
};
#endif