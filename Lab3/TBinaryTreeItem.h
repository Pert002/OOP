#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "hexagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Hexagon& hexagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
virtual ~TBinaryTreeItem();
Hexagon hexagon;
std::shared_ptr<TBinaryTreeItem> left;
std::shared_ptr<TBinaryTreeItem> right;
int counter;
};
#endif