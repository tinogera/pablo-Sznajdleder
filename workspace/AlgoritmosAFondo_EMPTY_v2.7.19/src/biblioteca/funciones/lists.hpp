#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;           // Información almacenada en el nodo.
   Node<T>* sig;     // Puntero al siguiente nodo.

};

template <typename T>
Node<T>* add(Node<T>*& p, T e)
{
   Node<T>* nuevo = new Node<T>;  // Crear un nuevo nodo.
   nuevo->info = e;               // Asignar el valor del elemento al nodo.
   nuevo->sig = nullptr;          // El nuevo nodo no apunta a ningún otro nodo, es el último.

   if( p==nullptr )
   {
      // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo.
      p = nuevo;
   }
   else
   {
      // Si la lista no está vacía, recorremos hasta el último nodo.
      Node<T>* temp = p;
      while( temp->sig!=nullptr )
      {
         temp = temp->sig;
      }
      temp->sig = nuevo;  // Asignar el nuevo nodo al final de la lista.
   }

   return nuevo;  // Retornar la dirección del nodo recién agregado.
}

template <typename T>
Node<T>* addFirst(Node<T>*& p, T e)
{
   Node<T>* nuevo = new Node<T>;  // Crear un nuevo nodo.
   nuevo->info = e;               // Asignar el valor del elemento al nodo.
   nuevo->sig = p;                // El nuevo nodo apunta al primer nodo actual.

   p = nuevo;  // Actualizar p para que apunte al nuevo nodo.

   return nuevo;  // Retornar la dirección del nodo recién agregado.
}

template <typename T, typename K>
T remove(Node<T>*& p, K k, int cmpTK(T, K))
{
   if( p==NULL )
   {
      throw std::runtime_error("La lista está vacía.");
   }

   Node<T>* actual = p;
   Node<T>* anterior = NULL;

// Recorrer la lista buscando el nodo con valor que coincida con `k`
   while( actual!=NULL&&cmpTK(actual->info,k)!=0 )
   {
      anterior = actual;       // Guardar el nodo anterior
      actual = actual->sig;    // Avanzar al siguiente nodo
   }

   if( actual==NULL )
   {
      throw std::runtime_error("Elemento no encontrado.");
   }

// Nodo encontrado
   T valorRemovido = actual->info;

   if( anterior==NULL )
   {
      // El nodo a eliminar es el primero
      p = actual->sig;
   }
   else
   {
      // Saltar el nodo a eliminar
      anterior->sig = actual->sig;
   }

   delete actual;  // Liberar la memoria del nodo eliminado
   return valorRemovido;  // Devolver el valor eliminado
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   if( p==NULL )
   {
      throw std::runtime_error("La lista está vacía.");
   }

   Node<T>* temp = p;   // Guardar el nodo que vamos a eliminar
   T valorRemovido = p->info;  // Almacenar el valor del nodo a eliminar

   p = p->sig;  // Avanzar el puntero para que apunte al siguiente nodo

   delete temp;  // Liberar la memoria del nodo eliminado

   return valorRemovido;  // Devolver el valor del nodo eliminado
}
template <typename T, typename K>
Node<T>* find(Node<T>* p, K k, int cmpTK(T, K))
{
   Node<T>* actual = p;  // Empezar desde el primer nodo

   while( actual!=NULL )
   {
      // Usar la función de comparación para ver si el nodo actual contiene el valor buscado
      if( cmpTK(actual->info,k)==0 )
      {
         return actual;  // Si encontramos el nodo, devolver la dirección
      }
      actual = actual->sig;  // Avanzar al siguiente nodo
   }

   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
   Node<T>* nuevo = new Node<T>(e);  // Crear un nuevo nodo con el elemento e

// Si la lista está vacía o el nuevo elemento debe ir antes del primer nodo
   if( p==NULL||cmpTT(e,p->info)<0 )
   {
      nuevo->sig = p;  // El nuevo nodo apunta al primer nodo actual
      p = nuevo;       // p apunta al nuevo nodo
      return nuevo;    // Retornar la dirección del nodo insertado
   }

// Si el nuevo elemento debe ir en el medio o al final de la lista
   Node<T>* actual = p;

// Recorrer la lista hasta encontrar la posición correcta
   while( actual->sig!=NULL&&cmpTT(e,actual->sig->info)>=0 )
   {
      actual = actual->sig;
   }

// Insertar el nuevo nodo en la posición encontrada
   nuevo->sig = actual->sig;  // El nuevo nodo apunta al siguiente nodo
   actual->sig = nuevo;       // El nodo actual apunta al nuevo nodo

   return nuevo;  // Retornar la dirección del nodo insertado
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
   Node<T>* actual = p;
   Node<T>* anterior = NULL;

// Recorrer la lista buscando el nodo con valor e
   while( actual!=NULL&&cmpTT(actual->info,e)<0 )
   {
      anterior = actual;
      actual = actual->sig;
   }

// Si encontramos el nodo con el valor e
   if( actual!=NULL&&cmpTT(actual->info,e)==0 )
   {
      enc = true;  // El valor ya estaba en la lista
      return actual;  // Retornar el nodo encontrado
   }

// Si no encontramos el valor, insertarlo de manera ordenada
   enc = false;

// Crear el nuevo nodo y asignar el valor
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;  // Asignar el valor
   nuevo->sig = NULL;  // Inicializar el siguiente puntero a NULL

// Caso cuando el elemento debe insertarse al principio
   if( anterior==NULL )
   {
      nuevo->sig = p;
      p = nuevo;
   }
   else
   {
      // Insertar el nuevo nodo entre anterior y actual
      nuevo->sig = anterior->sig;
      anterior->sig = nuevo;
   }

   return nuevo;  // Retornar el nodo recién insertado
}
template <typename T>
Node<T>* split(Node<T>* source)
{
   Node<T>* fast = source->sig;
   Node<T>* slow = source;

   while( fast!=NULL )
   {
      fast = fast->sig;
      if( fast!=NULL )
      {
         slow = slow->sig;
         fast = fast->sig;
      }
   }

   Node<T>* middle = slow->sig;
   slow->sig = NULL;
   return middle;
}
template <typename T>
Node<T>* merge(Node<T>* left, Node<T>* right, int cmpTT(T, T))
{
   if( left==NULL )
      return right;
   if( right==NULL )
      return left;

   if( cmpTT(left->info,right->info)<=0 )
   {
      left->sig = merge(left->sig,right,cmpTT);
      return left;
   }
   else
   {
      right->sig = merge(left,right->sig,cmpTT);
      return right;
   }
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
   if( p==NULL||p->sig==NULL )
   {
      return; // Lista vacía o con un solo elemento
   }

   Node<T>* middle = split(p);
   Node<T>* left = p;
   Node<T>* right = middle;

   sort(left,cmpTT);
   sort(right,cmpTT);

   p = merge(left,right,cmpTT);
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   if( p->sig!=NULL )
   {
      return false;
   }
   return true;
}

template <typename T>
void free(Node<T>*& p)
{
   Node<T>* actual = p;

   // Recorrer la lista y liberar cada nodo
   while( actual!=NULL )
   {
      Node<T>* temp = actual;  // Guardar referencia al nodo actual
      actual = actual->sig;    // Mover al siguiente nodo
      delete temp;             // Liberar el nodo actual
   }

   // Asignar NULL al puntero principal
   p = NULL;
}

template <typename T>
Node<T>* push(Node<T>*& p, T e)
{
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;
   nuevo->sig = p;
   p = nuevo;
   return nuevo;
}

template <typename T> T pop(Node<T>*& p)
{
   if( p==NULL )
   {
      throw std::out_of_range("La lista está vacía");
   }

   // Guardar el valor del primer nodo
   T valor = p->info;

   // Guardar el puntero al primer nodo
   Node<T>* temp = p;

   // Mover el puntero p al siguiente nodo
   p = p->sig;

   // Liberar el espacio del nodo removido
   delete temp;

   // Retornar el valor del nodo removido
   return valor;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T e)
{
   // Crear un nuevo nodo
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;
   nuevo->sig = NULL;  // El nuevo nodo será el último, por lo que su siguiente es NULL

   // Si la lista está vacía (p y q son NULL)
   if( p==NULL )
   {
      p = nuevo;  // El nuevo nodo será tanto el primer como el último nodo
      q = nuevo;
   }
   else
   {
      q->sig = nuevo;  // El nodo que antes era el último ahora apunta al nuevo nodo
      q = nuevo;       // Actualizar el puntero al último nodo
   }

   return nuevo;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{  // Crear un nuevo nodo
   Node<T>* nuevo = new Node<T>;
   nuevo->info = e;

   if( q==NULL )
   {
      // Si la lista está vacía, el nuevo nodo se enlaza a sí mismo
      nuevo->sig = nuevo;
      q = nuevo;
   }
   else
   {
      // El nuevo nodo apunta al primer nodo
      nuevo->sig = q->sig;
      // El último nodo actual (q) apunta al nuevo nodo
      q->sig = nuevo;
      // Ahora, q se actualiza para apuntar al nuevo nodo
      q = nuevo;
   }

   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   // Verificar si la lista está vacía
   if( p==NULL )
   {
      throw std::runtime_error("Error: La lista está vacía.");
   }

   // Guardar el valor del nodo que se va a eliminar
   T valor = p->info;

   // Caso especial: Si hay un solo nodo en la lista (p y q apuntan al mismo nodo)
   if( p==q )
   {
      delete p;
      p = q = NULL;  // La lista queda vacía
   }
   else
   {
      // Si hay más de un nodo en la lista
      Node<T>* temp = p;    // Guardar el nodo a eliminar
      p = p->sig;           // Mover p al siguiente nodo
      q->sig = p;           // Actualizar q->sig para que apunte al nuevo primer nodo
      delete temp;          // Eliminar el nodo que fue removido
   }

   return valor;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   if( q==NULL )
   {
      throw std::runtime_error("Error: La lista está vacía.");
   }

   // Apuntar al primer nodo de la lista
   Node<T>* p = q->sig;

   // Guardar el valor del nodo que se va a eliminar
   T valor = p->info;

   // Caso especial: Si hay un solo nodo en la lista
   if( p==q )
   {
      delete p;
      q = NULL;  // La lista queda vacía
   }
   else
   {
      // Si hay más de un nodo en la lista
      q->sig = p->sig;  // Actualizar el último nodo para apuntar al nuevo primer nodo
      delete p;         // Eliminar el nodo que fue removido
   }

   return valor;
}

#endif
