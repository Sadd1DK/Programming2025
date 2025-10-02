#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X;

    cout << "Enter the number x (not 0): ";
    cin >> X;

    if (X == 0) {
        cout << "X cannot be 0" << endl;
        return 1;
    }

    double reciprocal = 1.0 / X;

    int square = pow(X, 2);
    int fifth_power = pow(X, 5);

    cout << "Reverse number: " << reciprocal << endl;
    cout << "x^2: " << square << endl;
    cout << "x^5: " << fifth_power << endl;

    return 0;

}
