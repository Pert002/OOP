#include "TBinaryTreeItem.h"

TBinaryTreeItem::TBinaryTreeItem(const Hexagon &hexagon) {
    this->hexagon = hexagon;
    this->left = this->right = NULL;
    this->counter = 1;
}

TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem &other) {
    this->hexagon = other.hexagon;
    this->left = other.left;
    this->right = other.right;
    this->counter = other.counter;
}

TBinaryTreeItem::~TBinaryTreeItem() {}