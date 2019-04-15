#ifndef VAR_H
#define VAR_H

#include "operation.h"
#include <string>

class var : public operation
{
    private:
    std::string value;
    std::string name;
    public:
    var(std::string new_value, std::string new_name);
    void run();
};

#endif