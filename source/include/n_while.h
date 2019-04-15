#ifndef N_WHILE_H
#define N_WHILE_H

#include <string>
#include "operation.h"
#include "loop.h"
class n_while : public loop
{
    private:
        int mode;
        std::string var_kill_switch;
        std::string var_target;
    public:
        n_while(int new_mode,std::string new_var_kill_switch,std::string new_var_target); // 0= less than, 1=greater than
        void run();
};
#endif