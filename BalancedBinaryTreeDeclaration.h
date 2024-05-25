#pragma once
#include "LinkedListDeclaration.h"
template<typename Type>
struct Pair1{
	Type data_;
	int is_exist_{0};
	
};
template <typename Type>
class BalancedBinaryTree{
	private:
	struct Node{
		Node(Type t1);
		Node();
		Type data_;
		signed char height_;
		Node* leftptr_;
		Node* rightptr_;
	};
	Node* head{nullptr};

	public:
	/*template<typename Type1>
	friend void   PrintBinaryTree(typename BalancedBinaryTree<Type1>::Node* node);*/
	BalancedBinaryTree();
	BalancedBinaryTree(Type data);
	BalancedBinaryTree(BalancedBinaryTree<Type> const& base);
	BalancedBinaryTree(BalancedBinaryTree<Type>::Node* node);
	BalancedBinaryTree(LinkedList<Type> list);
	BalancedBinaryTree(Type* arr,size_t n);
	bool operator==(BalancedBinaryTree<Type> OtherTree);
	void insert(Type data);
	void PrintBinaryTree();
	void PrintBinaryTree(BalancedBinaryTree<Type>::Node* node);
	void Remove(Type data);
	Pair1<Type> RemoveFirst();
	void Map(Type (*FooMap)(Type)); //there are mutable functions
	void Where(bool (*FooWhere)(Type));
	void Confluence(BalancedBinaryTree<Type> anothertree);
	BalancedBinaryTree<Type> GetSubTreeForElement(Type key);
	bool Compare( BalancedBinaryTree<Type> SecondTree); // if 1 than they are equal
	Node* FindElement(Type key);
	BalancedBinaryTree<Type>::Node*  FindSubTree(BalancedBinaryTree<Type>::Node* root);
	BalancedBinaryTree<Type>::Node* FindSubTree(BalancedBinaryTree<Type> obj);
	void SideOutlet();
	void KLP();
	void KPL();
	void LPK();
	void PLK();
	void PKL();
	LinkedList<Type> Represent(int number_ob);
	~BalancedBinaryTree();
	static BalancedBinaryTree<Type> MakeTreeForRound(LinkedList<Type> const & listNLR,LinkedList<Type> const & listLNR);
	private:
	Node* FindElement_(Node* node,Type key);
	static Node* MakeTreeForRound_(LinkedList<Type> const & listNLR, int NLRleft, int NLRright, LinkedList<Type> const & listLNR,int LNRleft,int LNRright);
	void Represent_(LinkedList<Type> &list, Node* node,int number_ob);
	void PKL(Node* node);
	void PLK_(Node* node);
	void LPK_(Node* node);
	void KPL_(Node* node);
	void KLP_(Node* node);
	void SideOutlet_(Node* node,int space,bool isleft);
	int IsInclude(Node* head, Node* node);
	bool Compare_(Node* FirstNode, Node* SecondNode);//
	BalancedBinaryTree<Type> GetSubTree_(Node* node,Type key);
	Node* Remove_(Node* node, Type data);
	signed char GetHeight(Node* node);
	void FixHeight(Node* node);
	Node* Insert_(Node* node, Type data);
	Node* Balance(Node* node);
	Node* RightRotate(Node* node);
	Node* LeftRotate(Node* node);
	int BalanceFactor(Node* node);
	Node* FindMin(Node* node);
	Node* RemoveMin(Node* node);
};