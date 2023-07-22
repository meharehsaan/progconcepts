#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result << endl;
    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

/* Recursion can be a powerful tool for solving problems that exhibit recursive substructure. However, it can also lead to inefficient solutions and may cause stack overflow errors if the recursion depth becomes too large. In such cases, it is often possible to use an iterative approach or optimize the recursive function to reduce the number of recursive calls.

 */