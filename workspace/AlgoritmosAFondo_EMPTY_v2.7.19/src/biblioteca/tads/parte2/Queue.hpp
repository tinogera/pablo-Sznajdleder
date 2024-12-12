#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Queue
{
   Node<T>* front;  // Puntero al primer nodo de la cola
   Node<T>* rear;   // Puntero al �ltimo nodo de la cola
   int size;        // Tama�o de la cola
};

template <typename T>
Queue<T> queue()
{
   return Queue<T>();
}

template <typename T>
T* queueEnqueue(Queue<T>& q, T e)
{
   Node<T>* newNode = new Node<T>(e);  // Crear un nuevo nodo con el elemento
   if( q.rear==nullptr )
   {  // Si la cola est� vac�a
      q.front = q.rear = newNode;  // Ambos punteros apuntan al nuevo nodo
   }
   else
   {
      q.rear->sig = newNode;  // Enlazar el nuevo nodo al final de la cola
      q.rear = newNode;  // El nuevo nodo se convierte en el �ltimo nodo
   }
   q.size++;  // Incrementar el tama�o de la cola
   return &(newNode->info);  // Retornar la direcci�n del elemento reci�n encolado
}

template <typename T>
T queueDequeue(Queue<T>& q)
{
   if( q.front==nullptr )
   {
      throw std::runtime_error("La cola est� vac�a");  // Manejo de error si la cola est� vac�a
   }

   Node<T>* nodeToRemove = q.front;
   T element = nodeToRemove->info;  // Guardar el elemento antes de eliminar el nodo
   q.front = q.front->sig;  // Mover el front al siguiente nodo
   if( q.front==nullptr )
   {  // Si la cola queda vac�a
      q.rear = nullptr;  // Rear tambi�n debe apuntar a nullptr
   }
   delete nodeToRemove;  // Eliminar el nodo
   q.size--;  // Decrementar el tama�o de la cola
   return element;  // Retornar el elemento desencolado
}

template <typename T>
bool queueIsEmpty(Queue<T> q)
{
   return q.front==nullptr;
}

template <typename T>
int queueSize(Queue<T> q)
{
   return q.size;
}

#endif
