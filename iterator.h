#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;

    public:
        Iterator() {
            // TODO
        }

        Iterator(Node<T> *node) {
            current=node;
        }

        Iterator<T> operator=(Iterator<T> other) {          
            current=other->current;
            return other;
        }

        bool operator!=(Iterator<T> other) {
            return this->current!=other->current;
        }

        Iterator<T> operator++() {

        }

        Iterator<T> operator--() {

        }

        T operator*() {
            return current->data;
        }
};

#endif
