#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   Node<T>* top;  // Puntero al nodo superior de la pila
   int size;      // Tamaño de la pila
};

template <typename T>
Stack<T> stack()
{
   return Stack<T>();
}

template <typename T>
T* stackPush(Stack<T>& st, T e)
{
   Node<T>* newNode = new Node<T>(e,st.top);  // Crear un nuevo nodo que apunte al nodo anterior
   st.top = newNode;  // El nuevo nodo es el nuevo top
   st.size++;  // Incrementar el tamaño de la pila
   return &(newNode->info);  // Retornar la dirección del elemento recién apilado
}

template <typename T>
T stackPop(Stack<T>& st)
{

   Node<T>* nodeToRemove = st.top;
   T element = nodeToRemove->info;  // Guardar el elemento antes de eliminar el nodo
   st.top = nodeToRemove->sig;  // Mover el top al siguiente nodo
   delete nodeToRemove;  // Eliminar el nodo
   st.size--;  // Decrementar el tamaño de la pila
   return element;  // Retornar el elemento desapilado
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.top==nullptr;
}

template <typename T>
int stackSize(Stack<T> st)
{
   return st.size;
}

#endif
