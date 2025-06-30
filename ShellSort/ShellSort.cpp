#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shellSort(int* arr, int size, int srt, long* count = 0) {
    *count = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;

            if (srt) {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                    (*count)++;
                }
            }
            else {
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                    arr[j] = arr[j - gap];
                    (*count)++;
                }
            }
            arr[j] = temp;
            if (j != i) (*count)++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    FILE* f;
    int size;
    int* arr;
    char ch;
    long count = 0;

    do {
        system("cls");
        printf("МЕНЮ:\n");
        printf("1 - Сортировка случайных значений по возрастанию\n");
        printf("2 - Сортировка случайных значений по убыванию\n");
        printf("3 - Сортировка возрастающих значений по убыванию\n");
        printf("4 - Ввод своего массива для сортировки\n");
        printf("esc - выход\n");
        ch = _getch();

        switch (ch) {
        case '1': {
            system("cls");
            printf("Введите количество элементов массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));

            f = fopen("input.txt", "w");
            printf("Исходный массив:\n");
            for (int i = 0; i < size; i++) {
                arr[i] = rand() - rand();
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            time_t start = clock();
            shellSort(arr, size, 1, &count);
            time_t stop = clock();

            f = fopen("output.txt", "w");
            printf("\nОтсортированный массив:\n");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            printf("\nВремя выполнения: %.3lf сек\n", (stop - start) / 1000.0);
            printf("Количество перестановок: %ld\n", count);

            free(arr);
            system("pause");
            break;
        }

        case '2': {
            system("cls");
            printf("Введите количество элементов массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));

            f = fopen("input.txt", "w");
            printf("Исходный массив:\n");
            for (int i = 0; i < size; i++) {
                arr[i] = rand() - rand();
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            time_t start = clock();
            shellSort(arr, size, 0, &count);
            time_t stop = clock();

            f = fopen("output.txt", "w");
            printf("\nОтсортированный массив:\n");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            printf("\nВремя выполнения: %.3lf сек\n", (stop - start) / 1000.0);
            printf("Количество перестановок: %ld\n", count);

            free(arr);
            system("pause");
            break;
        }

        case '3': {
            system("cls");
            printf("Введите количество элементов массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));

            f = fopen("input.txt", "w");
            printf("Исходный массив:\n");
            arr[0] = rand() % 1000;
            for (int i = 1; i < size; i++) {
                arr[i] = arr[i - 1] + rand() % 100 + 1;
            }
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            time_t start = clock();
            shellSort(arr, size, 0, &count);
            time_t stop = clock();

            f = fopen("output.txt", "w");
            printf("\nОтсортированный массив:\n");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            printf("\nВремя выполнения: %.3lf сек\n", (stop - start) / 1000.0);
            printf("Количество перестановок: %ld\n", count);

            free(arr);
            system("pause");
            break;
        }

        case '4': {
            system("cls");
            printf("Введите количество элементов массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));

            printf("Введите %d элементов массива через пробел:\n", size);
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }

            printf("Выберите направление сортировки:\n");
            printf("1 - По возрастанию\n");
            printf("2 - По убыванию\n");
            int srt1 = _getch() == '1' ? 1 : 0;

            f = fopen("input.txt", "w");
            printf("\nИсходный массив:\n");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            time_t start = clock();
            shellSort(arr, size, srt1, &count);
            time_t stop = clock();

            f = fopen("output.txt", "w");
            printf("\nОтсортированный массив:\n");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            printArray(arr, size);
            fclose(f);

            printf("\nВремя выполнения: %.3lf сек\n", (stop - start) / 1000.0);
            printf("Количество перестановок: %ld\n", count);
            free(arr);
            system("pause");
            break;
        }
        }
    } while (ch != 27);
    return 0;
}
