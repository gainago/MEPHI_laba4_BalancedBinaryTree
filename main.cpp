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
	
	//BalancedBinaryTree<int> another(-333);
	
	/*exampletree.PrintBinaryTree();
	another.PrintBinaryTree();
	exampletree.Confluence(another);
	exampletree.PrintBinaryTree();
	//exampletree = exampletree.Map(FooMap);
	//exampletree.PrintBinaryTree();*/

	//exampletree.foo();
	exampletree.insert(5);
	exampletree.PrintBinaryTree();
	exampletree.SideOutlet();
	exampletree.KLP();
	
	// ooooooo

	
}
