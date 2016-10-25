/****************************************************************
   PROGRAM:   PROG3.H
   AUTHOR:    AKASH RANGOJOO
   LOGON ID:  Z1717009 
   DUE DATE:  9/16/2015

   FUNCTION:  CONTAINS CONSTANTS FOR FILE PATHS AND METHIDS THAT ARE CALLED FROM SOURCE FILE PROG3.CC
   INPUT:     NO INPUT. CONTAINS METHODS TO CREATE ENCODED MESSAGE
   OUTPUT:    NO OUTPUT
****************************************************************/



#include "/home/cs689/common/689.h"

#ifndef prog3_h
#define prog3_h

extern const int ALPHA;
extern const string FILE_PATH_TEXT;
extern const string FILE_PATH_SHIFT;

extern void process_infile(int);
extern string encodeCeaserCipher(string,int);
extern int new_position(char,int);

#endif
