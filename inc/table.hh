#ifndef TABLE_HH
#define TABLE_HH

#include <iostream>


/*  
Klasa tablicy stworzona na szablonie by moc przechowywac rozne typy danych
*/
template<typename T>
class Table {
public:

    T* data;
    size_t size;
    size_t capacity;

    /*Konstuktor tworzy podstawowa tablice o pojemnosci 5*/
    Table() {
        size = 0; /*aktlualny rozmiar tablicy*/
        capacity = 5; /*pojemnosc tablicy*/
        data = new T[capacity]; /*wskaznik na poczatek tablicy*/
    }

    /*Dekonstruktor usuwa tablice*/
    ~Table() {
        delete[] data;
    }

    /*Dodawanie elementu do tablicy jezeli rozmiar dodawanych elementow jest wiekszy od tablicy powieksz tablice*/
    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity + 1);
        }
        data[size++] = value;
    }

    /*Przeciarzenie operatora [] w clelu otrzymania elementu o danym indeksie*/
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    /*Usuniecie elementu z tablicy !!funkcja nie zmniejsza pojemnosci tablicy!!*/
    void remove(size_t index)
    {
    if (index >= size) {
        throw std::out_of_range("Index out of range.");
        }

    // Usuń element z danego indeksu.
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
        }
    --size;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

private:

    /*Funkcja zmienia rozmiar tablicy */
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    
};

#endif