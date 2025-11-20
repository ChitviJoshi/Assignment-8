#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool maxHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (maxHeap) {
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
    } else {
        if (left < n && arr[left] < arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] < arr[largest]) {
            largest = right;
        }
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, maxHeap);
    }
}

void heapSort(int arr[], int n, bool ascending) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, ascending);
    }
    
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, ascending);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr1[n], arr2[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    
    cout << "\nOriginal array: ";
    printArray(arr1, n);
    
    heapSort(arr1, n, true);
    cout << "Sorted in increasing order: ";
    printArray(arr1, n);
    
    heapSort(arr2, n, false);
    cout << "Sorted in decreasing order: ";
    printArray(arr2, n);
    
    return 0;
}
```

**Example Output:**
```
Enter number of elements: 7
Enter 7 elements: 64 34 25 12 22 11 90

Original array: 64 34 25 12 22 11 90 
Sorted in increasing order: 11 12 22 25 34 64 90 
Sorted in decreasing order: 90 64 34 25 22 12 11