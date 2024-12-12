#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   return charCount(s,sep)+1;
}

void addToken(string& s, char sep, string t)
{
   if(isEmpty(s)){
      s+=t;
   }
   else{
      s+=charToString(sep)+t;
   }
}

string getTokenAt(string s, char sep, int i)
{
   int d=0;
   int h=0;
   if( i==0 ){ // piden el primero
      d=0;
      h=indexOfN(s,sep,1);
      return substring(s,d,h);
   }
   else{ // piden el ultimo
      if( i+1==tokenCount(s,sep) ){
         d=lastIndexOf(s,sep);
         return substring(s,d);
      }
      else{
         // piden por el medio
         d= indexOfN(s,sep,i);
         h= indexOfN(s,sep,i+1);

         return substring(s,d+1,h);
      }
   }
}

void removeTokenAt(string& s, char sep, int i)
{
  //getTokenAt(s,sep,i)
   int d=0;
   int h=0;

   if( i==0 ){ //elimina si ekl token esta primero
        d=indexOfN(s,sep,1);
        s=substring(s,d+1);
     }

   else{//elimina si el token esta ultimo
      if( i+1==tokenCount(s,sep) ){
         d=0;
         h=lastIndexOf(s,sep);
         s=substring(s,d,h-1);
      }
      else{ //elimina el token del medio
         h=indexOfN(s,sep,i)-1;
         d=indexOfN(s,sep,i+1);
         s=substring(s,0,h)+substring(s,d);
      }
   }
}

void setTokenAt(string& s, char sep, string t, int i)
{
   //getTokenAt(s,sep,i)
   int d=0;
   int h=0;
   string f;
   if( i==0 ){ //remplazo t en el primer token
     removeTokenAt(s,sep,i);
    s=t+'|'+substring(s,0);
   }

   else{//remplazo t en el ultimo token
      if( i+1==tokenCount(s,sep) ){
         d=0;
         h=lastIndexOf(s,sep);
         s=substring(s,d,h-1)+'|'+t;
      }
      else{ //remplazo el token del medio
         h=indexOfN(s,sep,i);
         d=indexOfN(s,sep,i+1);
         s=substring(s,0,h)+'|'+t+substring(s,d);
      }
   }
}

int findToken(string s, char sep, string t)
{
   int inicioToken=0;
   int contaToken=0;
   int count=0;
   int sLength=length(s);
   while(inicioToken<sLength){
      contaToken=inicioToken;
      while(contaToken<sLength&&s[contaToken]!=sep){
         contaToken++;
      }
      if(contaToken==inicioToken){
         inicioToken++;
      }
      string token= substring(s,inicioToken,contaToken);
      if(token==t){
         return count;
      }
      else{
         count++;
      }
      inicioToken=contaToken+1;
   }
   return 0;
}
#endif


