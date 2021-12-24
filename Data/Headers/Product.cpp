#include "Product.h"
#include "Category.h"

Store::Product::Product(char* name) : id(overallID++){
    this->name = name;
}

void Store::Product::ChangePrice(float newPrice){
    this->price = newPrice;
}

void Store::Product::SellItem(){
    this->stock--;
}

Store::Product::~Product(){
    delete this;
}

float Store::Product::GetPrice(){
    return this->price;
}

unsigned int Store::Product::GetID(){
    return this->id;
}