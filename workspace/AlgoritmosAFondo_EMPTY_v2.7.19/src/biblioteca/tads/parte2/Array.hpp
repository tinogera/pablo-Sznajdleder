#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array
{
   T* arr;    // Puntero al array de datos
   int leng;  // Capacidad total del array
   int cant;  // Número actual de elementos en el array

};

template <typename T>
Array<T> array()
{
   Array<T> a;
   a.leng = 4;            // Capacidad inicial predeterminada
   a.cant = 0;            // El array está inicialmente vacío
   a.arr = new T[a.leng]; // Asigna memoria para la capacidad inicial
   return a;
}

template <typename T>
int arrayAdd(Array<T>& arr, T t)
{
   if( arr.cant==arr.leng )
   {
      // Redimensionar el array cuando está lleno
      arr.leng *= 2;
      T* newArr = new T[arr.leng];
      for( int i = 0; i<arr.cant; i++ )
      {
         newArr[i] = arr.arr[i]; // Copiar los elementos existentes al nuevo array
      }
      delete[] arr.arr; // Liberar la memoria del array antiguo
      arr.arr = newArr; // Actualizar el puntero al nuevo array
   }
   arr.arr[arr.cant++] = t;
   return arr.cant-1;
}

template <typename T>
T* arrayGet(Array<T> a, int p)
{
   if( p>=0&&p<a.cant )
   {
      return &a.arr[p];
   }
   return NULL;
}

template <typename T>
void arraySet(Array<T>& a, int p, T t)
{
   a.arr[p] = t;
}

template <typename T>
void arrayInsert(Array<T>& a, T t, int p)
{
   if( a.cant==a.leng )
   {
      a.leng *= 2;
      T* newArr = new T[a.leng];
      for( int i = 0; i<a.cant; i++ )
      {
         newArr[i] = a.arr[i];
         delete[] a.arr;
         a.arr = newArr;
      }
   }
   for( int i = a.cant; i>p; i-- )
   {
      a.arr[i] = a.arr[i-1];
   }
   a.arr[p] = t;
   a.cant++;
}

template <typename T>
int arraySize(Array<T> a)
{
   return a.cant;
}

template <typename T>
T arrayRemove(Array<T>& a, int p)
{
   T t = a.arr[p];
   for( int i = p; i<a.cant-1; i++ )
   {
      a.arr[i] = a.arr[i+1];
   }
   a.cant--;
   return t;
}

template <typename T>
void arrayRemoveAll(Array<T>& a)
{
   delete a.arr;
   a.leng = 4;
   a.cant = 0;
   a.arr = new T[a.leng];
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   for( int i = 0; i<a.cant; i++ )
   {
      if( cmpTK(a.arr[i],k)==0 )
      {
         return i;  // Retorna la posición si el elemento se encuentra
      }
   }
   return -1;  // Retorna un valor negativo si no se encuentra el elemento
}

template <typename T>
int arrayOrderedInsert(Array<T>& a, T t, int cmpTT(T, T))
{
   int i = 0;
   while( i<a.cant&&cmpTT(a.arr[i],t)<0 )
   {
      i++;
   }

   if( a.cant==a.leng )
   {
      // Redimensionar el array si está lleno
      a.leng *= 2;
      T* newArr = new T[a.leng];
      for( int j = 0; j<a.cant; j++ )
      {
         newArr[j] = a.arr[j];
      }
      delete[] a.arr;
      a.arr = newArr;
   }

   for( int j = a.cant; j>i; j-- )
   {
      a.arr[j] = a.arr[j-1];
   }

   a.arr[i] = t;
   a.cant++;

   return i;
}

template <typename T>
T* arrayDiscover(Array<T>& a, T t, int cmpTT(T, T))
{
   int i = 0;
   // Buscar el lugar adecuado o si el elemento ya está presente
   while( i<a.cant&&cmpTT(a.arr[i],t)<0 )
   {
      i++;
   }

   // Si se encuentra el elemento, se retorna su dirección
   if( i<a.cant&&cmpTT(a.arr[i],t)==0 )
   {
      return &a.arr[i];
   }

   // Si el array está lleno, redimensionar
   if( a.cant==a.leng )
   {
      a.leng *= 2;
      T* newArr = new T[a.leng];
      for( int j = 0; j<a.cant; j++ )
      {
         newArr[j] = a.arr[j];
      }
      delete[] a.arr;
      a.arr = newArr;
   }

   // Desplazar elementos para hacer espacio para el nuevo
   for( int j = a.cant; j>i; j-- )
   {
      a.arr[j] = a.arr[j-1];
   }

   // Insertar el nuevo elemento
   a.arr[i] = t;
   a.cant++;

   return &a.arr[i];
}

template <typename T>
void arraySort(Array<T>& a, int cmpTT(T, T))
{
   for( int i = 0; i<a.cant-1; i++ )
   {
      for( int j = 0; j<a.cant-i-1; j++ )
      {
         if( cmpTT(a.arr[j],a.arr[j+1])>0 )
         {
            // Intercambiar elementos si están en el orden incorrecto
            T temp = a.arr[j];
            a.arr[j] = a.arr[j+1];
            a.arr[j+1] = temp;
         }
      }
   }
}

#endif
