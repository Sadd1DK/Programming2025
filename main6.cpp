#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void sort_array(short*& arr, const short n) {
    for (short i = 0; i < n - 1; ++i) {
        for (short j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                short temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void free_matrix(short**& mat, const short rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}
void print_matrix(const short rows, const short cols, short** mat) {
    cout << endl;
    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void print_array(const short n, short* arr) {
    cout << endl;
    for (short i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}
void check_input(short& x) {
    cin >> x;
    while (x < 0) {
        cout << "Ошибка ввода" << endl;
        cin >> x;
    }
}
void fill_matrix(short**& mat, const short rows, const short cols, const short c, const short d) {
    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            if (i < 2 && j < 2) {
                continue;
            }
            mat[i][j] = ((i - 1) * c) + ((j - 1) * d);
        }
    }
}
void init_with_values(short*& arr, const short n) {
    for (short i = 0; i < n; ++i) {
        arr[i] = -1;
    }
}
short count_non_negative(short* arr, const short n) {
    short count = 0;
    for (short i = 0; i < n; ++i) {
        if (arr[i] >= 0) {
            ++count;
        }
    }
    return count;
}
bool find_in_array(short*& arr, const short n, const short val) {
    for (short i = 0; i < n; ++i) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}
void insert_unique(short*& arr, const short n, const short val) {
    if (find_in_array(arr, n, val)) {
        return;
    }
    for (short i = 0; i < n; ++i) {
        if (arr[i] == -1) {
            arr[i] = val;
            return;
        }
    }
}
void get_zero_columns(short**& mat, short*& indices, const short rows, const short cols) {
    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                insert_unique(indices, cols, j);
            }
        }
    }
}
void delete_zero_columns(short**& mat, const short rows, const short cols, short* indices, short zero_count, short& new_cols) {
    new_cols = cols - zero_count;
    for (short j = 0; j < zero_count; j++) {
        short remove_col = indices[j] - j;
        for (short col = remove_col; col < cols - 1; col++) {
            for (short row = 0; row < rows; row++) {
                mat[row][col] = mat[row][col + 1];
            }
        }
    }
    for (short i = 0; i < rows; i++) {
        mat[i] = (short*)realloc(mat[i], new_cols * sizeof(short));
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    const short ROWS = 2;
    const short COLS = 2;
    short** matrix = (short**)malloc(ROWS * sizeof(short*));
    for (int i = 0; i < COLS; ++i) {
        matrix[i] = (short*)calloc(COLS, sizeof(short));
    }
    cout << "Ввод матрицы" << endl;
    // Ввод начальных значений матрицы
    cout << "Введите количество добавляемых строк (>=0): ";
    check_input(matrix[0][0]);
    const short TOTAL_ROWS = matrix[0][0] + ROWS;
    cout << "Введите количество добавляемых столбцов (>=0): ";
    check_input(matrix[0][1]);
    const short TOTAL_COLS = matrix[0][1] + COLS;
    cout << "Введите коэффициент C: ";
    cin >> matrix[1][0];
    const short COEF_C = matrix[1][0];
    cout << "Введите коэффициент D: ";
    cin >> matrix[1][1];
    const short COEF_D = matrix[1][1];
    cout << "\nИсходная матрица 2x2:";
    print_matrix(ROWS, COLS, matrix);
    cout << "\nРасширение матрицы до " << TOTAL_ROWS << "x" << TOTAL_COLS << endl;
    matrix = (short**)realloc(matrix, TOTAL_ROWS * sizeof(short*));
    for (short i = 0; i < TOTAL_ROWS; ++i) {
        if (i < 2) {
            matrix[i] = (short*)realloc(matrix[i], TOTAL_COLS * sizeof(short));
        }
        else {
            matrix[i] = (short*)malloc(TOTAL_COLS * sizeof(short));
        }
    }
    fill_matrix(matrix, TOTAL_ROWS, TOTAL_COLS, COEF_C, COEF_D);
    cout << "Расширенная матрица:";
    print_matrix(TOTAL_ROWS, TOTAL_COLS, matrix);
    // Определяем столбцы с нулями
    cout << "\nПоиск столбцов с нулевым значением" << endl;
    short* zero_columns = (short*)calloc(TOTAL_COLS, sizeof(short));
    init_with_values(zero_columns, TOTAL_COLS);
    get_zero_columns(matrix, zero_columns, TOTAL_ROWS, TOTAL_COLS);
    short zero_count = count_non_negative(zero_columns, TOTAL_COLS);
    cout << "Найдено столбцов с нулями: " << zero_count << endl;
    if (zero_count == 0) {
        cout << "Столбцы с нулевыми элементами отсутствуют" << endl;
        free(zero_columns);
        free_matrix(matrix, TOTAL_ROWS);    
    }
    cout << "Индексы столбцов с нулями до сортировки: ";
    print_array(zero_count, zero_columns);
    zero_columns = (short*)realloc(zero_columns, zero_count * sizeof(short));
    sort_array(zero_columns, zero_count);
    cout << "Индексы столбцов с нулями после сортировки: ";
    print_array(zero_count, zero_columns);
    // Удаляем столбцы с нулями
    cout << "\nУдаление столбцов с нулевым значением" << endl;
    short result_cols = 0;
    delete_zero_columns(matrix, TOTAL_ROWS, TOTAL_COLS, zero_columns, zero_count, result_cols);
    cout << "Матрица после удаления " << zero_count << " столбцов: ";
    print_matrix(TOTAL_ROWS, result_cols, matrix);
    free_matrix(matrix, TOTAL_ROWS);
    free(zero_columns);
    // Пункт 2
    cout << "\nПункт 2" << endl;
    float* ptr1 = new float;
    float* ptr2 = new float;
    cout << "Введите первое число: ";
    cin >> *ptr1;
    cout << "Введите второе число: ";
    cin >> *ptr2;
    *ptr1 *= 3;
    cout << "Первое число умножено на 3: " << *ptr1 << endl;
    float tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
    cout << "После обмена значениями: " << endl;
    cout << "Первое число = " << *ptr1 << endl;
    cout << "Второе число = " << *ptr2 << endl;
    delete ptr1;
    delete ptr2;
    return 0;
}
