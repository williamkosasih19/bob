#ifndef OPERATION_H
#define OPERATION_H

#include "param.h"
#include <string>

class operation
{
    protected:
        int op_ctr;
        operation** op_list= new operation*[MAX_BRANCH];
        std::string line;
        //operation* op_list[MAX_BRANCH];
    public:
        operation();
        void add_operation(operation* new_op);
        std::string get_line();
        void set_line(std::string newline);
        virtual void run();
        ~operation();

};
#endif