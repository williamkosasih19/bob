/* Determine.cpp                                            *
 * This file contains int determine() function, which will  *
 * read user input line by line, and translate the syntax   *
 * this function has a pointer to operation*. A recursive   *
 * call for "branching" operators such as while, if and for *
 * are used so that it will be possible to declare code in  *
 * a "scope"                                                */


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "include/operation.h"
#include "include/glob_variable.h"
#include "include/newline.h"
#include "include/n_if.h"
#include "include/n_operator.h"
#include "include/n_scan.h"
#include "include/n_while.h"
#include "include/prins.h"
#include "include/print.h"
#include "include/s_operator.h"
#include "include/space.h"
#include "include/var.h"
#include "include/n_for.h"
#include "include/nbreak.h"
#include "include/loop.h"
#include "include/glob_array.h"
#include "include/array.h"
#include "include/push.h"
#include "include/pop.h"

using namespace std;

extern ifstream* input_stream;
extern glob_variable global_variable;
extern glob_array global_array;
extern bool fault;

int determine(operation* cur_op)
{
   
    //STRINGSTREAM
    // This section will split up codes into 5 parts

    if(input_stream->eof())
        return -5;
    string s;
    getline(*input_stream,s);
    if(!s.length())
        return 0;
    vector<string> split_string;
    istringstream iss(s);
    for(std::string s; iss >> s; )
    split_string.push_back(s);
    //~STRINGSTREAM
    int input_size = split_string.size(); // how many words there is in each line
    if(!input_size)
        return 0;
    string command=split_string[0];
    string param_a;
    string param_b;
    string param_c;
    string param_d;
    switch(input_size)
    {
        case 2:  
            param_a=split_string[1];
            param_b="";
            param_c="";
            param_d="";
        break;
        case 3:
            param_a=split_string[1];
            param_b=split_string[2];
            param_c="";
            param_d="";
        break;
        case 4:
            param_a=split_string[1];
            param_b=split_string[2];
            param_c=split_string[3];
            param_d="";
        break;
        case 5:
            param_a=split_string[1];
            param_b=split_string[2];
            param_c=split_string[3];
            param_d=split_string[4];
        break;
        default:                        // Every line that has moer than 5 words will automatically be ignored
            param_a="//";
            param_b="";
            param_c="";
            param_d="";
        break;
    }
    if(command=="stop")
        return -4;
    if(command=="endif")
        return -5;
    if(command=="endwhile")
        return -6;
    if(command=="else")
        return -7;
    else if(command=="//")
        return 100;
      
    else if(command=="while")
    {
            n_while* temp_while;
        if(param_b=="<")
            temp_while = new n_while(0,param_a,param_c);
        if(param_b==">")
            temp_while = new n_while(1,param_a,param_c);
        while(determine(temp_while)>=0);
        temp_while->set_line(s);
        cur_op->add_operation(temp_while);
    }
    else if(command=="var")
    {
        if(param_b=="")
            param_b="0";
        var* temp= new var(param_b,param_a);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="print")
    {
         if(!param_a.size())
            return -2;
        string new_varname=param_a;
        print* temp_print = new print(new_varname,0);
        temp_print->set_line(s);
        cur_op->add_operation(temp_print);
    }
    else if(command=="printline")
    {
         if(!param_a.size())
            return -2;
        string new_varname=param_a;
        print* temp_print = new print(new_varname,1);
        temp_print->set_line(s);
        cur_op->add_operation(temp_print);
    }
    else if(command=="prins")
    {
        prins* temp= new prins(param_a,0);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="prinsline")
    {
        prins* temp= new prins(param_a,1);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="if"||command=="elseif")
    {
        n_if* temp;
        if(param_b=="<")
            temp = new n_if(param_a,0,param_c);
        if(param_b=="=")
            temp = new n_if(param_a,1,param_c);
        if(param_b==">")
            temp = new n_if(param_a,2,param_c);
        while(determine(temp)>=0);
        while(determine(temp->alt_op)>=0);
        temp->set_line(s);
        cur_op->add_operation(temp);
        // if the command is elseif, issue another if object, then directly return
        // negative number so that the recursive function breaks
        if(command=="elseif")
            return -98;
    }
    else if(command=="for")
    {
        int neffector;
        try
        {
            neffector=stoi(param_d);
        }
        catch(...)
        {
            fault=true;
            cout<<"invalid addition argument : "<<param_d<<endl;
            cout<<"in line : "<<s<<endl<<endl;
            neffector=1;
        }
        n_for* temp = new n_for(neffector,param_a,param_c);
        while(determine(temp)>=0);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="+")
    {
        n_operator* temp= new n_operator(0,param_a,stoi(param_b));  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="-")
    {
        n_operator* temp= new n_operator(1,param_a,stoi(param_b));  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="*")
    {
        n_operator* temp= new n_operator(2,param_a,stoi(param_b));  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="/")
    {
        n_operator* temp= new n_operator(3,param_a,stoi(param_b));  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="==")
    {
        s_operator* temp= new s_operator(param_a,param_b,"0",4);  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="=")
    {
        n_operator* temp= new n_operator(4,param_a,stoi(param_b));  //(int type, string var, int effector)
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="++")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,0);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="--")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,1);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="**")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,2);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="///")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,3);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="%")
    {
        s_operator* temp = new s_operator(param_a,param_b,param_c,5);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="space")
    {
        space* temp = new space;
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="newline")
    {
        newline* temp = new newline;
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="scan")
    {
        n_scan* temp = new n_scan(param_a);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="break")
    {
        nbreak* temp= new nbreak;
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="array")
    {
        array* temp = new array(param_a,param_b);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="push")
    {
        push* temp= new push(param_a,param_b,param_c);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(command=="pop")
    {
        pop* temp = new pop(param_b,param_c,param_a);
        temp->set_line(s);
        cur_op->add_operation(temp);
    }
    else if(param_a=="=")
    {
        if(param_b=="")
        {

        }
        else if(param_c=="")
        {
            s_operator* temp= new s_operator(command,param_b,"0",4);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        else if(param_c=="+")
        {
            s_operator* temp= new s_operator(command,param_b,param_d,0);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        else if(param_c=="-")
        {
            s_operator* temp= new s_operator(command,param_b,param_d,1);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        else if(param_c=="*")
        {
            s_operator* temp= new s_operator(command,param_b,param_d,2);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        else if(param_c=="/")
        {
            s_operator* temp= new s_operator(command,param_b,param_d,3);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        else if(param_c=="%")
        {
            s_operator* temp = new s_operator(command,param_b,param_d,5);
            temp->set_line(s);
            cur_op->add_operation(temp);
        }
        
    }
    return 0;
}