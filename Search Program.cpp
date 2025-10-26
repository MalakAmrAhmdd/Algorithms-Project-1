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


//int main() {
//    cout << "Hello from search!" << std::endl;
//    int n = 5;
//    int arr[] = {1, 3, 5, 6, 7};
//    SequentialSearch<int> seq;
//    printSearchResult(arr, seq.iterative(arr, n, 6));
//    printSearchResult(arr, seq.recursive(arr, n, 8, 0));
//
//    BinarySearch<int> bin;
//    printSearchResult(arr, bin.iterative(arr, n, 4));
//    printSearchResult(arr, bin.recursive(arr, n, 7, 0, n - 1));
//
//
//    return 0;
//}

int main() {
    cout << "Welcome to the Search Program!" << endl;
    char again;

    do {
        cout << "\nChoose a search method:\n";
        cout << "1) Sequential Search (Iterative)\n";
        cout << "2) Sequential Search (Recursive)\n";
        cout << "3) Binary Search (Iterative)\n";
        cout << "4) Binary Search (Recursive)\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;

        cout << "Enter the size of the array: ";
        int n;
        cin >> n;

        int arr[n];
        cout << "Enter " << n << " elements (sorted for binary search): ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << "Enter the value to search for: ";
        int val;
        cin >> val;

        SequentialSearch<int> seq;
        BinarySearch<int> bin;

        cout << "\nResult: ";
        int res = -1;
        switch (choice) {
            case 1:
                res = seq.iterative(arr, n, val);
                break;
            case 2:
                res = seq.recursive(arr, n, val, 0);
                break;
            case 3:
                res = bin.iterative(arr, n, val);
                break;
            case 4:
                res = bin.recursive(arr, n, val, 0, n - 1);
                break;
            default:
                cout << "Invalid choice! Please select from the list.\n";
        }

        printSearchResult(arr, res);

        cout << "\nWould you like to perform another search? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the Search Program!\n";
    cout << "Goodbye!\n";

    return 0;
}