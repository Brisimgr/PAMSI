#ifndef HEAPSORT_HH
#define HEAPSORT_HH


#include <algorithm>
#include <fstream>
#include <chrono>

// Funkcja pomocnicza do sortowania przez kopcowanie - ustawia element największy na pozycji korzenia
void heapify(int arr[], int n, int i)
{
    int largest = i;    // Inicjalizujemy korzeń jako największy element
    int l = 2 * i + 1;  // Indeks lewego dziecka w kopcu
    int r = 2 * i + 2;  // Indeks prawego dziecka w kopcu

    // Jeśli lewe dziecko jest większe od korzenia
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Jeśli prawe dziecko jest większe od korzenia
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Jeśli największy element nie jest korzeniem
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        // Przywracamy kopcowanie dla zmniejszonego kopca
        heapify(arr, n, largest);
    }
}

// Funkcja sortująca przez kopcowanie
void heapSort(int arr[], int n)
{
    // Tworzymy kopiec
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wyjmujemy elementy z kopca w kolejności malejącej
    for (int i = n - 1; i >= 0; i--)
    {
        // Przenosimy korzeń do końca tablicy
        std::swap(arr[0], arr[i]);

        // Przywracamy kopcowanie dla zmniejszonego kopca
        heapify(arr, i, 0);
    }
}
#endif