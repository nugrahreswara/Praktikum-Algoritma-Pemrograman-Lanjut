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

// Fungsi rekursif untuk mencetak garis pemisah tabel
void cetakGaris(int panjang, char karakter = '-') {
    if (panjang <= 0) return;
    cout << karakter;
    cetakGaris(panjang - 1, karakter);
}

// Fungsi bantu untuk mencetak string dengan lebar tetap (rata kiri)
void cetakDenganLebar(string teks, int lebar) {
    cout << " " << teks;
    for (int i = teks.length(); i < lebar; i++) cout << " ";
    cout << " ";
}

// Overloading fungsi lihatVM: untuk admin (melihat semua VM)
void lihatVM(VM daftarVM[], int jumlahVM) {
    if (jumlahVM == 0) {
        cout << "Tidak ada VM." << endl;
        return;
    }

    // Hitung lebar maksimum setiap kolom
    int maxNamaVM = 8; // panjang "Nama VM"
    int maxPemilik = 7; // "Pemilik"
    int maxStatus = 6; // "Status"
    for (int i = 0; i < jumlahVM; i++) {
        int len = daftarVM[i].namaVM.length();
        if (len > maxNamaVM) maxNamaVM = len;
        len = daftarVM[i].pemilik.length();
        if (len > maxPemilik) maxPemilik = len;
        len = daftarVM[i].status.length();
        if (len > maxStatus) maxStatus = len;
    }
    int lebarNo = 2; // nomor maksimal 99 (karena MAX_VM=100, tapi 100 butuh 3 digit, kita set 3)
    if (jumlahVM >= 10) lebarNo = 2;
    if (jumlahVM >= 100) lebarNo = 3;
    int lebarCPU = 3;
    int lebarRAM = 3;
    int lebarStorage = 7; // "Storage"

    // Garis atas
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNamaVM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxPemilik+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxStatus+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarCPU+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarRAM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarStorage+2; i++) cout << "-";
    cout << "+" << endl;

    // Header
    cout << "|";
    cetakDenganLebar("No", lebarNo);
    cout << "|";
    cetakDenganLebar("Nama VM", maxNamaVM);
    cout << "|";
    cetakDenganLebar("Pemilik", maxPemilik);
    cout << "|";
    cetakDenganLebar("Status", maxStatus);
    cout << "|";
    cetakDenganLebar("CPU", lebarCPU);
    cout << "|";
    cetakDenganLebar("RAM", lebarRAM);
    cout << "|";
    cetakDenganLebar("Storage", lebarStorage);
    cout << "|" << endl;

    // Garis pemisah
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNamaVM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxPemilik+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxStatus+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarCPU+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarRAM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarStorage+2; i++) cout << "-";
    cout << "+" << endl;

    // Data
    for (int i = 0; i < jumlahVM; i++) {
        cout << "|";
        // No
        cout << " " << i+1;
        int lenNo = (i+1 < 10 ? 1 : (i+1 < 100 ? 2 : 3));
        for (int j = lenNo; j < lebarNo; j++) cout << " ";
        cout << " ";

        cout << "|";
        cetakDenganLebar(daftarVM[i].namaVM, maxNamaVM);
        cout << "|";
        cetakDenganLebar(daftarVM[i].pemilik, maxPemilik);
        cout << "|";
        cetakDenganLebar(daftarVM[i].status, maxStatus);
        cout << "|";
        // CPU
        cout << " " << daftarVM[i].spek.cpu;
        int lenCPU = (daftarVM[i].spek.cpu < 10 ? 1 : (daftarVM[i].spek.cpu < 100 ? 2 : 3));
        for (int j = lenCPU; j < lebarCPU; j++) cout << " ";
        cout << " ";
        cout << "|";
        // RAM
        cout << " " << daftarVM[i].spek.ram;
        int lenRAM = (daftarVM[i].spek.ram < 10 ? 1 : (daftarVM[i].spek.ram < 100 ? 2 : 3));
        for (int j = lenRAM; j < lebarRAM; j++) cout << " ";
        cout << " ";
        cout << "|";
        // Storage
        cout << " " << daftarVM[i].spek.storage;
        int lenStorage = (daftarVM[i].spek.storage < 10 ? 1 : (daftarVM[i].spek.storage < 100 ? 2 : 3));
        for (int j = lenStorage; j < lebarStorage; j++) cout << " ";
        cout << " ";
        cout << "|" << endl;
    }

    // Garis bawah
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNamaVM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxPemilik+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxStatus+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarCPU+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarRAM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < lebarStorage+2; i++) cout << "-";
    cout << "+" << endl;
}

// Overloading fungsi lihatVM: untuk user (hanya milik sendiri)
void lihatVM(VM daftarVM[], int jumlahVM, string pemilik) {
    cout << "Daftar VM milik " << pemilik << ":" << endl;
    bool ada = false;

    for (int i = 0; i < jumlahVM; i++) {
        if (daftarVM[i].pemilik == pemilik) {
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
}

// Prosedur untuk melihat semua user dengan tabel rapi
void lihatSemuaUser(Pengguna daftarPengguna[], int jumlahPengguna) {
    if (jumlahPengguna == 0) {
        cout << "Tidak ada user." << endl;
        return;
    }

    // Hitung lebar maksimum setiap kolom
    int maxNama = 4; // panjang "Nama"
    int maxNIM = 3;  // "NIM"
    int maxEmail = 5; // "Email"
    int maxRole = 4; // "Role"
    for (int i = 0; i < jumlahPengguna; i++) {
        int len = daftarPengguna[i].nama.length();
        if (len > maxNama) maxNama = len;
        len = daftarPengguna[i].nim.length();
        if (len > maxNIM) maxNIM = len;
        len = daftarPengguna[i].email.length();
        if (len > maxEmail) maxEmail = len;
        len = daftarPengguna[i].role.length();
        if (len > maxRole) maxRole = len;
    }
    int lebarNo = 2; // nomor, jika >=10 jadi 2, >=100 jadi 3
    if (jumlahPengguna >= 10) lebarNo = 2;
    if (jumlahPengguna >= 100) lebarNo = 3;

    // Garis atas
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNama+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNIM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxEmail+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxRole+2; i++) cout << "-";
    cout << "+" << endl;

    // Header
    cout << "|";
    cetakDenganLebar("No", lebarNo);
    cout << "|";
    cetakDenganLebar("Nama", maxNama);
    cout << "|";
    cetakDenganLebar("Password", maxNIM);
    cout << "|";
    cetakDenganLebar("Email", maxEmail);
    cout << "|";
    cetakDenganLebar("Role", maxRole);
    cout << "|" << endl;

    // Garis pemisah
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNama+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNIM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxEmail+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxRole+2; i++) cout << "-";
    cout << "+" << endl;

    // Data
    for (int i = 0; i < jumlahPengguna; i++) {
        cout << "|";
        // No
        cout << " " << i+1;
        int lenNo = (i+1 < 10 ? 1 : (i+1 < 100 ? 2 : 3));
        for (int j = lenNo; j < lebarNo; j++) cout << " ";
        cout << " ";
        cout << "|";
        cetakDenganLebar(daftarPengguna[i].nama, maxNama);
        cout << "|";
        cetakDenganLebar(daftarPengguna[i].nim, maxNIM);
        cout << "|";
        cetakDenganLebar(daftarPengguna[i].email, maxEmail);
        cout << "|";
        cetakDenganLebar(daftarPengguna[i].role, maxRole);
        cout << "|" << endl;
    }

    // Garis bawah
    cout << "+";
    for (int i = 0; i < lebarNo+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNama+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxNIM+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxEmail+2; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < maxRole+2; i++) cout << "-";
    cout << "+" << endl;
}

// Prosedur untuk mengubah data user (admin) - tetap sama
void ubahDataUser(Pengguna daftarPengguna[], int jumlahPengguna, VM daftarVM[], int jumlahVM, int indeksLogin) {
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
        return;
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
        // Cek duplikat nama
        bool namaAda = false;
        for (int i = 0; i < jumlahPengguna; i++) {
            if (i != index && daftarPengguna[i].nama == input) {
                namaAda = true;
                break;
            }
        }
        if (namaAda) {
            cout << "Nama sudah digunakan. Perubahan nama dibatalkan." << endl;
        } else {
            string namaLama = daftarPengguna[index].nama;
            for (int j = 0; j < jumlahVM; j++) {
                if (daftarVM[j].pemilik == namaLama) {
                    daftarVM[j].pemilik = input;
                }
            }
            daftarPengguna[index].nama = input;
        }
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
}

// Prosedur untuk menghapus user (admin)
void hapusUser(Pengguna daftarPengguna[], int &jumlahPengguna, VM daftarVM[], int &jumlahVM, int indeksLogin) {
    for (int i = 0; i < jumlahPengguna; i++) {
        cout << i+1 << ". " << daftarPengguna[i].nama << " (" << daftarPengguna[i].role << ")" << endl;
    }

    cout << "Pilih nomor user yang akan dihapus: ";
    int no;
    cin >> no;
    cin.ignore();

    if (no < 1 || no > jumlahPengguna) {
        cout << "Nomor tidak valid." << endl;
        return;
    }

    int index = no-1;

    // Mencegah agar admin tidak dapat menghapus diri sendiri
    if (index == indeksLogin) {
        cout << "Anda tidak dapat menghapus akun sendiri melalui menu ini. Gunakan menu Ubah Profil jika ingin menghapus diri." << endl;
        return;
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
}

// Prosedur untuk membuat VM baru (admin)
void buatVM(VM daftarVM[], int &jumlahVM, Pengguna daftarPengguna[], int jumlahPengguna) {
    if (jumlahVM >= MAX_VM) {
        cout << "Kapasitas VM penuh!" << endl;
        return;
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
        return;
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
}

// Prosedur untuk konfigurasi VM (admin)
void konfigurasiVM(VM daftarVM[], int jumlahVM, Pengguna daftarPengguna[], int jumlahPengguna) {
    if (jumlahVM == 0) {
        cout << "Tidak ada VM." << endl;
        return;
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
        return;
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
        } else {
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
}

// Prosedur untuk operasi VM (admin)
void operasiVMAdmin(VM daftarVM[], int jumlahVM) {
    if (jumlahVM == 0) {
        cout << "Tidak ada VM." << endl;
        return;
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
        return;
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
    } else if (op == 2) {
        daftarVM[index].status = "stopped";
        cout << "VM dimatikan." << endl;
    } else if (op == 3) {
        daftarVM[index].status = "stopped";
        daftarVM[index].status = "running";
        cout << "VM direstart." << endl;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Prosedur untuk operasi VM (user)
void operasiVMUser(VM daftarVM[], int jumlahVM, string pemilik) {
    int daftarIndeks[100];
    int count = 0;

    for (int i = 0; i < jumlahVM; i++) {
        if (daftarVM[i].pemilik == pemilik) {
            daftarIndeks[count] = i;
            cout << count+1 << ". " << daftarVM[i].namaVM << " (status: " << daftarVM[i].status << ")" << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "Anda tidak memiliki VM." << endl;
        return;
    }

    cout << "Pilih nomor VM: ";
    int no;
    cin >> no;
    cin.ignore();
    if (no < 1 || no > count) {
        cout << "Nomor tidak valid." << endl;
        return;
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
    } else if (operasiVM == 2) {
        daftarVM[indexVM].status = "stopped";
        cout << "VM dimatikan." << endl;
    } else if (operasiVM == 3) {
        daftarVM[indexVM].status = "stopped";
        daftarVM[indexVM].status = "running";
        cout << "VM direstart." << endl;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Prosedur untuk menghapus VM (admin)
void hapusVM(VM daftarVM[], int &jumlahVM) {
    if (jumlahVM == 0) {
        cout << "Tidak ada VM." << endl;
        return;
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
        return;
    }

    int index = no-1;

    for (int j = index; j < jumlahVM-1; j++) {
        daftarVM[j] = daftarVM[j+1];
    }

    jumlahVM--;
    cout << "VM dihapus." << endl;
}

// Prosedur untuk mengubah profil admin sendiri
void ubahProfilAdmin(Pengguna daftarPengguna[], int indeksLogin, VM daftarVM[], int jumlahVM, int jumlahPengguna) {
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
        // Cek duplikat nama
        bool namaAda = false;
        for (int i = 0; i < jumlahPengguna; i++) {
            if (i != index && daftarPengguna[i].nama == input) {
                namaAda = true;
                break;
            }
        }
        if (namaAda) {
            cout << "Nama sudah digunakan. Perubahan nama dibatalkan." << endl;
        } else {
            string namaLama = daftarPengguna[index].nama;
            for (int j = 0; j < jumlahVM; j++) {
                if (daftarVM[j].pemilik == namaLama) {
                    daftarVM[j].pemilik = input;
                }
            }
            daftarPengguna[index].nama = input;
        }
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
}

// Prosedur untuk mengubah profil user sendiri
void ubahProfilUser(Pengguna daftarPengguna[], int indeksLogin, VM daftarVM[], int jumlahVM, int jumlahPengguna) {
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
        // Cek duplikat nama
        bool namaAda = false;
        for (int i = 0; i < jumlahPengguna; i++) {
            if (i != index && daftarPengguna[i].nama == input) {
                namaAda = true;
                break;
            }
        }
        if (namaAda) {
            cout << "Nama sudah digunakan. Perubahan nama dibatalkan." << endl;
        } else {
            string namaLama = daftarPengguna[index].nama;
            for (int j = 0; j < jumlahVM; j++) {
                if (daftarVM[j].pemilik == namaLama) {
                    daftarVM[j].pemilik = input;
                }
            }
            daftarPengguna[index].nama = input;
        }
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
}

// Prosedur untuk menghapus akun user sendiri
void hapusAkunUser(Pengguna daftarPengguna[], int &jumlahPengguna, VM daftarVM[], int &jumlahVM, int &indeksLogin, bool &logout) {
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
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}

// Fungsi untuk login (mengembalikan indeks pengguna yang login, atau -1 jika gagal)
int login(Pengguna daftarPengguna[], int jumlahPengguna) {
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "Masukkan username: ";
        string inputNama;
        getline(cin, inputNama);
        cout << "Masukkan password: ";
        string inputNim;
        getline(cin, inputNim);

        for (int i = 0; i < jumlahPengguna; i++) {
            if (daftarPengguna[i].nama == inputNama && daftarPengguna[i].nim == inputNim) {
                cout << "Login berhasil! Selamat datang, " << daftarPengguna[i].nama << endl;
                return i;
            }
        }

        percobaan++;
        cout << "Login gagal. Percobaan ke-" << percobaan << " dari 3." << endl;
        if (percobaan == 3) {
            cout << "Anda telah gagal 3 kali. Kembali ke menu awal." << endl;
        }
    }
    return -1;
}

// Prosedur untuk registrasi/buat user baru dengan validasi input
void registrasi(Pengguna daftarPengguna[], int &jumlahPengguna) {
    if (jumlahPengguna >= MAX_PENGGUNA) {
        cout << "Kapasitas user penuh!" << endl;
        return;
    }

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
        return;
    }

    cout << "Masukkan password: ";
    getline(cin, baru.nim);
    cout << "Masukkan email: ";
    getline(cin, baru.email);
    baru.role = "user";
    daftarPengguna[jumlahPengguna] = baru;
    jumlahPengguna++;
    cout << "Registrasi berhasil! Silakan login." << endl;
}

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
            int indeksLogin = login(daftarPengguna, jumlahPengguna);
            if (indeksLogin != -1) {
                string roleLogin = daftarPengguna[indeksLogin].role;

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

                        switch (pilihan) {
                            case 1: registrasi(daftarPengguna, jumlahPengguna); break;
                            case 2: lihatSemuaUser(daftarPengguna, jumlahPengguna); break;
                            case 3: ubahDataUser(daftarPengguna, jumlahPengguna, daftarVM, jumlahVM, indeksLogin); break;
                            case 4: hapusUser(daftarPengguna, jumlahPengguna, daftarVM, jumlahVM, indeksLogin); break;
                            case 5: buatVM(daftarVM, jumlahVM, daftarPengguna, jumlahPengguna); break;
                            case 6: lihatVM(daftarVM, jumlahVM); break;
                            case 7: konfigurasiVM(daftarVM, jumlahVM, daftarPengguna, jumlahPengguna); break;
                            case 8: operasiVMAdmin(daftarVM, jumlahVM); break;
                            case 9: hapusVM(daftarVM, jumlahVM); break;
                            case 10: ubahProfilAdmin(daftarPengguna, indeksLogin, daftarVM, jumlahVM, jumlahPengguna); break;
                            case 11: logout = true; cout << "Logout berhasil." << endl; break;
                            case 12: cout << "Terima kasih telah menggunakan program." << endl; return 0;
                            default: cout << "Pilihan tidak valid." << endl;
                        }
                    }
                }
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
                            case 1: lihatVM(daftarVM, jumlahVM, daftarPengguna[indeksLogin].nama); break;
                            case 2: operasiVMUser(daftarVM, jumlahVM, daftarPengguna[indeksLogin].nama); break;
                            case 3: ubahProfilUser(daftarPengguna, indeksLogin, daftarVM, jumlahVM, jumlahPengguna); break;
                            case 4: hapusAkunUser(daftarPengguna, jumlahPengguna, daftarVM, jumlahVM, indeksLogin, logout); break;
                            case 5: logout = true; cout << "Logout berhasil." << endl; break;
                            case 6: cout << "Terima kasih telah menggunakan program." << endl; return 0;
                            default: cout << "Pilihan tidak valid." << endl;
                        }
                    }
                }
            }
        }

        // Registrasi
        else if (pilihanAwal == 2) {
            registrasi(daftarPengguna, jumlahPengguna);
        }
        else if (pilihanAwal == 3) {
            cout << "Terima kasih telah menggunakan program." << endl;
            return 0;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}