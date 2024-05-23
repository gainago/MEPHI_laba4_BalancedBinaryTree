#include <iostream>
#include "BalancedBinaryTreeDeclaration.h"
#include "BalancedBinaryTreeDefinition.h"
#include "functions.h"
#include "LinkedListDefinition.h"
#include "test_speed.cpp"


int main()
{
	int NLR[7] = {1,2,3,7,4,5,6};
	int LNR[7] = {3,7,2,4,5,1,6};
	LinkedList<int> NLRlist(NLR,7);
	LinkedList<int> LNRlist(LNR,7);
	BalancedBinaryTree<int> tree = BalancedBinaryTree<int> :: MakeTreeForRound(NLRlist,LNRlist);
	tree.SideOutlet();
	
	
	
}
