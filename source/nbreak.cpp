/* nbreak.cpp                                               *
 * this provides break functionality to get                 *
 * out of loop i.e for and while                            *
 * does the job bykeeping track the last instance of loop   *
 * and sending sig_break into it                            *
 * a friend class of loop and its descendance               */

#include "include/nbreak.h"
#include "include/loop.h"

extern loop** ploop_array;
extern int n_loops;

using namespace std;

void nbreak::run()
{
    ploop_array[n_loops]->sig_break=true;
}