#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
        unsigned int sz=0;
    public:
        BSTree() : root(nullptr) {};

        bool find(T data) {
            if (root!=nullptr){
                Node<T>* n = root;
                while(n->data!=data){
                    if(data > n->data) {
                        if(n->right)
                            n = n->right;
                        else return false;
                    }
                    if(data < n->data) {
                        if(n->left)
                            n = n->left;
                        else return false;
                    }
                }
                return true;
            }
        } 

        bool insert(T data) {
            Node<T>* temp= new Node<T>(data);
            Node<T> **ptr=&root;
            while(*ptr!=nullptr)
            {
                if(data>(*ptr)->data)
                    ptr=&((*ptr)->right);

                if(data<(*ptr)->data)
                    ptr=&((*ptr)->left);
            }
            *ptr=temp;
        }

        bool remove(T data) {
            if(find(data)){
                this->sz--;
                Node<T>* current=root;
                Node<T>** prevptr=&current;
                while(current->data!=data){
                    if(current->data < data) {
                        prevptr = &(current->right);
                        current = current->right;
                    } else {
                        prevptr = &(current->left);
                        current = current->left;
                    }
                }
                if(current->right && current->left){
                    Node<T>* maxleft=current->left;
                    while(maxleft->right!=nullptr){
                        maxleft=maxleft->right;
                    }
                    current->data = maxleft->data;
                    remove(maxleft->data);
                    delete current;
                } else if(current->right || current->left){
                    if(current->right){
                        *prevptr=current->right;
                        delete current;
                    } else if(current->left){
                        *prevptr=current->left;
                        delete current;
                    }
                } else if(!current->right && !current->left){
                    *prevptr=nullptr;
                    delete current;
                }
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
