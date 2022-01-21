#include "TbinaryTreeItem.h"
template<class T>
TBinaryTreeItem<T>::TBinaryTreeItem(const std::shared_ptr<T>& data){
    //std::cout << "In TBItem constructor\n";
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->counter = 1;
}

template<class T>
TBinaryTreeItem<T>::TBinaryTreeItem(std::shared_ptr<TBinaryTreeItem<T>>& other) {
    this->data = other->data;
    this->left = other->left;
    this->right = other->right;
    this->counter = other->counter;
}

template <class T>
TAllocationBlock TBinaryTreeItem<T>::stackitem_allocator(sizeof(TBinaryTreeItem<T>), 100);

template<class T>
std::shared_ptr<T> TBinaryTreeItem<T>::GetData() {
    return this->data;
}

template<class T>
void TBinaryTreeItem<T>::SetData(const std::shared_ptr<T>& data) {
    this->data = data;
}

template<class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::GetLeft() {
    if (this != nullptr){
        return this->left;
    }
    else
        return nullptr;
}

template<class T>
void TBinaryTreeItem<T>::SetLeft(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem) {
    if (this != nullptr){
        this->left = tBinTreeItem;
    }
}

template<class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::GetRight() {
    if (this != nullptr){
        return this->right;
    }
    else
        return nullptr;
}

template<class T>
void TBinaryTreeItem<T>::SetRight(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem) {
    if (this != nullptr){
        this->right = tBinTreeItem;
    }
}

template<class T>
std::ostream& operator << (std::ostream& out, std::shared_ptr<TBinaryTreeItem<T>> treeItem){
    if (treeItem != nullptr){
        out << treeItem->counter << '*' << std::setprecision(5) << treeItem->GetData()->GetArea();
    }
    else {
        out << "null";
    }
    return out;
}

template <class T>
void* TBinaryTreeItem<T>::operator new(size_t size) {
    return stackitem_allocator.allocate();
}

template <class T>
void TBinaryTreeItem<T>::operator delete(void* p) {
    stackitem_allocator.deallocate(p);
}

template<class T>
TBinaryTreeItem<T>::~TBinaryTreeItem<T>() {
    //std::cout << "Destructor TBinaryTreeItem was called\n";
}

template class TBinaryTreeItem<Hexagon>;
template std::ostream& operator <<(std::ostream& out, std::shared_ptr<TBinaryTreeItem<Hexagon>> treeItem);