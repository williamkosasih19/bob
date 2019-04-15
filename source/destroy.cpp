/* Destroy.cpp                                         *
 * This file contains void destory() function          *
 * this will delete the ".code" after the program ends *
 *                                                     */

#include <stdio.h>

void destroy()
{
	remove(".code");
}