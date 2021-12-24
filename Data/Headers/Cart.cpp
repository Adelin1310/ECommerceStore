#include "Cart.h"

Store::Cart::Cart() : id(overallID++)
{
    this->products = nullptr;
}

void Store::Cart::AddProduct(Store::Product newProduct)
{
    if (this->products == nullptr)
        this->products = new Store::List<Product>(newProduct);
    else
    {
        List<Product> *newNode = new List<Product>(newProduct);
        this->products->InsertNode(newNode);
        this->products = newNode;
    }
}

void Store::Cart::RemoveProduct(unsigned int productID){
    List<Product>* aux = this->products;
    while(aux->GetItem().GetID() != productID || aux != nullptr)
        aux = aux->GetPreviousNode();
}

float Store::Cart::GetTotal()
{
    List<Product> *aux = this->products;
    float sum = 0.00f;
    while (aux != nullptr)
    {
        sum += this->products->GetItem().GetPrice();
        aux = aux->GetPreviousNode();
    }

    return sum;
}