#pragma once

namespace Store
{
    template <typename T>
    class List{
        public:
        List<T>(T item);
        ~List<T>();
        void InsertNode(List<T>* newNode);
        List<T>* GetPreviousNode();
        T GetItem();
        private:
        List<T>* previousNode;
        T item;
    };
} // namespace Store
