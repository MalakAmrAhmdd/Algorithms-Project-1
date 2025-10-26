#include <bits/stdc++.h>
#define ll long long
using namespace std;

void printSearchResult(int arr[], int i) {
    if (i == -1) {
        cout << "The element is not found in the array." << endl;
    }
    else {
        cout << "The element " << arr[i] << " is found at index " << i << endl;
    }
}

template <typename T>
class SequentialSearch {
public:
    int iterative(T arr[], int n, T val){
        for (int i = 0; i < n; ++i) {
            if(arr[i] == val){
                return i;
            }
        }
        return -1;
    }
    int recursive(T arr[], int n, T val, int i) {
        if (i == n) {
            return -1;
        }
        else if (arr[i] == val) {
            return i;
        }
        else {
            return recursive(arr, n, val, i + 1);
        }
    }
};

template <typename T>
class BinarySearch {
public:
    int iterative(T arr[], int n, T val) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > val) {
                r = mid - 1;
            }
            else if (arr[mid] < val) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    int recursive(T arr[], int n, T val, int l, int r) {
        if (l > r) return -1;

        int mid = (l + r) / 2;
        if (arr[mid] > val) {
            return recursive(arr, n, val, l, mid - 1);
        } else if (arr[mid] < val) {
            return recursive(arr, n, val, mid + 1, r);
        } else {
            return mid;
        }
    }
};


int main() {
    cout << "Hello from search!" << std::endl;
    int n = 5;
    int arr[] = {1, 3, 5, 6, 7};
    SequentialSearch<int> seq;
    printSearchResult(arr, seq.iterative(arr, n, 6));
    printSearchResult(arr, seq.recursive(arr, n, 8, 0));

    BinarySearch<int> bin;
    printSearchResult(arr, bin.iterative(arr, n, 4));
    printSearchResult(arr, bin.recursive(arr, n, 7, 0, n - 1));
    return 0;
}