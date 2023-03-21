#ifndef PRIORITYQUEUE_HH
#define PRIORITYQUEUE_HH

#include<iostream>

/* Klasa pojedynczego elementu listy stworzona na szablonie, do przechowywania roznych typow danych */
template<typename T>
class Node
{
    public:
    T val; 
    int priority;
    Node* next;
    /* Konstruktor tworzy pusty element listy*/
    template<typename Y> Node(): val(NULL), priority(0), next(NULL) {}
    /* Konstruktor tworzy element listy o podanej wartosci*/
    template<typename Y> Node(Y v, int p): val(v), priority(p), next(NULL) {}
    /* Dekonstruktor */
    ~Node(){delete[] next;}
};

/* Klasa listy jednokierunkowej stworzona na szablonie, do przechowywania roznych typow danych */
template<typename T>
class PQueue
{
    private:
    Node<T>* head;

    public:
    /* Konstruktor listy jednokierunkowej */
    PQueue(){this->head = NULL;}
    /* Funkcja zwracajaca jak dluga jest lista */
    int howLong();
    /* Funkcja dodająca element do kolejki */
    void push(T v, int p);
    /* Funkcja usuwająca element na szczycie */
    void pop();
    /* Funkcja zwraca element na pierwszym miejscu */
    T getVal(){return head->val;}
    /* Funckja zwraca wartosc priorytetu */
    int getPrio(){return head->priority;}
    /* Funkcja wyszukujaca dany element, ktora zwraca na ktorym miejscu sie znajduje */
    T get(int index);
    /* Funkcja wyswietla wszystkie elementy kolejki */
    void display();
};

template<typename T>
int PQueue<T>::howLong()
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
void PQueue<T>::push(T v, int p)
{

    Node<T>* temp1 = new Node<T>(v, p);
    Node<T>* temp2;

    if(head == NULL || p < head->priority)
    {
        temp1->next = head;
        head = temp1;
    }
    else
    {
        temp2 = head;

        while(temp2->next != NULL && temp2->next->priority <= p)
            temp2 = temp2->next;
        
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

}

template<typename T>
void PQueue<T>::pop()
{
    if(head->next == NULL)
    {
        std::cout << "Kolejka jest pusta." << std::endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    free(temp);
}

template<typename T>
T PQueue<T>::get(int index)
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
void PQueue<T>::display()
{
    Node<T>* temp = head;
    while(temp != NULL)
    {
        std::cout << "Val: " << temp->val << " " << "Prio: " << temp->priority << std::endl;
        temp = temp->next;
    }   
}





#endif
