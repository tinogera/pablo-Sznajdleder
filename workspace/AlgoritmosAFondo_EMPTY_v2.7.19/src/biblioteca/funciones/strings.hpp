#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;
   while(s[i]!='\0'){
      i++;
   }
   return i;
}

int charCount(string s,char c)
{
   int i=0,cant=0;
   while(s[i]!='\0'){
         if(s[i]==c){
            cant++;
         }
         i++;
      }
   return cant;
}

string substring(string s,int d,int h)
{
   string i;
   while(d<h){
      i=i+s[d];
      d++;
   }
   return i;
}

string substring(string s,int d) // ok
{
   string i;
     while(s[d]!='\0'){
        i=i+s[d];
        d++;
     }
     return i;
}

int indexOf(string s,char c) // ok
{
   int i=0;

  while(s[i]!=c && s[i]!='\0'){
     i++;
  }
   if(s[i]=='\0'){
      i=-1;
   }

   return i;
}

int indexOf(string s,char c,int offSet) // ok
{
   int i=offSet;
  while(s[i]!=c && s[i]!='\0'){
     i++;
  }
   if(s[i]=='\0'){
      i=-1;
   }

  return i;
}

int indexOf(string s,string toSearch) // ok
{
       int found = -1, i = 0, j = 0;
       int str=length(s);
       int toSear=length(toSearch);

       while (i < str) {

           if (s[i] == toSearch[j]) {

               if (j == 0) {
                   found = i;
               }

               j++;

               if (j == toSear) {
                   return found;
               }
           }

           else {

               j = 0;

               found = -1;
           }

           i++;
       }

       return -1;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int i = offset;
   int Slong=length(s);
   int toSearchLong=length(toSearch);
   while (i < Slong && i + toSearchLong > i) {
       int j = 0;
       while (j < toSearchLong && s[i + j] == toSearch[j]) {
           j++;
       }

       if (j == toSearchLong) {
           return i;
       }

       i++;
   }

   return -1;
}

int lastIndexOf(string s,char c)
{
   int cant=charCount(s,c);
   int i=0,can=0;
   while(can!=cant && s[i]!='\0'){
      if(s[i]==c){
         can++;
      }
      i++;
   }

   if(cant==0){
      i=-1;
   }

   return i;
}

int indexOfN(string s,char c,int n){
   int slong=length(s);
   int count = 0;
   for (int i = 0; i < slong; i++) {
      if (s[i] == c) {
         count++;
         if (count == n) {
            return i;
         }
       }
     }
     if (n > count) {
       return slong;
     } else {
       return -1;
     }
}

int charToInt(char c){
  if ('0' <= c && c <= '9') {
    return c - '0';
  } else if ('A' <= c && c <= 'Z') {
    return c - 'A' + 10;
  } else if ('a' <= c && c <= 'z') {
    return c - 'a' + 10;
  } else {
    return -1;
  }
}

char intToChar(int i)
{
     if (i >= 0 && i <= 9) {
       return i + '0';
     } else if (i >= 10 && i <= 35) {
       return i - 10 + 'A';
     } else {
       return -1;
     }

   return -1;
}

int getDigit(int n,int i)
{
   while (n >= 10 && i > 0) {
       n /= 10;
       i--;
   }
   return n % 10;
}

int digitCount(int n)
{
   int i=0;
   while(n!=0){
      i++;
      n/=10;
   }
   return i;
}

string intToString(int i)
{
   int a=digitCount(i);
   int j=a-1,num=0;
   string s;
   while(j>=0){
      num=getDigit(i,j);
      s+=intToChar(num);
      j--;
   }
   return s;
}

int stringToInt(string s,int b) {

   int slength = length(s);
   int resultado = 0;
   int pos = 1;
   for (int i = slength - 1; i >= 0; i--) {
       char c = s[i];
       int num = 0;
       if (c >= '0' && c <= '9') {
           num = c - '0';
       } else if (c >= 'a' && c <= 'z') {
           num = c - 'a' + 10;
       } else if (c >= 'A' && c <= 'Z') {
           num = c - 'A' + 10;
       }

       resultado += num * pos;
       pos *= b;
   }
   return resultado;
   }

int stringToInt(string s) // ok
{
   int slength=length(s);
   int result=0;
   for(int i=0;i<slength;i++){
     int num=s[i]-'0';
     result=result*10+num;
   }

   return result;
}

string charToString(char c)
{
   string s;
   s+=c;
   return s;
}

char stringToChar(string s)
{
   int sLength=length(s);
   if(sLength!=1){
   cout<<"Mas de un caracter";
   return -1;
   }
   return s[0];
}

string stringToString(string s)
{
   string str;
   str+=s;
   return str;
}

string doubleToString(double d)
{
 return 0;
}

double stringToDouble(string s)
{

   return 1.1;
}

bool isEmpty(string s)
{
   bool b=false;
   int sLength=length(s);
   if(sLength>0){
      return b;
   }
   else{
      b=true;
   }

   return b;
}

bool startsWith(string s,string x)
{
  int sLength=length(s),xLength=length(x);
       if (sLength < xLength) {
           return false;
       }
       for (int i = 0; i < xLength; i++) {
           if (s[i] != x[i]) {
               return false;
           }
       }
       return true;
}

bool endsWith(string s,string x)
{
  int sLength=length(s),xLength=length(x);
      if (sLength < xLength) {
          return false;
    }
      for (int i = xLength; i >= 0; i--) {
         if (s[sLength - xLength + i] != x[i]) {
                     return false;
         }
      }

  return true;

}

bool contains(string s,char c)
{
   for(int i=0; s[i]!='\0';i++){
      if(s[i]==c){
         return true;
      }
   }
   return false;
}

string replace(string s,char oldChar,char newChar)
{
   if(!contains(s,oldChar)){
      return s;
   }
   for(int i=0; s[i]!='\0';i++){
         if(s[i]==oldChar){
            s[i]-=oldChar;
            s[i]+=newChar;
         }
      }
   return s;
}

string insertAt(string s,int pos,char c)
{
   int sLength=length(s);
   string result;
   if(pos<0||pos>sLength){
      return s;
   }
   for(int i=0;i<pos;i++){
      result+=s[i];
   }
   result+=c;
   for (int i = pos; i < sLength; ++i) {
       result += s[i];
   }

return result;
}

string removeAt(string s,int pos)
{
    int sLength=length(s);
    if(pos<0||pos>sLength){
       return s;
    }
    string result;
    for(int i=0;i<sLength;i++){
       if(i!=pos){
          result+=s[i];
       }
    }
 return result;
}

string ltrim(string s)
{
   int sLength=length(s);
   int pos = 0;
   while (pos < sLength && s[pos] == ' ') {
      pos++;
   }
   if (pos == 0) {
      return s;
   }
return substring(s,pos);
}


string rtrim(string s)
{
   int sLength=length(s);
   int pos = sLength - 1;
   while (pos >= 0 && s[pos] == ' ') {
      pos--;
   }
   if (pos == sLength - 1) {
      return s;
   }
   string result;
   for (int i = 0; i <= pos; ++i) {
      result += s[i];
   }
return result;
}

string trim(string s)
{
   string r=ltrim(s);
   string result=rtrim(r);

   return result;
}

string replicate(char c,int n)
{
   string s;
   if(n==0){
      return s;
   }
   while(n>0){
      s+=c;
      n--;
   }
   return s;
}

string spaces(int n)
{
   string s;
   char c=' ';
   if(n==0){
      return s;
   }
   while(n>0){
      s+=c;
      n--;
   }
   return s;
}

string lpad(string s,int n,char c)
{
   int Slength=length(s);
   if(n==0||n<Slength){
      return s;
   }
   int relleno=n-Slength;
   string result;
   for(int i=0;i<relleno;i++){
      result+=c;
   }
   result+=s;
   return result;
}

string rpad(string s,int n,char c)
{
   int Slength=length(s);
    if(n==0||n<Slength){
       return s;
    }
    int relleno=n-Slength;
    string result;
    result+=s;
    for(int i=0;i<relleno;i++){
       result+=c;
    }
    return result;
}

string cpad(string s,int n,char c)
{
   int sLength=length(s);
   if (n <= sLength) {
      return s;
   }

   int completar= n-sLength;
   int completarIzq = completar/2;
   int completarDrch = completar-completarIzq;
   string result;
   for (int i = 0; i < completarIzq; ++i) {
      result += c;
   }
   result+=s;
   for (int i = 0; i < completarDrch; ++i) {
      result+= c;
   }
   return result;
}

bool isDigit(char c)
{
   bool b=false;
   if(c>='0'&&c<='9'){
      b=true;
      return b;
   }
   return b;
}

bool isLetter(char c)
{
   bool b=false;
   if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
      b=true;
      return b;
   }
   return b;
}

bool isUpperCase(char c)
{
   bool b=false;
     if(c>='A'&&c<='Z'){
        b=true;
        return b;
     }
     return b;
}

bool isLowerCase(char c)
{
   bool b=false;
   if(c>='a'&&c<='z'){
      b=true;
      return b;
   }
   return b;
}

char toUpperCase1(char c)
{
   char cont='a';

   if(isDigit(c)){
      return c;
   }
   while(cont<='z'){
      if (c >= 'a' && c <= 'z') {
         return c - 32;
      }
      cont++;
   }

   return c;
}

char toLowerCase1(char c)
{
   char cont='A';

   if(isDigit(c)){
      return c;
   }
   while(cont<='Z'){
      if(c >= 'A' && c <= 'Z'){
        return c+32;
      }
      cont++;
   }

   return c;
}


string toUpperCase(string s)
{
   int sLength=length(s);
   for(int i=0;i<sLength;i++){
      s[i]=0;
   }
   return s;
}

string toLowerCase(string s)
{
   int sLength=length(s);
   for(int i=0;i<sLength;i++){
      s[i]=0;
   }
   return s;
}

int cmpString(string a,string b)
{
   int aLength=length(a);
   for(int i=0;i<aLength;i++){
      if(a[i]<b[i])
      {
         return -1;
      }
      else if(a[i]>b[i]){
         return 2;
      }
}
   return 0;
}

int cmpDouble(double a,double b)
{

   return 0;
}

#endif
