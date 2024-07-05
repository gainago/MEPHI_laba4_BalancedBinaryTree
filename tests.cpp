#include <iostream>
#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"
#include <cassert>
#include "Structs/Structs.h"
void TestInsert()
{
    int ArrayInput[5] = {1,2,3,4,5};//создание двух массивов для заполнения деревьев
    int ArrayOutput[6] = {1,2,3,4,5,0};
    BalancedBinaryTree<int> TreeIntToInsert(ArrayInput,5);//создание дерева, в которое вставится элемент
    BalancedBinaryTree<int> TreeINtAnswer(ArrayOutput,6);//создание дерева которое должно получится после вставки
    TreeIntToInsert.insert(0);
    assert(TreeINtAnswer == TreeIntToInsert);//сравнение ожидаемого и полученного деревьев

    BalancedBinaryTree<int> TreeTest1(1);//проверка вставки элемента в пустое дерево
    BalancedBinaryTree<int> TreeTest2;
    TreeTest2.insert(1);
    assert(TreeTest1 == TreeTest2);

    float ArrayFloatInput[5] = {1.4,2.2,3.6,4.4,5.9};//проверка вставки числа в плавающей точкой
    float ArrayFloatOutput[6] = {1.4,2.2,3.6,4.4,5.9,0.0};
    BalancedBinaryTree<float> TreeFloatToInsert(ArrayFloatInput,5);
    BalancedBinaryTree<float> TreeFloatAnswer(ArrayFloatOutput,6);
    TreeFloatToInsert.insert(0);
    assert(TreeFloatAnswer == TreeFloatToInsert);

    Complex ArrayComplexInput[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};//проверка вставки комплексного числа в дерево
    Complex ArrayComplexOutput[6] = {{1,1},{2,2},{3,3},{4,4},{5,5},{0,0}};
    BalancedBinaryTree<Complex> TreeComplexToInsert(ArrayComplexInput,5);
    BalancedBinaryTree<Complex> TreeComplexAnswer(ArrayComplexOutput,6);
    TreeComplexToInsert.insert(Complex(0,0));
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Char1 ArrayChar1Input[5] = {33,34,35,36,37};//проверка вставки символа в дерево
    Char1 ArrayChar1Output[6] = {33,34,35,36,37,32};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,6);
    TreeChar1ToInsert.insert(Char1(32));
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};//проверка вставки объекта класса Человек в дерево
    Person ArrayPersonOutput[6] = {{123,456},{100,200},{1,2},{41,23},{12,321},{0,10000}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,6);
    TreePersonToInsert.insert(Person(0,10000));
    assert(TreePersonToInsert == TreePersonToOutput);  
}
void TestRemove()
{
    int ArrayInput[5] = {1,2,3,4,5};//проверка функции удаления элемента из дерева для целого числа
    int ArrayOutput[6] = {1,2,3,4,5,0};
    BalancedBinaryTree<int> TreeIntToInsert(ArrayInput,5);
    BalancedBinaryTree<int> TreeIntToAnswer(ArrayOutput,6);
    TreeIntToAnswer.Remove(0);
    assert(TreeIntToAnswer == TreeIntToInsert);

    BalancedBinaryTree<int> TreeToRemove(1);// проверка удаления единственного элемента из дерева
    BalancedBinaryTree<int> TreeIntToAnswerRemove;
    TreeToRemove.Remove(1);
    assert(TreeToRemove == TreeIntToAnswerRemove);
    BalancedBinaryTree<int> Tree3;//проверка удаления элемента которого нет в дереве из пустого дерева
    BalancedBinaryTree<int> Tree4;
    Tree3.Remove(0);
    assert(Tree3 == Tree4);

    BalancedBinaryTree<int> Tree5(1);//проверка удаления элемента которого нет в дереве из непустого дерева
    BalancedBinaryTree<int> Tree6(1);
    Tree5.Remove(13);
    assert(Tree5 == Tree6);


    float ArrayFloatInput[5] = {1.4,2.2,3.6,4.4,5.9};//проверка удаления элемента типа число с плавающей точкой из дерева
    float ArrayFloatOutput[6] = {1.4,2.2,3.6,4.4,5.9,0.0};
    BalancedBinaryTree<float> TreeFloatToInsert(ArrayFloatInput,5);
    BalancedBinaryTree<float> TreeFloatAnswer(ArrayFloatOutput,6);
    TreeFloatAnswer.Remove(0);
    assert(TreeFloatAnswer == TreeFloatToInsert);

     Complex ArrayComplexInput[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};//проверка удаления комплексного числа из дерева
    Complex ArrayComplexOutput[6] = {{1,1},{2,2},{3,3},{4,4},{5,5},{0,0}};
    BalancedBinaryTree<Complex> TreeComplexToInsert(ArrayComplexInput,5);
    BalancedBinaryTree<Complex> TreeComplexAnswer(ArrayComplexOutput,6);
    TreeComplexAnswer.Remove(Complex(0,0));
    assert(TreeComplexAnswer == TreeComplexToInsert);


    Char1 ArrayChar1Input[5] = {33,34,35,36,37};//проверка удаления символа из дерева
    Char1 ArrayChar1Output[6] = {33,34,35,36,37,32};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,6);
    TreeChar1Answer.Remove(Char1(32));
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};//проверка удаления объекта типа человек из дерева
    Person ArrayPersonOutput[6] = {{123,456},{100,200},{1,2},{41,23},{12,321},{0,10000}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,6);
    TreePersonToInsert.insert(Person(0,10000));
    assert(TreePersonToInsert == TreePersonToOutput);  

}
void TestRemoveLeaf()
{
    int ArrayIntInput[1]  = {120};//проверка удаления объекта типа число с фиксированной точкой из листа
    int ArrayIntOutput[0] = {};
    BalancedBinaryTree<int> TreeIntToRemove(ArrayIntInput,1);
    BalancedBinaryTree<int> TreeIntToOutput(ArrayIntOutput,0);
    TreeIntToRemove.Remove(120);
    assert(TreeIntToRemove == TreeIntToOutput);  

    Person ArrayPersonInput[1]  = {{123,456}};//проверка удаления объекта типа человек из листа
    Person ArrayPersonOutput[0] = {};
    BalancedBinaryTree<Person> TreePersonToRemove(ArrayPersonInput,1);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,0);
    TreePersonToRemove.Remove(Person(123,456));
    assert(TreePersonToRemove == TreePersonToOutput);  
}
void TestRemoveNodeAndSon()
{
    int ArrayIntInput[2]  = {120,110};//проверка удаления объекта типа человек из узла с одним потомком
    int ArrayIntOutput[1] = {110};
    BalancedBinaryTree<int> TreeIntToRemove(ArrayIntInput,2);
    BalancedBinaryTree<int> TreeIntToOutput(ArrayIntOutput,1);
    TreeIntToRemove.Remove(120);
    assert(TreeIntToRemove == TreeIntToOutput);  

    Person ArrayPersonInput[2]  = {{123,456},{111,-222}};//проверка удаления объекта типа человек из узла с одним потомком
    Person ArrayPersonOutput[1] = {{111,-222}};
    BalancedBinaryTree<Person> TreePersonToRemove(ArrayPersonInput,2);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,1);
    TreePersonToRemove.Remove(Person(123,456));
    assert(TreePersonToRemove == TreePersonToOutput);  
}
void TestRemoveNodeandSons()
{
    int ArrayIntInput[3]  = {120,110,100};//проверка удаления объекта типа целое число из узла с двумя потомками
    int ArrayIntOutput[2] = {120,100};
    BalancedBinaryTree<int> TreeIntToRemove(ArrayIntInput,3);
    BalancedBinaryTree<int> TreeIntToOutput(ArrayIntOutput,2);
    TreeIntToRemove.Remove(110);
    //PrettyPrinterSideTraversal<Person> Printer;
    //Printer.Print(TreePersonToRemove);
    assert(TreeIntToRemove == TreeIntToOutput);

    Person ArrayPersonInput[3]  = {{123,456},{111,-222},{100,0}};//проверка удаления объекта типа человек из узла с двумя потомками
    Person ArrayPersonOutput[2] = {{123,456},{100,0}};
    BalancedBinaryTree<Person> TreePersonToRemove(ArrayPersonInput,3);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,2);
    TreePersonToRemove.Remove(Person(111,-222));
    //PrettyPrinterSideTraversal<Person> Printer;
    //Printer.Print(TreePersonToRemove);
    assert(TreePersonToRemove == TreePersonToOutput);
}
void TestRemoveNodeHeight()
{
    int ArrayIntInput[5]  = {120,110,100,550,-100};//проверка удаления объекта типа целое число из узла, высота поддерева которого больше двух
    int ArrayIntOutput[4] = {120,100,550,-100};
    BalancedBinaryTree<int> TreeIntToRemove(ArrayIntInput,5);
    BalancedBinaryTree<int> TreeIntToOutput(ArrayIntOutput,4);
    //PrettyPrinterSideTraversal<Person> Printer;
    //Printer.Print(TreePersonToRemove);
    TreeIntToRemove.Remove(110);
    assert(TreeIntToRemove == TreeIntToOutput);

    Person ArrayPersonInput[5]  = {{123,456},{111,-222},{100,0},{555,444},{-1,444}};//проверка удаления объекта типа человек из узла, высота поддерева которого больше двух
    Person ArrayPersonOutput[4] = {{123,456},{100,0},{555,444},{-1,444}};
    BalancedBinaryTree<Person> TreePersonToRemove(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,4);
    //PrettyPrinterSideTraversal<Person> Printer;
    //Printer.Print(TreePersonToRemove);
    TreePersonToRemove.Remove(Person(111,-222));
    assert(TreePersonToRemove == TreePersonToOutput);
    
}
void TestDeleteAndInsert()
{
    int ArrayIntOutput[1] = {100};// Тестирование удаления узла из пустого поддерева и вставка узла после этого для типа данных целое число
    BalancedBinaryTree<int> TreeIntToRemove;
    BalancedBinaryTree<int> TreeIntToOutput(ArrayIntOutput,1);
    TreeIntToRemove.Remove(int(200));
    TreeIntToRemove.insert(100);
    assert(TreeIntToRemove == TreeIntToOutput);

    Person ArrayPersonOutput[1] = {{123,456}};// Тестирование удаления узла из пустого поддерева и вставка узла после этого для типа данных человек
    BalancedBinaryTree<Person> TreePersonToRemove;
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,1);
    TreePersonToRemove.Remove(Person(111,-222));
    TreePersonToRemove.insert(Person(123,456));
    assert(TreePersonToRemove == TreePersonToOutput);
}
void TestMap()
{
    int ArrayIntToMap[5] = {1,2,3,4,5};//проверка функции map для дерева заполненнного числами с фиксированной точкой
    int ArrayIntToAnswer[5] = {2,4,6,8,10};
    BalancedBinaryTree<int> TreeToMap(ArrayIntToMap,5);
    BalancedBinaryTree<int> TreeToAnswer(ArrayIntToAnswer,5);
    TreeToMap.Map(FooMap);
    assert(TreeToAnswer == TreeToMap);

    Complex ArrayComplexToMap[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};//проверка функции map для дерева заполненного комплексными числами
    Complex ArrayComplexToAnswer[5] = {{2,2},{4,4},{6,6},{8,8},{10,10}};
    BalancedBinaryTree<Complex> TreeComplexToMap(ArrayComplexToMap,5);
    BalancedBinaryTree<Complex> TreeComplexToAnswer(ArrayComplexToAnswer,5);
    TreeComplexToMap.Map(FooMap);
    assert(TreeComplexToAnswer == TreeComplexToMap);

    Char1 ArrayChar1Input[5] = {33,34,35,36,37};// проверка функции map для дерева заполненными символами
    Char1 ArrayChar1Output[5] = {66,68,70,72,74};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,5);
    TreeChar1ToInsert.Map(FooMap);
    assert(TreeChar1Answer == TreeChar1ToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};//проверка функции map на объекте типа Человек
    Person ArrayPersonOutput[5] = {{246,912},{200,400},{2,4},{82,46},{24,642}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,5);
    TreePersonToInsert.Map(FooMap);
    assert(TreePersonToInsert == TreePersonToOutput);
}
void TestWhere()
{
    BalancedBinaryTree<int> Tree(2);//провека функции where при котором ни один элемент лерева не удовлетворяет условию
    BalancedBinaryTree<int> TreeAnswer;
    Tree.Where(FooWhere);
    assert(TreeAnswer == Tree);

    Complex ArrayComplexToMap[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};//провека функции where для комплексных чисел
    Complex ArrayComplexToAnswer[3] = {{1,1},{3,3},{5,5}};
    BalancedBinaryTree<Complex> TreeComplexToMap(ArrayComplexToMap,5);
    BalancedBinaryTree<Complex> TreeComplexToAnswer(ArrayComplexToAnswer,3);
    TreeComplexToMap.Where(FooWhere);
    assert(TreeComplexToAnswer == TreeComplexToMap);

    Char1 ArrayChar1Input[5] = {33,34,35,36,37};//проверка функции where для объектов типа символ
    Char1 ArrayChar1Output[3] = {33,35,37};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,3);
    TreeChar1ToInsert.Where(FooWhere);
    assert(TreeChar1Answer == TreeChar1ToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23}};// проверка функции where для обектов типа Человек
    Person ArrayPersonOutput[4] = {{123,456},{1,2},{41,23}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,4);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,3);
    TreePersonToInsert.Where(FooWhere);
    assert(TreePersonToInsert == TreePersonToOutput); 

}