#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
        int sz=0;
    public:
        BSTree() : root(nullptr) {};

        bool find(T data) {
            if (root!=nullptr){
                Node<T>* n = root;
                while(n->data!=data){
                    if(data > n->data) {
                        if(n->right)
                            n = n->right;
                        else
                            return false;
                    }

                    if(data < n->data) {
                        if(n->left)
                            n = n->left;
                        else
                            return false;
                    }
                }
                return true;
            }
        } 

        bool insert(T data) {
            if(root==nullptr){
                Node<T>* n = new Node<T>(data);
                root=n;
                this->sz++;
                return true;
            }
            if (!find(data)){
                Node<T>* nodo = new Node<T>(data);
                Node<T>* current = root;
                while(current->left or current->right){
                    if(data > current->data and current->right)
                        current=current->right;
                    else
                        break;

                    if(data < current->data and current->left)
                        current=current->left;
                    else
                        break;
                }
                if(data>current->data)
                    current->right=nodo;
                else
                    current->left=nodo;
                this->sz++;
                return true;
            } else {
                return false;
            }
        }

        bool remove(T data) {
            if(!find(data)){
                this->sz--;
                Node<T>* current=root;
                // ya me rendi
            } else
                return false;
        }

        unsigned int size() {
            return this->sz;
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            Node<T>* current = root;
            while(current->left){
                current=current->left;
            }
            return current;
        }

        Iterator<T> end() {
            Node<T>* current = root;
            while(current->right){
                current=current->right;
            }
            return current;
        }

        ~BSTree() {
           root->SuicidioMasivo();
        }
};

#endif
