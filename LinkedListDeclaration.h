#pragma once
template<typename Type>
class LinkedList 
{
    public:
    LinkedList(Type* items, int count);
    void ShowLinkedList() const;
    LinkedList();
    LinkedList(LinkedList<Type> const & LL);
    Type GetFirst() const;
    Type GetLast() const;
    Type GetIndex(int index) const;
    int GetLength() const;
    void Append(Type T);
    LinkedList<Type> * GetSubList(int start, int end) const;
    void Prepend(Type type);
    void Set(int index, Type data);
    void InsertAt(Type data, int index);
    LinkedList<Type> * Concat(LinkedList<Type>* LL ) const;
    bool empty();
    Type front();
    void pop();
    void push(Type);
    void operator=(LinkedList<Type> const & LL)
    {
        if(this->head == LL.head)
            return;
        this->~LinkedList();
        if(LL.size == 0)
        return;
        Node* ptr = LL.head; 
       for(int i = 0; i < LL.size;i++)
       {
            this->Append(ptr->value);
            ptr = ptr->next;
       }
    }
    ~LinkedList()
    {   
        Node* curr;
        for(int i = 0;i < size;i++)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
        size = 0;
        head = nullptr;
    }
    void DeleteIndex(int index);
    private:

    class Node
    {   public:
        Node(Type value);
        Type value;
        Node *next;
    };
    Node* head{0};
    Node* tail{0}; 
    size_t size{0};

};