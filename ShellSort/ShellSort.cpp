#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
        printf("esc - выход\n");
        ch = _getch();

        switch (ch) {
        case '1': {
            system("cls");
            printf("Введите количество элементов массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));

            f = fopen("input.txt", "w");
            for (int i = 0; i < size; i++) {
                arr[i] = rand() - rand();
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);

            shellSort(arr, size, 1, &count);

            f = fopen("output.txt", "w");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);
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
            for (int i = 0; i < size; i++) {
                arr[i] = rand() - rand();
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);

            shellSort(arr, size, 0, &count);

            f = fopen("output.txt", "w");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);

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
            arr[0] = rand() % 1000;
            for (int i = 1; i < size; i++) {
                arr[i] = arr[i - 1] + rand() % 100 + 1;
            }
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);

            shellSort(arr, size, 0, &count);

            f = fopen("output.txt", "w");
            for (int i = 0; i < size; i++) {
                fprintf(f, "%d ", arr[i]);
            }
            fclose(f);
            free(arr);
            system("pause");
            break;
        }
        }
    } while (ch != 27);
    return 0;
}
