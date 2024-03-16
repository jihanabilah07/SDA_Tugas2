#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int *array, int size) {
    srand(time(NULL)); // Inisialisasi seed berdasarkan waktu saat ini

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Menghasilkan bilangan acak antara 0 sampai 999
    }
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Menukar elemen jika elemen sebelumnya lebih besar dari elemen berikutnya
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                // Mencari indeks elemen terkecil di dalam array
                min_index = j;
            }
        }
        // Menukar elemen terkecil dengan elemen pada indeks ke-i
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

void insertionSort(int *array, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Memindahkan elemen array[0..i-1] yang lebih besar dari key
        // ke satu posisi ke depan dari posisi mereka sekarang
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void saveToFile(int *array, int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file untuk penulisan.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}

int main() {
    int sizes[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    const char *algorithms[] = {"Bubble Sort", "Selection Sort", "Insertion Sort"};

    printf("+----------------+----------------+---------------------+\n");
    printf("| Jenis Algoritma | Jumlah Bilangan | Waktu Eksekusi (ms) |\n");
    printf("+----------------+----------------+---------------------+\n");

    // Bubble Sort
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int size = sizes[i];
        int *numbers = (int *)malloc(size * sizeof(int));

        generateRandomNumbers(numbers, size);

        clock_t start, end;
        double time_taken;

        start = clock();
        bubbleSort(numbers, size);
        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        char size_str[15];
        sprintf(size_str, "%dk", size / 1000);

        printf("| Bubble Sort    | %-14s | %-19.2f |\n", size_str, time_taken);

        char filename[20];
        sprintf(filename, "BubbleSort_%dk.txt", size / 1000);
        saveToFile(numbers, size, filename);

        free(numbers);
    }

    // Selection Sort and Insertion Sort
    for (int j = 0; j < sizeof(algorithms) / sizeof(algorithms[0]); j++) {
        for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
            int size = sizes[i];
            int *numbers = (int *)malloc(size * sizeof(int));

            generateRandomNumbers(numbers, size);

            clock_t start, end;
            double time_taken;

            start = clock();
            if (j == 0) {
                // Skip Bubble Sort
            } else if (j == 1) {
                selectionSort(numbers, size);
            } else if (j == 2) {
                insertionSort(numbers, size);
            }
            end = clock();

            time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

            char size_str[15];
            sprintf(size_str, "%dk", size / 1000);

            printf("| %-14s | %-14s | %-19.2f |\n", algorithms[j], size_str, time_taken);

            char filename[20];
            sprintf(filename, "%s_%dk.txt", algorithms[j], size / 1000);
            saveToFile(numbers, size, filename);

            free(numbers);
        }
    }

    printf("+----------------+----------------+---------------------+\n");

    return 0;
}
