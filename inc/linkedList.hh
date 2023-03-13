#ifndef LINKEDLIST_HH
#define LINKEDLIST_HH

#include<iostream>

template<typename T>
class Node
{
    public:
    T val; 
    Node* next;
    template<typename Y> Node(): val(NULL), next(NULL) {}
    template<typename Y> Node(Y v): val(v), next(NULL) {}
};


template<typename T>
class LinkedList
{
    private:
    Node<T>* head;

    public:
    LinkedList(){this->head = NULL;}
    int howLong();
    T get(int index);
    void display();
    void addAtHead(T val);
    void addAtTail(T val);
    void addAtIndex(int index, T val);
    void deleteAtIndex(int index);
};

template<typename T>
int LinkedList<T>::howLong()
{
    Node<T>* temp = head;

    int howLong = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        ++howLong;
    }

    return howLong;
}

template<typename T>
T LinkedList<T>::get(int index)
{
    Node<T>* temp = head;

    if(head == NULL)
        return -1;
    
    int howLong = this->howLong();

    if(index > howLong-1)
       return -1;

    temp = head;

    for(int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }

    return temp->val;
}

template<typename T>
void LinkedList<T>::display()
{
    Node<T>* temp = head;
    while(temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::addAtHead(T val)
{
    Node<T>* temp = new Node<T>(val);
    temp->next = head;
    head = temp;
}

template<typename T>
void LinkedList<T>::addAtTail(T val)
{
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T>(val);

    if(head == NULL)
    {   
        this->addAtHead(val);
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

template<typename T>
void LinkedList<T>::addAtIndex(int index, T val)
{
    if(head == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    newNode->next = NULL;

    if(index == 0)
    {
        this->addAtHead(val);
        return;
    }
    
    Node<T>* temp = head;

    int howLong = this->howLong();

    if(index == (howLong -1))
    {
        this->addAtTail(val);
        return;
    }
    else if(index > (howLong - 1))
    {
        std::cout << "Index is too big" << std::endl;
        return;
    }

    temp = head;

    for(int i = 0; i < index; ++i)
    {
        if(temp != NULL)
            temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    //delete temp;
}

template<typename T>
void LinkedList<T>::deleteAtIndex(int index)
{
    if(head == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node<T>* temp = head;
    Node<T>* temp2 = NULL;

    if(index == 0)
    {
        head = head->next;
        delete temp;
        return;
    }
    
    int howLong = this->howLong();
    if(index > (howLong - 1))
    {
        std::cout << "Index is too big" << std::endl;
        return;
    }

    for(int i = 0; i < index; ++i)
    {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = temp->next;
    delete temp;
}

#endif
