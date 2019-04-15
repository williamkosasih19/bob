#ifndef N_SCAN_H
#define N_SCAN_H

#include <string>
#include "operation.h"

class n_scan : public operation
{
    private:
        std::string param_a;
    public:
        n_scan(std::string new_param_a);
        void run();
};
#endif