/* glob_array.cpp
 * this file contains the definition of glob_array class     *
 * the class handles all creation, mofif, access of arrays   *
 * redifinition of arrays will be treated as if it was newly *
 * created (wiped)                                           */


#include <string>
#include "include/glob_array.h"
#include "include/glob_variable.h"

extern glob_variable global_variable;

using namespace std;

void glob_array::declare_array(string newname, string newsize)
{
    bool found=false;
    int token;
    int i=0;
    int inewsize;
    try
    {
        inewsize=global_variable.find_variable(newsize);
    }
    catch(...)
    {
        try
        {
            inewsize=stoi(newsize);
        }
        catch(...)
        {
            throw newsize;
        }  
    };
    for(i;i<ctr;i++)
    {
        if(arr_names[i]==newname)
        {
            token=i;
            found=true;
            break;
        } 
    }
    if(found==true)
    {
        delete[] array_store[i];
        array_store[i]=new int[inewsize];
    }
    else
    {
        array_store[ctr]=new int[inewsize];
        arr_names[ctr++]=newname;
    }
}
void glob_array::add_value(string arrname, string index, string value)
{
    int iindex;
    try
    {
        iindex=global_variable.find_variable(index);
    }
    catch(...)
    {
        try
        {
            iindex=stoi(index);
        }
        catch(...)
        {
            throw index;
        }        
    };
    
    int ivalue;
    try
    {
        ivalue=global_variable.find_variable(value);
    }
    catch(...)
    {
        try
        {
            ivalue=stoi(value);
        }
        catch(...)
        {
            throw value;
        }
    };
    for(int i=0;i<ctr;i++)
    {
        if(arr_names[i]==arrname)
            *(array_store[i]+iindex)=ivalue;
    }
}
int glob_array::get_value(string arrname, string index, string var)
{
    int iindex;
    try
    {
        iindex=global_variable.find_variable(index);
    }
    catch(...)
    {
        try
        {
            iindex=stoi(index);
        }
        catch(...)
        {
            throw index;
        }
        
    };
    for(int i=0;i<ctr;i++)
    {
        if(arr_names[i]==arrname)
        {
            global_variable.set_variable(*(array_store[i]+iindex),var);
            break;
        }
    }
}