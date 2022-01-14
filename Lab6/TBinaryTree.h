#ifndef LAB5_TBINARY_TREE_H
#define LAB5_TBINARY_TREE_H

#include "TBinaryTreeItem.h"
#include "Titerator.h"

template<class T> class TBinaryTree {
private:
    std::shared_ptr<TBinaryTreeItem<T>> root;
    std::shared_ptr<TBinaryTreeItem<T>> treeEnd;
public:
    TBinaryTree<T>(); 
    TBinaryTree(TBinaryTree<T>& otherBinTree); 
    void Push(const std::shared_ptr<T>& data); 
    void Pop(const std::shared_ptr<T>& data); 
    void Clear(); 
    bool Empty(); 
    int Count(const std::shared_ptr<T>& data);
    std::shared_ptr<T> GetItemNotLess(double area); 
    template<class A> friend std::ostream& operator << (std::ostream &out, TBinaryTree<A>* tree); 
    std::shared_ptr<TBinaryTreeItem<T>> GetRoot();

    TIterator<TBinaryTreeItem<T>, T> begin();
    TIterator<TBinaryTreeItem<T>, T> end();

    virtual ~TBinaryTree();

};


#endif //LAB5_TBINARY_TREE_H