#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Задание 1
    short A;
    cout << "Введите число A (short): ";
    cin >> A;

    int i;
    cout << "Введите номер бита i (0-7): ";
    cin >> i;

    // Проверка правильности ввода i
    if (i < 0 || i > 7) {
        cout << "Ошибка: номер бита должен быть от 0 до 7" << endl;
        return 1;
    }

    // Вывод числа в бинарном виде (первые 8 бит)
    cout << A << " = ";
    for (int j = 7; j >= 0; j--) {
        cout << ((A >> j) & 1);
    }
    cout << endl;

    // Получаем значение i-го бита в отдельную переменную
 int KolichestvoBitov = (A >> i) & 1;

 // Тернарный оператор для получения значения флага
 string  normILIstrem = (KolichestvoBitov == 1) ? "установлен" : "не установлен";
 cout << "Бит " << i << " " << normILIstrem << " (" << KolichestvoBitov << ")" << endl;

 // Проверка условия
 if (KolichestvoBitov != 0) {
        // Изменяем i-й бит на противоположный
        A = A ^ (1 << i);
        cout << "Результат после изменения бита: " << A << " = ";
        for (int j = 7; j >= 0; j--) {
            cout << ((A >> j) & 1);
        }
        cout << endl;
    }
    else {
        // Вводим два целых числа
        int num1, num2;
        cout << "Введите два целых числа: ";
        cin >> num1 >> num2;

        // Определяем максимальное по модулю
        int maxAbs = (abs(num1) > abs(num2)) ? num1 : num2;
        maxAbs = (abs(num1) == abs(num2)) ? num1 : maxAbs; // если равны по модулю

        cout << "Максимальное по модулю: " << maxAbs << maxAbs << endl;
    }

    cout << endl;
    // Задание 2
    int N, M;
    cout << "Введите цифру N (не 0): ";
    cin >> N;
    cout << "Введите цифру M (не 0): ";
    cin >> M;

    // Формируем двузначное число
    int number = N * 10 + M;

    // Проверяем, является ли число дублем
    if (N == M) {
        switch (number) {
        case 11:
            cout << "Барабанные палочки" << endl;
            break;
        case 22:
            cout << "Утята" << endl;
            break;
        case 33:
            cout << "Тридцать три" << endl;
            break;
        case 44:
            cout << "Стульчики" << endl;
            break;
        case 55:
            cout << "Перчатки" << endl;
            break;
        case 66:
            cout << "Валенки" << endl;
            break;
        case 77:
            cout << "Топорики" << endl;
            break;
        case 88:
            cout << "Бабушка" << endl;
            break;
        case 99:
            cout << "Дедушка" << endl;
            break;
        default:
            cout << "Номер не дубль" << endl;
        }
    }
    else {
        cout << "Номер не дубль" << endl;
    }

    return 0;

}
