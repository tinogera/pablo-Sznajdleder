#ifndef _TMTX_T_
#define _TMTX_T_

#include <iostream>
#include "Coll.hpp"

using namespace std;

template<typename T>
struct Mtx
{
};

template <typename T>
Mtx<T> mtx(int f,int c,T valorDefault,string tToString(T))
{
   Mtx<T> m;
   return m;
}

template <typename T>
T mtxGetAt(Mtx<T> m,int f,int c,T tFromString(string))
{
   T t;
   return t;
}

template <typename T>
void mtxSetAt(Mtx<T>& m,T t,int f,int c,string tToString(T))
{
}

// ------------------------

template<typename T>
struct Cube
{
};

template <typename T>
Cube<T> cube(int f,int c,int p,T valorDefault,string tToString(T))
{
   return {};
}

template <typename T>
T cubeGetAt(Cube<T> cu,int f,int c,int p,T tFromString(string))
{
   T t;
   return t;
}

template <typename T>
void cubeSetAt(Cube<T>& cu,T t,int f,int c,int p,string tToString(T))
{
}



#endif
