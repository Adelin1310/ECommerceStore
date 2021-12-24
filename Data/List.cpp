#include<List.h>

template <typename T>
Store::List<T>::List<T>(T item){
    this->item = item;
}

template <typename T>
T Store::List<T>::GetItem(){
    return this->item;
}

template <typename T>
void Store::List<T>::InsertNode(List<T>* newNode){
    newNode->previousNode = this;
}