/* determine_helper.cp
 * This file contains the determine_helper() function   *
 * This will check if the return value for the main     *
 * reccurence of operation is still positive, if it is  *
 * the program will continue to read for inputs, and if *
 * it returns negative, the program will terminate      *
 * program can be terminated either with eof flag or    *
 * stop flag in the final recurrence of the determine   *
 * function                                             */
 
#include "include/operation.h"

extern operation* p_operation_main;
extern int determine(operation*);

void determine_helper()
{
   while(determine(p_operation_main)>=0);
}