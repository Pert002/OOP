#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "hexagon.h"

template <class T>
class TBinaryTreeItem {
public:
TBinaryTreeItem(const T& hexagon);
TBinaryTreeItem(const TBinaryTreeItem<T>& other);
T& GetHexagon();
void SetHexagon(T& hexagon);
std::shared_ptr<TBinaryTreeItem<T>> GetLeft();
std::shared_ptr<TBinaryTreeItem<T>> GetRight();
void SetLeft(std::shared_ptr<TBinaryTreeItem<T>> item);
void SetRight(std::shared_ptr<TBinaryTreeItem<T>> item);
void SetHexagon(const T& hexagon);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

template<class A>
friend std::ostream &operator<<(std::ostream &os, const TBinaryTreeItem<A> &obj);

private:
T hexagon;
std::shared_ptr<TBinaryTreeItem<T>> left;
std::shared_ptr<TBinaryTreeItem<T>> right;
int counter;
};
#endif