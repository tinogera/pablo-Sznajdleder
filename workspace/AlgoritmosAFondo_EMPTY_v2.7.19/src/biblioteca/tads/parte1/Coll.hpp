#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sepa;
   int curr;
};

template<typename T>
Coll<T> coll(char sep)//Crea una coleccion vacia y nos dan el separador
{
   Coll<T> c;

   c.s="";
   c.sepa=sep;

   return c;
}

template<typename T>
Coll<T> coll()//Crea una coleccion vacia y elegimos nosotros el separador
{
   Coll<T> c;

   c.s="";
   c.sepa='|';

   return c;
}

template<typename T>
int collSize(Coll<T> c)//cantidad de elementos que contiene c
{
   int cToken =tokenCount(c.s,c.sepa) ;
   //Juan|pedro|Agustin
   return cToken;
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sepa,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sepa,tToString(t));
   return tokenCount(c.s,c.sepa)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s,c.sepa,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   t=tFromString(getTokenAt(c.s,c.sepa,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{

   for(int i=0;i<collSize(c);i++){
      T t=tFromString(getTokenAt(c.s,c.sepa,i));
      if(cmpTK(t,k)==0){
         return i;
      }
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   T aux;
   for(int i=0;i<collSize(c);i++){
      T t1= tFromString(getTokenAt(c.s,c.sepa,i));
      for(int j=0;j<collSize(c);j++){
         T t2=tFromString(getTokenAt(c.s,c.sepa,j));
         if(cmpTT(t1,t2)>0){
            aux=t1;
            t1=t2;
            t2=aux;
         }
         collSetAt(c,t1,i,tToString);
         collSetAt(c,t2,j,tToString);
      }
   }
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   if(collSize(c)>c.curr){
      return true;
   }
   return false;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t;
   string s;
   if(collHasNext(c)){
      s=getTokenAt(c.s,'|',c.curr);
      t=tFromString(s);
      c.curr++;
   }
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   string s;
   if(endOfColl){
      s=getTokenAt(c.s,'|',c.curr);
      t=tFromString(s);
      c.curr++;
   }
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.curr=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sepa+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sepa=s[0];
   c.s=substring(s,1);
   return c;
}

#endif
