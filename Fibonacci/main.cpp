#include <iostream>

using namespace std;

int main() {

    int num, Fibonacci = 0, second = 1, next;

    cout << "Enter the number of terms to be printed in the Fibonacci series" << endl;
    cin >> num; // user enters a number
    
    cout << "Fibonacci series" << endl;

    for (int i = 0; i < num; ++i)
    {
        cout << Fibonacci << endl; // initialized as 0
        next =  Fibonacci + second; // 0 + 1 = 1
        Fibonacci = second; // 1
        second = next;
    }

    return 0;
}
