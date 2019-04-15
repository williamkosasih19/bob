#ifndef GLOB_VAR_H
#define GLOB_VAR_H

#include "param.h"
#include <string>

class glob_variable
{
    private:
        int values[MAX_GLOB_VAR];
        std::string names[MAX_GLOB_VAR];
        int var_ctr;
    public:
        glob_variable();
        void add_variable(int new_value, std::string new_name);
        int find_variable(std::string name);
        int set_variable(int new_value, std::string var_name);
};
#endif