#ifndef PRINS_H
#define PRINS_H

#include <string>
#include "operation.h"

class prins : public operation
{
    private:
        int mode;           //0 = no newline , 1= new line
        std::string to_print;
    public:
        prins(std::string new_to_print, int new_mode);
        void run();
};
#endif