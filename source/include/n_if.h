#ifndef N_IF_H
#define N_IF_H

#include <string>
#include "operation.h"

class n_if : public operation
{
    private:
        int mode;       // 1= < , 2 = =, 3= >
        std::string param_a;
        std::string param_c;
    public:
        operation* alt_op;
        n_if(std::string new_param_a, int new_mode , std::string new_param_c);
        void run();
};
#endif