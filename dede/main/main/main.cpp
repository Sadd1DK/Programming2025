#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int X;

    cout << "Введите число X (не ноль): ";
    cin >> X;

    if (X == 0) {
        cout << "X cannot be 0" << endl;
        return 1;
    }

    // Вычисление обратного числа
    double reciprocal = 1.0 / X;

    // Вычисление степеней
    int square = pow(X, 2);
    int fifth_power = pow(X, 5);

    cout << "Обратное число: " << reciprocal << endl;
    cout << "X во второй степени: " << square << endl;
    cout << "X в пятой степени: " << fifth_power << endl;

    return 0;
}
