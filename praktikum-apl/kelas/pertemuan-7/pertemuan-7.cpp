#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;
#ifndef HITUNG_H
#define HITUNG_H

int tambah(int a, int b) {
    return a + b;
}

int kali(int a, int b) {
    return a * b;
}
#endif

// Fungsi untuk Contoh Exception Handling (Pointer) [cite: 429]
void cekData(int* ptr) {
    if (ptr == nullptr) { // Perbaikan sintaks dari PDF: ptr == nullptr
        throw runtime_error("Error: Pointer bernilai NULL!"); [cite: 431]
    }
    cout << "Nilai dalam pointer: " << *ptr << endl; [cite: 438]
}

// Fungsi untuk Contoh Print Debugging [cite: 471]
int hitungFaktorial(int n) {
    int hasil = 1;
    cout << "[DEBUG] Memulai perhitungan untuk n = " << n << endl; [cite: 473]
    for (int i = 1; i <= n; i++) {
        hasil = hasil * i;
        // Melacak perubahan nilai 'hasil' di setiap perulangan [cite: 478]
        cout << "[DEBUG] Iterasi ke-" << i << ", hasil sementara: " << hasil << endl;
    }
    return hasil;
}

// Fungsi untuk Pendeteksi Kesalahan Otomatis [cite: 503]
void laporError(const string& pesan, const char* file, int baris, const char* fungsi) {
    stringstream ss;
    ss << "\n[CRITICAL ERROR DETECTED!]\n";
    ss << "--------------------------\n";
    ss << "Pesan  : " << pesan << endl; [cite: 510]
    ss << "File   : " << file << endl; [cite: 511]
    ss << "Fungsi : " << fungsi << "()" << endl; [cite: 513]
    ss << "Baris  : " << baris << endl; [cite: 514]
    ss << "--------------------------\n";
    throw runtime_error(ss.str()); [cite: 524]
}

// Makro ASSERT untuk pengecekan kondisi [cite: 525]
#define ASSERT(kondisi, pesan) \
    if (!(kondisi)) { \
        laporError(pesan, __FILE__, __LINE__, __func__); \
    }

void prosesData(int index, int pembagi) {
    cout << "Sedang memproses data..." << endl; [cite: 530]
    ASSERT(pembagi != 0, "Dilarang membagi dengan nol!"); // Perbaikan logika: pembagi != 0 [cite: 531]
    ASSERT(index <= 10, "Akses index melebihi batas array (Out of Range)!"); [cite: 532]
    int hasil = 100 / pembagi;
    cout << "Hasil proses: " << hasil << endl; [cite: 536]
}

int main() {
    cout << "=== LAPORAN PERTEMUAN MODUL 8: ERROR HANDLING & LIBRARY ===\n" << endl;

    // --- Skenario 1: Dasar Try-Catch (Pembagian) --- [cite: 357]
    try {
        int a = 10, b = 0;
        if (b == 0) throw runtime_error("Error pembagian dengan 0"); [cite: 365]
        cout << "Hasil: " << a / b << endl;
    } catch (const runtime_error& e) {
        cout << "Exception 1 ditangkap: " << e.what() << endl; [cite: 370]
    }

    // --- Skenario 2: Input Validation --- [cite: 387]
    try {
        int angka = -5; // Contoh nilai negatif untuk memicu error
        if (angka < 0) throw runtime_error("Bilangan harus bernilai positif!"); [cite: 399]
    } catch (const exception& e) {
        cout << "Exception 2 ditangkap: " << e.what() << endl; [cite: 411]
    }

    // --- Skenario 3: Pointer Check --- [cite: 441]
    try {
        int* dataKosong = nullptr;
        cekData(dataKosong); [cite: 446]
    } catch (const runtime_error& e) {
        cout << "Exception 3 ditangkap: " << e.what() << endl; [cite: 449]
    }

    // --- Skenario 4: Debugging Faktorial --- [cite: 484]
    int hasilFaktorial = hitungFaktorial(5);
    cout << "Hasil Akhir Faktorial: " << hasilFaktorial << endl << endl; [cite: 495]

    // --- Skenario 5: Internal Library (cmath & vector) --- [cite: 568]
    double val = 16.0;
    cout << "Akar dari " << val << " adalah: " << sqrt(val) << endl; [cite: 569]
    vector<int> data = {50, 10, 30, 20, 40}; [cite: 571]
    sort(data.begin(), data.end());
    cout << "Data vector terurut: ";
    for (int n : data) cout << n << " "; [cite: 572]
    cout << endl << endl;

    // --- Skenario 6: External Library (hitung.h) --- [cite: 579]
    int x = 10, y = 5;
    cout << "Hasil Tambah (Library): " << tambah(x, y) << endl; [cite: 581]
    cout << "Hasil Kali (Library)  : " << kali(x, y) << endl << endl; [cite: 582]

    // --- Skenario 7: Critical Error Detection --- [cite: 538]
    try {
        prosesData(15, 5); // Akan memicu ASSERT out of range [cite: 555]
    } catch (const exception& e) {
        cout << e.what() << endl; [cite: 557]
    }

    cout << "Program selesai dijalankan." << endl; [cite: 414]
    return 0;
}
