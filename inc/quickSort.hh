#ifndef SORT_HH
#define SORT_HH

// Funkcja zamieniająca wartości dwóch elementów tablicy
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Funkcja pomocnicza do sortowania QuickSort.
 * Parametry:
 * arr - tablica do posortowania
 * low - indeks początkowy (najniższy)
 * high - indeks końcowy (najwyższy)
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Pivot (element do podziału)
    int i = (low - 1);  // Indeks mniejszego elementu

    for (int j = low; j <= high - 1; j++)
    {
        // Jeśli bieżący element jest mniejszy lub równy pivot
        if (arr[j] <= pivot)
        {
            i++;    // Inkrementacja indeksu mniejszego elementu
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Funkcja sortująca QuickSort.
 * Parametry:
 * arr - tablica do posortowania
 * low - indeks początkowy (najniższy)
 * high - indeks końcowy (najwyższy)
 */
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi jest indeksem podziału, arr[pi] jest już na właściwym miejscu
        int pi = partition(arr, low, high);

        // Rekurencyjnie sortuj elementy przed podziałem i po podziale
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Funkcja wyświetlająca tablicę
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

#endif

