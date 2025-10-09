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
    double obratnoe = 1.0 / X;

    // Вычисление степеней
    int stepenDva = pow(X, 2);
    int stepenPyat = pow(X, 5);

    cout << "Обратное число: " << obratnoe << endl;
    cout << "X во второй степени: " << stepenDva << endl;
    cout << "X в пятой степени: " << stepenPyat << endl;

    return 0;
}
