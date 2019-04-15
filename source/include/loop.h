#ifndef LOOP_H
#define LOOP_H

#include "operation.h"
#include "nbreak.h"
class loop : public operation
{
    protected:
        bool sig_break=false;
        friend void nbreak::run();
    public:
        virtual void run()=0;
        
};

#endif