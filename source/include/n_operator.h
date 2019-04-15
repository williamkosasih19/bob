#ifndef N_OPERATOR_H
#define N_OPERATOR_H

#include <string>
#include "operation.h"

class n_operator : public operation
{
    private:
        int type; // 0 plus - 1 minus - 2 multiply - 3 divide - 4 equals to
        int effector;
        std::string variable;
    public:
        n_operator(int new_type, std::string new_variable, int new_effector);
        void run();
};
#endif