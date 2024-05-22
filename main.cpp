#include <iostream>
#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"

int main()
{
	
	BalancedBinaryTree<int> exampletree(5);
	for(int i= 0;i < 10;i++)
	{	exampletree.insert(i);
		
	}
	/*BalancedBinaryTree<int> another(-333);
	for(int i = 0;i < 10; i++)
		another.insert(-i);
	exampletree.PrintBinaryTree();
	another.PrintBinaryTree();
	exampletree.Confluence(another);
	exampletree.PrintBinaryTree();
	//exampletree = exampletree.Map(FooMap);
	//exampletree.PrintBinaryTree();*/

	//exampletree.foo();
	exampletree.insert(5);
	exampletree.PrintBinaryTree();
	BalancedBinaryTree<int> other;
	other.insert(6);
	other.insert(5);
	other.insert(8);
	other.testoutput();
	// ooooooo

	
}
