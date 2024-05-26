#include "../BalancedBinaryTreeDeclaration.h"
#include "../BalancedBinaryTreeDefinition.h"
#include "../functions.h"
#include "../LinkedListDefinition.h"
#include <time.h>
#include <iostream>
#include <fstream>

void TestSpeedInsert()
{   std::ofstream FileOut("TestsSpeedInsert.txt",std::ios::app);
    if(!FileOut.is_open())
    {
        std::cout << "did not managed to open file\n";
        return;
    }
    FileOut << "на каждый размер бинарного сбалансированного дерева поиска функция будет вызвана 1000\n \
    для получения читаемых данных\n";
    FileOut <<"function insert\n";
    BalancedBinaryTree<int> tree;
    for(int i = 0; i < 100000;i++)
        tree.insert(i);
    clock_t start = clock();
    for(int i = 0; i < 1000;i++)
    tree.insert(rand());
    clock_t end = clock();
    FileOut << "10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 5*100000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.insert(rand());
     end = clock();
    FileOut << "5*10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 5*1000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.insert(rand());
     end = clock();
    FileOut << "5*10^6\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 5*10000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.insert(rand());
     end = clock();
    FileOut << "5*10^7\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();*/
     
}
void TestSpeedRemove()
{   std::ofstream FileOut("TestsSpeedRemove.txt",std::ios::app);
    if(!FileOut.is_open())
    {
        std::cout << "did not managed to open file\n";
        return;
    }
    FileOut << "на каждый размер бинарного сбалансированного дерева поиска функция будет вызвана 1000\n \
    для получения читаемых данных\n";
    FileOut <<"function remove\n";
    BalancedBinaryTree<int> tree;
    for(int i = 0; i < 5*10000;i++)
        tree.insert(i);
    clock_t start = clock();
    for(int i = 0; i < 1000;i++)
    tree.Remove(rand());
    clock_t end = clock();
    FileOut << "5*10^4\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i <100000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.Remove(rand());
     end = clock();
    FileOut << "10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 5*1000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.Remove(rand());
     end = clock();
    FileOut << "5*10^6\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i <5* 10000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.Remove(rand());
     end = clock();
    FileOut << "5*10^7\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree(); */
}
void TestSpeedMap()
{   std::ofstream FileOut("TestsSpeedMap.txt",std::ios::app);
    if(!FileOut.is_open())
    {
        std::cout << "did not managed to open file\n";
        return;
    }
    //FileOut << "на каждый размер бинарного сбалансированного дерева поиска функция будет вызвана 1  раз\n \
    //для получения читаемых данных\n";
     // FileOut <<"function Map\n";
    BalancedBinaryTree<int> tree;
    for(int i = 0; i < 10000;i++)
        tree.insert(i);
    clock_t start = clock();
    //for(int i = 0; i < 1000;i++)
    tree.Map(FooMap);
    clock_t end = clock();
    FileOut << "10^4\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 100000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
        tree.Map(FooMap);
     end = clock();
    FileOut << "10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 1000000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
    tree.Map(FooMap);
     end = clock();
    FileOut << "10^6\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 10000000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
        tree.Map(FooMap);
     end = clock();
    FileOut << "10^7\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree(); */
}
void TestSpeedWhere()
{   std::ofstream FileOut("TestsSpeedWhere.txt",std::ios::app);
    if(!FileOut.is_open())
    {
        std::cout << "did not managed to open file\n";
        return;
    }
    //FileOut << "на каждый размер бинарного сбалансированного дерева поиска функция будет вызвана 1  раз\n \
    для получения читаемых данных\n";
    //  FileOut <<"function Where\n";
    BalancedBinaryTree<int> tree;
    for(int i = 0; i < 10000;i++)
        tree.insert(i);
    clock_t start = clock();
    //for(int i = 0; i < 1000;i++)
    tree.Where(FooWhere);
    clock_t end = clock();
    FileOut << "10^4\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 100000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
        tree.Map(FooMap);
     end = clock();
    FileOut << "10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 1000000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
    tree.Map(FooMap);
     end = clock();
    FileOut << "10^6\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 10000000;i++)
        tree.insert(i);
     start = clock();
    //for(int i = 0; i < 1000;i++)
        tree.Map(FooMap);
     end = clock();
    FileOut << "10^7\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree(); */
}
void TestSpeedFindElement()
{   std::ofstream FileOut("TestsSpeedFindElement.txt",std::ios::app);
    if(!FileOut.is_open())
    {
        std::cout << "did not managed to open file\n";
        return;
    }
   // FileOut << "на каждый размер бинарного сбалансированного дерева поиска функция будет вызвана 1000 раз\n \
    для получения читаемых данных\n";
   // FileOut <<"function FindElement\n";
   clock_t start;
   clock_t end;
        BalancedBinaryTree<int> tree;
    for(int i = 0; i < 100000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "10^5\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 1000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "10^6\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    for(int i = 0; i < 10000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "10^7\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 100000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "10^8\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();

    /*for(int i = 0; i < 5*100000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "5*10^8\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();
     
    /* for(int i = 0; i < 1000000000;i++)
        tree.insert(i);
     start = clock();
    for(int i = 0; i < 1000;i++)
    tree.FindElement(rand());
     end = clock();
    FileOut << "10^9\t" << (double)(end - start)/(CLOCKS_PER_SEC)<< "\n";
    tree.~BalancedBinaryTree();*/
}