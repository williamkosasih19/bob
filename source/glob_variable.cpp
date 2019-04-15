/* glob_variable.cpp
 * this file contains the class definition of glob_variable          *
 * the class is responsible for handling variable creation,          *
 * access, and modification. global_variable will be the object      *
 * of the class, and is globally declared so that it can be accessed *
 * from every functions and classes                                  */

#include "include/glob_variable.h"
#include <string>

using namespace std;

glob_variable::glob_variable()
{
    var_ctr=0;
}
void glob_variable::add_variable(int new_value, string new_name)
{
    bool found=false;
    int token;
    int i=0;
    for(i;i<var_ctr;i++)
    {
        if(names[i]==new_name)
        {
            token=i;
            found=true;
            break;
        } 
    }
    if(found==true)
    {
        values[i]=new_value;
    }
    else
    {
        values[var_ctr]=new_value;
        names[var_ctr++]=new_name;
    }
}
int glob_variable::find_variable(string name)
{
    bool found=false;
    int token;
    for(int i=0;i<var_ctr;i++)
    {
        if(names[i]==name)
        {
            token=values[i];
            found=true;
            break;
        }
            
    }
    if(found==false)
    {
        try
        {
            token=stoi(name);
        }
        catch(...)
        {
            throw name;
        }
    }
        
    return token;
}
int glob_variable::set_variable(int new_value, string var_name)
{
    int token=-1;
    for(int i=0;i<var_ctr;i++)
    {
        if(names[i]==var_name)
        {
            values[i]=new_value;
            token=0;
            break;
        }
            
    }
    return token;
}