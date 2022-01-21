#include "TBinaryTree.h"
#include "string"

template<class T>
TBinaryTree<T>::TBinaryTree() {
    this->root = nullptr;
    std::shared_ptr<Hexagon> octEnd = std::make_shared<Hexagon>();
    //std::cout << "In TBTree: in constructor before NULL_OCT\n";
    //this->treeEnd = std::make_shared<TBinaryTreeItem<T>>(TBinaryTreeItem<T>(octEnd));
}

template<class T>
void recursiveCopying(std::shared_ptr<TBinaryTreeItem<T>> parItem, std::shared_ptr<TBinaryTreeItem<T>> curItem,
                      std::shared_ptr<TBinaryTreeItem<T>> otherItem, bool isLeftChild){
    if (otherItem != nullptr){
        curItem = std::make_shared<TBinaryTreeItem<T>>(TBinaryTreeItem<T>(otherItem));
        if (isLeftChild){
            parItem->SetLeft(curItem);
        }
        else{
            parItem->SetRight(curItem);
        }
        recursiveCopying(curItem, curItem->GetLeft(), otherItem->GetLeft(), true);
        recursiveCopying(curItem, curItem->GetRight(), otherItem->GetRight(), false);
    }
}

template<class T>
TBinaryTree<T>::TBinaryTree(TBinaryTree<T>& otherBinTree){
    this->root = std::make_shared<TBinaryTreeItem<T>>(TBinaryTreeItem<T>(otherBinTree.root));
    recursiveCopying(this->root, this->root->GetLeft(), otherBinTree.root->GetLeft(), true);
    recursiveCopying(this->root, this->root->GetRight(), otherBinTree.root->GetRight(), false);
}

template<class T>
void TBinaryTree<T>::Push(const std::shared_ptr<T>& data){
    bool needChangeEnd = true;
    if (this->root == nullptr){
        this->root = std::make_shared<TBinaryTreeItem<T>>(TBinaryTreeItem<T>(data));
        //root->SetRight(treeEnd);
    }
    else if (*this->root->GetData() == *data){
        ++this->root->counter;
    }
    else{
        std::shared_ptr<TBinaryTreeItem<T>> parent = this->root;
        std::shared_ptr<TBinaryTreeItem<T>> curItem;
        bool childInLeft = true;
        if (data->GetArea() < parent->GetData()->GetArea()) {
            curItem = this->root->GetLeft();
            needChangeEnd = false;
        }
        else {
            curItem = this->root->GetRight();
            childInLeft = false;
        }
        while (curItem != nullptr){ // while we are not in needed place in tree
            if (*curItem->GetData() == *data){ // if all points are same
                ++curItem->counter;
                return;
            }
            else { // compare with area
                if (data->GetArea() < curItem->GetData()->GetArea()){ // go to left child
                    parent = curItem;
                    curItem = parent->GetLeft();
                    childInLeft = true;
                    needChangeEnd = false;
                }
                else { // go to right child
                    parent = curItem;
                    curItem = parent->GetRight();
                    childInLeft = false;
                }
            }
        }
        curItem = std::make_shared<TBinaryTreeItem<T>>(TBinaryTreeItem<T>(data));
        //if (needChangeEnd)
            //curItem->SetRight(treeEnd);
        if (childInLeft){ // set the pointers
            parent->SetLeft(curItem);
        }
        else{
            parent->SetRight(curItem);
        }
    }
}

template<class T>
void TBinaryTree<T>::Pop(const std::shared_ptr<T>& data){
    std::shared_ptr<TBinaryTreeItem<T>> deletedItem = root;
    bool needChangeEnd = true;
    if (root != nullptr) { // if tree isn't empty
        std::shared_ptr<TBinaryTreeItem<T>> parentDelItem = root;
        bool isLeftLeaf = true; // will need this var in delete leaf
        while (deletedItem != nullptr && !(*deletedItem->GetData() == *data)) {
            if (deletedItem != root){
                parentDelItem = deletedItem;
            }
            if (data->GetArea() < deletedItem->GetData()->GetArea()) {
                deletedItem = deletedItem->GetLeft();
                isLeftLeaf = true;
                needChangeEnd = false;
            } else {
                deletedItem = deletedItem->GetRight();
                isLeftLeaf = false;
            }

        }
        if (deletedItem == nullptr) {
            throw std::invalid_argument("There isn't such hexagon in tree!");
        }
        if (deletedItem->counter > 1){
            --deletedItem->counter;
            return;
        }
        else {
            if (deletedItem->GetLeft() != nullptr){ // check left subtree
                std::shared_ptr<TBinaryTreeItem<T>> largestChild = deletedItem->GetLeft();
                if (largestChild->GetRight() != nullptr) { // if he isn't the largest child himself
                    std::shared_ptr<TBinaryTreeItem<T>> parent = largestChild;
                    largestChild = parent->GetRight();
                    while (largestChild->GetRight() != nullptr) {
                        parent = largestChild;
                        largestChild = largestChild->GetRight();
                    }
                    // here we swap the values in deleted item and largest child and change pointers to children
                    deletedItem->counter = largestChild->counter;
                    deletedItem->SetData(largestChild->GetData());
                    // in fact, we don't delete deletedItem, we delete the largest child and put his values to deletedItem
                    parent->SetRight(largestChild->GetLeft());
                    //delete largestChild;
                    largestChild = nullptr;
                }
                else{ // if he is the largest child himself. Parent is unnecessary
                    deletedItem->counter = largestChild->counter;
                    //largestChild->counter = tmpCounter;
                    deletedItem->SetData(largestChild->GetData());
                    deletedItem->SetLeft(largestChild->GetLeft());
                    //delete largestChild;
                    largestChild = nullptr;
                }
            }
            else if (deletedItem->GetRight() != nullptr){ // check right subtree
                std::shared_ptr<TBinaryTreeItem<T>> leastChild = deletedItem->GetRight();
                if (leastChild->GetLeft() != nullptr) { // if he isn't the least child himself
                    std::shared_ptr<TBinaryTreeItem<T>> parent = leastChild;
                    leastChild = parent->GetLeft();
                    while (leastChild->GetLeft() != nullptr) {
                        parent = leastChild;
                        leastChild = leastChild->GetLeft();
                    }
                    //if (needChangeEnd && deletedItem->GetRight() == leastChild){
                        //deletedItem->SetRight(treeEnd);
                    //}
                    // here we swap the values in deleted item and largest child and change pointers to children
                    deletedItem->counter = leastChild->counter;
                    deletedItem->SetData(leastChild->GetData());
                    // in fact, we don't delete deletedItem, we delete the largest child and put his values to deletedItem
                    parent->SetLeft(leastChild->GetRight());
                    //delete leastChild;
                    leastChild = nullptr;
                }
                else{ // if he is the least child himself
                    deletedItem->counter = leastChild->counter;
                    deletedItem->SetData(leastChild->GetData());
                    deletedItem->SetRight(leastChild->GetRight());
                    //delete leastChild;
                    leastChild = nullptr;
                }
            }
            else{ // if deleted item is a leaf
                if (deletedItem == root) {
                    root = nullptr;
                    //delete root;
                }
                else {
                    deletedItem = nullptr;
                    //delete deletedItem;
                    if (isLeftLeaf)
                        parentDelItem->SetLeft(nullptr);
                    else{
                        //if (needChangeEnd)
                        //    parentDelItem->SetRight(treeEnd);
                        //else
                            parentDelItem->SetRight(nullptr);
                    }

                    //deletedItem = nullptr;
                }
            }
        }
    }
    else {
        std::cout << "Tree is empty!\n";
    }
}

template<class T>
void recursiveCount(const std::shared_ptr<T>& data, std::shared_ptr<TBinaryTreeItem<T>> curItem, int& ans){
    if (curItem != nullptr){
        recursiveCount(data, curItem->GetLeft(), ans);
        recursiveCount(data, curItem->GetRight(), ans);
        if (*curItem->GetData() == *data){
            ans += curItem->counter;
        }
    }
}

template<class T>
int TBinaryTree<T>::Count(const std::shared_ptr<T>& data){
    int ans = 0;
    recursiveCount(data, root, ans);
    return ans;
}

template<class T>
void recursiveClear(std::shared_ptr<TBinaryTreeItem<T>> curItem){
    if (curItem != nullptr){
        recursiveClear(curItem->GetLeft());
        recursiveClear(curItem->GetRight());
        //delete curItem;
        curItem = nullptr;
    }
}

template<class T>
void TBinaryTree<T>::Clear(){
    recursiveClear(root);
    //delete root;
    root = nullptr;
}

template<class T>
bool TBinaryTree<T>::Empty(){
    return root == nullptr;
}

template<class T>
std::shared_ptr<T> TBinaryTree<T>::GetItemNotLess(double area) {
    std::shared_ptr<TBinaryTreeItem<T>> curItem = root;
    while (curItem != nullptr){
        if (curItem->GetData()->GetArea() >= area){
            return curItem->GetData();
        }
        else {
            curItem = curItem->GetRight();
        }
    }
    throw std::out_of_range("Passed area is bigger then maximum in tree!");

}

template<class T>
void recursivePrint(std::ostream& out, std::shared_ptr<TBinaryTreeItem<T>> curItem){
    if (curItem != nullptr){
        out << curItem->counter << "*" << std::setprecision(5) << curItem->GetData()->GetArea();
        if (curItem->GetLeft() != nullptr || curItem->GetRight() != nullptr){
            out << ": [";
        }

        recursivePrint(out, curItem->GetLeft());

        if (curItem->GetLeft() != nullptr && curItem->GetRight() != nullptr){
            out << ", ";
        }
        recursivePrint(out, curItem->GetRight());
        if (curItem->GetLeft() != nullptr || curItem->GetRight() != nullptr)
            out << "]";
    }
}

template<class T>
std::ostream& operator << (std::ostream& out, TBinaryTree<T>* tree){
    if (tree == nullptr){
        out << "Tree is null" << std::endl;
    }
    else if (tree->root == nullptr){
        out << "Tree is empty\n";
    }
    else{
        recursivePrint(out, tree->root);
        out << std::endl;
    }
    return out;
}

template<class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::GetRoot(){
    return root;
}

template<class T>
TIterator<TBinaryTreeItem<T>, T> TBinaryTree<T>::begin(){
    std::shared_ptr<TBinaryTreeItem<T>> beginItem = root;
    while(beginItem->GetLeft() != nullptr){
        beginItem = beginItem->GetLeft();
    }
    return TIterator<TBinaryTreeItem<T>, T>(beginItem);
}

template<class T>
TIterator<TBinaryTreeItem<T>, T> TBinaryTree<T>::end(){
    return TIterator<TBinaryTreeItem<T>, T>(treeEnd);
}

template<class T>
TBinaryTree<T>::~TBinaryTree<T>() {
    std::cout << "Destructor TBinaryTree was called\n";
    Clear();
}

template class TBinaryTree<Hexagon>;
template std::ostream& operator <<(std::ostream &out, TBinaryTree<Hexagon>* tree);