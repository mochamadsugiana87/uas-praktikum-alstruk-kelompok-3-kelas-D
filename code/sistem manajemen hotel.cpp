#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

// =====================================
// STRUCT DATA KAMAR
// =====================================
struct Kamar {
    int nomor;
    string tipe;
    int harga;
    string status;
};

// =====================================
// VARIABEL GLOBAL
// =====================================

// ARRAY KAMAR
Kamar kamar[100];
int jumlahKamar = 0;

// =====================================
// DEKLARASI FUNCTION
// =====================================

// MENU KAMAR
void menuKamar();

void tambahKamar();

// =====================================
// MAIN PROGRAM
// =====================================
int main() {

    int pilihan;

    do {
        cout << "\n========================================";
        cout << "\n      SISTEM MANAJEMEN HOTEL";
        cout << "\n========================================";

        cout << "\n1. Kelola Kamar";
        cout << "\n2. Reservasi";
        cout << "\n3. Check-In";
        cout << "\n4. Check-Out";
        cout << "\n5. Riwayat Transaksi";
        cout << "\n0. Keluar";

        cout << "\n\nPilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                menuKamar();
                break;

            case 2:
               	cout << "\n[Fitur Reservasi Belum Dibuat]";
                break;

            case 3:
                cout << "\n[Fitur Check-In Belum Dibuat]";
                break;

            case 4:
                cout << "\n[Fitur Check-Out Belum Dibuat]";
                break;

            case 5:
                cout << "\n[Fitur Riwayat Transaksi Belum Dibuat]";
                break;

            case 0:
                cout << "\nProgram Selesai...";
                break;

            default:
                cout << "\nPilihan Tidak Valid!";
        }

    } while (pilihan != 0);

    return 0;
}

// =====================================
// MENU KELOLA KAMAR
// =====================================
void menuKamar() {

    int pilih;

    do {

        cout << "\n\n===== KELOLA KAMAR =====";

        cout << "\n1. Tambah Kamar";
        cout << "\n2. Lihat Daftar Kamar";
        cout << "\n3. Cari Kamar";
        cout << "\n4. Ubah Status Kamar";
        cout << "\n5. Hapus Kamar";
        cout << "\n0. Kembali";

        cout << "\n\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                tambahKamar();
                break;

            case 2:
                cout << "\n[Fitur Lihat Daftar Kamar Belum Dibuat]";
                break;

            case 3:
                cout << "\n[Fitur Cari Kamar Belum Dibuat]";
                break;

            case 4:
                cout << "\n[Fitur Ubah Status Kamar Belum Dibuat]";
                break;

            case 5:
                cout << "\n[Fitur Hapus Kamar Belum Dibuat]";
                break;

            case 0:
                break;

            default:
                cout << "\nPilihan Tidak Valid!";
        }

    } while (pilih != 0);
}

// =====================================
// TAMBAH KAMAR
// =====================================
void tambahKamar() {

    cout << "\n===== TAMBAH KAMAR =====";

    cout << "\nNomor Kamar : ";
    cin >> kamar[jumlahKamar].nomor;

    cout << "Tipe Kamar  : ";
    cin >> kamar[jumlahKamar].tipe;

    cout << "Harga       : ";
    cin >> kamar[jumlahKamar].harga;

    kamar[jumlahKamar].status = "Tersedia";

    jumlahKamar++;

    cout << "\nData kamar berhasil ditambahkan.";
    cout << "\nStatus Awal : Tersedia\n";
}
