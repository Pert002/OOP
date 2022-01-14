#ifndef LAB3_TBINARY_TREE_H
#define LAB3_TBINARY_TREE_H

#include "TBinaryTreeItem.h"

template<class T> class TBinaryTree {
private:
    std::shared_ptr<TBinaryTreeItem<T>> root;
public:
    TBinaryTree<T>(); 
    TBinaryTree(TBinaryTree<T>& otherBinTree); 
    void Push(const std::shared_ptr<T>& data); 
    void Pop(const std::shared_ptr<T>& data); 
    void Clear(); 
    bool Empty(); 
    int Count(const std::shared_ptr<T>& data); // rewrote, checked
    std::shared_ptr<T> GetItemNotLess(double area); // rewrote with throw, checked
    template<class A> friend std::ostream& operator << (std::ostream &out, TBinaryTree<A>* tree); 
    std::shared_ptr<TBinaryTreeItem<T>> GetRoot();
    virtual ~TBinaryTree();

};


#endif 