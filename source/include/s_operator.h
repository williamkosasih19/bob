/* s_operator.cpp                                                       *
 * this file contains the definition of class s_operator                *
 * which will handle pretty much all the operations in the interpreter  *
 * tightly integrated to global_variable                                *
 * this replaces n_operator as it is proofed, won't crash program if    *
 * an invalid integer/variable named is used                            *
 * new codes should use this instead of n_operator                      */

#ifndef S_OPERATOR_H
#define S_OPERATOR_H

#include <string>
#include "operation.h"

class s_operator : public operation
{
    private:
        std::string param_a;
        std::string param_b;
        std::string param_c;
        int mode;       //0 ++, 1 --, 2 **, 3 **
    public:
        s_operator(std::string new_param_a, std::string new_param_b, std::string new_param_c, int new_mode);
        void run();
};
#endif