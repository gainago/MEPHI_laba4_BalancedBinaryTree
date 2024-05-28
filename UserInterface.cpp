#include <iostream>
#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"
#include <cassert>
#include "Structs/Structs.h"
#include "scanfint.cpp"
template<typename Type>
void User()
{
    LinkedList<BalancedBinaryTree<Type>*> MassiveOfTrees;
    int Action = 1;
    int flag = 0;
    while(Action)
    {
        std::cout << "Выберите действие:\n\
        1. Создать сбаленсированное бинарное дерево поиска\n\
        2. Вывести дерево на экран в повернутом виде\n\
        3. Добавить элемент в дерево\n\
        4. Удалить элемент из дерева\n\
        5. Применить функцию Map\n\
        6. Применить функцию Where\n\
        7. Найти поддерево корнем которого является элемент и вывести его \n\
        8. Вывести дерево определенным образом(с помощью обходов)\n\
        9. Получить дерево по двум обходам(NLR,LNR)\n\
        0. Выйти\n\
        ";
        std::cout << "У вас " << MassiveOfTrees.GetLength() << " деревьев" << std::endl;
        do{
            flag = scanfint(&Action);
        }while(flag == -1|| Action > 9 || Action < 0);
        switch (Action)
        {
        case 1:
            {
                std::cout << "Введите количество элементов \n";
                int SizeOfTree = 0;
                do{
                    flag = scanfint(&SizeOfTree);
                }while(flag == -1 || SizeOfTree < 0);
                BalancedBinaryTree<Type>* Tree = new BalancedBinaryTree<Type>;
                std::cout << "Введите " << SizeOfTree << " элементов\n";

                for(int i = 0; i < SizeOfTree; i++)
                {
                    Type data;
                    std::cin >> data;
                    Tree->insert(data);
                }
                MassiveOfTrees.push(Tree);
            }
            break;
            case 2:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        return;
                    }
                    std::cout << "Введите номер дерева(начиная с нуля) \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    MassiveOfTrees.GetIndex(NumberOfTree)->SideOutlet();
                }
            break;
            case 3:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        break;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    std::cout << "Введите элемент который хотите добавить\n";
                    Type data;
                    std::cin >> data;
                    MassiveOfTrees.GetIndex(NumberOfTree)->insert(data);
                }
                break;
            case 4:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        break;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    std::cout << "Введите элемент который хотите удалить\n";
                    Type data;
                    std::cin >> data;
                    MassiveOfTrees.GetIndex(NumberOfTree)->Remove(data);
                    
                }
                break;
            case 5:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        return;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    MassiveOfTrees.GetIndex(NumberOfTree)->Map(FooMap);
                }
                break;
            case 6:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        return;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    MassiveOfTrees.GetIndex(NumberOfTree)->Where(FooWhere);
                }
                break;
            case 7:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        return;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    std::cout << "Введите элемент по которому хотите найти поддерево\n";
                    Type data;
                    std::cin >> data;
                    (MassiveOfTrees.GetIndex(NumberOfTree)->GetSubTreeForElement(data)).SideOutlet();
                }
                break;
            case 8:
                {
                    if(MassiveOfTrees.GetLength() == 0)
                    {
                        std::cout << "У вас нет ни одного созданного дерева\n";
                        return;
                    }
                    std::cout << "Введите номер дерева \n";
                    int NumberOfTree = 0;
                    do{
                        flag = scanfint(&NumberOfTree);
                    }while(flag == -1 || NumberOfTree < 0 || NumberOfTree >= MassiveOfTrees.GetLength());
                    std::cout << "Введите номер обхода:\n\
                    1. КЛП\n\
                    2. КПЛ\n\
                    3. ЛПК\n\
                    4. ЛКП\n\
                    5. ПЛК\n\
                    6. ПКЛ\n";
                    int NumberOfRound = 0;
                    do
                    {
                        flag = scanfint(&NumberOfRound);
                    } while (flag == -1 || NumberOfRound > 6 || NumberOfRound <= 0);
                    LinkedList<Type> List;
                    List = MassiveOfTrees.GetIndex(NumberOfTree)->Represent(NumberOfRound);
                    for(int i = 0; i < List.GetLength();i ++)
                        std:: cout << List.GetIndex(i) << " ";
                    std::cout << "\n";   
                }
                break;
            case 9:
                {
                    std::cout << "Введите количество элементов в обходах \n";
                    int SizeOfRound = 0;
                    do{
                        flag = scanfint(&SizeOfRound);
                    }while (flag == -1||SizeOfRound < 0);
                    LinkedList<Type> ListNLR;
                    LinkedList<Type> ListLNR;
                    std::cout << "Введите " << SizeOfRound << " элементов которые соответствуют прямому(КЛП) обходу\n";
                    for(int i = 0;i < SizeOfRound;i ++)
                    {
                        Type data;
                        std::cin >> data;
                        ListNLR.push(data);
                    }
                    std::cout << "Введите " << SizeOfRound << " элементов которые соответствуют  центрированному(ЛКП) обходу\n";
                    for(int i = 0;i < SizeOfRound;i ++)
                    {
                        Type data;
                        std::cin >> data;
                        ListLNR.push(data);
                    }
                    try{
                    BalancedBinaryTree<Type> *Tree = new BalancedBinaryTree<Type>(BalancedBinaryTree<Type>::MakeTreeForRound(ListNLR,ListLNR));
                    Tree->SideOutlet();
                    MassiveOfTrees.push(Tree);
                    }
                    catch(char const* str)
                    {
                        std::cout << str << "\n";
                    }
                }
                break;
        }
    }
}