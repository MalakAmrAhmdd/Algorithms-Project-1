#include <iostream>
#define ll long long
using namespace std;

ll RecursiveFib(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return RecursiveFib(n - 1) + RecursiveFib(n - 2);
}

void matrixMultiplication(ll A[2][2], ll B[2][2]) {
    ll result[2][2];

    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (ll k = 0; k < 2; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }

    for (ll i = 0; i < 2; i++)
        for (ll j = 0; j < 2; j++)
            A[i][j] = result[i][j];
}

void powerMatrix(ll A[2][2], ll n) {
    if (n == 0 || n == 1) return;

    ll M[2][2] = {{1, 1},{1, 0}};

    powerMatrix(A, n/2);
    matrixMultiplication(A, A);

    if (n % 2 != 0) matrixMultiplication(A, M);
}

ll MatrixFib(ll n) {
    if (n == 0) return 0;
    ll A[2][2] = {{1, 1},{1, 0}};
    powerMatrix(A, n-1);
    return A[0][0];
}

ll DPFib(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    ll prev2 = 0;
    ll prev1 = 1;
    ll curr = prev1 + prev2;

    for (ll i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    cout << "Welcome to Fibonacci Program!\n";
    char again;

    do {
        cout << "\nChoose a Fibonacci calculation method:\n";
        cout << "1) Recursive Fibonacci\n";
        cout << "2) Matrix Multiplication Fibonacci\n";
        cout << "3) Dynamic Programming Fibonacci\n";
        cout << "Enter your choice (1-3):";

        ll choice; cin >> choice;

        cout << "Enter the number to calculate:";
        ll n; cin >> n;

        cout << "\nResult: ";
        switch (choice) {
            case 1:
                cout << RecursiveFib(n);
            break;
            case 2:
                cout << MatrixFib(n);
            break;
            case 3:
                cout << DPFib(n);
            break;
            default:
                cout << "Invalid choice! Please select from the list\n";
        }

        cout << "\nWould you like to perform another calculation? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the Fibonacci Program!\n";
    cout << "Goodbye!\n";

    return 0;
}