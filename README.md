# SDA_Tugas2

### README

#### Deskripsi
Program ini adalah implementasi sederhana dari tiga algoritma pengurutan, yaitu Bubble Sort, Selection Sort, dan Insertion Sort. Program ini memiliki beberapa fitur, antara lain:
- Mampu menghasilkan sejumlah bilangan secara acak.
- Melakukan pengurutan bilangan menggunakan tiga algoritma yang ditentukan.
- menghitung waktu yang diperlukan untuk setiap algoritma pengurutan dengan jumlah bilangan yang ditingkatkan sebanyak 100 ribu pada setiap proses pencatatan waktu.
- Menyimpan bilangan sebelum dan setelah pengurutan ke dalam file teks.

###Fungsi yang Digunakan dalam Kode Program
1. `generateRandomNumbers(int *array, int size)` : Fungsi ini digunakan untuk mengisi array dengan bilangan bulat acak antara 0 hingga 999.
2. `bubbleSort(int *array, int size)`: Fungsi ini mengurutkan array menggunakan algoritma Bubble Sort.
3. `selectionSort(int *array, int size)`: Fungsi ini mengurutkan array menggunakan algoritma Selection Sort.
4. `insertionSort(int *array, int size)`: Fungsi ini mengurutkan array menggunakan algoritma Insertion Sort.
5. `saveToFile(int *array, int size, const char *filename)`: Fungsi ini menyimpan isi array ke dalam sebuah berkas dengan nama yang diberikan.

#### Cara Menjalankan Kode Program
1. Buat code program dan simpan dalam sebuah file dengan ekstensi `.c`.
2. Compile program menggunakan kompilator C (dalam hal ini saya menggunakan GCC) dengan perintah `gcc nama_file.c -o nama_program`. contoh: `gcc 2208107010035_Simple_Sorting.c -o sorting`
3. Jalankan program dengan mengetikkan `./nama_program` di terminal atau command prompt. contoh: `./sorting`
