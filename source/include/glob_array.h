#ifndef GLOB_ARRAY
#define GLOB_ARRAY

#include <string>
#include "param.h"

class glob_array
{
    private:
        std::string* arr_names= new std::string[MAX_GLOB_ARRAY];
        int** array_store= new int*[MAX_GLOB_ARRAY];
        int ctr=0;
    public:
        void declare_array(std::string newname, std::string newsize);
        int get_value(std::string arrname, std::string index, std::string var);
        void add_value(std::string arrname, std::string index, std::string value);
};

#endif