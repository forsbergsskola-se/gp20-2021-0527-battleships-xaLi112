#include <iostream>
#include <ctime>
using namespace std;

int main() {

    srand (time(NULL));

    cout << rand() %20;
    return 0;
}

//  Number 7: 30 times
//  Number 5: 27 times 
