#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "operation.h"
#include "glob_array.h"

class array : public operation
{
    private:
    std::string arr_name;
    std::string arr_size;
    public:
    array(std::string newname, std::string newsize);
    void run();
};

#endif