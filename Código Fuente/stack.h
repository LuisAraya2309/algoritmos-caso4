#ifndef _stack_
#define _stack_

#include "node.h"
#include "list.h"

#include <iostream>

using namespace std;

template <class T>

class Stack : public List<T> {
	public:
		void push(T &pValue){
			this->addToBeginning(pValue);
		}

		void pop(){
            T removed = this->removeFirstElement();
			//cout << removed.getName() << endl;
		}
};

#endif