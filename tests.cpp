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

    float ArrayFloatInput[5] = {1.4,2.2,3.6,4.4,5.9};
    float ArrayFloatOutput[6] = {1.4,2.2,3.6,4.4,5.9,0.0};
    BalancedBinaryTree<float> TreeFloatToInsert(ArrayFloatInput,5);
    BalancedBinaryTree<float> TreeFloatAnswer(ArrayFloatOutput,6);
    TreeFloatToInsert.insert(0);
    //TreeFloatToInsert.SideOutlet();
    //std:: cout << "-------\n";
    //TreeFloatAnswer.SideOutlet();
    assert(TreeINtAnswer == TreeIntToInsert);

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
}