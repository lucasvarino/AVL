#include <iostream>
#include "AVL.h"

int main() {
    AVLTree avl;

    avl.root = avl.insert(avl.root, 12);
    avl.root = avl.insert(avl.root, 70);
    avl.root = avl.insert(avl.root, 80);
    avl.root = avl.insert(avl.root, 43);
    avl.root = avl.insert(avl.root, 41);
    avl.root = avl.insert(avl.root, 60);
    avl.root = avl.insert(avl.root, 82);
    avl.root = avl.insert(avl.root, 90);
    avl.root = avl.insert(avl.root, 99);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 64);

    std::cout << "Chaves da árvore AVL em ordem crescente:" << std::endl;
    avl.print();

    return 0;
}

