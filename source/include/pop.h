#ifndef POP_H
#define POP_H

#include <string>
#include "operation.h"

class pop : public operation
{
    private:
        std::string arr_name;
        std::string arr_index;
        std::string var_name;
    public:
        pop(std::string newname, std::string newindex, std::string newvar);
        void run();
};
#endif