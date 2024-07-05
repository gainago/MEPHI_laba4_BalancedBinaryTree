#pragma once
#include "LinkedListDeclaration.h"
#include <string>
#include <iostream>
#include "BalancedBinaryTreePrint.h"
template<typename Type>
struct Pair1{
	Type data_;
	int is_exist_{0};
	
};
template<typename Type>
class BalancedBinaryTree;

template<typename Type>
class Node;

template <typename Type>
class ReturnNode
{
public:
	virtual Type const & Get() = 0;
};


template <typename Type>
class BalancedBinaryTree{
private:
	//public:
	struct Node{
		Node(Type t1);
		Node();
		Type data_;
		signed char height_;
		Node* leftptr_;
		Node* rightptr_;
		static void DeleteTree(Node* node)
		{
			if(node->leftptr_ != 0)
				DeleteTree(node->leftptr_);
			delete node->leftptr_;
			if(node->rightptr_ != 0)
				DeleteTree(node->rightptr_);
			delete node->rightptr_;
			
		}
	};
	Node* head{nullptr};
	template<typename T = Type>
	class ReturnNodeBalancedTree : public ReturnNode<T>
	{
	private:
		Type data_;
	public:
		ReturnNodeBalancedTree(Type const & data) : data_(data){}
		Type const & Get()
		{
			return data_;
		}

	};
	template<typename T>
	friend class PrettyPrinterKLP;
	template<typename T>
	friend class PrettyPrinterKPL;
	template<typename T>
	friend class PrettyPrinterLPK;
	template<typename T>
	friend class PrettyPrinterPLK;
	template<typename T>
	friend class PrettyPrinterPKL;
	template<typename T>
	friend class PrettyPrinterSideTraversal;
public:
	static BalancedBinaryTree<Type> MakeTreeForRound(LinkedList<Type> const & listNLR,LinkedList<Type> const & listLNR);
	
	BalancedBinaryTree();
	BalancedBinaryTree(Type data);
	BalancedBinaryTree(BalancedBinaryTree<Type> const& base);
	BalancedBinaryTree(BalancedBinaryTree<Type>::Node* node);
	BalancedBinaryTree(LinkedList<Type> list);
	BalancedBinaryTree(Type* arr,size_t n);
	bool operator==(BalancedBinaryTree<Type> OtherTree);
	Node* insert(Type data);
	
	BalancedBinaryTree<Type> const & Remove(Type data);
	Pair1<Type> RemoveFirst();
	BalancedBinaryTree<Type> const &Map(Type (*FooMap)(Type)); //there are mutable functions
	BalancedBinaryTree<Type> const & Where(bool (*FooWhere)(Type));
	BalancedBinaryTree<Type> const & Confluence(BalancedBinaryTree<Type> anothertree);
	BalancedBinaryTree<Type> GetSubTreeForElement(Type key);
	bool Compare( BalancedBinaryTree<Type> SecondTree); // if 1 than they are equal
	ReturnNode<Type>*  FindElement(Type key);
	
	BalancedBinaryTree<Type>::Node*  FindSubTree(BalancedBinaryTree<Type>::Node* root);
	BalancedBinaryTree<Type>::Node* FindSubTree(BalancedBinaryTree<Type> const & obj);
	
	LinkedList<Type> Represent(int number_ob);
	~BalancedBinaryTree();
private:
	ReturnNode<Type>*  FindElement_(Node* node,Type key);
	static Node* MakeTreeForRound_(LinkedList<Type> const & listNLR, int NLRleft, int NLRright, LinkedList<Type> const & listLNR,int LNRleft,int LNRright);
	
	void Represent_(LinkedList<Type> &list, Node* node,int number_ob);
	
	int IsInclude(Node* head, Node* node);
	bool Compare_(Node* FirstNode, Node* SecondNode);//
	BalancedBinaryTree<Type> GetSubTree_(Node* node,Type key);
	Node* Remove_(Node* node, Type data);
	signed char GetHeight(Node* node);
	void FixHeight(Node* node);
	Node* Insert_(Node* node, Type data,BalancedBinaryTree<Type>::Node* NodeReturn);
	Node* Balance(Node* node);
	Node* RightRotate(Node* node);
	Node* LeftRotate(Node* node);
	int BalanceFactor(Node* node);
	Node* FindMin(Node* node);
	Node* RemoveMin(Node* node);
};
template<class T>
void SideOutlet(BalancedBinaryTree<T> const & tree);
template<class T>
void SideOutlet_(typename BalancedBinaryTree<T>::Node const * node,int space,bool isleft);


