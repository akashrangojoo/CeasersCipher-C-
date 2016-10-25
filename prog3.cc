/****************************************************************
   PROGRAM:   PROG3.CC
   AUTHOR:    AKASH RANGOJOO
   LOGON ID:  Z1717009  (your Z number here)
   DUE DATE:  9/16/2015

   FUNCTION:  Implements Ceaser's Cipher. Shifts each alphabet in the String  according to the Shift value.
   INPUT:     Takes a shift value and a string. 
   OUTPUT:    After shifting all the characters, the encoded message is given as output.
****************************************************************/


#include "prog3.h"
#include "error.h"
const int  ALPHA = 26;
const string FILE_PATH_SHIFT = "/home/cs689/progs/p3/prog3.d1"; //original path of Datafile to get shift value
const string FILE_PATH_TEXT  = "/home/cs689/progs/p3/prog3.d2";//original path of Datafile to get Text
const string FILE_PATH_OUT = "prog3.out";

int main() {

   ifstream input;
   input.open(FILE_PATH_SHIFT.c_str());
   if(input.fail()) error("Error while opening file to read SHIFT Value.!");
   int shift;
   while(input >> shift) {
      cout<<endl<<"Encoded Message when Shift value is "<< shift<<" : "<<endl;
      if(shift>ALPHA)   shift = shift%ALPHA; // If given shift value is greater than 26, making it less than 26
      if(shift<-1*ALPHA)  shift = shift%(-1*ALPHA); // If given shift value is less than -26 getting it to greater than -26
      if(shift==ALPHA)   shift = 0;   
      process_infile(shift);
   }
   input.close();
   cout<<endl;
}

/*This function passes thee shuft vlue extracted from the file and open the file that contains
 *  message text to encode */
void process_infile(int shift) {
   ifstream infile;
   infile.open(FILE_PATH_TEXT.c_str());
   if(infile.fail()) error("Error while opening file to Read the Message.!");
   string str,cipher;
   int count =0;
   while(infile >> str){
      if(count==0) { 
         cipher = encodeCeaserCipher(str,shift); // Calling encode method with each string one by one
         count++;
      }
      else cipher = cipher + " " + encodeCeaserCipher(str,shift);
   }
   cout<<cipher<<endl;
   infile.close();
}
/*This function takes string value and a shift value, where  it send 
 * each character one by one to get hte new postion*/
string encodeCeaserCipher(string str, int shift) {
   string lower = "abcdefghijklmnopqrstuvwxyz";
   string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   for(unsigned i=0;i<str.length();i++) {
      if(isalpha(str[i])){
         if(islower(str[i]))        str[i]=lower[new_position(str[i],shift)]; // getting new position by sending each character one by one
         if(isupper(str[i]))        str[i]=upper[new_position(str[i],shift)];
      }
   }
   return str;
}

/*This function takes a character and a shift value 
 * and returns the new position acc. to shift value*/
int new_position(char c, int shift){
   int newPos;
   int num;
   string lowerAlpha = "abcdefghijklmnopqrstuvwxyz";
   string upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
   if(islower(c))  num = lowerAlpha.find(c);
   if(isupper(c))  num = upperAlpha.find(c);
   if(num==-1) cerr<<"Error..!! character not found"<<endl;
  
   newPos = num+shift;
   
   if(newPos<0)    newPos +=ALPHA;
   if(newPos>=ALPHA)   newPos -=ALPHA;
   return newPos;
}
