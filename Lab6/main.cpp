#include <iostream>
#include "TBinaryTree.h"
int main() {
    int command;
    std::vector<std::shared_ptr<Hexagon>> addedHexagons;
    TBinaryTree<Hexagon>* tree = nullptr;
    int numOfItem = 0;
    while(true){
        std::cout << "----------------MENU----------------\n";
        std::cout << "0 : Exit the program" << "\n"; 
        std::cout << "1 : Add hexagon in tree\n"; 
        std::cout << "2 : Get first item with area not less than entered\n"; 
        std::cout << "3 : Get number of entries of hexagon by the queue number of your input\n"; 
        std::cout << "4 : Get the first item with area not less entered and delete it\n"; 
        std::cout << "5 : Clear tree\n"; 
        std::cout << "6 : Create tree from another tree\n"; 
        std::cout << "7 : Print tree\n"; 
        std::cout << "8 : Create tree\n"; 
        std::cout << "9 : Delete tree\n"; 
        std::cout << "10 : Use iterators\n";
        std::cin >> command;

        switch (command) {
            case 0:{
                delete tree;
                return 0;
            }
            case 1:{
                std::cout << numOfItem + 1 << ".\n";
                std::shared_ptr<Hexagon> oct = std::make_shared<Hexagon>();
                std::cin >> *oct;
                std::cout << oct->GetArea() << std::endl;
                addedHexagons.push_back(oct);
                ++numOfItem;
                tree->Push(oct);
                break;
            }
            case 2:{
                double area;
                std::cout << "Enter the area:\n";
                std::cin >> area;
                try{
                    std::shared_ptr<Hexagon> oct = tree->GetItemNotLess(area);
                    std::cout << *oct << "(its area = " << std::setprecision(5) << oct->GetArea() << ")" << std::endl;
                }
                catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            }
            case 3:{
                int num;
                std::cout << "Enter the index number of entered items:\n";
                std::cin >> num;
                std::cout << *addedHexagons[num - 1] << "with area = " << std::setprecision(4) <<
                          addedHexagons[num - 1]->GetArea() << " meets " <<
                          tree->Count(addedHexagons[num - 1]) << " times in tree\n";
                break;
            }
            case 4:{
                double area;
                std::cout << "Enter the area:\n";
                std::cin >> area;
                try{
                    std::shared_ptr<Hexagon> deletedOct = tree->GetItemNotLess(area);
                    tree->Pop(deletedOct);
                }
                catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            }
            case 5:{
                tree->Clear();
                numOfItem = 0;
                break;
            }
            case 6:{
                TBinaryTree<Hexagon>* otherTree = new TBinaryTree<Hexagon>;
                std::cout << "Copied: " << otherTree;
                delete otherTree;
                break;
            }
            case 7:{
                std::cout << tree;
                break;
            }
            case 8:{
                tree = new TBinaryTree<Hexagon>();
                break;
            }
            case 9:{
                delete tree;
                tree = nullptr;
                numOfItem = 0;
                break;
            }
            case 10:{
                TIterator<TBinaryTreeItem<Hexagon>, Hexagon> iterator(tree->GetRoot());
                std:: cout << "Iterator points on hexagon: " << *iterator << std:: endl;
                iterator.GoToLeft();
                std:: cout << "Its left descendant: ";
                std:: cout << *iterator << std:: endl;
                iterator.GoToRight();
                std:: cout << "Its right descendant: " << *iterator << std:: endl;
                TIterator<TBinaryTreeItem<Hexagon>, Hexagon> iterA(tree->GetRoot()->GetLeft());
                TIterator<TBinaryTreeItem<Hexagon>, Hexagon> iterB(tree->GetRoot()->GetLeft());
                if (iterA == iterB) {
                    std:: cout << "Comparison of iterators is working: 1" << std::endl;
                }
                TIterator<TBinaryTreeItem<Hexagon>, Hexagon> iterC(tree->GetRoot()->GetRight());
                if (iterC != iterA) {
                    std:: cout << "Comparison of iterators is working: 2" << std::endl;
                }
                break;
            }
        }
    }
}
