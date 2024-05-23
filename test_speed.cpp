#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"
#include <time.h>
#include <iostream>

void TestSpeed()
{   
    BalancedBinaryTree<int> tree;
    for(int i = 0; i < 10000;i++)
        tree.insert(i);
    clock_t start = clock();
    for(int i = 0; i < 10000000;i++)
    tree.insert(4553);
    clock_t end = clock();
    std:: cout << (double)(end - start)/CLOCKS_PER_SEC << "\n";
    tree.~BalancedBinaryTree();
    
    for(int i = 0; i < 100000;i++)
        tree.insert(i);
    start = clock();
    for(int i = 0; i < 10000000;i++)
    tree.insert(45535);
    end = clock();
    std:: cout << (double)(end - start)/CLOCKS_PER_SEC << "\n";
    tree.~BalancedBinaryTree();
    
    for(int i = 0; i < 1000000;i++)
        tree.insert(i);
    start = clock();
    for(int i = 0; i < 10000000;i++)
    tree.insert(455351);
    end = clock();
    std:: cout << (double)(end - start)/CLOCKS_PER_SEC << "\n";
    tree.~BalancedBinaryTree();
    
    for(int i = 0; i < 10000000;i++)
        tree.insert(i);
    start = clock();
    for(int i = 0; i < 10000000;i++)
    tree.insert(4553510);
    end = clock();
    std:: cout << (double)(end - start)/CLOCKS_PER_SEC << "\n";
}