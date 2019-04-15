#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX_GLOB_VAR 100
#define MAX_BRANCH 100

//GLOBAL_VARIABLE
    //string filename;
    ifstream* input_stream;

//GLOBAL_VARIABLE

//int debug_ctr=0;

class glob_variable
{
    private:
        int values[MAX_GLOB_VAR];
        string names[MAX_GLOB_VAR];
        int var_ctr;
    public:
        glob_variable()
        {
            var_ctr=0;
        }
        void add_variable(int new_value, string new_name)
        {
            values[var_ctr]=new_value;
            names[var_ctr++]=new_name;
        }
        int find_variable(string name)
        {
            int token=-1;
            for(int i=0;i<var_ctr;i++)
            {
                if(names[i]==name)
                {
                    token=values[i];
                    break;
                }
                    
            }
            return token;
        }
        int set_variable(int new_value, string var_name)
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
} global_variable;

class operation
{
    protected:
        int op_ctr;
        operation** op_list= new operation*[MAX_BRANCH];
        //operation* op_list[MAX_BRANCH];
    public:
        operation()
        {
            op_ctr=0;
        }
        void add_operation(operation* new_op)
        {
            op_list[op_ctr++]=new_op;
        }
        virtual void run()
        {
            for(int i=0;i<op_ctr;i++)
            {
                op_list[i]->run();
            }
        }
        ~operation()
        {
            delete[] op_list;
        }

};

class print : public operation
{
    private:
        int selector;
        int newline;
        string varname;
    public:
        print(string new_varname)
        {
            varname=new_varname;
            selector=0;
            newline=0;
        }
        print(string new_varname, int new_newline)
        {
            varname=new_varname;
            selector=0;
            newline=new_newline;
        }
        void run()
        {
            switch(newline)
            {
                case 0:
                    cout<<global_variable.find_variable(varname);
                break;
                case 1:
                    cout<<global_variable.find_variable(varname)<<endl;
                break;
            }
            
        }
};

class prins : public operation
{
    private:
        int mode;           //0 = no newline , 1= new line
        string to_print;
    public:
        prins(string new_to_print, int new_mode)
        {
            to_print=new_to_print;
            mode=new_mode;
        }
        void run()
        {
            switch(mode)
            {
                case 0:
                    cout<<to_print;
                break;
                case 1:
                    cout<<to_print<<endl;
                break;
            }
        }
};

class n_while : public operation
{
    private:
        int mode;
        string var_kill_switch;
        string var_target;
    public:
        n_while(int new_mode,string new_var_kill_switch,string new_var_target) // 0= less than, 1=greater than
        {
            mode=new_mode;
            var_kill_switch=new_var_kill_switch;
            var_target=new_var_target;
        }
        void run()
        {
            int kill_switch=global_variable.find_variable(var_kill_switch);
            int target=global_variable.find_variable(var_target);
            switch(mode)
            {
                case 0:
                    while(kill_switch<target)
                    {
                        for(int i=0;i<op_ctr;i++)
                            op_list[i]->run();
                        kill_switch=global_variable.find_variable(var_kill_switch);
                        target=global_variable.find_variable(var_target);
                    }
                break;
                case 1:
                    while(kill_switch>target)
                    {
                        for(int i=0;i<op_ctr;i++)
                            op_list[i]->run();
                        kill_switch=global_variable.find_variable(var_kill_switch);
                        target=global_variable.find_variable(var_target);
                    }
                break;
            }
            
        }
};

class n_operator : public operation
{
    private:
        int type; // 0 plus - 1 minus - 2 multiply - 3 divide - 4 equals to
        int effector;
        string variable;
    public:
        n_operator(int new_type, string new_variable, int new_effector)
        {
            type=new_type;
            variable=new_variable;
            effector=new_effector;
        }
        void run()
        {
            int current=global_variable.find_variable(variable);
            switch(type)
            {
                case 0:
                    global_variable.set_variable(current+effector,variable);
                break;
                case 1:
                    global_variable.set_variable(current-effector,variable);
                break;
                case 2:
                    global_variable.set_variable(current*effector,variable);
                break;
                case 3:
                    global_variable.set_variable(current/effector,variable);
                break;
                case 4:
                    global_variable.set_variable(effector,variable);
                break;
            }
            
        }
};

class s_operator : public operation
{
    private:
        string param_a;
        string param_b;
        string param_c;
        int mode;       //0 ++, 1 --, 2 **, 3 **
    public:
        s_operator(string new_param_a, string new_param_b, string new_param_c, int new_mode)
        {
            param_a=new_param_a;
            param_b=new_param_b;
            param_c=new_param_c;
            mode=new_mode;
        }
        void run()
        {
            int nparam_b=global_variable.find_variable(param_b);
            int nparam_c=global_variable.find_variable(param_c);
            switch(mode)
            {
                case 0:
                    global_variable.set_variable(nparam_b+nparam_c,param_a);
                break;
                case 1:
                    global_variable.set_variable(nparam_b-nparam_c,param_a);
                break;
                case 2:
                    global_variable.set_variable((int)(nparam_b*nparam_c),param_a);
                break;
                case 3:
                    global_variable.set_variable(nparam_b/nparam_c,param_a);
                break;
                case 4:
                     global_variable.set_variable(nparam_b,param_a);
                break;
                case 5:
                    global_variable.set_variable(nparam_b%nparam_c,param_a);
                break;
            }
        }
};

/* To add alternate flow pass the alt_op pointer to the determine function
   the add_alt op should be extracted from inside the class
   */

class n_if : public operation
{
    private:
        int mode;       // 1= < , 2 = =, 3= >
        string param_a;
        string param_c;
    public:
        operation* alt_op;
        n_if(string new_param_a, int new_mode , string new_param_c)
        {
            param_a=new_param_a;
            param_c=new_param_c;
            mode=new_mode;
            alt_op= new operation;
        }
        void run()
        {
            int whichs=0;
            int nparam_a=global_variable.find_variable(param_a);
            int nparam_c=global_variable.find_variable(param_c);
            switch(mode)
            {
                case 0:
                    if(nparam_a<nparam_c)
                        whichs=0;
                    else
                        whichs=1;
                break;
                case 1:
                    if(nparam_a==nparam_c)
                        whichs=0;
                    else
                        whichs=1;
                break;
                case 2:
                    if(nparam_a>nparam_c)
                        whichs=0;
                    else
                        whichs=1;
                break;
            }
            switch(whichs)
            {
                case 0:
                    for(int i=0; i<op_ctr;i++)
                            {
                                op_list[i]->run();
                            }
                break;
                case 1:
                                alt_op->run();
                break;

            }
        }

};

class n_scan : public operation
{
    private:
        string param_a;
    public:
        n_scan(string new_param_a)
        {
            param_a=new_param_a;
        }
        void run()
        {
            int temp_var;
            cin>>temp_var;
            global_variable.set_variable(temp_var,param_a);
        }
};

class space : public operation
{
    public :
    void run()
    {
        cout<<" ";
    }
        
};

class newline : public operation
{
    public :
    void run()
    {
        cout<<endl;
    }
        
};

//int operations_ctr=0;

operation* p_operation_main;

int determine(operation* cur_op)
{
   
    //STRINGSTREAM
    // This section will split up codes into 5 parts

    if(input_stream->eof())
        return -5;

    string s;
    getline(*input_stream,s);
    
    vector<string> split_string;
    istringstream iss(s);
    for(std::string s; iss >> s; )
    split_string.push_back(s);

    //~STRINGSTREAM

    int input_size = split_string.size();   //

    string command=split_string[0];
    string param_a;
    string param_b;
    string param_c;
    switch(input_size)
    {
        case 2:  
            param_a=split_string[1];
        break;
        case 3:
            param_a=split_string[1];
            param_b=split_string[2];
        break;
        case 4:
            param_a=split_string[1];
            param_b=split_string[2];
            param_c=split_string[3];
        break;
        default:
            param_a="//";
            param_b="";
            param_c="";
        break;
    }
     /*cout<<"COMMAND DETECTED : "<<command<<endl;
    cout<<"PARAM_A = "<<param_a<<endl;
    cout<<"PARAM_B = "<<param_b<<endl;
    cout<<"PARAM_C = "<<param_c<<endl;
    */
    if(command=="stop")
        return -4;
    if(command=="//")
        return 100;
      

   
    
    //DEFINE PARAMETERS
    
    //~DEFINE PARAMETERS
    
     
    /*string command=split_string[0];
    string param_a=split_string[1];
    string param_b=split_string[2];
    string param_c=split_string[3];*/
   
  
    if(command=="while")
    {
        //if(!param_a.size() || !param_b.size())
            //return -2;
        //int base= global_variable.find_variable(param_a);
        //int target=global_variable.find_variable(param_b);
       // if(base==-1||target==-1)
            //return -1;
            n_while* temp_while;
        if(param_b=="<")
            temp_while = new n_while(0,param_a,param_c);
        if(param_b==">")
            temp_while = new n_while(1,param_a,param_c);
        //int ctr=d_line;
        while(determine(temp_while)>=0);
        //{
            //debug_ctr++;
            //cout<<"DEBUG CTR = "<<debug_ctr<<endl;
        //}
        // WHILE NO ; is seen add the operations
        cur_op->add_operation(temp_while);
    }
    if(command=="var")
    {
        global_variable.add_variable(stoi(param_b),param_a);
        //cout<<"VAR EXECUTED"<<endl;
    }
    if(command=="print")
    {
        //cout<<"PRINT EXECUTED"<<endl;
         if(!param_a.size())
            return -2;
        string new_varname=param_a;
        print* temp_print = new print(new_varname,0);
        cur_op->add_operation(temp_print);
        return 0;
    }
    if(command=="printline")
    {
         if(!param_a.size())
            return -2;
        string new_varname=param_a;
        print* temp_print = new print(new_varname,1);
        cur_op->add_operation(temp_print);
    }
    if(command=="prins")
    {
        prins* temp= new prins(param_a,0);
        cur_op->add_operation(temp);
    }
    if(command=="prinsline")
    {
        prins* temp= new prins(param_a,1);
        cur_op->add_operation(temp);
    }
    if(command=="if")
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
        cur_op->add_operation(temp);
    }
    if(command=="+")
    {
        n_operator* temp= new n_operator(0,param_a,stoi(param_b));  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
    if(command=="-")
    {
        n_operator* temp= new n_operator(1,param_a,stoi(param_b));  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
     if(command=="*")
    {
        n_operator* temp= new n_operator(2,param_a,stoi(param_b));  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
     if(command=="/")
    {
        n_operator* temp= new n_operator(3,param_a,stoi(param_b));  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
    if(command=="==")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,4);  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
    if(command=="=")
    {
        n_operator* temp= new n_operator(4,param_a,stoi(param_b));  //(int type, string var, int effector)
        cur_op->add_operation(temp);
    }
    if(command=="++")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,0);
        cur_op->add_operation(temp);
    }
    if(command=="--")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,1);
        cur_op->add_operation(temp);
    }
    if(command=="**")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,2);
        cur_op->add_operation(temp);
    }
    if(command=="///")
    {
        s_operator* temp= new s_operator(param_a,param_b,param_c,3);
        cur_op->add_operation(temp);
    }
    if(command=="%")
    {
        s_operator* temp = new s_operator(param_a,param_b,param_c,5);
        cur_op->add_operation(temp);
    }
    if(command=="space")
    {
        space* temp = new space;
        cur_op->add_operation(temp);
    }
    if(command=="newline")
    {
        newline* temp = new newline;
        cur_op->add_operation(temp);
    }
    if(command=="scan")
    {
        n_scan* temp = new n_scan(param_a);
        cur_op->add_operation(temp);
    }
}

int determine_helper()
{
   while(determine(p_operation_main)>=0);
}

void generate(char* currentfile,char* input_f, char* gen)
{
    ifstream  src(currentfile, std::ios::binary);
    ofstream  dst(gen,   std::ios::binary);
    dst << src.rdbuf();
    src.close();
    dst.close();
    //cout<<"GENERATE()"<<endl;
    ofstream gen_out;
    ifstream input(input_f);
    gen_out.open(gen,std::ios_base::app);
    gen_out<<endl;
    gen_out<<"DATASECDATASECDATASEC"<<endl;
    string s;
    while(!input.eof())
    {
        getline(input,s);
        gen_out<<s.c_str()<<endl;

    }
    //cout<<"GENERATED!"<<endl;
    gen_out<<"ENDFILEENDFILE"<<endl;
    gen_out.close();
    input.close();

}

void extract(char* currentfile)
{
    //cout<<"EXTRACT()"<<endl;
    ifstream curfile(currentfile);
    ifstream checkend(currentfile);
    int end_ctr=0;
    int cur_ctr=0;
    string checke;
    checkend>>checke;
     while(checke!="DATASECDATASECDATASEC")
    {
        //cout<<check<<endl;
        getline(checkend,checke);
    }
    while(!checkend.eof())
    {
        getline(checkend,checke);
        if(checke=="ENDFILEENDFILE")
            break;
        end_ctr++;
        
    }
    checkend.close();
    string check;
    curfile>>check;
    while(check!="DATASECDATASECDATASEC")
    {
        //cout<<check<<endl;
        getline(curfile,check);
    }
    
    ofstream outfile(".code");
    string s;
    while(!curfile.eof())
    {
        getline(curfile,s);
        if(s=="ENDFILEENDFILE")
            break;
        if(cur_ctr==end_ctr-1)
            outfile<<s.c_str();
        else
            outfile<<s.c_str()<<endl;
        cur_ctr++;
    }
    curfile.close();
    //outfile.close();
    //cout<<"EXTRACTED!"<<endl;
}

int main(int argc, char* argv[])
{
    
    switch(argc)
    {
        case 1: 
            extract(argv[0]);
            input_stream= new ifstream(".code");
            p_operation_main= new operation;
            determine_helper();
            p_operation_main->run();
        break;
        case 2:
            p_operation_main= new operation;
            input_stream= new ifstream(argv[1]);
            determine_helper();
            p_operation_main->run();
        break;
        case 3:
            generate(argv[0],argv[1],argv[2]);
        break;
            
    }
    //cout<<"ARGC="<<argc<<endl;
    //generate(argv[0],argv[1],argv[2]);
    //input_stream= new ifstream(argv[1]);
    
    //determine_helper();
    //p_operation_main->run();
    //operation** operations = new operation*[5];
    /* Operation lists
        Print("Hello WORLD");
        Print(5);
        while(i<5)
            print
    */
  /* print* hello = new print("HELLO WORLD");
   global_variable.add_variable(10,"mynewvar");
   print* number= new print(global_variable.find_variable("mynewvar"),1);
   n_while* testwhile= new n_while(10);
   testwhile->add_operation(hello);
   testwhile->add_operation(number);
    operations[0]=hello;
    operations[1]=number;
    operations[2]=testwhile;
   
    for(int i=0;i<3;i++)
    {
        operations[i]->run();
    }*/

}
// PROGRAM READS THE INSTRUCTION
// TOKENIZE EACH LINE
// if first character is ... then 
    //operations[0]= ...
    // if it's while then seek until ;
    //FORMAT = print 50
    //         print singlelinecharacter
    //         while 0 10
    //         if var 10
    //         else
    //         ;