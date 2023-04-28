#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

void buble_sort(long long int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void quick_sort(long long int* arr, int left, int right) {
    int v = arr[(left + right) / 2];
    int i, j, x;
    i = left;
    j = right;
    do
    {
        while (arr[i] < v) i++;
        while (arr[j] > v) j--;
        if (i <= j)
        {
            x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > left) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

void heapify(long long int* arr, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest);
    }
}

// main function to do heap sort 
void heapSort(long long int* arr, int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end 
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap 
        heapify(arr, i, 0);
    }
}

double theTime(clock_t start, clock_t stop) {
    double time = 0.0;
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    return time;
}

int main()
{
    int size, howMany;
    clock_t start, stop;
    cout << "ile liczb chcesz podac: ";
    cin >> size;
    cout << "ile razy chcesz losowac: ";
    cin >> howMany;

    long long int* arr_buble = new long long int[size];
    long long  int* arr_quick = new long long int[size];
    long long int* arr_heap = new long long int[size];
    double time_buble = 0, time_quick = 0, time_heap = 0;

    srand(time(NULL));

    for (int i = 0; i < howMany; i++) {
        for (int j = 0; j < size; j++) {
            arr_buble[j] = rand() % 1000;
            arr_quick[j] = arr_buble[j];
            arr_heap[j] = arr_buble[j];
        }
        start = clock();
        buble_sort(arr_buble, size);
        stop = clock();
        time_buble += theTime(start, stop);
        start = clock();
        quick_sort(arr_quick, 0, size - 1);
        stop = clock();
        time_quick += theTime(start, stop);
        start = clock();
        heapSort(arr_heap, size);
        stop = clock();
        time_heap += theTime(start, stop);
    }

    cout << "BA: " << setprecision(20) << time_buble / howMany << endl;
    cout << "ST: " << setprecision(20) << time_quick / howMany << endl;
    cout << "SZ: " << setprecision(20) << time_heap / howMany << endl;
    delete[] arr_buble;
    delete[] arr_quick;
    delete[] arr_heap;
}


