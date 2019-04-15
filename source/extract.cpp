/* extract.cpp                                       *
 * This file contains void extract() function        *
 * The function will read its own file, and search   *
 * (read through) the whole file until certain flags *
 * are found, when it finds the flag, it will start  *
 * extracting the codes into a file named ".code"    */

#include <fstream>
#include <string>

using namespace std;

void extract(char* currentfile)
{
    ifstream curfile(currentfile);
    ifstream checkend(currentfile);
    int end_ctr=0;
    int cur_ctr=0;
    string checke;
    checkend>>checke;
    // HACK!
    // checks for datasec flag, and begin incrementing end_ctr
    // This is made this way because the program has no way of knowing
    // where the endfile flag is, and rather than having to reset/ make a data structure for
    // storing certain lines of string with its associated line number, i'd rather just
    // make another instance of ifstream, and control the main ifstream with a variable
    // ~bad implementation but it's fast
     while(checke!="DATASECDATASECDATASEC")
    {
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
}