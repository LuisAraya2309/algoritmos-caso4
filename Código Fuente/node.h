#ifndef _node_
#define _node_ 

#include <iostream>

using namespace std;

template <class T>

class Node {
    private:
        T* data;
        Node<T>* next;

    public:
        Node(T &pData) {
            this->data =  &pData;
            this->next = nullptr;
        }

        T getValue() {
            return (*this->data);
        }

        Node<T>* getNextNode() {
            return this->next;
        }

        void setNextNode(Node<T>* pNext) {
            this->next = pNext;
        }
};

#endif
