/*
Nama: Anugerah Fakhriza Reswara
NIM: 2509106025
Kelas: Informatika A2'25
Praktikum: Algoritma Pemrograman Lanjut
Posttest: 1
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variabel Login
    string username = "Anugerah Fakhriza Reswara";
    string password = "025";
    string inputUsername;
    string inputPassword;
    int percobaanLogin = 0;
    int maksimalPercobaan = 3;
    bool statusLogin = false;

    // Variabel Menu
    int pilihanMenu;
    double nilaiInput;
    double hasilMeter;
    double hasilKilometer;
    double hasilSentimeter;
    bool lanjutProgram = true;

    cout << "========================================" << endl;
    cout << "            PROGRAM KONVERSI            " << endl;
    cout << "========================================" << endl << endl;

    while (percobaanLogin < maksimalPercobaan) {
        cout << "========================================" << endl;
        cout << "             SILAHKAN LOGIN             " << endl;
        cout << "========================================" << endl << endl;
        cout << "Masukkan Username : ";
        getline(cin, inputUsername);
        cout << "Masukkan Password : ";
        cin >> inputPassword;
        cout << endl;

        if (inputUsername == username && inputPassword == password) {
            statusLogin = true;
            cout << "Login Berhasil! Selamat Datang, " << username << endl;
            cout << endl;
            break;
        }

        else {
            percobaanLogin = percobaanLogin + 1;
            cout << "Username atau Password Salah!" << endl;
            cout << "Sisa kesempatan: " << (maksimalPercobaan - percobaanLogin) << endl;
            cout << endl;
            
            // Membersihkan buffer input jika login gagal agar getline berikutnya tidak error
            cin.ignore(); 
        }
    }

    if (statusLogin == false) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0; 
    }

    // Menu utama
    while (lanjutProgram == true) {
        cout << "============================================" << endl;
        cout << "                 MENU UTAMA                " << endl;
        cout << "============================================" << endl;
        cout << "1. Konversi Sentimeter -> Meter & Kilometer" << endl;
        cout << "2. Konversi Meter ->  Sentimeter & Kilometer" << endl;
        cout << "3. Konversi Kilometer -> Sentimeter & Meter" << endl;
        cout << "4. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Masukkan Pilihan Menu (1-4): ";
        cin >> pilihanMenu;
        cout << endl;

        // Konversi Sentimeter
        if (pilihanMenu == 1) {
            cout << "=== Konversi Sentimeter ===" << endl;
            cout << "Masukkan nilai dalam Sentimeter: ";
            cin >> nilaiInput;

            hasilMeter = nilaiInput / 100;
            hasilKilometer = nilaiInput / 100000;

            cout << "Hasil Konversi:" << endl;
            cout << nilaiInput << " Sentimeter = " << hasilMeter << " Meter" << endl;
            cout << nilaiInput << " Sentimeter = " << hasilKilometer << " Kilometer" << endl << endl;

        // Konversi Meter
        } else if (pilihanMenu == 2) {
            cout << "=== Konversi Meter ===" << endl;
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilaiInput;

            hasilSentimeter = nilaiInput * 100;
            hasilKilometer = nilaiInput / 1000;

            cout << "Hasil Konversi:" << endl;
            cout << nilaiInput << " Meter = " << hasilSentimeter << " Sentimeter" << endl;
            cout << nilaiInput << " Meter = " << hasilKilometer << " Kilometer" << endl << endl;

        // Konversi Kilometer
        } else if (pilihanMenu == 3) {
            cout << "=== Konversi Kilometer ===" << endl;
            cout << "Masukkan nilai dalam Kilometer: ";
            cin >> nilaiInput;

            hasilSentimeter = nilaiInput * 100000;
            hasilMeter = nilaiInput * 1000;

            cout << "Hasil Konversi:" << endl;
            cout << nilaiInput << " Kilometer = " << hasilSentimeter << " Sentimeter" << endl;
            cout << nilaiInput << " Kilometer = " << hasilMeter << " Meter" << endl << endl;

	// Keluar program
        } else if (pilihanMenu == 4) {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            lanjutProgram = false; 

	// Pilihan menu tidak valid
        } else {
            cout << "Pilihan menu tidak valid! Silakan pilih 1-4." << endl << endl;
        }
    }

    return 0;
}
