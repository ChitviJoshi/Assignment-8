#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;
    
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    int leftChild(int i) {
        return 2 * i + 1;
    }
    
    int rightChild(int i) {
        return 2 * i + 2;
    }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = temp;
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < size && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < size && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        
        if (i != maxIndex) {
            int temp = heap[i];
            heap[i] = heap[maxIndex];
            heap[maxIndex] = temp;
            heapifyDown(maxIndex);
        }
    }
    
public:
    PriorityQueue() {
        size = 0;
    }
    
    void insert(int value) {
        if (size >= 100) {
            cout << "Priority queue is full" << endl;
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << value << " inserted" << endl;
    }
    
    int extractMax() {
        if (size <= 0) {
            cout << "Priority queue is empty" << endl;
            return -1;
        }
        
        int max = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return max;
    }
    
    int getMax() {
        if (size <= 0) {
            cout << "Priority queue is empty" << endl;
            return -1;
        }
        return heap[0];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
    
    void display() {
        if (size == 0) {
            cout << "Priority queue is empty" << endl;
            return;
        }
        cout << "Priority queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;
    
    while (true) {
        cout << "\n1. Insert element" << endl;
        cout << "2. Extract max" << endl;
        cout << "3. Get max" << endl;
        cout << "4. Display" << endl;
        cout << "5. Get size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.insert(value);
                break;
                
            case 2:
                value = pq.extractMax();
                if (value != -1) {
                    cout << "Extracted max: " << value << endl;
                }
                break;
                
            case 3:
                value = pq.getMax();
                if (value != -1) {
                    cout << "Max element: " << value << endl;
                }
                break;
                
            case 4:
                pq.display();
                break;
                
            case 5:
                cout << "Size: " << pq.getSize() << endl;
                break;
                
            case 6:
                return 0;
                
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}
