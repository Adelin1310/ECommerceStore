#pragma once
#include "List.h"

namespace Store{
    class Category{
        private:
        static unsigned int overallID;
        const unsigned int id;
        char* name;
        List<Product>* products;
        public:
        Category(char* name);
        ~Category();
        void AddProduct(Product newProduct);
        void RemoveProduct(Product product);
        List<Product>* GetAllProducts();
    };
}