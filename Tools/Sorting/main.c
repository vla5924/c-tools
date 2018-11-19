#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
#define K 10

void gen(int a[], int n);
void output(int a[], int n);

void choosing_sort(int a[], int n);
void insert_sort(int a[], int n);
void bubble_sort(int a[], int n);
void counting_sort(int a[], int n);

void main() {
    int a[N], algo;
    setlocale(LC_ALL, "Russian");
    gen(a, N);
    printf("Исходный массив:        ");
    output(a, N);
    printf("Алгоритм сортировки:       ");
    scanf("%d", &algo);
    switch (algo) {
    case 1:
        choosing_sort(a, N);
        break;
    case 2:
        insert_sort(a, N);
        break;
    case 3:
        bubble_sort(a, N);
        break;
    case 4:
        counting_sort(a, N);
        break;
    default:
        printf("Неверный номер.\n");
        return;
    }
    printf("Отсортированный массив: ");
    output(a, N);
}

void gen(int a[], int n) {
    int i;
    srand((unsigned)time(0));
    for (i = 0; i < n; i++) {
        a[i] = rand() % (5 - 0 + 1) + 0;
    }
}

void output(int a[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        printf("%4d", a[i]);
    }
    printf("%4d\n", a[n - 1]);
}

void choosing_sort(int a[], int n)
{
    int i, j, min, minidx;
    for(i = 0; i < n; i++) {
        min = a[i];
        minidx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                minidx = j;
            }
        }
        a[minidx] = a[i];
        a[i] = min;
    }
}

void insert_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j]>temp)) {
            a[j + 1] = a[j];
            a[j--] = temp;
        }
    }
}

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (a[j - 1]>a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void counting_sort(int a[], int n)
{
    int count[K] = { 0 };
    int idx = 0, i, j;
    for (i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (i = 0; i < K; i++) {
        for (j = 0; j < count[i]; j++) {
            a[idx++] = i;
        }
    }
}
