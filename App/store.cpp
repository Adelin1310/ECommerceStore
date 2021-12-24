#include <iostream>
#include <fstream>
#include "Cart.h"
#include "Category.h"
#include "Product.h"
#include "User.h"
#include "sfunc.h"

bool EXIT = false;

bool Initialize(){
    return true;
}

void Run(){


    while(!EXIT);
}


int main()
{
    Store::Initialize();
    while(true){
        Run();
    }
    return 0;
}
