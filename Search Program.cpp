#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Sequential_Search{
    int n;
    vector<int> v;
public:
    void take_input(){
        v.resize(n);
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
    }

    void seqSearch(ll x){
        for (int i = 0; i < v.size(); ++i) {
            if(v[i] == x){
                cout << "The element " << x << " is found at index " << i << endl;
                return;
            }
        }
        cout << "The element " << x << " is not found in the array." << endl;
    }
};


int main() {
    std::cout << "Hello from search!" << std::endl;
    return 0;
}