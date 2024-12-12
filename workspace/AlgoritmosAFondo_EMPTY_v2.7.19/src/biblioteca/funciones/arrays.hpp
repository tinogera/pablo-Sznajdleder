#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int& len, T e)
{
   arr[len] = e;  // Agrega el elemento al final del array
   return len++;  // Incrementa la longitud y retorna la posición donde fue insertado

}

template <typename T>
void insert(T arr[], int& len, T e, int p)
{
   for( int i = len; i>p; --i )
   {
      arr[i] = arr[i-1];  // Desplaza los elementos a la derecha
   }
   arr[p] = e;  // Inserta el nuevo elemento en la posición p
   len++;  // Incrementa la longitud del array

}

template <typename T>
T remove(T arr[], int& len, int p)
{
   T removedElement = arr[p];
   for( int i = p; i<len-1; i++ )
   {
      arr[i] = arr[i+1];  // Desplaza los elementos a la izquierda
   }
   len--;  // Decrementa la longitud del array
   return removedElement;  // Retorna el elemento removido
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   for( int i = 0; i<len; i++ )
   {
      if( cmpTK(arr[i],k)==0 )
      {
         return i;  // Retorna la posición si el elemento es encontrado
      }
   }
   return -1;  // Retorna -1 si el elemento no se encuentra
}

template <typename T>
int orderedInsert(T arr[], int& len, T e, int cmpTT(T, T))
{
   int i;
   for( i = 0; i<len; i++ )
   {
      if( cmpTT(arr[i],e)>0 )
      {
         break;  // Encuentra la posición donde debe ser insertado
      }
   }
   insert(arr,len,e,i);  // Usa la función `insert` para agregar el elemento
   return i;  // Retorna la posición donde fue insertado
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   for( int i = 0; i<len-1; i++ )
   {
      for( int j = 0; j<len-i-1; j++ )
      {
         if( cmpTT(arr[j],arr[j+1])>0 )
         {
            // Intercambia si los elementos están en el orden incorrecto
            T temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

#endif
