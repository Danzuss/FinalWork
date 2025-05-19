#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

void initializeArray(int* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 10;
    }
}

void printArrayToFile(const int* arr, int size, FILE* file) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n");
}

void processArray(int* arr, int size, int k1, int k2) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            arr[i] -= arr[k1];
        }
        else {
            arr[i] -= arr[k2];
        }
    }
}

int sumArray(int* arr, int size) {
    if (size == 0) {
        return 0;
    }
    return arr[size - 1] + sumArray(arr, size - 1);
}

void readArrayFromFile(int* arr, int size, FILE* file) {
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
}

int main() {
    setlocale(LC_ALL, "");
    int A[20];
    int k1, k2;

    // Открытие файла для добавления данных
    FILE* file = fopen("E:/Programmirovanie/labworks/lab10/results.txt", "a");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    // Генерация массива случайных чисел, если необходимо
    initializeArray(A, 20);
    k1 = rand() % 20;
    k2 = rand() % 20;

    // Запись исходного массива в файл
    fprintf(file, "Исходный массив A:\n");
    printArrayToFile(A, 20, file);

    // Обработка массива
    processArray(A, 20, k1, k2);
    fprintf(file, "Обработанный массив A:\n");
    printArrayToFile(A, 20, file);

    fprintf(file, "k1 = %d, k2 = %d\n", k1, k2);

    int sum = sumArray(A, 20);
    fprintf(file, "Сумма A: %d\n", sum);

    // Закрытие файла
    fclose(file);

    printf("Результаты сохранены в файл results.txt\n");

    //прочитать данные из файла и использовать их для дальнейшей обработки:
    FILE* readFile = fopen("results.txt", "r");
    if (readFile == NULL) {
        printf("Ошибка открытия файла для чтения!\n");
        return 1;
    }

    // Прочитаем массив из файла (если данные записаны в правильном формате)
    readArrayFromFile(A, 20, readFile);

    //обработаем прочитанный массив:
    processArray(A, 20, k1, k2);
    printf("Обработанный массив из файла: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    fclose(readFile);

    return 0;
}
