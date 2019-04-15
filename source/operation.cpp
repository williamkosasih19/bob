/* operation.cpp                                                  *
 * This file contains the definition of the class operation       *
 * which is the main component in this interpreter                *
 * this class is used both as an object and as an interface to    *
 * other operations (for,while,print,etc)                         *
 * The object can be used in other types operation as a container *
 * for other operations, such as in (if)                          */

#include "include/operation.h"
#include <iostream>
#include <string>

using namespace std;

extern bool fault;

operation::operation()
{
    op_ctr=0;
}
std::string operation::get_line()
{
    return line;
}
void operation::set_line(string newline)
{
    line=newline;
}
void operation::add_operation(operation* new_op)
{
    op_list[op_ctr++]=new_op;
}
void operation::run()
{
    for(int i=0;i<op_ctr;i++)
    {
        try
        {
            op_list[i]->run();
        }
        catch(string err_var)
        {
            fault=true;
            cout<<"Undefined variable : "<<err_var<<" found at operation line #"<<i<<endl;
            cout<<op_list[i]->get_line()<<endl<<endl;
        }
        catch(...)
        {
            fault=true;
            cout<<"unknown exception at line #"<<i<<endl;
            cout<<op_list[i]->get_line()<<endl<<endl;
        }
        
    }
}
operation::~operation()
{
    delete[] op_list;
}

