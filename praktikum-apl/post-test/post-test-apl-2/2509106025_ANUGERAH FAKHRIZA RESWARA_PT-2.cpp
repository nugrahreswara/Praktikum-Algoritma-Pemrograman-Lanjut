#include <iostream>
#include <string>
using namespace std;

const int MAX_PENGGUNA = 100;
const int MAX_VM = 100;

struct Spesifikasi {
    int cpu;
    int ram;      // dalam GB
    int storage;  // dalam GB
};

struct VM {
    string namaVM;
    string pemilik;   // username pemilik
    string status;    // "running" atau "stopped"
    Spesifikasi spek;
};

struct Pengguna {
    string nama;
    string nim;   // digunakan sebagai password
    string email;
    string role;  // "admin" atau "user"
};

int main() {
    // Inisialisasi data default admin
    Pengguna daftarPengguna[MAX_PENGGUNA];
    VM daftarVM[MAX_VM];
    int jumlahPengguna = 0;
    int jumlahVM = 0;

    // Admin default
    daftarPengguna[0].nama = "Anugerah Fakhriza Reswara";
    daftarPengguna[0].nim = "2509106025";
    daftarPengguna[0].email = "nugrah@nugrah.my.id";
    daftarPengguna[0].role = "admin";
    jumlahPengguna = 1;

    int pilihanAwal;

    // Loop utama untuk login dan registrasi
    while (true) {
        cout << "=== PROGRAM MANAJEMEN VIRTUAL MACHINE & CONTAINER ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Registrasi" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihanAwal;
        cin.ignore();

        // Login
        if (pilihanAwal == 1) {
            int percobaan = 0;
            bool loginBerhasil = false;
            int indeksLogin;
            string roleLogin;

            while (percobaan < 3) {
                cout << "Masukkan username: ";
                string inputNama;
                getline(cin, inputNama);
                cout << "Masukkan password: ";
                string inputNim;
                getline(cin, inputNim);

                for (int i = 0; i < jumlahPengguna; i++) {
                    if (daftarPengguna[i].nama == inputNama && daftarPengguna[i].nim == inputNim) {
                        loginBerhasil = true;
                        indeksLogin = i;
                        roleLogin = daftarPengguna[i].role;
                        break;
                    }
                }

                if (loginBerhasil) {
                    cout << "Login berhasil! Selamat datang, " << daftarPengguna[indeksLogin].nama << endl;
                    break;
                } 
                
                else {
                    percobaan = percobaan + 1;
                    cout << "Login gagal. Percobaan ke-" << percobaan << " dari 3." << endl;
                    if (percobaan == 3) {
                        cout << "Anda telah gagal 3 kali. Kembali ke menu awal." << endl;
                        break;
                    }
                }
            } // while (percobaan < 3)

            if (loginBerhasil) {
                // Menu Admin
                if (roleLogin == "admin") {
                    bool logout = false;
                    while (!logout) {
                        cout << endl << "=== MENU ADMIN ===" << endl;
                        cout << "1. Buat User Baru" << endl;
                        cout << "2. Lihat Semua User" << endl;
                        cout << "3. Ubah Data User" << endl;
                        cout << "4. Hapus User" << endl;
                        cout << "5. Buat VM/Container" << endl;
                        cout << "6. Lihat Semua VM" << endl;
                        cout << "7. Konfigurasi VM" << endl;
                        cout << "8. Operasi VM (Start/Stop/Restart)" << endl;
                        cout << "9. Hapus VM" << endl;
                        cout << "10. Ubah Profil Admin" << endl;
                        cout << "11. Logout" << endl;
                        cout << "12. Keluar" << endl;
                        cout << "Pilih: ";
                        int pilihan;
                        cin >> pilihan;
                        cin.ignore();

                        // Switch Case untuk menu admin
                        switch (pilihan) {
                            // Buat user baru
                            case 1: { 
                                if (jumlahPengguna >= MAX_PENGGUNA) {
                                    cout << "Kapasitas user penuh!" << endl;
                                    break;
                                }

                                Pengguna baru;
                                cout << "Masukkan nama: ";
                                getline(cin, baru.nama);
                                cout << "Masukkan password: ";
                                getline(cin, baru.nim);
                                cout << "Masukkan email: ";
                                getline(cin, baru.email);
                                baru.role = "user";  // default role = user
                                daftarPengguna[jumlahPengguna] = baru;
                                jumlahPengguna++;
                                cout << "User berhasil ditambahkan." << endl;
                                break;
                            }

                            // Lihat semua user
                            case 2: {
                                if (jumlahPengguna == 0) {
                                    cout << "Tidak ada user." << endl;
                                    break;
                                }

                                // Tampilkan tabel
                                cout << "+----+----------------------+----------------------+----------------------+--------+" << endl;
                                cout << "| No | Nama                 | NIM                  | Email                | Role   |" << endl;
                                cout << "+----+----------------------+----------------------+----------------------+--------+" << endl;

                                for (int i = 0; i < jumlahPengguna; i++) {
                                    cout << "| " << i+1;
                                    // Nama
                                    cout << " | " << daftarPengguna[i].nama;
                                    for (int j = daftarPengguna[i].nama.length(); j < 20; j++) cout << " ";
                                    // NIM
                                    cout << " | " << daftarPengguna[i].nim;
                                    for (int j = daftarPengguna[i].nim.length(); j < 20; j++) cout << " ";
                                    // Email
                                    cout << " | " << daftarPengguna[i].email;
                                    for (int j = daftarPengguna[i].email.length(); j < 20; j++) cout << " ";
                                    // Role
                                    cout << " | " << daftarPengguna[i].role;
                                    for (int j = daftarPengguna[i].role.length(); j < 6; j++) cout << " ";
                                    cout << " |" << endl;
                                }

                                cout << "+----+----------------------+----------------------+----------------------+--------+" << endl;
                                break;
                            }

                            // Ubah data user
                            case 3: {
                                // Tampilkan daftar user
				cout << endl;
                                for (int i = 0; i < jumlahPengguna; i++) {
                                    cout << i+1 << ". " << daftarPengguna[i].nama << " (" << daftarPengguna[i].role << ")" << endl;
                                }

                                cout << endl << "Pilih nomor user yang akan diubah: ";
                                int no;
                                cin >> no;
                                cin.ignore();

                                if (no < 1 || no > jumlahPengguna) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int index = no-1;
                                cout << "=== Data lama ===" << endl;
                                cout << "Nama: " << daftarPengguna[index].nama << endl;
                                cout << "NIM: " << daftarPengguna[index].nim << endl;
                                cout << "Email: " << daftarPengguna[index].email << endl;
                                cout << "Role: " << daftarPengguna[index].role << endl;
                                cout << endl << "Masukkan data baru (kosongkan jika tidak diubah):" << endl;
                                string input;
                                cout << "Nama baru: ";
                                getline(cin, input);

                                // Update data di VM juga jika ada VM milik user ini
                                if (!input.empty()) {
                                    string namaLama = daftarPengguna[index].nama;
                                    for (int j = 0; j < jumlahVM; j++) {
                                        if (daftarVM[j].pemilik == namaLama) {
                                            daftarVM[j].pemilik = input;
                                        }
                                    }
                                    daftarPengguna[index].nama = input;
                                }

                                cout << "Password baru: ";
                                getline(cin, input);

                                if (!input.empty()) {
                                    daftarPengguna[index].nim = input;
                                }

                                cout << "Email baru: ";
                                getline(cin, input);

                                if (!input.empty()) {
                                    daftarPengguna[index].email = input;
                                }

                                cout << "Role baru (admin/user): ";
                                getline(cin, input);

                                if (!input.empty() && (input == "admin" || input == "user")) {
                                    daftarPengguna[index].role = input;
                                }

                                cout << "Data berhasil diubah." << endl;
                                break;
                            }

                            // Hapus user
                            case 4: {
                                for (int i = 0; i < jumlahPengguna; i++) {
                                    cout << i+1 << ". " << daftarPengguna[i].nama << " (" << daftarPengguna[i].role << ")" << endl;
                                }

                                cout << "Pilih nomor user yang akan dihapus: ";
                                int no;
                                cin >> no;
                                cin.ignore();

                                if (no < 1 || no > jumlahPengguna) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int index = no-1;

                                // Mencegah agar admin tidak dapat menghapus diri sendiri
                                if (index == indeksLogin) {
                                    cout << "Anda tidak dapat menghapus akun sendiri melalui menu ini. Gunakan menu Ubah Profil jika ingin menghapus diri." << endl;
                                    break;
                                }

                                // Hapus semua VM milik user ini
                                for (int j = 0; j < jumlahVM; j++) {
                                    if (daftarVM[j].pemilik == daftarPengguna[index].nama) {
                                        // Hapus VM dengan menggeser
                                        for (int k = j; k < jumlahVM-1; k++) {
                                            daftarVM[k] = daftarVM[k+1];
                                        }
                                        jumlahVM--;
                                        j--; // karena indeks bergeser
                                    }
                                }

                                // Hapus user dengan menggeser
                                for (int j = index; j < jumlahPengguna-1; j++) {
                                    daftarPengguna[j] = daftarPengguna[j+1];
                                }

                                jumlahPengguna--;
                                cout << "User dan VM-nya telah dihapus." << endl;
                                break;
                            }

                            // Buat VM baru
                            case 5: {
                                if (jumlahVM >= MAX_VM) {
                                    cout << "Kapasitas VM penuh!" << endl;
                                    break;
                                }

                                VM baru;
                                cout << "Masukkan nama VM: ";
                                getline(cin, baru.namaVM);

                                // Cek apakah nama sudah ada? (sederhana, lewati)
                                cout << "Masukkan pemilik (username): ";
                                getline(cin, baru.pemilik);

                                // Cek pemilik ada
                                bool pemilikAda = false;
                                for (int i = 0; i < jumlahPengguna; i++) {
                                    if (daftarPengguna[i].nama == baru.pemilik) {
                                        pemilikAda = true;
                                        break;
                                    }
                                }

                                if (!pemilikAda) {
                                    cout << "Pemilik tidak ditemukan. VM gagal dibuat." << endl;
                                    break;
                                }

                                cout << "Masukkan jumlah CPU: ";
                                cin >> baru.spek.cpu;
                                cout << "Masukkan RAM (GB): ";
                                cin >> baru.spek.ram;
                                cout << "Masukkan Storage (GB): ";
                                cin >> baru.spek.storage;
                                cin.ignore();
                                baru.status = "stopped";
                                daftarVM[jumlahVM] = baru;
                                jumlahVM++;
                                cout << "VM berhasil dibuat." << endl;
                                break;
                            }

                            // Lihat semua VM
                            case 6: {
                                if (jumlahVM == 0) {
                                    cout << "Tidak ada VM." << endl;
                                    break;
                                }

                                cout << "+----+----------------------+----------------------+---------+-----+-----+--------+" << endl;
                                cout << "| No | Nama VM              | Pemilik              | Status  | CPU | RAM | Storage|" << endl;
                                cout << "+----+----------------------+----------------------+---------+-----+-----+--------+" << endl;

                                for (int i = 0; i < jumlahVM; i++) {
                                    cout << "| " << i+1;

                                    // Nama VM
                                    cout << " | " << daftarVM[i].namaVM;

                                    // Pemilik
                                    for (int j = daftarVM[i].namaVM.length(); j < 20; j++) cout << " ";
                                    cout << " | " << daftarVM[i].pemilik;

                                    // Status
                                    for (int j = daftarVM[i].pemilik.length(); j < 20; j++) cout << " ";
                                    cout << " | " << daftarVM[i].status;

                                    // CPU
                                    for (int j = daftarVM[i].status.length(); j < 7; j++) cout << " ";
                                    cout << " | " << daftarVM[i].spek.cpu;
                                    if (daftarVM[i].spek.cpu < 10) {cout << " ";}

                                    // RAM
                                    cout << " | " << daftarVM[i].spek.ram;
                                    if (daftarVM[i].spek.ram < 10) {cout << " ";}

                                    // Storage
                                    cout << " | " << daftarVM[i].spek.storage;
                                    if (daftarVM[i].spek.storage < 10) {cout << " ";}
                                    cout << " |" << endl;
                                }

                                cout << "+----+----------------------+----------------------+---------+-----+-----+--------+" << endl;
                                break;
                            }

                            // Konfigurasi VM (ubah spesifikasi/pemilik)
                            case 7: {
                                if (jumlahVM == 0) {
                                    cout << "Tidak ada VM." << endl;
                                    break;
                                }

                                for (int i = 0; i < jumlahVM; i++) {
                                    cout << i+1 << ". " << daftarVM[i].namaVM << " (pemilik: " << daftarVM[i].pemilik << ")" << endl;
                                }

                                cout << "Pilih nomor VM yang akan dikonfigurasi: ";
                                int no;
                                cin >> no;
                                cin.ignore();

                                if (no < 1 || no > jumlahVM) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int index = no-1;
                                cout << "Data VM saat ini:" << endl;
                                cout << "Nama VM: " << daftarVM[index].namaVM << endl;
                                cout << "Pemilik: " << daftarVM[index].pemilik << endl;
                                cout << "CPU: " << daftarVM[index].spek.cpu << endl;
                                cout << "RAM: " << daftarVM[index].spek.ram << endl;
                                cout << "Storage: " << daftarVM[index].spek.storage << endl;
                                cout << "Status: " << daftarVM[index].status << endl;
                                cout << "Masukkan data baru (kosongkan jika tidak diubah):" << endl;
                                string input;
                                cout << "Nama VM baru: ";
                                getline(cin, input);

                                if (!input.empty()) {
                                    daftarVM[index].namaVM = input;
                                }

                                cout << "Pemilik baru: ";
                                getline(cin, input);

                                // Cek jika ada pemilik vmnya
                                if (!input.empty()) {
                                    bool ada = false;
                                    for (int i = 0; i < jumlahPengguna; i++) {
                                        if (daftarPengguna[i].nama == input) {
                                            ada = true;
                                            break;
                                        }
                                    }

                                    if (ada) {
                                        daftarVM[index].pemilik = input;
                                    }

                                    else {
                                        cout << "Pemilik tidak ditemukan, perubahan dibatalkan." << endl;
                                    }
                                }

                                cout << "CPU baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarVM[index].spek.cpu = stoi(input);
                                }

                                cout << "RAM baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarVM[index].spek.ram = stoi(input);
                                }

                                cout << "Storage baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarVM[index].spek.storage = stoi(input);
                                }

                                cout << "Konfigurasi VM berhasil diubah." << endl;
                                break;
                            }

                            // Operasi VM (start/stop/restart)
                            case 8: {
                                if (jumlahVM == 0) {
                                    cout << "Tidak ada VM." << endl;
                                    break;
                                }

                                for (int i = 0; i < jumlahVM; i++) {
                                    cout << i+1 << ". " << daftarVM[i].namaVM << " (status: " << daftarVM[i].status << ")" << endl;
                                }

                                cout << "Pilih nomor VM: ";
                                int no;
                                cin >> no;
                                cin.ignore();

                                if (no < 1 || no > jumlahVM) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int index = no-1;
                                cout << "Pilih operasi:" << endl;
                                cout << "1. Start" << endl;
                                cout << "2. Stop" << endl;
                                cout << "3. Restart" << endl;
                                cout << "Pilih: ";
                                int op;
                                cin >> op;
                                cin.ignore();

                                if (op == 1) {
                                    daftarVM[index].status = "running";
                                    cout << "VM dijalankan." << endl;
                                }

                                else if (op == 2) {
                                    daftarVM[index].status = "stopped";
                                    cout << "VM dimatikan." << endl;
                                }

                                else if (op == 3) {
                                    daftarVM[index].status = "stopped";
                                    daftarVM[index].status = "running";
                                    cout << "VM direstart." << endl;
                                }

                                else {
                                    cout << "Pilihan tidak valid." << endl;
                                }

                                break;
                            }

                            // Hapus VM
                            case 9: {
                                if (jumlahVM == 0) {
                                    cout << "Tidak ada VM." << endl;
                                    break;
                                }

                                for (int i = 0; i < jumlahVM; i++) {
                                    cout << i+1 << ". " << daftarVM[i].namaVM << endl;
                                }

                                cout << "Pilih nomor VM yang akan dihapus: ";
                                int no;
                                cin >> no;
                                cin.ignore();

                                if (no < 1 || no > jumlahVM) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int index = no-1;

                                for (int j = index; j < jumlahVM-1; j++) {
                                    daftarVM[j] = daftarVM[j+1];
                                }

                                jumlahVM--;
                                cout << "VM dihapus." << endl;
                                break;
                            }

                            // Ubah profil admin sendiri
                            case 10: {
                                int index = indeksLogin;
                                cout << "=== Data profil Anda ===" << endl;
                                cout << "Nama: " << daftarPengguna[index].nama << endl;
                                cout << "NIM: " << daftarPengguna[index].nim << endl;
                                cout << "Email: " << daftarPengguna[index].email << endl;
                                cout << endl << "Masukkan data baru (kosongkan jika tidak diubah):" << endl;
                                string input;
                                cout << "Nama baru: ";
                                getline(cin, input);

                                // Update VM yang dimiliki admin
                                if (!input.empty()) {
                                    string namaLama = daftarPengguna[index].nama;
                                    for (int j = 0; j < jumlahVM; j++) {
                                        if (daftarVM[j].pemilik == namaLama) {
                                            daftarVM[j].pemilik = input;
                                        }
                                    }

                                    daftarPengguna[index].nama = input;
                                }

                                // Update Password
                                cout << "Password baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarPengguna[index].nim = input;
                                }

                                // Update Email
                                cout << "Email baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarPengguna[index].email = input;
                                }

                                cout << "Profil berhasil diubah." << endl;
                                break;
                            }

                            // Logout
                            case 11:
                                logout = true;
                                cout << "Logout berhasil." << endl;
                                break;

                            case 12:
                                cout << "Terima kasih telah menggunakan program." << endl;
                                return 0;

                            default:
                                cout << "Pilihan tidak valid." << endl;

                        } // switch (pilihan)

                    } // while (!logout)

                } // if (roleLogin == "admin")

                // Menu user
                else {
                    bool logout = false;
                    while (!logout) {
                        cout << endl << "=== MENU USER ===" << endl;
                        cout << "1. Lihat VM Saya" << endl;
                        cout << "2. Operasi VM (Start/Stop/Restart)" << endl;
                        cout << "3. Ubah Profil Saya" << endl;
                        cout << "4. Hapus Akun Saya" << endl;
                        cout << "5. Logout" << endl;
                        cout << "6. Keluar" << endl;
                        cout << "Pilih: ";
                        int pilihan;
                        cin >> pilihan;
                        cin.ignore();

                        switch (pilihan) {
                            // Lihat VM milik sendiri
                            case 1: {
                                cout << "Daftar VM milik " << daftarPengguna[indeksLogin].nama << ":" << endl;
                                bool ada = false;

                                for (int i = 0; i < jumlahVM; i++) {
                                    if (daftarVM[i].pemilik == daftarPengguna[indeksLogin].nama) {
                                        ada = true;
                                        cout << "Nama VM: " << daftarVM[i].namaVM
                                            << ", Status: " << daftarVM[i].status
                                            << ", CPU: " << daftarVM[i].spek.cpu
                                            << ", RAM: " << daftarVM[i].spek.ram
                                            << ", Storage: " << daftarVM[i].spek.storage << endl;
                                    }
                                }

                                if (!ada) {
                                    cout << "Anda tidak memiliki VM." << endl;
                                }

                                break;
                            }

                            // Operasi VM milik sendiri
                            case 2: {
                                int daftarIndeks[100];
                                int count = 0;

                                for (int i = 0; i < jumlahVM; i++) {
                                    if (daftarVM[i].pemilik == daftarPengguna[indeksLogin].nama) {
                                        daftarIndeks[count] = i;
                                        cout << count+1 << ". " << daftarVM[i].namaVM << " (status: " << daftarVM[i].status << ")" << endl;
                                        count++;
                                    }
                                }

                                if (count == 0) {
                                    cout << "Anda tidak memiliki VM." << endl;
                                    break;
                                }

                                cout << "Pilih nomor VM: ";
                                int no;
                                cin >> no;
                                cin.ignore();
                                if (no < 1 || no > count) {
                                    cout << "Nomor tidak valid." << endl;
                                    break;
                                }

                                int indexVM = daftarIndeks[no-1];
                                cout << "Pilih operasi:" << endl;
                                cout << "1. Start" << endl;
                                cout << "2. Stop" << endl;
                                cout << "3. Restart" << endl;
                                cout << "Pilih: ";
                                int operasiVM;
                                cin >> operasiVM;
                                cin.ignore();

                                if (operasiVM == 1) {
                                    daftarVM[indexVM].status = "running";
                                    cout << "VM dijalankan." << endl;
                                }
                    
                                else if (operasiVM == 2) {
                                    daftarVM[indexVM].status = "stopped";
                                    cout << "VM dimatikan." << endl;
                                } 

                                else if (operasiVM == 3) {
                                    daftarVM[indexVM].status = "stopped";
                                    daftarVM[indexVM].status = "running";
                                    cout << "VM direstart." << endl;
                                } 
                                
                                else {
                                    cout << "Pilihan tidak valid." << endl;
                                }

                                break;
                            }

                            // Ubah profil sendiri
                            case 3: {
                                int index = indeksLogin;
                                cout << "=== Data profil Anda ===" << endl;
                                cout << "Nama: " << daftarPengguna[index].nama << endl;
                                cout << "NIM: " << daftarPengguna[index].nim << endl;
                                cout << "Email: " << daftarPengguna[index].email << endl;
                                cout << endl << "Masukkan data baru (kosongkan jika tidak diubah):" << endl;
                                string input;
                                cout << "Nama baru: ";
                                getline(cin, input);

                                // Update VM
                                if (!input.empty()) {
                                    string namaLama = daftarPengguna[index].nama;

                                    for (int j = 0; j < jumlahVM; j++) {
                                        if (daftarVM[j].pemilik == namaLama) {
                                            daftarVM[j].pemilik = input;
                                        }
                                    }

                                    daftarPengguna[index].nama = input;
                                }

                                // Update Password
                                cout << "Password baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarPengguna[index].nim = input;
                                }

                                // Update Email
                                cout << "Email baru: ";
                                getline(cin, input);
                                if (!input.empty()) {
                                    daftarPengguna[index].email = input;
                                }

                                cout << "Profil berhasil diubah." << endl;
                                break;
                            }

                            // Hapus akun sendiri
                            case 4: {
                                cout << "Apakah Anda yakin ingin menghapus akun Anda? (y/n): ";
                                string konfirmasi;
                                getline(cin, konfirmasi);

                                if (konfirmasi == "y" || konfirmasi == "Y") {
                                    int index = indeksLogin;

                                    // Hapus semua VM milik user
                                    for (int j = 0; j < jumlahVM; j++) {
                                        if (daftarVM[j].pemilik == daftarPengguna[index].nama) {
                                            for (int k = j; k < jumlahVM-1; k++) {
                                                daftarVM[k] = daftarVM[k+1];
                                            }

                                            jumlahVM--;
                                            j--;
                                        }
                                    }

                                    // Hapus user
                                    for (int j = index; j < jumlahPengguna-1; j++) {
                                        daftarPengguna[j] = daftarPengguna[j+1];
                                    }

                                    jumlahPengguna--;
                                    cout << "Akun Anda telah dihapus. Logout." << endl;
                                    logout = true;
                                } 
                    
                                else {
                                    cout << "Penghapusan dibatalkan." << endl;
                                }

                                break;
                            }

                            // Logout
                            case 5:
                                logout = true;
                                cout << "Logout berhasil." << endl;
                                break;

                            case 6:
                                cout << "Terima kasih telah menggunakan program." << endl;
                                return 0;

                            default:
                                cout << "Pilihan tidak valid." << endl;

                        } // switch (pilihan)

                    } // while (!logout)

                } // else

            } // if (loginBerhasil)

        } // if (pilihanAwal == 1)

        // Registrasi
        else if (pilihanAwal == 2) {
            if (jumlahPengguna >= MAX_PENGGUNA) {
                cout << "Kapasitas user penuh!" << endl;
            } 

            else {
                Pengguna baru;
                cout << "Masukkan nama: ";
                getline(cin, baru.nama);
    
                // Cek apakah nama sudah terdaftar
                bool namaSudahAda = false;
                for (int i = 0; i < jumlahPengguna; i++) {
                    if (daftarPengguna[i].nama == baru.nama) {
                        namaSudahAda = true;
                        break;
                    }
                }

                if (namaSudahAda) {
                    cout << "Nama sudah terdaftar. Gunakan nama lain." << endl;
                }

                else {
                    cout << "Masukkan password: ";
                    getline(cin, baru.nim);
                    cout << "Masukkan email: ";
                    getline(cin, baru.email);
                    baru.role = "user"; // Role default registrasi adalah user
                    daftarPengguna[jumlahPengguna] = baru;
                    jumlahPengguna = jumlahPengguna + 1;
                    cout << "Registrasi berhasil! Silakan login." << endl;
                }
            }
        }

        else if (pilihanAwal == 3) {
            cout << "Terima kasih telah menggunakan program." << endl;
            return 0;
        }

        else {
            cout << "Pilihan tidak valid." << endl;
        }

    } // while (true)

    return 0;

} // main()
