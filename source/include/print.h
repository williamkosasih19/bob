#ifndef PRINT_H
#define PRINT_H

#include <string>
#include "operation.h"

class print : public operation
{
    private:
        int newline;
        std::string varname;
    public:
        print(std::string new_varname);
        print(std::string new_varname, int new_newline);
        void run();
};
#endif