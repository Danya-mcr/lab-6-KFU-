#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    // задание 1А
    float* pa = new float{ 1.5 };
    float* pp = new float{ M_PI };
    cout << "Значения:  " << *pa << "," << *pp << endl;
    cout << "Адрес: " << &pa << "," << &pp << endl;
    cout << "Разность адрессов: " << &pa - &pp << endl;
    cout << "Вес (байт): " << sizeof(pa) << "," << sizeof(pp) << endl;
    
    // задание 1Б
    float* pnums = new float[5] {1.5, M_PI, -0.7, 3.0, -2.4};
    float* pnums1 = &pnums[0];
    float* pnums2 = &pnums[1];
    cout << "Значение 1-ого элемента: " << *pnums << ". Адрес 1-ого элемента: " << pnums << endl;
    cout << "Значение 2-ого элемента: " << *(pnums + 1) << ". Адрес 2-ого элемента: " << pnums + 1 << endl;
    cout << "Значение 5-ого элемента: " << *(pnums + 4) << ". Адрес 5-ого элемента: " << pnums + 4 << endl;
    cout << "Разность адресов 1-ого и 2-ого элемента: " << pnums1 - pnums2;
    
    // задание 1В
    float* pa = new float(1.5 + M_PI);
    float* pp = new float(1.5 - M_PI);
    cout << "Значения переменных: " << *pa << ", " << pp << endl;
    cout << "Адреса переменных: " << pa << ", " << pp << endl;
    cout << "Разность адресов: " << pa - pp;

    // задание 2
    int n, sum_el = 0, min_el = 20 * pow(10, 6), min_el2 = 20 * pow(10, 6), sc_pr = 0; cout << "Введите количество элементов в списке: "; cin >> n;
    int* nums = new int[n];// массив для пункта 1 и 2
    int* nums2 = new int[n]; // массив для пункта 3
    cout << endl << "Введите " << n << " элементов в массив: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) // сумма положительных элементов
            sum_el += nums[i];
        if (nums[i] < min_el) // нахождение min элемента массива
            min_el = nums[i];
    }
    for (int i = 0; i < n; i++) { // нахождение 2-ого min элемента
        if (nums[i] < min_el2 && nums[i] != min_el)
            min_el2 = nums[i];
    }
    for (int i = 0; i < n; i++) { // выполнения условия 3
        if (nums[i] > 0)
            nums2[i] = nums[i] * 10;
        else
            nums2[i] = nums[i] - 100;
        cout << "Элементы второго массива: " << nums2[i] << " ";
        sc_pr += nums[i] * nums2[i];// выполнение условия 4
    }
    cout << endl << "Сумма положительных элементов массива: " << sum_el << endl;
    cout << "Второй минимальный элемент: " << min_el2 << endl;
    cout << "Скалярное произведение: " << sc_pr;
    
    // задание 3
    int n; cout << "Введите размер матрицы: " << endl;; cin >> n;
    int pr = 1, cnt_el = 0;
    int** nums = new int* [n] {};
    int* nums2 = new int[n] {}; // массив для выполнения условия 1
    for (int i = 0; i < n; i++) { // создание первичного многомерного массива
        nums[i] = new int[n];
    }
    for (int i = 0; i < n; i++) { // ввод чисел в матрицу
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    for (int i = 0; i < n; i++) { // вывод чисел из матрицы
        for (int j = 0; j < n; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) { // нахождение кол-ва нулевых эл. матрицы
        for (int j = 0; j < n; j++) {
            if (nums[j][i] == 0) {
                nums2[i]++;
            }
        }
    }
    cout << "Элементы массива 1-ого задания: ";
    for (int i = 0; i < n; i++)// вывод массива задания 1
        cout << nums2[i] << " ";
    cout << endl;
    short cnt = n - 1;// переменная для нахождения чисел в правой диагонали 
    for (int i = 0; i < n; i++) { // произведение чисел в диагонали 2
        for (int j = 0; j < n; j++) {
            if (j == cnt) { // нахождение чисел в правой диагонали
                pr *= nums[i][j];
                cnt--;
            }

        }
    }
    cout << "Произведение диагональных элементов матрицы: " << pr << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && nums[i][j] > 0)
                cnt_el++;
        }
    }
    cout << "Количесвто + элементов над гл диагональю: " << cnt_el;
    
    // задание 4
    short* cnt_per_day = new short[7]; // массив для хранения кол-ва измерений за каждый день
    short max_cnt = 0; // максимально кол-во измерений t в день
    cout << "Введите количество измерений t за каждый день: ";
    for (int i = 0; i < 7; i++) { // создание массива с кол-во измерениями t за каждый день
        cin >> cnt_per_day[i];
        if (cnt_per_day[i] > max_cnt) // нахождение max кол-ва измерений в день
            max_cnt = cnt_per_day[i];
    }
    cout << endl << "Введите температуру: " << endl;
    float** temp = new float* [7] {}; // создание многомерного массива со всей t
    for (int i = 0; i < 7; i++) {
        temp[i] = new float[max_cnt] {};
    }
    for (int i = 0; i < 7; i++) { // заполнение многомерного массива
        for (int j = 0; j < cnt_per_day[i]; j++) {
            cin >> temp[i][j];
        }
    }
    for (int i = 0; i < 7; i++) { // вывод многомерного массива
        for (int j = 0; j < max_cnt; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    short min_t = 32000; // счётчик минимальной t
    for (int i = 0; i < cnt_per_day[0]; i++) { // нахождение min t за первый день
        if (temp[0][i] < min_t)
            min_t = temp[0][i];
    }
    cout << "Минимальная температура за первый день: " << min_t << endl;;
    short cnt_neg = 0; // счётчик отрицательных t
    for (int i = 5; i < 7; i++) { // нахождение кол-ва отрицательных t в выходные
        for (int j = 0; j < cnt_per_day[i]; j++) {
            if (temp[i][j] < 0)
                cnt_neg++;
        }
    }
    cout << "Кол-во отрицательных t в выходные: " << cnt_neg << endl;
    short max_t = 0, day = 1; // max_t - счётчик макс температуры || day - счётчик дней
    for (int i = 0; i < 7; i++) { // нахождение max температуры за неделю
        for (int j = 0; j < max_cnt; j++) {
            if (temp[i][j] > max_t) {
                max_t = temp[i][j];
                day = i + 1;
            }
        }
    }
    cout << "Макс. температура за неделю: " << max_t << " была зафиксирована в";
    switch (day) { // ключ-значение дней недели 
    case 1: cout << " понедельник" << endl; break;
    case 2: cout << "о вторник" << endl; break;
    case 3: cout << " среду" << endl; break;
    case 4: cout << " четверг" << endl; break;
    case 5: cout << " пятницу" << endl; break;
    case 6: cout << " субботу" << endl; break;
    case 7: cout << " воскресенье" << endl; break;
    }
    float mid_t = 0.0; // нахождение ср температуры только за первые дни
    for (int i = 0; i < 7; i++) {
        mid_t += temp[i][0];
    }
    cout << "Средняя температура по первым замерам: " << mid_t / 7.0;

}


