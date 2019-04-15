/* generate.cpp
 * this file cntains the generate() function            *
 * the function will copy itself, then append codes     *
 * to the end (ios::app) part of the copied file        *
 * some flags will be added so the newly created binary *
 * will be able to differentiate between the binary     *
 * section of the program and the text section of the   *
 * program                                              */

#include <fstream>
#include <string>

using namespace std;

void generate(char* currentfile,char* input_f, char* gen)
{
    ifstream  src(currentfile, std::ios::binary);
    ofstream  dst(gen,   std::ios::binary);
    dst << src.rdbuf();
    src.close();
    dst.close();
    ofstream gen_out;
    ifstream input(input_f);
    gen_out.open(gen,std::ios_base::app);
    gen_out<<endl;
    gen_out<<"DATASECDATASECDATASEC"<<endl;         // This flag indicates the start of the text section
    string s;
    while(!input.eof())
    {
        getline(input,s);
        gen_out<<s.c_str()<<endl;

    }
    gen_out<<"ENDFILEENDFILE"<<endl;                // This flag indicates the end of the text section
    gen_out.close();
    input.close();

}