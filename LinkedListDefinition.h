
#pragma once
#include "LinkedListDeclaration.h"
template<typename Type>
    LinkedList<Type> ::  LinkedList(Type* items, int count)
    {
        if(items == NULL || count == 0|| count < 0)
            return;

        head = new Node(items[0]);
        Node* current_ptr = head;
        for(int i = 0; i < count -1; i++)
        {
            current_ptr->next = new Node(items[i+1]);
            current_ptr = current_ptr->next;
        }
        tail = current_ptr;
        size = (size_t)count;

    }
    template<typename Type>
    void LinkedList<Type> ::  ShowLinkedList() const
    {
        for(int i = 0; i < size; i++)
        {
            std:: cout << i << "\t";
        }
        std:: cout << "\n";
        Node* current_ptr = head;
        for(int i = 0; i < size; i++)
        {
            std:: cout << current_ptr->value << "\t";
            //Print(current_ptr->value);
            current_ptr = current_ptr->next;
        }
        std:: cout << "\n";
    }
    template<typename Type>
    LinkedList<Type> ::  LinkedList(){
        this->head = 0;
        this->size = 0;
        this->tail = 0;
    }
    template<typename Type>
    LinkedList<Type> ::  LinkedList(LinkedList<Type> const & LL)
    {
        if(LL.size == 0)
        return;
        this->size = LL.size;
        head = new Node(LL.head->value);
        Node* current_ptr2 = LL.head;
        Node* current_ptr1 = head;
        for(int i = 0; i < size - 1;i++)
        {
            current_ptr1->next = new Node(current_ptr2->next->value);
            current_ptr1 = current_ptr1->next;
            current_ptr2 = current_ptr2->next;
        }
        tail = current_ptr1;
    }

    template <typename Type>
    Type LinkedList<Type>::GetFirst() const
    {   
        if(this->size == 0)
            throw "size == 0\n";
        return this->head->value;
    }

    template <typename Type>
    Type LinkedList<Type>::GetLast() const
    {
        if(this->size == 0)
            throw "size == 0\n";
        return this->tail->value;
    }
    template <typename Type>
    Type LinkedList<Type> :: GetIndex(int index) const
    {
        if(index < 0)
        throw "index < 0\n";
        if(size == 0 || index >= size)
            throw "index out of size\n";
        Node * curr_prt = head;
        for(int i= 0;i < index; i++)
            curr_prt = curr_prt->next;
        return curr_prt->value;
    }
    template<typename Type>
    LinkedList<Type>* LinkedList<Type> :: GetSubList(int start, int end) const
    {
        if(start <0 || end >= size || start > end)
        throw "error: wrong indexes\n";
        LinkedList<Type>* ptr_LL = new LinkedList();
        Node* current_ptr = head;
        for(int i = 0; i < start;i++)
            current_ptr = current_ptr->next;
        for(int i = start; i <= end;i++)
        {    
            ptr_LL->Append(current_ptr->value);
            current_ptr = current_ptr->next;
        }
        return ptr_LL;
    }
    template<typename Type>
    void LinkedList<Type>:: Prepend(Type data)
    {
        Node* curr_ptr = new Node(data);
        curr_ptr->next = head;
        head = curr_ptr;
        size++;
    }
    template <typename Type>
    void LinkedList<Type>::Set(int index, Type data)
    {
        if(index >= this->size|| index < 0)
            throw "error:invalid index\n";
        Node* curr_node = head;
        for(int i = 0; i < index; i++)
        {
            curr_node = curr_node->next;
        }
        curr_node->value = data;
    }
    template <typename Type>
    void LinkedList<Type>::InsertAt(Type data, int index)
    {
        if(index < 0 || index > size)
            throw "error: index out of range\n";
            if(index == 0)
            {
                this->Prepend(data);
                return;
            }
            if(index == size)
            {
                this->Append(data);
            }
        Node* curr_ptr = head;
        for(int i = 0;i < index - 1;i++)
            curr_ptr = curr_ptr->next;
        Node* new_ptr = new Node(data);
        new_ptr->next = curr_ptr->next;
        curr_ptr->next = new_ptr;
        size++;
    }
    template <typename Type>
    int LinkedList<Type>::GetLength() const
    {
        return size;
    }
    template<typename Type>
    void LinkedList<Type> :: Append(Type T)
    {
        if(tail == NULL)
        {
            head = new Node(T);
            tail = head; 
            size++;   
        }
        else{
            tail->next = new Node(T);
            size++;
            tail = tail->next;
        }
    }
    template<typename Type>    
    LinkedList<Type> ::  Node  :: Node(Type value)
    {
        this->value =value;
        next = NULL;
    }
    template<typename Type>
    LinkedList<Type> * LinkedList<Type>:: Concat(LinkedList<Type> *LL) const
    {
        LinkedList<Type> * ptr_new = new LinkedList<Type>;
        for(int i = 0;i < LL->GetLength();i++)
            ptr_new->Append(LL->GetIndex(i));
        for(int i = 0;i < this->GetLength();i++)
            ptr_new->Append(this->GetIndex(i));
        return ptr_new;
    }

    template <typename Type>
    void LinkedList<Type>::DeleteIndex(int index)
    {
        if(index < 0 || index >= this->GetLength())
            throw "error: index out of range\n";
        LinkedList<Type>* curr_ptr = new LinkedList<Type>();
        
        for( int i = 0; i < index ;i++)
            curr_ptr->Append(this->GetIndex(i));
        for(int i = index + 1;i < this->size;i++)
            curr_ptr->Append(this->GetIndex(i));
        while(head != NULL)
        {
            Node* ptr = head->next;
            delete head;
            head = ptr;
        }
        this->head = curr_ptr->head;
        this->tail = curr_ptr->tail;
        this->size = curr_ptr->size;
    }
    template<typename Type>
    bool LinkedList<Type>:: empty()
    {
        if(this->head == 0)
            return true;
        return false;
    }
    template <typename Type>
    Type LinkedList<Type>::front()
    {
        return this->GetFirst();
    }

    template <typename Type>
     void LinkedList<Type>::pop()
    {
        this->DeleteIndex(0);
    }

    template <typename Type>
    void LinkedList<Type>::push(Type data)
    {
        this->Append(data);
    }
