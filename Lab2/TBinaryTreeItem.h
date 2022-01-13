#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "hexagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Hexagon& hexagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
virtual ~TBinaryTreeItem();
Hexagon hexagon;
TBinaryTreeItem *left;
TBinaryTreeItem *right;
int counter;
};
#endif