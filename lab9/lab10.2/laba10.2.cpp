#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void inputMatrix(int* matrix, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(matrix + i * cols + j) = rand() % 21 - 10;
        }
    }
}

void printMatrix(FILE* file, const int* matrix, int rows, int cols, const char* message) {
    fprintf(file, "%s\n", message);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d\t", *(matrix + i * cols + j));
        }
        fprintf(file, "\n");
    }
}

void findMinSumColumn(const int* matrix, int rows, int cols, int* minCol, int* minSum) {
    int* sum = (int*)malloc(cols * sizeof(int));

    for (int j = 0; j < cols; j++) {
        sum[j] = 0;
        for (int i = 0; i < rows; i++) {
            sum[j] += *(matrix + i * cols + j);
        }
    }

    *minSum = sum[0];
    *minCol = 0;
    for (int j = 1; j < cols; j++) {
        if (sum[j] < *minSum) {
            *minSum = sum[j];
            *minCol = j;
        }
    }

    free(sum);
}

void printResults(FILE* file, int minCol, int minSum) {
    fprintf(file, "Столбец с минимальной суммой: %d (сумма = %d)\n", minCol + 1, minSum);
}

int main() {
    setlocale(LC_ALL, "");
    int N[6][5];
    int minCol, minSum;


    // Открытие файла для добавления
    FILE* file = fopen("C:/Users/Konstantin/Desktop/10.0/results.txt", "a");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    inputMatrix(&N[0][0], 6, 5);
    printMatrix(file, &N[0][0], 6, 5, "Матрица N:");
    findMinSumColumn(&N[0][0], 6, 5, &minCol, &minSum);
    printResults(file, minCol, minSum);

    // Закрытие файла
    fclose(file);

    printf("Результаты записаны в файл results.txt\n");

    return 0;
}
