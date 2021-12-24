#pragma once

namespace Store{
    class Product{
        private:
        static unsigned int overallID;
        const unsigned int id;
        char* name;
        float price = 0.00f;
        int stock = 0;

        public:
        Product(char* name);
        ~Product();
        void SellItem();
        void ChangePrice(float newPrice);
        float GetPrice();
        unsigned int GetID();
    };
}