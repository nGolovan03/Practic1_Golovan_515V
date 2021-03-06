/*
* @file practice_2021.cpp
* @author Головань Н.И. , 515-В
* @date 1 июля 2021 г.
* @brief Учебная практика
*/
#include<stdio.h> 
#include<locale.h> 
#include<time.h> 
#include<stdlib.h> 
#define N 1000

int i;
//Прототипы функций
void rand_r(int*);
void findRepeats(int*);
void print(int*);

int main() {
    //Включение русского языка
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    int arr[N];
    rand_r(arr);
    print(arr);
    findRepeats(arr);
}
//Функция для заполнения массива случайными значениями 
void rand_r(int* arr) {
    for (i = 0; i < N; i++) {
        *(arr + i) = rand() % 15 - 10;
    }
}
//Функция для вывода массива на экран
void print(int* arr) {
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}
//Функция для нахождения наибольшей послеовательности нулей
void findRepeats(int* arr) {
    int repeats = 0;
    int x = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] == 0) {
            repeats++;
        }
        else {
            if (repeats < x) {
                repeats = 0;
            }
            else {
                x = repeats;
                repeats = 0;
            }
        }
    }
    printf("\nКолчиство нулей подряд:%d", x);
}