#include <iostream>
#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"
#include <cassert>
#include "Structs/Structs.h"
void TestInsert()
{
    int ArrayInput[5] = {1,2,3,4,5};
    int ArrayOutput[6] = {1,2,3,4,5,0};
    BalancedBinaryTree<int> TreeIntToInsert(ArrayInput,5);
    BalancedBinaryTree<int> TreeINtAnswer(ArrayOutput,6);
    TreeIntToInsert.insert(0);
    assert(TreeINtAnswer == TreeIntToInsert);

    BalancedBinaryTree<int> TreeTest1(1);
    BalancedBinaryTree<int> TreeTest2;
    TreeTest2.insert(1);
    assert(TreeTest1 == TreeTest2);

    float ArrayFloatInput[5] = {1.4,2.2,3.6,4.4,5.9};
    float ArrayFloatOutput[6] = {1.4,2.2,3.6,4.4,5.9,0.0};
    BalancedBinaryTree<float> TreeFloatToInsert(ArrayFloatInput,5);
    BalancedBinaryTree<float> TreeFloatAnswer(ArrayFloatOutput,6);
    TreeFloatToInsert.insert(0);
    //TreeFloatToInsert.SideOutlet();
    //std:: cout << "-------\n";
    //TreeFloatAnswer.SideOutlet();
    assert(TreeFloatAnswer == TreeFloatToInsert);

    Complex ArrayComplexInput[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Complex ArrayComplexOutput[6] = {{1,1},{2,2},{3,3},{4,4},{5,5},{0,0}};
    BalancedBinaryTree<Complex> TreeComplexToInsert(ArrayComplexInput,5);
    BalancedBinaryTree<Complex> TreeComplexAnswer(ArrayComplexOutput,6);
    TreeComplexToInsert.insert(Complex(0,0));
   // TreeComplexToInsert.SideOutlet();
   // std:: cout << "-------\n";
    //TreeComplexAnswer.SideOutlet();
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Char1 ArrayChar1Input[5] = {33,34,35,36,37};
    Char1 ArrayChar1Output[6] = {33,34,35,36,37,32};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,6);
    TreeChar1ToInsert.insert(Char1(32));
    //TreeChar1ToInsert.SideOutlet();
    //std:: cout << "-------\n";
    //TreeChar1Answer.SideOutlet();
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};
    Person ArrayPersonOutput[6] = {{123,456},{100,200},{1,2},{41,23},{12,321},{0,10000}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,6);
    TreePersonToInsert.insert(Person(0,10000));
    /*TreePersonToInsert.SideOutlet();
    std:: cout << "-------\n";
    TreePersonToOutput.SideOutlet();*/
    assert(TreePersonToInsert == TreePersonToOutput);  
}
void TestRemove()
{
    int ArrayInput[5] = {1,2,3,4,5};
    int ArrayOutput[6] = {1,2,3,4,5,0};
    BalancedBinaryTree<int> TreeIntToInsert(ArrayInput,5);
    BalancedBinaryTree<int> TreeIntToAnswer(ArrayOutput,6);
    TreeIntToAnswer.Remove(0);
    assert(TreeIntToAnswer == TreeIntToInsert);

    BalancedBinaryTree<int> TreeToRemove(1);
    BalancedBinaryTree<int> TreeIntToAnswerRemove;
    TreeToRemove.Remove(1);
    assert(TreeToRemove == TreeIntToAnswerRemove);
    BalancedBinaryTree<int> Tree3;
    BalancedBinaryTree<int> Tree4;
    Tree3.Remove(0);
    assert(Tree3 == Tree4);

    BalancedBinaryTree<int> Tree5(1);
    BalancedBinaryTree<int> Tree6(1);
    Tree5.Remove(13);
    assert(Tree5 == Tree6);


    float ArrayFloatInput[5] = {1.4,2.2,3.6,4.4,5.9};
    float ArrayFloatOutput[6] = {1.4,2.2,3.6,4.4,5.9,0.0};
    BalancedBinaryTree<float> TreeFloatToInsert(ArrayFloatInput,5);
    BalancedBinaryTree<float> TreeFloatAnswer(ArrayFloatOutput,6);
    TreeFloatAnswer.Remove(0);
    //TreeFloatToInsert.SideOutlet();
    //std:: cout << "-------\n";
    //TreeFloatAnswer.SideOutlet();
    assert(TreeFloatAnswer == TreeFloatToInsert);

     Complex ArrayComplexInput[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Complex ArrayComplexOutput[6] = {{1,1},{2,2},{3,3},{4,4},{5,5},{0,0}};
    BalancedBinaryTree<Complex> TreeComplexToInsert(ArrayComplexInput,5);
    BalancedBinaryTree<Complex> TreeComplexAnswer(ArrayComplexOutput,6);
    TreeComplexAnswer.Remove(Complex(0,0));
   // TreeComplexToInsert.SideOutlet();
   // std:: cout << "-------\n";
    //TreeComplexAnswer.SideOutlet();
    assert(TreeComplexAnswer == TreeComplexToInsert);


    Char1 ArrayChar1Input[5] = {33,34,35,36,37};
    Char1 ArrayChar1Output[6] = {33,34,35,36,37,32};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,6);
    TreeChar1Answer.Remove(Char1(32));
    //TreeChar1ToInsert.SideOutlet();
    //std:: cout << "-------\n";
    //TreeChar1Answer.SideOutlet();
    assert(TreeComplexAnswer == TreeComplexToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};
    Person ArrayPersonOutput[6] = {{123,456},{100,200},{1,2},{41,23},{12,321},{0,10000}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,6);
    TreePersonToInsert.insert(Person(0,10000));
    /*TreePersonToInsert.SideOutlet();
    std:: cout << "-------\n";
    TreePersonToOutput.SideOutlet();*/
    assert(TreePersonToInsert == TreePersonToOutput);  

}
void TestMap()
{
    int ArrayIntToMap[5] = {1,2,3,4,5};
    int ArrayIntToAnswer[5] = {2,4,6,8,10};
    BalancedBinaryTree<int> TreeToMap(ArrayIntToMap,5);
    BalancedBinaryTree<int> TreeToAnswer(ArrayIntToAnswer,5);
    TreeToMap.Map(FooMap);
    //TreeToMap.SideOutlet();
    //TreeToAnswer.SideOutlet();
    assert(TreeToAnswer == TreeToMap);

    Complex ArrayComplexToMap[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Complex ArrayComplexToAnswer[5] = {{2,2},{4,4},{6,6},{8,8},{10,10}};
    BalancedBinaryTree<Complex> TreeComplexToMap(ArrayComplexToMap,5);
    BalancedBinaryTree<Complex> TreeComplexToAnswer(ArrayComplexToAnswer,5);
    TreeComplexToMap.Map(FooMap);
    assert(TreeComplexToAnswer == TreeComplexToMap);

    Char1 ArrayChar1Input[5] = {33,34,35,36,37};
    Char1 ArrayChar1Output[5] = {66,68,70,72,74};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,5);
    TreeChar1ToInsert.Map(FooMap);
    //TreeChar1ToInsert.SideOutlet();
    //std:: cout << "-------\n";
   //TreeChar1Answer.SideOutlet();
    assert(TreeChar1Answer == TreeChar1ToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23},{12,321}};
    Person ArrayPersonOutput[5] = {{246,912},{200,400},{2,4},{82,46},{24,642}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,5);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,5);
    TreePersonToInsert.Map(FooMap);
    /*TreePersonToInsert.SideOutlet();
    std:: cout << "-------\n";
    TreePersonToOutput.SideOutlet();*/
    assert(TreePersonToInsert == TreePersonToOutput);
}
void TestWhere()
{
    BalancedBinaryTree<int> Tree(2);
    BalancedBinaryTree<int> TreeAnswer;
    Tree.Where(FooWhere);
    assert(TreeAnswer == Tree);

    Complex ArrayComplexToMap[5] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Complex ArrayComplexToAnswer[3] = {{1,1},{3,3},{5,5}};
    BalancedBinaryTree<Complex> TreeComplexToMap(ArrayComplexToMap,5);
    BalancedBinaryTree<Complex> TreeComplexToAnswer(ArrayComplexToAnswer,3);
    TreeComplexToMap.Where(FooWhere);
    assert(TreeComplexToAnswer == TreeComplexToMap);

     Char1 ArrayChar1Input[5] = {33,34,35,36,37};
    Char1 ArrayChar1Output[3] = {33,35,37};
    BalancedBinaryTree<Char1> TreeChar1ToInsert(ArrayChar1Input,5);
    BalancedBinaryTree<Char1> TreeChar1Answer(ArrayChar1Output,3);
    TreeChar1ToInsert.Where(FooWhere);
    //TreeChar1ToInsert.SideOutlet();
    //std:: cout << "-------\n";
   //TreeChar1Answer.SideOutlet();
    assert(TreeChar1Answer == TreeChar1ToInsert);

    Person ArrayPersonInput[5]  = {{123,456},{100,200},{1,2},{41,23}};
    Person ArrayPersonOutput[4] = {{123,456},{1,2},{41,23}};
    BalancedBinaryTree<Person> TreePersonToInsert(ArrayPersonInput,4);
    BalancedBinaryTree<Person> TreePersonToOutput(ArrayPersonOutput,3);
    TreePersonToInsert.Where(FooWhere);
    /*TreePersonToInsert.SideOutlet();
    std:: cout << "-------\n";
    TreePersonToOutput.SideOutlet();*/
    assert(TreePersonToInsert == TreePersonToOutput); 

}