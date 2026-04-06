// #include <iostream>
// #include <string>
// using namespace std;
// 
// int main() {
// 
//   // Contoh deklarasi
//   int bilangan[5]; // Array integer, 5 elemen
//   string nama[4]; // Array string, 4 elemen
//   float nilai[10]; // Array float, 10 elemen
// 
//   // Deklarasi array tanpa inisialisasi elemen array
//   int angka[3];
// 
//   angka[0] = 10;
//   angka[1] = 19;
//   angka[2] = 30;
// 
//   // Deklarasi + Inisialisasi langsung
//   //string buah[4] = {"Jeruk", "Mangga", "Nanas", "Apel"};
// 
//   // Penyisipan
//   cout << endl << "=== Penyisipan ===" << endl;
//   string buah[4] = {"Jeruk", "Mangga", "Nanas", "Apel"};
//   buah[4] = "Rambutan";
// 
//   for (int i=0; i<5; i++) {
//     cout << buah[i] << endl;
//   }
// 
//   // Pengaksesan
//   cout << endl << "Pengaksesan:" << endl;
//   cout << buah[0] << endl;
//   cout << angka[2] << endl;
//   cout << endl;
// 
//   // For each perulangan
//   for (string x : buah) {
//     cout << x << endl;
//   }
// 
//   int angkaa[5] = {10, 20, 30, 40, 50};
//   // sizeof(angka) = 20 bytes (5 elemen × 4 bytes per int)
//   // sizeof(angka[0]) = 4 bytes (1 elemen int)
//   int panjang = sizeof(angkaa) / sizeof(angkaa[0]);
//   cout << "Panjang array: " << panjang << endl;
// 
// }

// #include <iostream>
// using namespace std;
// 
// #define MAX_MAHASISWA 100 // Ukuran maksimum array
// 
// int main() {
// 
//     int panjang = 0; // Jumlah data mahasiswa saat ini
//     string mahasiswa[MAX_MAHASISWA]; // Array 1 dimensi
// 
//     int pilihan, index;
// 
//     do {
//         cout << "\n=== MENU PROGRAM DATA MAHASISWA ===" << endl;
//         cout << "1. Tampilkan Mahasiswa" << endl;
//         cout << "2. Tambah Mahasiswa" << endl;
//         cout << "3. Ubah Mahasiswa" << endl;
//         cout << "4. Hapus Mahasiswa" << endl;
//         cout << "5. Keluar" << endl;
//         cout << "Pilihan: ";
//         cin >> pilihan;
// 
//         switch (pilihan) {
// 
//         case 1: // READ
//             if (panjang == 0) {
//                 cout << "Belum ada mahasiswa." << endl;
//             } else {
//                 for (int i = 0; i < panjang; i++) {
//                     cout << "Mahasiswa ke-" << i + 1 
//                          << ": " << mahasiswa[i] << endl;
//                 }
//             }
//             break;
// 
//         case 2: // CREATE
//             if (panjang < MAX_MAHASISWA) {
//                 cout << "Masukkan nama mahasiswa: ";
//                 cin.ignore();
//                 getline(cin, mahasiswa[panjang]);
//                 panjang++;
//                 cout << "Mahasiswa berhasil ditambahkan." << endl;
//             } else {
//                 cout << "Kapasitas penuh!" << endl;
//             }
//             break;
// 
//         case 3: // UPDATE
//             if (panjang == 0) {
//                 cout << "Belum ada mahasiswa untuk diubah." << endl;
//             } else {
//                 for (int i = 0; i < panjang; i++) {
//                     cout << "Mahasiswa ke-" << i + 1 
//                          << ": " << mahasiswa[i] << endl;
//                 }
// 
//                 cout << "Masukkan nomor mahasiswa yang akan diubah: ";
//                 cin >> index;
// 
//                 if (index > 0 && index <= panjang) {
//                     cout << "Masukkan nama baru: ";
//                     cin.ignore();
//                     getline(cin, mahasiswa[index - 1]);
//                     cout << "Data berhasil diubah." << endl;
//                 } else {
//                     cout << "Nomor tidak valid." << endl;
//                 }
//             }
//             break;
// 
//         case 4: // DELETE
//             if (panjang == 0) {
//                 cout << "Belum ada mahasiswa untuk dihapus." << endl;
//             } else {
//                 for (int i = 0; i < panjang; i++) {
//                     cout << "Mahasiswa ke-" << i + 1 
//                          << ": " << mahasiswa[i] << endl;
//                 }
// 
//                 cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
//                 cin >> index;
// 
//                 if (index > 0 && index <= panjang) {
//                     for (int i = index - 1; i < panjang - 1; i++) {
//                         mahasiswa[i] = mahasiswa[i + 1]; 
//                     }
//                     panjang--;
//                     cout << "Mahasiswa berhasil dihapus." << endl;
//                 } else {
//                     cout << "Nomor tidak valid." << endl;
//                 }
//             }
//             break;
// 
//         case 5:
//             cout << "Program selesai." << endl;
//             break;
// 
//         default:
//             cout << "Pilihan tidak valid." << endl;
//         }
// 
//     } while (pilihan != 5);
// 
//     return 0;
// }

// #include <iostream>
// using namespace std;
// 
// int main() {
//   int nilai[2][2][2] = {
//     { // Tingkat ke-0
//       {80, 85}, // Baris ke-0, kolom ke-0 dan kolom ke-1
//       {75, 90}  // Kolom ke-1, kolom ke-0 dan kolom ke-1
//     }, 
// 
//     { // Tingkat ke-1
//       {88, 92}, // Baris ke-0, kolom ke-0 dan kolom ke-1
//       {70, 78}  // Baris ke-0, kolom ke-0 dan kolom ke-1
//     } 
//   };
// 
//   cout << " === DATA NILAI MAHASISWA === \n\n";
// 
//   for (int k = 0; k << 2; k++) {
//     cout << "Kelas " << char('A' + k) << endl;
// 
//     for (int m = 0; m << 2; m++) {
//       cout << " Mahasiswa " << m + 1 << endl;
//       cout << " UTS : " << nilai[k][m][0] << endl;
//       cout << " UAS : " << nilai[k][m][1] << endl;
//     }
//     cout << endl;
//   }
// 
//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// 
// // Struct pertama (untuk Alamat)
// struct Alamat {
//     string jalan;
//     string kota;
// };
// 
// // Struct kedua (Induk) yang mengandung struct Alamat
// struct Mahasiswa {
//     string nama;
//     Alamat domisili; // Inilah Nested Struct
// };
// 
// int main() {
//     Mahasiswa mhs;
// 
//     mhs.nama = "Andi";
//     mhs.domisili.jalan = "Jl. Merdeka No. 10"; // Akses bertingkat
//     mhs.domisili.kota = "Jakarta";
// 
//     cout << mhs.nama << " tinggal di " << mhs.domisili.kota << endl;
// 
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    int tahunTerbit;
};

int main() {
    // Membuat Array of Struct berkapasitas 3 buku
    Buku rak[3];

    // 1. Mengisi data secara manual
    rak[0].judul = "Laskar Pelangi";
    rak[0].penulis = "Andrea Hirata";
    rak[0].tahunTerbit = 2005;

    // 2. Mengisi data menggunakan input user (Looping)
    for(int i = 1; i < 3; i++) {
        cout << "Masukkan Judul Buku ke-" << i << ": ";
        getline(cin >> ws, rak[i].judul); // ws untuk membersihkan buffer
        cout << "Masukkan Penulis: ";
        getline(cin, rak[i].penulis);
        cout << "Masukkan Tahun Terbit: ";
        cin >> rak[i].tahunTerbit;
        cout << "--------------------" << endl;
    }

    // 3. Menampilkan semua data
    cout << "\nDAFTAR BUKU DI RAK:\n";
    for(int i = 0; i < 3; i++) {
        cout << i+1 << ". " << rak[i].judul << " karya " << rak[i].penulis 
             << " (" << rak[i].tahunTerbit << ")" << endl;
    }

    return 0;
}
