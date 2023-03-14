#include <iostream>

/* Klasa stosu stworzona na szablonie, do przechowywania roznych typow danych */
template<typename T>
class Stack{

    private:
        int top_;
        int capacity_;
        T* storage_;   

    public:
        /* Konstruktor */
        Stack();
        /* Dekonstruktor */
        ~Stack();

        //Funkcja dostepowa do sprawdzania
        int getCapacity()const{return capacity_;}
        //Operacje na stosie
        void resize(int const &capacity);
        bool isEmpty()const;
        void push(T const &  value);
        T pop();
        int size()const{return top_;}
        T top()const;
};

template<typename T>
Stack<T>::Stack()
:capacity_(1),top_(0)
{
    storage_ = new T[capacity_];   
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] storage_;
}

/*
Zmiana pojemności stosu

Jeżeli wartość nie jest większa niż
wcześniejszy rozmiar, to bez zmian.
*/
template<typename T>
void Stack<T>::resize(int const &capacity)
{

    if(capacity > this->capacity_)
    {
        T* temp = new T[capacity]; 

        for(int i = 0 ; i < this->top_; ++i )
        {
            temp[i] = this->storage_[i];
        }

        delete[] storage_;

        storage_ = temp; //storage_ wkasuje już na większą pamiec
        temp = nullptr;
        
        this->capacity_ = capacity;
        
    }
    
}

/*
Sprawdzanie czy stos jest pusty.

Jeżeli tak - 1
jeżeli nie - 0;
*/
template<typename T>
bool Stack<T>::isEmpty()const
{
   return(!(top_ > 0));
}

/*
Wyświetlanie górnego elementu stosu
*/
template<typename T>
T Stack<T>::top()const
{
    return storage_[top_ - 1];      
}

/*
Dodawanie do stosu
Jeżeli powiodło się - 1
Jeżeli nie - 0
*/
template<typename T>
void Stack<T>::push(T const &value)
{
   
    if(top_ == capacity_)
    {
        resize(capacity_ * 2);
    }
    storage_[top_] = value;
    ++top_;

}

/*
Usuwa wartosc ze szczytu stosu i zwraca ja

Jezeli stos jest pusty, zwraca podstawowy konstruktor zmiennej
*/
template<typename T>
T Stack<T>::pop()
{
    if(top_ != 0)
    {
          T value = storage_[top_];
        --top_;

        if(top_ == capacity_ / 4) resize(capacity_ / 2);
        return value;
    }
    return 0;
}
