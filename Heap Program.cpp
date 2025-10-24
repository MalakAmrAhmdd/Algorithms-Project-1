#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] <<  " ";
    }
    cout << endl;
}

class Heap{
public:
    void heapify(int arr[],int n , int i){
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
            heapify(arr,n,maxx);
        }
    }
    void buildheap(int arr[], int n){
        for (int i = n/2 - 1; i >=0 ; i--) {
            heapify(arr, n, i);
        }
    }
    void insert(int arr[], int& n, int key){
        n++;
        arr[n-1] = key;
        buildheap(arr, n);
    }

    ll extractMax(int arr[], int& n){
        if(n <= 0) return -1;
        if(n == 1){
            n--;
            return arr[0];
        }
        ll root = arr[0];
        arr[0] = arr[n-1];
        n--;
//        heapify(arr,n,0);
        buildheap(arr, n);
        return root;
    }

    ll extractMin(int arr[], int& n){
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
        buildheap(arr, n);
        return min;
    }
};

class PriorityQueue {
    struct Node {
        int data;
        int priority;
        Node* next;
    };
};

class HeapSort {
public:
    void heapSort(int arr[] ,int n){
        Heap h;
        h.buildheap(arr,n);
        for (int i = n - 1; i >=0 ; i--) {
            swap(arr[0] , arr[i]);
            h.heapify(arr,i,0);
        }
    }
};


int main() {
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    HeapSort hs;
//    Heap h;
//
////    hs.heapSort(arr, n);
////    print(arr, n);
////    cout<< "The max is "<<h.extractMax(arr, n) << endl;
////    cout<< "The min is "<<h.extractMin(arr, n) << endl;
//    h.insert(arr, n, 15);
//    h.buildheap(arr,n);
//    print(arr, n);
    Heap h;
    HeapSort hs;
    PriorityQueue pq;

    cout<< "Enter the number of elements in the heap: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the heap: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    h.buildheap(arr, n);
    while(true){
        cout << "Choose an operation:" << endl;
        cout << "1. Insert element into heap" << endl;
        cout << "2. Extract max from heap" << endl;
        cout << "3. Extract min from heap" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        if(choice == 5) break;
        switch(choice){
            case 1:{
                int key;
                cout << "Enter element to insert: ";
                cin >> key;
                h.insert(arr, n, key);
                cout << "Heap after insertion: ";
                print(arr, n);
                break;
            }
            case 2:{
                ll maxVal = h.extractMax(arr, n);
                if(maxVal != -1){
                    cout << "Extracted max: " << maxVal << endl;
                    cout << "Heap after extraction: ";
                    print(arr, n);
                } else {
                    cout << "Heap is empty!" << endl;
                }
                break;
            }
            case 3:{
                ll minVal = h.extractMin(arr, n);
                if(minVal != -1){
                    cout << "Extracted min: " << minVal << endl;
                    cout << "Heap after extraction: ";
                    print(arr, n);
                } else {
                    cout << "Heap is empty!" << endl;
                }
                break;
            }
            case 4:{
                int size = n;
                hs.heapSort(arr, size);
                cout << "Sorted array: ";
                print(arr, size);
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }



    return 0;
}
