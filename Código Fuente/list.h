#ifndef _list_
#define _list_

#include <iostream>
#include "node.h"

using namespace std;

template <class T>

class List {
    private:
        int count = 0;
        Node<T>* first;
        Node<T>* last;
        Node<T>* current;

    public:
        List() {
            this->first = nullptr;
            this->last = nullptr;
            this->current = nullptr;
            this->count = 0;
        }

        void addToEnd(T &pValue) {
            Node<T>* newNode = nullptr;
            newNode = new Node<T>(pValue);
            if(this->last != nullptr) {
                this->last->setNextNode(newNode);
                this->last = newNode;
            } else {
                this->first = newNode;
                this->last = newNode;
            }
            this->count++;
            this->current = this->first;
        }

        void addToBeginning(T &pValue) {
            Node<T>* newNode = nullptr;
            newNode = new Node<T>(pValue);
            if(this->first != nullptr) {
                newNode->setNextNode(this->first);
                this->first = newNode;
            } else {
                this->first = newNode;
                this->last = newNode;
            }
            this->count++;
            this->current = this->first;
        }

        void removeFirstElement() {
            if(this->first != nullptr) {
                // Pongo un puntero al primero
                Node<T>* temporal = this->first;
                /* Ahora mi puntero first va a apuntar al que esta siguiente al primero, 
                que va a ser el nuevo primero */
                this->first = this->first->getNextNode();
                //Borro el primero
                delete(temporal);
                /* Esta linea la puse porque el cout en el main, se hace a partir 
                del current, que dijo el profe que el lo usaba siempre en el primer elemento */
                this->current = this->first;
            }
        }
        
        void removeLastElement() {
            if(this->last != nullptr) {
                Node<T>* temporal;
                Node<T>* auxiliar = this->first;
                /* Con este ciclo llevo al auxiliar al nodo que está antes del 
                último (el que voy a borrar) */
                while(auxiliar->getNextNode() != this->last) {
                    auxiliar = auxiliar->getNextNode();
                }
                // El último ahora va a ser el penúltimo, porque el último lo voy a borrar
                this->last = auxiliar;
                // En temporal almaceno el ultimo nodo, que es el que voy a borrar
                temporal = auxiliar->getNextNode();
                //Pongo al auxiliar, que ahora va a ser el ultimo, a apuntar a null
                auxiliar->setNextNode(nullptr);
                // Borro temporal (el último nodo)
                delete(temporal);
            }
        }

        T getFirst() {
            this->current = this->first;
            return (T)(*this->first).getValue();
        }

        T getLast() {
            this->current = this->first;
            return (T)(*this->last).getValue();
        }

        T getNext() {
            T result = (*this->current).getValue();
            this->current = this->current->getNextNode();
            return result;
        }

        int getCount() {
            return this->count;
        }

        bool hasMore() {
            bool result = this->current != nullptr;
            this->current = !result? this->first : this->current; //result? this->current : this->first; 
            return result;
        }

};

#endif
