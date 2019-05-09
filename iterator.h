#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
template <typename T>
class Iterator {
private:
    Node<T> *current;
    stack<Node<T>*> nodos;
    stack<Node<T>*> past;

public:
    Iterator() {
        current=nullptr;
    }

    Iterator(Node<T> *node) {
        current=node;
        while(current->left){
            nodos.push(current);
            current = current->left;
        }
    }

    Iterator<T> operator=(Iterator<T> other) {
        current=other.current;
        return this;
    }

    bool operator!=(Iterator<T> other) {
        return this->current!=other.current;
    }

    Iterator<T> operator++() {
        past.push(nodos.top());
        nodos.pop();
        if(current->right){
            current=current->right;
            nodos.push(current);
            while(current->left){
                current = current->left;
                nodos.push(current);
            }
        } else {
            current=nodos.top();
        }
        return *this;
    }

    Iterator<T> operator--() {
        nodos.push(past.top());
        past.pop();
        current = nodos.top();
        return *this;
    }

    T operator*() {
        if (current==nullptr)
            throw out_of_range("Iterator is empty");
        return current->data;
    }
};

#endif
