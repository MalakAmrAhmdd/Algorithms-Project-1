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
        for (int i = n/2 - 1; i >=0 ; i--) {
            heapify(arr, n, i);
        }
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
        heapify(arr,n,0);
        return root;
    }

    ll extractMin(int arr[], int& n){}

};

class PriorityQueue {};

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



    return 0;
}
