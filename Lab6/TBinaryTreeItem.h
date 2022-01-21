#ifndef LAB6_TBINARY_TREE_ITEM_H
#define LAB6_TBINARY_TREE_ITEM_H

#include "hexagon.h" // checked
#include "TAllocationBlock.h"

template<class T> class TBinaryTreeItem {
private:
    std::shared_ptr<T> data;
    std::shared_ptr<TBinaryTreeItem<T>> left;
    std::shared_ptr<TBinaryTreeItem<T>> right;
    static TAllocationBlock stackitem_allocator;

public:
    TBinaryTreeItem<T>(const std::shared_ptr<T>& data);
    TBinaryTreeItem<T>(std::shared_ptr<TBinaryTreeItem<T>>& other);
    std::shared_ptr<T> GetData();
    void SetData(const std::shared_ptr<T>& data);
    std::shared_ptr<TBinaryTreeItem> GetLeft();
    void SetLeft(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem);
    std::shared_ptr<TBinaryTreeItem> GetRight();
    void SetRight(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem);
    template<class A> friend std::ostream& operator << (std::ostream& out, std::shared_ptr<TBinaryTreeItem<A>> treeItem);
    virtual ~TBinaryTreeItem();

    void* operator new(size_t size);
    void operator delete(void* p);

    int counter;
};


#endif //LAB6_TBINARY_TREE_ITEM_H