#ifndef LAB5_TITERATOR_H
#define LAB5_TITERATOR_H


#include <iostream>

template <class node, class T>
class TIterator {
public:
    TIterator(std::shared_ptr<node> n) {
        nodePtr = n;
    }

    std::shared_ptr<node> operator*() {
        return nodePtr;
    }

    std::shared_ptr<T> operator->() {
        return nodePtr->GetData();
    }

    bool operator==(TIterator const& i) {
        return nodePtr == i.nodePtr;
    }

    bool operator!=(TIterator const& i) {
        return !(*this == i);
    }

    void GoToLeft() {
        if (nodePtr == NULL) {
            std:: cout << "Node doesn't exist" << std:: endl;
        }
        else {
            nodePtr = nodePtr->GetLeft();
        }
    }
    void GoToRight() {
        if (nodePtr == NULL) {
            std:: cout << "Node doesn't exist" << std:: endl;
        }
        else {
            nodePtr = nodePtr->GetRight();
        }
    }

private:
    std::shared_ptr<node> nodePtr;
};

#endif //LAB5_TITERATOR_H