#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct PQItem {
    int value{};
    int priority{};
    bool operator<(const PQItem& other) const {
        if (priority != other.priority) return priority < other.priority;
        return value < other.value;
    }
    bool operator>(const PQItem& other) const {
        if (priority != other.priority) return priority > other.priority;
        return value > other.value;
    }
};
static inline ostream& operator<<(ostream& os, const PQItem& it){
    os << '(' << it.priority << ':' << it.value << ')';
    return os;
}


static const int cap = 100;
template <typename T>
class Heap{
    T arr[cap];
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
    void insert(T key){
        if (n >= cap) { cout << "Heap is full!\n"; return; }
        n++;
        arr[n-1] = key;
        buildheap();
    }

    T extractMax(){
        if(n <= 0) return T{};
        if(n == 1){
            n--;
            return arr[0];
        }
        T root = arr[0];
        arr[0] = arr[n-1];
        n--;
        buildheap();
        return root;
    }

    T extractMin(){
        if(n <= 0) return T{};
        if(n == 1){
            n--;
            return arr[0];
        }
        T minVal = arr[0];
        int min_idx = 0;
        for (int i = 1; i < n; ++i) {
            if(arr[i] < minVal){
                minVal = arr[i];
                min_idx = i;
            }
        }
        swap(arr[n-1],arr[min_idx]);
        n--;
        buildheap();
        return minVal;
    }

    void print(){
        for (int i = 0; i < n; ++i) {
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }
    // helpers
    int size() const { return n; }
    bool empty() const { return n == 0; }
};

class PriorityQueueVP {
    Heap<PQItem> heap;
public:
    void enqueue(int value, int priority){ heap.insert(PQItem{value, priority}); }
    PQItem dequeueMax(){ return heap.extractMax(); }
    PQItem dequeueMin(){ return heap.extractMin(); }
    bool empty() const { return heap.empty(); }
    void print(){ heap.print(); }
};

template <typename T>
class HeapSort {
    T arr[cap];
    int n;
public:
    void heapSort(){
        Heap <ll>h;
        h.buildheap();
        for (int i = n - 1; i >=0 ; i--) {
            swap(arr[0] , arr[i]);
            h.heapify(i);
        }
    }
};


int main() {
    cout << "Welcome to the Heap Program!" << endl;
    Heap<int> h;
    HeapSort<int> hs;
    PriorityQueueVP pq;          // value + priority version

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Heap - Insert element\n";
        cout << "2. Heap - Extract max\n";
        cout << "3. Heap - Extract min\n";
        cout << "4. Heap - Rebuild heap (buildheap)\n";
        cout << "5. Heap - Print\n";
        cout << "6. HeapSort current array\n";
        cout << "7. PriorityQueue (value,priority) - Enqueue\n";
        cout << "8. PriorityQueue (value,priority) - Dequeue max\n";
        cout << "9. PriorityQueue (value,priority) - Dequeue min\n";
        cout << "10. Print current Priority Queue (Value, Priority)\n";
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
                if (h.empty()) { cout << "Heap is empty!\n"; break; }
                int maxVal = h.extractMax();
                cout << "Extracted max: " << maxVal << "\nHeap after extraction: ";
                h.print();
                break;
            }
            case 3: {
                if (h.empty()) { cout << "Heap is empty!\n"; break; }
                int minVal = h.extractMin();
                cout << "Extracted min: " << minVal << "\nHeap after extraction: ";
                h.print();
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
                int v, p;
                cout << "Enter value and priority: ";
                cin >> v >> p;
                pq.enqueue(v, p);
                cout << "Enqueued (P = " << p << ", V = " << v << ")\n";
                break;
            }
            case 8: {
                if (pq.empty()) cout << "PriorityQueue is empty!\n";
                else {
                    PQItem it = pq.dequeueMax();
                    cout << "Dequeued max -> priority = " << it.priority << ", value = " << it.value << "\n";
                }
                break;
            }
            case 9: {
                if (pq.empty()) cout << "PriorityQueue is empty!\n";
                else {
                    PQItem it = pq.dequeueMin();
                    cout << "Dequeued min -> priority = " << it.priority << ", value = " << it.value << "\n";
                }
                break;
            }
            case 10: {
                cout << "Current Priority Queue elements: ";
                pq.print();
                break;
            }
            default:
                cout << "Invalid choice! Please try again\n";
        }
    }
    return 0;
}
