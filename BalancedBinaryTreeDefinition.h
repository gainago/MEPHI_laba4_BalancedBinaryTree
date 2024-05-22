#pragma once
#include "BalancedBinaryTreeDeclaration.h"
#include "LinkedListDeclaration.h"
#include "LinkedListDefinition.h"
template<typename Type>
BalancedBinaryTree<Type> :: Node :: Node(Type t1) : data_(t1), height_(1), leftptr_(nullptr), rightptr_(nullptr) {}
template<typename Type>
BalancedBinaryTree<Type> :: Node :: Node() : data_(Type()), height_(1), leftptr_(nullptr), rightptr_(nullptr) {}
template<typename Type>
BalancedBinaryTree<Type> :: BalancedBinaryTree() : head(nullptr) {}
template<typename Type>
BalancedBinaryTree<Type> ::BalancedBinaryTree(Type data)
	{
		head = new Node(data);
	}
template <typename Type>
BalancedBinaryTree<Type>::BalancedBinaryTree(BalancedBinaryTree<Type> const &base) : BalancedBinaryTree(base.head)
	{
    }
    template <typename Type>
    BalancedBinaryTree<Type>::BalancedBinaryTree(BalancedBinaryTree<Type>::Node *node)
    {
		if(node== 0)
		{	this->head = 0;
			return;
		}
		LinkedList<BalancedBinaryTree<Type>::Node*> QueueNode;
		LinkedList<Type> QueueType;
		QueueNode.push(node);
		while(!QueueNode.empty())
		{
			QueueType.push(QueueNode.front()->data_);

			if(QueueNode.front()->leftptr_ != NULL)
			QueueNode.push(QueueNode.front()->leftptr_);

			if(QueueNode.front()->rightptr_ != NULL)
			QueueNode.push(QueueNode.front()->rightptr_);

			QueueNode.pop();
		}
		while(!QueueType.empty())
		{
			this->head = Insert_(head,QueueType.front());
			QueueType.pop();
		}
	}
template <typename Type>
void BalancedBinaryTree<Type>::insert(Type data)
	{
		head = Insert_(head , data);
	}
template<typename Type>
void    BalancedBinaryTree<Type> :: PrintBinaryTree()
	{
		if(head == 0)
			return;
		Node* specific = new Node();
		specific->height_ = -1;
		//std::queue<Node*> Q;
		LinkedList<BalancedBinaryTree<Type>::Node*> Q;
		Q.push(head);
		//Q.Append(head);
		int i = 1;
		int q = 1;
		while(!Q.empty())
		{	
			for(int ii = 0; ii < 5 - q;ii++)
				std::cout << "  ";
			if(Q.front()->height_ == -1)
				std::cout << "__" <<" ";
			else
				std::cout << Q.front()->data_ <<" ";
			
			if(i == q)
			{
				std::cout << "\n";
				i = 0;
				q = q*2;
			}
			i++;
			if(Q.front()->leftptr_ != NULL)
			Q.push(Q.front()->leftptr_ );

			if(Q.front()->leftptr_ == NULL&&Q.front()->height_!=-1)
				Q.push(specific);

			if(Q.front()->rightptr_ != NULL)
			Q.push(Q.front()->rightptr_);
				
				if(Q.front()->rightptr_ == NULL&&Q.front()->height_!=-1)
				Q.push(specific);
			Q.pop();
		}
		std::cout << "\n---------------\n";
	}
template <typename Type>
void BalancedBinaryTree<Type>::PrintBinaryTree(BalancedBinaryTree<Type>::Node *node)
    {
		if(node == 0)
			return;
		Node* specific = new Node();
		specific->height_ = -1;
		//std::queue<Node*> Q;
		LinkedList<BalancedBinaryTree<Type>::Node*> Q;
		Q.push(node);
		//Q.Append(head);
		int i = 1;
		int q = 1;
		while(!Q.empty())
		{	
			for(int ii = 0; ii < 5 - q;ii++)
				std::cout << "  ";
			if(Q.front()->height_ == -1)
				std::cout << "__" <<" ";
			else
				std::cout << Q.front()->data_ <<" ";
			
			if(i == q)
			{
				std::cout << "\n";
				i = 0;
				q = q*2;
			}
			i++;
			if(Q.front()->leftptr_ != NULL)
			Q.push(Q.front()->leftptr_ );

			if(Q.front()->leftptr_ == NULL&&Q.front()->height_!=-1)
				Q.push(specific);

			if(Q.front()->rightptr_ != NULL)
			Q.push(Q.front()->rightptr_);
				
				if(Q.front()->rightptr_ == NULL&&Q.front()->height_!=-1)
				Q.push(specific);
			Q.pop();
		}
		std::cout << "\n---------------\n";
    }
    template <typename Type>
    void BalancedBinaryTree<Type>::Remove(Type data)
    {
		head = Remove_(head,data);
	}
template <typename Type>
inline Pair1<Type> BalancedBinaryTree<Type>::RemoveFirst()
    {
		if(head == 0)
		return Pair1<Type>{0,0};
		Type current = head->data_;
        head = Remove_(head,head->data_);
		return Pair1<Type>{current,1};
    }
template <typename Type>
void BalancedBinaryTree<Type>::Map(Type (*FooMap)(Type))
    {	
		if(head == 0)
		return;
		LinkedList<BalancedBinaryTree<Type>::Node*> Q;
		Q.push(head);
		while(!Q.empty())
		{
			Q.front()->data_ = FooMap(Q.front()->data_);
			if(Q.front()->leftptr_ != NULL)
				Q.push(Q.front()->leftptr_);
			if(Q.front()->rightptr_ != NULL)
				Q.push(Q.front()->rightptr_);
			Q.pop();
		}

    }
template <typename Type>
void BalancedBinaryTree<Type>::Where(bool (*FooWhere)(Type))
    {
		LinkedList<Type> Q;
		Pair1<Type> para = this->RemoveFirst();
		while(para.is_exist_ != 0)
		{
			if(FooWhere(para.data_))
				Q.push(para.data_);
			para = this->RemoveFirst();
		}
		while(!Q.empty())
		{
			this->insert(Q.front());
			Q.pop();
		}
    }
template <typename Type>
void BalancedBinaryTree<Type>::Confluence(BalancedBinaryTree<Type> anothertree)
    {
		LinkedList<Type> Q;
		Pair1<Type> para = anothertree.RemoveFirst();
		while(para.is_exist_ != 0)
		{
			
			Q.push(para.data_);
			para = anothertree.RemoveFirst();
		}
		while(!Q.empty())
		{
			this->insert(Q.front());
			Q.pop();
		}
    }
template <typename Type>
BalancedBinaryTree<Type> BalancedBinaryTree<Type>::GetSubTree(Type key)
    {
        return GetSubTree_(head,key);
    }
template <typename Type>
bool BalancedBinaryTree<Type>::Compare( BalancedBinaryTree<Type> SecondTree)
    {
        return Compare_(this->head,SecondTree.head);
    }
template <typename Type>
typename BalancedBinaryTree<Type>::Node* BalancedBinaryTree<Type>::FindElement_(Node *node, Type key)
    {
        if(node == 0)
			return 0;
		if(node->data_ == key)
			return node;
		if(key <= node->data_)
			return FindElement_(node->leftptr_,key);
		else{
			return FindElement_(node->rightptr_,key);
		}
    }
template <typename Type>
Pair1< typename BalancedBinaryTree<Type>::Node*> BalancedBinaryTree<Type>::FindSubTree(BalancedBinaryTree<Type>::Node* root)
    {
        if(head == 0&& root == 0)
		{
			/*Pair1<BalancedBinaryTree<Type>::Node*> para;
					 para.data_ = root;
					 para.is_exist_ = 1;*/
					 return nullptr;
		}
			
		LinkedList<BalancedBinaryTree<Type>::Node*> Queue;
		Queue.push(head);
		while(!Queue.empty())
		{
			if(Queue.front()->data_ == root->data_)
			{
				if(IsInclude(Queue.front(),root))
				{
					/* Pair1<BalancedBinaryTree<Type>::Node*> para;
					 para.data_ = Queue.front();
					 para.is_exist_ = 1;
					 return para;*/
					 return Queue.front();
				}
					
			}
			if(Queue.front()->leftptr_ != NULL)
				Queue.push(Queue.front()->leftptr_);

			if(Queue.front()->rightptr_ != NULL)
				Queue.push(Queue.front()->rightptr_);
			Queue.pop();
		}
		 Pair1<BalancedBinaryTree<Type>::Node*> para;
					 para.data_ = root;
					 para.is_exist_ = 0;
					 return para;
		
		
    }
template <typename Type>
Pair1< typename BalancedBinaryTree<Type>::Node*>  BalancedBinaryTree<Type>::FindSubTree(BalancedBinaryTree<Type> obj)
    {
        return FindSubTree(obj.head);
    }
    template <typename Type>
    int BalancedBinaryTree<Type>::IsInclude(Node *head, Node *node)
    {
        if(node == NULL)
			return true;
		if(head == NULL && node != NULL)
			return false;
		LinkedList<BalancedBinaryTree<Type>::Node*> QueueHead;
		LinkedList<BalancedBinaryTree<Type>::Node*> QueueNode;
		while(!QueueNode.empty())
		{
			if(QueueHead.empty())
				return 0;
			if(QueueHead.front()->data_ != QueueNode.front()->data_ )
				return 0;
			if(QueueNode.front()->leftptr_ != NULL && QueueHead.front()->leftptr_ == NULL)
				return 0;
			if(QueueNode.front()->rightptr_ != NULL && QueueHead.front()->rightptr_ == NULL)
				return 0;
			if(QueueNode.front()->leftptr_ != NULL)
			{
				QueueNode.push(QueueNode.front()->leftptr_);
				QueueHead.push(QueueHead.front()->leftptr_);
			}
			if(QueueNode.front()->rightptr_ != NULL)
			{
				QueueNode.push(QueueNode.front()->rightptr_);
				QueueHead.push(QueueHead.front()->rightptr_);
			}
			QueueHead.pop();
			QueueNode.pop();
				
		}
		return 1;
    }
    template <typename Type>
    bool BalancedBinaryTree<Type>::Compare_(Node *FirstNode, Node *SecondNode) // if 1 then they are equal
    {
		if(FirstNode == 0&&SecondNode != 0)
			return false;
		if(SecondNode == 0&& FirstNode != 0)
			return false;
		if(FirstNode == 0 && SecondNode == 0)
			return true;
        LinkedList<BalancedBinaryTree<Type>::Node*> QueueFirst;
		LinkedList<BalancedBinaryTree<Type>::Node*> QueueSecond;
		QueueFirst.push(FirstNode);
		QueueSecond.push(SecondNode);
		while (!QueueFirst.empty())
		{
			if(QueueSecond.empty())
				return 0;
			if(QueueFirst.front()->data_ != QueueSecond.front()->data_) 
				return 0;
			if((QueueFirst.front()->leftptr_ == 0 && QueueSecond.front()->leftptr_ != 0)|| (QueueFirst.front()->leftptr_ != 0 && QueueSecond.front()->leftptr_ == 0) )
				return 0;
			if((QueueFirst.front()->rightptr_ == 0 && QueueSecond.front()->rightptr_ != 0)|| (QueueFirst.front()->rightptr_ != 0 && QueueSecond.front()->rightptr_ == 0) )
				return 0; 													
			if(QueueFirst.front()->leftptr_ != 0)
			{
				QueueFirst.push(QueueFirst.front()->leftptr_ );
				QueueSecond.push(QueueSecond.front()->leftptr_ );
			}
			if(QueueFirst.front()->rightptr_ != 0)
			{
				QueueFirst.push(QueueFirst.front()->rightptr_ );
				QueueSecond.push(QueueSecond.front()->rightptr_ );
			}
			QueueFirst.pop();
			QueueSecond.pop();
		}
		return 1;
		
    }
    template <typename Type>
    BalancedBinaryTree<Type> BalancedBinaryTree<Type>::GetSubTree_(Node *node, Type key)
    {	
		if(node == 0)
			return BalancedBinaryTree<Type>();
        if(node->data_ == key)
			return BalancedBinaryTree<Type>(node);
		if(node->data_ <= key)
			return GetSubTree_(node->rightptr_,key);
		else{
			return GetSubTree_(node->leftptr_,key);
		}
    }
template <typename Type>
typename BalancedBinaryTree<Type>::Node *BalancedBinaryTree<Type>::Remove_(Node *node, Type data)
    {
		if(node == NULL)
			return nullptr;
		if(data < node->data_)
			node->leftptr_ = Remove_(node->leftptr_,data);
		else if(data > node->data_)
				node->rightptr_ = Remove_(node->rightptr_,data);
		else{ //data == node->data_
		
			Node* less = node->leftptr_;
			Node* more = node->rightptr_;
			delete node;
			if(!more)
				return less;
			Node* min = FindMin(more);
			more = RemoveMin(more);
			min->leftptr_ = less;
			min->rightptr_ = more;
			min = Balance(min);
			return min;

		}
		node = Balance(node);
		return node;
	}
template<typename Type>
signed char    BalancedBinaryTree<Type> ::GetHeight(Node* node)
	{
		return node? node->height_ : 0 ;
	}
template<typename Type>
void    BalancedBinaryTree<Type> ::FixHeight(Node* node)
	{
		signed char rh = GetHeight(node->rightptr_);
		signed char lh = GetHeight(node->leftptr_);
		node->height_ = (rh>lh?rh:lh) + 1;
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> ::Insert_(Node* node, Type data)
	{
		if(node == NULL)
			return new Node(data);
		if(data <= node->data_)
			node->leftptr_ = Insert_(node->leftptr_,data);
		else
			node->rightptr_ = Insert_(node->rightptr_,data);
		node = Balance(node);
		return node;
		
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> ::Balance(Node* node)
	{
		FixHeight(node);
		if(BalanceFactor(node) == 2)
		{
			if(BalanceFactor(node->rightptr_) < 0)
				node->rightptr_ = RightRotate(node->rightptr_);
			return LeftRotate(node);
		}

		if(BalanceFactor(node) == -2)
		{
			if(BalanceFactor(node->leftptr_) > 0)
				node->leftptr_ = LeftRotate(node->leftptr_);
			return RightRotate(node);
		}
		return node;
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> ::RightRotate(Node* node)
	{
		Node* p2 = node->leftptr_;
		node->leftptr_ = p2->rightptr_;
		p2->rightptr_ = node;
		FixHeight(node);
		FixHeight(p2);
		return p2;
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> ::LeftRotate(Node* node)
	{
		Node* p2 = node->rightptr_;
		node->rightptr_ = p2->leftptr_;
		p2->leftptr_ = node;
		FixHeight(node);
		FixHeight(p2);
		return p2;
	}
template<typename Type>
int      BalancedBinaryTree<Type> :: BalanceFactor(Node* node)
	{
		return GetHeight(node->rightptr_) - GetHeight(node->leftptr_);
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> :: FindMin(Node* node)
	{
		return node->leftptr_? FindMin(node->leftptr_) : node;
	}
template<typename Type>
typename BalancedBinaryTree<Type> ::Node*    BalancedBinaryTree<Type> :: RemoveMin(Node* node)
	{
		if(node->leftptr_ == 0)
			return node->rightptr_;
		node->leftptr_ = RemoveMin(node->leftptr_);
		return Balance(node);
	}