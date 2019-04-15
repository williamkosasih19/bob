#ifndef PUSH_H
#define PUSH_H

#include <string>
#include "operation.h"

class push : public operation
{
    private:
        std::string arr_name;
        std::string arr_value;
        std::string arr_index;
    public:
        push(std::string newname, std::string newindex, std::string newvalue);
        void run();
};

#endif