#pragma once

#include "List.h"
#include "Product.h"

namespace Store{
    class Cart{
        public:
        Cart();
        ~Cart();
        float GetTotal();
        void AddProduct(Product newProduct);
        void RemoveProduct(unsigned int productID);
        void ClearCart();
        private:
        static unsigned int overallID;
        const unsigned int id;
        List<Product>* products;
        float Total = 0.00f;
    };
}