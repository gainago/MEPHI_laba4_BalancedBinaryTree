template<typename Type>
class BalancedBinaryTree;

template<typename Type>
class Node;

template<typename Type>
class PrettyPrinter
{
public:
	virtual void Print(BalancedBinaryTree<Type>const & Tree) = 0;
};

template<typename Type>
class PrettyPrinterKLP : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			KLP_(Tree.head);
			std::cout << "\n";
		}
	private:	
		void KLP_(typename BalancedBinaryTree<Type>::Node* node)
		{
			if(node == 0)
			return;
			std::cout << node->data_ << "  ";
			KLP_(node->leftptr_);
			KLP_(node->rightptr_);
		}
	};

	template<typename Type>
class PrettyPrinterKPL : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			KPL_(Tree.head);
			std::cout << "\n";
		}
	private:	
		void KPL_(typename BalancedBinaryTree<Type>::Node* node)
		{
			if(node == 0)
			return;
			std::cout << node->data_ << "  ";
			KPL_(node->rightptr_);
			KPL_(node->leftptr_);
		}
	};

	template<typename Type>
class PrettyPrinterLPK : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			LPK_(Tree.head);
			std::cout << "\n";
		}
	private:	
		void LPK_(typename BalancedBinaryTree<Type>::Node* node)
		{
			if(node == 0)
			return;
			LPK_(node->leftptr_);
			LPK_(node->rightptr_);
			std::cout << node->data_ << "  ";
		}
	};

	template<typename Type>
class PrettyPrinterPLK : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			PLK_(Tree.head);
			std::cout << "\n";
		}
	private:	
		void PLK_(typename BalancedBinaryTree<Type>::Node* node)
		{
			if(node == 0)
			return;
			PLK_(node->rightptr_);
			PLK_(node->leftptr_);
			std::cout << node->data_ << " ";
		}
	};

	template<typename Type>
class PrettyPrinterPKL : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			PKL_(Tree.head);
			std::cout << "\n";
		}
	private:	
		void PKL_(typename BalancedBinaryTree<Type>::Node* node)
		{
			if(node == 0)
			return;
			PKL_(node->rightptr_);
			std::cout << node->data_ << " ";
			PKL_(node->leftptr_);
		}
	};
	template<typename Type>
	class PrettyPrinterSideTraversal : public PrettyPrinter<Type>
	{
	public:
		void Print(BalancedBinaryTree<Type> const & Tree) override
		{
			if(Tree.head == 0)
			{
			std::cout << "дерево пустое \n";
			return;
			}

			SideTraversal_(Tree.head,0,false);
		}
	private:	
		void SideTraversal_(typename BalancedBinaryTree<Type>::Node const *node, int space, bool isleft)
		{
			if(node == 0) return;
			int BaseSpase = 5;
			space += BaseSpase;
			SideTraversal_(node->rightptr_,space,false);
			for(int i = BaseSpase; i < space; i ++)
				std::cout << " ";
			if(isleft)
				std::cout << "\\___";
			else
				std::cout << "/---";
			std::cout << node->data_ << std::endl;
			SideTraversal_(node->leftptr_,space,true);
		}
	};