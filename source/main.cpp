/* main.cpp                               *
 * this file contains the main() function */

#include "include/operation.h"
#include <fstream>

using namespace std;

extern void extract(char*);
extern void generate(char*, char*, char*);
extern void determine_helper();
extern void destroy();

extern ifstream* input_stream;
extern operation* p_operation_main;

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
	    destroy();
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
}