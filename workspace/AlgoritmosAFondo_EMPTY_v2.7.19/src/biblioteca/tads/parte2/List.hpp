#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List
{
   Node<T>* head;  // Puntero al primer nodo
   Node<T>* current; // Puntero para iterar sobre la lista
};

template <typename T>
List<T> list()
{
   List<T> lst;
   lst.head = nullptr;  // Inicializamos con la lista vacía
   lst.current = nullptr;
   return lst;
}

template <typename T>
T* listAdd(List<T>& lst, T e)
{
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;
   nuevo->sig = nullptr;

   if( lst.head==nullptr )
   {
      // Si la lista está vacía, agregamos el primer nodo
      lst.head = nuevo;
   }
   else
   {
      // Buscamos el último nodo
      Node<T>* temp = lst.head;
      while( temp->sig!=nullptr )
      {
         temp = temp->sig;
      }
      temp->sig = nuevo;  // Añadimos el nuevo nodo al final
   }

   return &(nuevo->info);
}

template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;
   nuevo->sig = lst.head;
   lst.head = nuevo;  // El nuevo nodo es ahora el primer nodo

   return &(lst.head->info);  // Retornamos la dirección del elemento agregado

}

template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
   Node<T>* prev = nullptr;
   Node<T>* curr = lst.head;

// Recorremos la lista buscando el nodo que concuerde con k
   while( curr!=nullptr )
   {
      if( cmpTK(curr->info,k)==0 )
      {
         // Encontramos el nodo a eliminar
         T info = curr->info;

         if( prev==nullptr )
         {
            // El nodo a eliminar es el primero
            lst.head = curr->sig;
         }
         else
         {
            // El nodo está en el medio o al final
            prev->sig = curr->sig;
         }

         delete curr;  // Liberamos la memoria del nodo
         return info;  // Retornamos el valor del nodo eliminado
      }

      prev = curr;
      curr = curr->sig;
   }
}

template <typename T>
T listRemoveFirst(List<T>& lst)
{
   if( lst.head==nullptr )
   {
      throw std::runtime_error("La lista está vacía.");
   }

   Node<T>* temp = lst.head;  // Guardamos el nodo a eliminar
   T info = temp->info;  // Guardamos el valor del nodo

   lst.head = lst.head->sig;  // El siguiente nodo se convierte en el primer nodo
   delete temp;  // Liberamos el nodo

   return info;  // Retornamos el valor del nodo eliminado
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{

   Node<T>* current = lst.head;

   while( current!=nullptr )
   {
      if( cmpTK(current->info,k)==0 )
      {
         return &(current->info);  // Retorna la dirección del elemento encontrado
      }
      current = current->sig;
   }

   return nullptr;  // Si no se encontró el elemento

}

template <typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.head==nullptr;  // Retorna true si la lista está vacía
}

template <typename T>
int listSize(List<T> lst)
{
   int count = 0;
   Node<T>* current = lst.head;

   while( current!=nullptr )
   {
      count++;
      current = current->sig;
   }

   return count;  // Retorna la cantidad de elementos en la lista
}

template <typename T>
void listFree(List<T>& lst)
{
   Node<T>* current = lst.head;
   while( current!=nullptr )
   {
      Node<T>* temp = current;
      current = current->sig;
      delete temp;
   }
   lst.head = nullptr;  // Aseguramos que la lista quede vacía
   lst.current = nullptr;
}

template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT)
{
   Node<T>* current = lst.head;

   // Buscar el elemento en la lista
   while( current!=nullptr )
   {
      if( cmpTT(current->info,t)==0 )
      {
         return &(current->info);  // Elemento encontrado, retornar su dirección
      }
      current = current->sig;
   }

   // Si no lo encuentra, lo agrega al final
   listAdd(lst,t);  // Agregar al final de la lista
   return &(lst.tail->info);  // Retorna la dirección del elemento agregado
}

template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   Node<T>* nuevo = new Node<T>(t);
   Node<T>* current = lst.head;
   Node<T>* prev = nullptr;

   // Encontrar la posición correcta para insertar
   while( current!=nullptr&&cmpTT(current->info,t)<0 )
   {
      prev = current;
      current = current->sig;
   }

   // Insertar al inicio si es el primer elemento o si es menor que todos los demás
   if( prev==nullptr )
   {
      nuevo->sig = lst.head;
      lst.head = nuevo;
      if( lst.tail==nullptr )
         lst.tail = nuevo;
   }
   else
   {
      // Insertar en medio o al final
      prev->sig = nuevo;
      nuevo->sig = current;
      if( current==nullptr )
         lst.tail = nuevo;
   }

   return &(nuevo->info);  // Retorna la dirección del elemento insertado
}

template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   if( !lst.head||!lst.head->sig )
   {
      return;  // La lista está vacía o tiene un solo elemento
   }

   Node<T>* sorted = nullptr;  // Nueva lista ordenada
   Node<T>* current = lst.head;

   while( current )
   {
      Node<T>* next = current->sig;  // Guardar el siguiente nodo

      // Insertar el nodo actual en la lista ordenada
      if( !sorted||cmpTT(current->info,sorted->info)<=0 )
      {
         current->sig = sorted;
         sorted = current;
      }
      else
      {
         Node<T>* sortedCurrent = sorted;
         while( sortedCurrent->sig&&cmpTT(current->info,sortedCurrent->sig->info)>0 )
         {
            sortedCurrent = sortedCurrent->sig;
         }
         current->sig = sortedCurrent->sig;
         sortedCurrent->sig = current;
      }

      current = next;  // Avanzar al siguiente nodo en la lista original
   }

   lst.head = sorted;  // La nueva cabeza es la lista ordenada
}

template <typename T>
void listReset(List<T>& lst)
{
   lst.current = lst.head;  // Ponemos el puntero de iteración en el primer nodo
}

template <typename T>
bool listHasNext(List<T> lst)
{
   return lst.current!=nullptr;
}

template <typename T>
T* listNext(List<T>& lst)
{
   if( lst.current==nullptr )
   {
      throw std::runtime_error("No hay más elementos en la lista.");
   }
   T* info = &(lst.current->info);  // Retornamos la dirección del valor actual
   lst.current = lst.current->sig;  // Avanzamos al siguiente nodo
   return info;

}

template <typename T>
T* listNext(List<T>& lst, bool& endOfList)
{
   if( !lst.iter )
   {
      endOfList = true;  // Se llegó al final de la lista
      return nullptr;
   }

   endOfList = false;
   T* result = &(lst.iter->info);  // Obtener el valor actual
   lst.iter = lst.iter->sig;  // Avanzar el iterador

   if( !lst.iter )
   {
      endOfList = true;  // No hay más elementos después de este
   }

   return result;
}

#endif
