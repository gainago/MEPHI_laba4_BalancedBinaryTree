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
    BalancedBinaryTree<Type>::BalancedBinaryTree(LinkedList<Type> list)
    {
		for(int i = 0;i < list.GetLength();i++)
			head = Insert_(head,list.GetIndex(i));
    }
    template <typename Type>
    inline BalancedBinaryTree<Type>::BalancedBinaryTree(Type *Array, size_t MassiveSize)
    {
		for(int i = 0;i < MassiveSize;i++)
			head = Insert_(head,Array[i]);
    }
    template <typename Type>
    inline bool BalancedBinaryTree<Type>::operator==(BalancedBinaryTree<Type> OtherTree)
    {
        return this->Compare(OtherTree);
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
	Pair1<Type> BalancedBinaryTree<Type>::RemoveFirst()
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
	BalancedBinaryTree<Type> BalancedBinaryTree<Type>::GetSubTreeForElement(Type key)
    {
        return GetSubTree_(head,key);
    }
	template <typename Type>
	bool BalancedBinaryTree<Type>::Compare( BalancedBinaryTree<Type> SecondTree)
    {
        return Compare_(this->head,SecondTree.head);
    }
    template <typename Type>
    inline typename BalancedBinaryTree<Type>::Node* BalancedBinaryTree<Type>::FindElement(Type key)
    {
        return FindElement_(head,key);
    }
    template <typename Type>
    typename BalancedBinaryTree<Type>::Node *BalancedBinaryTree<Type>::FindElement_(Node *node, Type key)
    {
        if(node == 0)
			return 0;
		if(node->data_ == key)
			return node;
		if(node->data_ > key)
			return FindElement_(node->leftptr_,key);
		else{
			return FindElement_(node->rightptr_,key);
		}
    }
	template <typename Type>
	 typename BalancedBinaryTree<Type>::Node* BalancedBinaryTree<Type>::FindSubTree(BalancedBinaryTree<Type>::Node* root)
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
	typename BalancedBinaryTree<Type>::Node* BalancedBinaryTree<Type>::FindSubTree(BalancedBinaryTree<Type> obj)
    {
        return FindSubTree(obj.head);
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::SideOutlet()
    {	
		if(head == 0)
		{
		std::cout << "дерево пустое \n";
		return;
		}

		SideOutlet_(head,0,false);
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::KLP()
    {
		KLP_(head);
		std::cout << "\n";
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::KPL()
	{
		KPL_(head);
		std::cout << "\n";
	}
	template <typename Type>
	void BalancedBinaryTree<Type>::LPK()
    {
		LPK(head);
		std::cout << "\n";
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::PLK()
    {
		PLK_(head);
		std::cout << "\n";
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::PKL()
    {
		PKL_(head);
		std::cout << "\n";
    }
    template <typename Type>
    LinkedList<Type> BalancedBinaryTree<Type>::Represent(int number_ob)
    {	if(number_ob <= 0 || number_ob > 6)
			throw "недопустимый номер обхода\n";
        LinkedList<Type> list;
		Represent_(list,head, number_ob);
		return list;
    }
    template <typename Type>
    inline BalancedBinaryTree<Type>::~BalancedBinaryTree()
    {
		while(head != 0)
		{
			head = Remove_(head,head->data_);
		}
    }

    template <typename Type>
    BalancedBinaryTree<Type> BalancedBinaryTree<Type>::MakeTreeForRound(LinkedList<Type> const & listNLR,LinkedList<Type> const & listLNR)
    {
		if(listLNR.GetLength() != listNLR.GetLength())
			throw "неверные размеры обходов";
		for(int i = 0; i < listLNR.GetLength(); i++)
		{
			int coincidencess = 0;
			for(int j = 0; j < listNLR.GetLength();j++)
			{
				if(listLNR.GetIndex(i) == listNLR.GetIndex(j))
				{
					coincidencess++;
				}
			}
			if(coincidencess == 0)
			throw "элементы в обходах не совпадают";
		}
        BalancedBinaryTree<Type> tree;
		tree.head =  MakeTreeForRound_(listNLR,0,listNLR.GetLength() - 1,listLNR,0,listLNR.GetLength() - 1);
		return tree;
    }

    template <typename Type>
    typename BalancedBinaryTree<Type>::Node* BalancedBinaryTree<Type>::MakeTreeForRound_(LinkedList<Type> const &listNLR,int NLRleft, int NLRright, LinkedList<Type> const &listLNR, int LNRleft, int LNRright)
    {
		if(NLRleft > NLRright)
			return nullptr;
		if(LNRleft > LNRright)
			return nullptr;
		Node* node = new Node(listNLR.GetIndex(NLRleft));
		int ind = 0;
		for(int i = LNRleft; i <= LNRright; i++)
			if(listLNR.GetIndex(i) == listNLR.GetIndex(NLRleft))
				ind = i;
		node->leftptr_ = MakeTreeForRound_(listNLR,NLRleft + 1,NLRleft + ind - LNRleft,listLNR,LNRleft, ind - 1);
		//node->rightptr_ = MakeTreeForRound_(listNLR,NLRleft + ind + 1 ,NLRright, listLNR,LNRleft + ind + 1 ,LNRright);
		node->rightptr_ = MakeTreeForRound_(listNLR,NLRleft + ind - LNRleft + 1,NLRright, listLNR, ind + 1 ,LNRright);
		return node;
    }

    template <typename Type>
    inline void BalancedBinaryTree<Type>::Represent_(LinkedList<Type> &list, Node *node, int number_ob)
    {
		if(node == 0)
			return;
		switch (number_ob)
		{
		case 1:
			{
				list.push(node->data_);
				Represent_(list,node->leftptr_,number_ob);
				Represent_(list,node->rightptr_,number_ob);
			}
			break;
		case 2:
			{
				list.push(node->data_);
				Represent_(list,node->rightptr_,number_ob);
				Represent_(list,node->leftptr_,number_ob);
			}
			break;
		case 3:
			{
				Represent_(list,node->leftptr_,number_ob);
				Represent_(list,node->rightptr_,number_ob);
				list.push(node->data_);
			}
			break;
		case 4:
			{
				Represent_(list,node->leftptr_,number_ob);
				list.push(node->data_);
				Represent_(list,node->rightptr_,number_ob);
			}
			break;
		case 5:
			{
				Represent_(list,node->rightptr_,number_ob);
				Represent_(list,node->leftptr_,number_ob);
				list.push(node->data_);
			}
			break;
		case 6:
			{
				Represent_(list,node->rightptr_,number_ob);
				list.push(node->data_);
				Represent_(list,node->leftptr_,number_ob);
			}
			break;
		}
		
    }
    template <typename Type>
    void BalancedBinaryTree<Type>::PKL(Node *node)
    {
		if(node == 0)
			return;
		PKL_(node->rightptr_);
		std::cout << node->data_ << " ";
		PKL_(node->leftptr_);

    }
    template <typename Type>
    void BalancedBinaryTree<Type>::PLK_(Node *node)
    {
		if(node == 0)
			return;
		PLK_(node->rightptr_);
		PLK_(node->leftptr_);
		std::cout << node->data_ << " ";
    }
    template <typename Type>
    void BalancedBinaryTree<Type>::LPK_(Node *node)
    {
		if(node == 0)
			return;
		LPK_(node->leftptr_);
		LPK_(node->rightptr_);
		std::cout << node->data_ << "  ";
    }
    template <typename Type>
    void BalancedBinaryTree<Type>::KPL_(Node *node)
    {
		if(node == 0)
			return;
		std::cout << node->data_ << "  ";
		KPL_(node->rightptr_);
		KPL_(node->leftptr_);
    }
	template <typename Type>
	void BalancedBinaryTree<Type>::KLP_(Node *node)
    {
		if(node == 0)
			return;
		std::cout << node->data_ << "  ";
		KLP_(node->leftptr_);
		KLP_(node->rightptr_);
    }
    template <typename Type>
    void BalancedBinaryTree<Type>::SideOutlet_(Node *node, int space, bool isleft)
    {
		if(node == 0) return;
		int BaseSpase = 5;
		space += BaseSpase;
		SideOutlet_(node->rightptr_,space,false);
		for(int i = BaseSpase; i < space; i ++)
			std::cout << " ";
		if(isleft)
			std::cout << "\\___";
		else
			std::cout << "/---";
		std::cout << node->data_ << std::endl;
		SideOutlet_(node->leftptr_,space,true);
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