#include <bits/stdc++.h>
#define ll long long
using namespace std;


static const int cap = 100;
class Heap{
    int arr[cap];
    int n = 0;
public:
    void heapify(int i){
        int left = 2 * i +1;
        int right = 2 * i +2;
        int maxx = i;
        if(left < n && arr[left] > arr[maxx]){
            maxx = left;
        }
        if(right < n &&arr[right] > arr[maxx]){
            maxx = right;
        }
        if(maxx!=i){
            swap(arr[i], arr[maxx]);
            heapify(maxx);
        }
    }
    void buildheap(){
        for (int i = n/2 - 1; i >=0 ; i--) {
            heapify(i);
        }
    }
    void insert(int key){
        n++;
        arr[n-1] = key;
        buildheap();
    }

    ll extractMax(){
        if(n <= 0) return -1;
        if(n == 1){
            n--;
            return arr[0];
        }
        ll root = arr[0];
        arr[0] = arr[n-1];
        n--;
//        heapify(arr,n,0);
        buildheap();
        return root;
    }

    ll extractMin(){
        if(n <= 0) return -1;
        if(n == 1){
            n--;
            return arr[0];
        }
        ll min = arr[0], min_idx = 0;
        for (int i = 1; i < n; ++i) {
            if(arr[i] < min){
                min = arr[i];
                min_idx = i;
            }
        }
        swap(arr[n-1],arr[min_idx]);
        n--;
        buildheap();
        return min;
    }

    void print(){
        for (int i = 0; i < n; ++i) {
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }
};
class PriorityQueue {
    Heap heap;
//    int arr[cap];
//    int n;
public:
    void enqueue(int element){
        heap.insert(element);
    }

    ll dequeueMax(){
        return heap.extractMax();
    }

    ll dequeueMin(){
        return heap.extractMin();
    }

    void print(){
        heap.print();
    }

};

class HeapSort {
    int arr[cap];
    int n;
public:
    void heapSort(){
        Heap h;
        h.buildheap();
        for (int i = n - 1; i >=0 ; i--) {
            swap(arr[0] , arr[i]);
            h.heapify(i);
        }
    }
};


int main() {
    cout << "Welcome to the Heap Program!" << endl;
    Heap h;
    HeapSort hs;
    PriorityQueue pq;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Heap - Insert element\n";
        cout << "2. Heap - Extract max\n";
        cout << "3. Heap - Extract min\n";
        cout << "4. Heap - Rebuild heap (buildheap)\n";
        cout << "5. Heap - Print\n";
        cout << "6. HeapSort current array\n";
        cout << "7. PriorityQueue - Enqueue\n";
        cout << "8. PriorityQueue - Dequeue max\n";
        cout << "9. PriorityQueue - Dequeue min\n";
        cout << "10. Print current Priority Queue\n";
        cout << "11. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 11) break;

        switch (choice) {
            case 1: {
                int key;
                cout << "Enter element to insert: ";
                cin >> key;
                h.insert(key);
                cout << "Heap after insertion: ";
                h.print();
                break;
            }
            case 2: {
                ll maxVal = h.extractMax();
                if (maxVal != -1) {
                    cout << "Extracted max: " << maxVal << "\nHeap after extraction: ";
                    h.print();
                } else {
                    cout << "Heap is empty!\n";
                }
                break;
            }
            case 3: {
                ll minVal = h.extractMin();
                if (minVal != -1) {
                    cout << "Extracted min: " << minVal << "\nHeap after extraction: ";
                    h.print();
                } else {
                    cout << "Heap is empty!\n";
                }
                break;
            }
            case 4: {
                h.buildheap();
                cout << "Heap rebuilt.\nCurrent heap: ";
                h.print();
                break;
            }
            case 5: {
                cout << "Heap: ";
                h.print();
                break;
            }
            case 6: {
                hs.heapSort();
                cout << "Sorted array: ";
                h.print();
                break;
            }
            case 7: {
                int x;
                cout << "Enter element to enqueue (priority is the value itself): ";
                cin >> x;
                pq.enqueue(x);
                cout << "Enqueued.\n";
                break;
            }
            case 8: {
                ll v = pq.dequeueMax();
                if (v != -1) cout << "Dequeued max: " << v << "\n";
                else cout << "PriorityQueue is empty!\n";
                break;
            }
            case 9: {
                ll v = pq.dequeueMin();
                if (v != -1) cout << "Dequeued min: " << v << "\n";
                else cout << "PriorityQueue is empty!\n";
                break;
            }
            case 10: {
                cout << "Current Priority Queue elements: ";
                pq.print();
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
