#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    private:
        T data;
        Node<T> *left=nullptr;
        Node<T> *right=nullptr;
public:
    Node<T>(T d){
        data=d;
    }
    void SuicidioMasivo(){
        if(this->right) this->right->SuicidioMasivo();
        if(this->left) this->left->SuicidioMasivo();
        delete this;
    }
    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif