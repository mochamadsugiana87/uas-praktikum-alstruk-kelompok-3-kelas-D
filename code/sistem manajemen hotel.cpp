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
// STRUCT DATA RESERVASI
// =====================================
struct Reservasi {
    string idReservasi;
    string namaTamu;

    int nomorKamar;

    string tanggalCheckIn;

    int lamaMenginap;

    string statusReservasi;
    string statusPembayaran;
};

// =====================================
// NODE LINKED LIST RESERVASI
// =====================================
struct NodeReservasi {
    Reservasi data;
    NodeReservasi* next;
};

// =====================================
// VARIABEL GLOBAL
// =====================================

// ARRAY KAMAR
Kamar kamar[100];
int jumlahKamar = 0;

// LINKED LIST RESERVASI
NodeReservasi* headReservasi = NULL;
int nomorReservasi = 1;

// =====================================
// DEKLARASI FUNCTION
// =====================================

// MENU KAMAR
void menuKamar();

void tambahKamar();
void lihatKamar();
void cariKamar();
void ubahStatusKamar();
void hapusKamar();

// MENU RESERVASI
void menuReservasi();

void tambahReservasi();

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
               	menuReservasi();
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
                lihatKamar();
                break;

            case 3:
                cariKamar();
                break;

            case 4:
                ubahStatusKamar();
                break;

            case 5:
                hapusKamar();
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

// =====================================
// LIHAT DAFTAR KAMAR
// =====================================
void lihatKamar() {

    cout << "\n===== DAFTAR KAMAR =====";

    if(jumlahKamar == 0) {

        cout << "\n\nBelum ada data kamar.\n";
        return;
    }

    cout << "\n================================================================================";
    cout << "\nNo\tNo. Kamar\tTipe\t\tHarga\t\tStatus";
    cout << "\n================================================================================";

    for(int i = 0; i < jumlahKamar; i++) {

        cout << "\n"
             << i + 1 << "\t"
             << kamar[i].nomor << "\t\t"
             << kamar[i].tipe << "\t\t"
             << kamar[i].harga << "\t\t"
             << kamar[i].status;
    }

    cout << "\n================================================================================\n";
}

// =====================================
// CARI KAMAR
// =====================================
void cariKamar() {

    int nomor;
    bool ditemukan = false;

    cout << "\n===== CARI KAMAR =====";

    cout << "\nMasukkan Nomor Kamar : ";
    cin >> nomor;

    for (int i = 0; i < jumlahKamar; i++) {

        if (kamar[i].nomor == nomor) {

            cout << "\n\nData Ditemukan";

            cout << "\nNomor Kamar : " << kamar[i].nomor;
            cout << "\nTipe        : " << kamar[i].tipe;
            cout << "\nHarga       : " << kamar[i].harga;
            cout << "\nStatus      : " << kamar[i].status;

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData kamar tidak ditemukan.";
    }

    cout << endl;
}

// =====================================
// UBAH STATUS KAMAR
// =====================================
void ubahStatusKamar() {

    int nomor;
    bool ditemukan = false;

    cout << "\n===== UBAH STATUS KAMAR =====\n";
    
    // Tampilkan daftar kamar terlebih dahulu
	lihatKamar();

    cout << "\nMasukkan Nomor Kamar : ";
    cin >> nomor;

    for (int i = 0; i < jumlahKamar; i++) {

        if (kamar[i].nomor == nomor) {

            ditemukan = true;

            int pilihanStatus;
            
            cout << "\n\nData Ditemukan";

			cout << "\nNomor Kamar : "
			     << kamar[i].nomor;
			
			cout << "\nTipe        : "
			     << kamar[i].tipe;
			
			cout << "\nHarga       : "
			     << kamar[i].harga;

            cout << "\nStatus Saat Ini : "
                 << kamar[i].status;

			cout << "\n\nPilih Status Baru";
			
            cout << "\n\n1. Tersedia";
            cout << "\n2. Booking";
            cout << "\n3. Terisi";
            cout << "\n4. Maintenance";

            cout << "\n\nPilihan : ";
            cin >> pilihanStatus;

            switch (pilihanStatus) {

                case 1:
                    kamar[i].status = "Tersedia";
                    break;

                case 2:
                    kamar[i].status = "Booking";
                    break;

                case 3:
                    kamar[i].status = "Terisi";
                    break;
                    
                case 4:
                kamar[i].status = "Maintenance";
                break;

                default:
                    cout << "\nPilihan tidak valid.";
                    return;
            }

            cout << "\nStatus berhasil diubah.";
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData kamar tidak ditemukan.";
    }

    cout << endl;
}

// =====================================
// HAPUS KAMAR
// =====================================
void hapusKamar() {

    int nomor;
    bool ditemukan = false;

    cout << "\n===== HAPUS KAMAR =====\n";
    
    // Tampilkan daftar kamar terlebih dahulu
    lihatKamar();

    cout << "\nMasukkan Nomor Kamar : ";
    cin >> nomor;

    for (int i = 0; i < jumlahKamar; i++) {

        if (kamar[i].nomor == nomor) {

            ditemukan = true;

            // Validasi kamar sedang terisi
            if (kamar[i].status == "Terisi") {
            	cout << "\nData Ditemukan!\n";

			    cout << "\nNomor Kamar : "
			         << kamar[i].nomor;
			
			    cout << "\nTipe        : "
			         << kamar[i].tipe;
			
			    cout << "\nHarga       : "
			         << kamar[i].harga;
			
			    cout << "\nStatus      : "
			         << kamar[i].status;

                cout << "\n\nKamar sedang digunakan.";
                cout << "\nData tidak dapat dihapus.\n";
                return;
            }

            char konfirmasi;

            cout << "\nNomor Kamar : "
                 << kamar[i].nomor;

            cout << "\nTipe        : "
                 << kamar[i].tipe;

            cout << "\nHarga       : "
                 << kamar[i].harga;

            cout << "\nStatus      : "
                 << kamar[i].status;

            cout << "\n\nYakin ingin menghapus? (Y/T) : ";
            cin >> konfirmasi;

            if (konfirmasi == 'Y' || konfirmasi == 'y') {

                for (int j = i; j < jumlahKamar - 1; j++) {
                    kamar[j] = kamar[j + 1];
                }

                jumlahKamar--;

                cout << "\nData kamar berhasil dihapus.";
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData kamar tidak ditemukan.";
    }

    cout << endl;
}

// =====================================
// MENU RESERVASI
// =====================================
void menuReservasi() {

    int pilih;

    do {

        cout << "\n\n===== RESERVASI =====";

        cout << "\n1. Tambah Reservasi";
        cout << "\n2. Lihat Reservasi";
        cout << "\n3. Cari Reservasi";
        cout << "\n4. Batalkan Reservasi";
        cout << "\n0. Kembali";

        cout << "\n\nPilih Menu : ";
        cin >> pilih;

        switch(pilih) {

            case 1:
                tambahReservasi();
                break;

            case 2:
                cout << "\n Fitur lihat reservasi belum dibuat";
                break;

            case 3:
                cout << "\n Fitur cari reservasi belum dibuat";
                break;

            case 4:
                cout << "\n Fitur hapus reservasi belum dibuat";
                break;

            case 0:
                break;

            default:
                cout << "\nPilihan tidak valid!";
        }

    } while(pilih != 0);
}

// =====================================
// TAMBAH RESERVASI
// =====================================
void tambahReservasi() {

    cout << "\n===== TAMBAH RESERVASI =====\n";
    
    bool adaKamar = false;

	cout << "\nDAFTAR KAMAR TERSEDIA";
	
	cout << "\n================================================================================";
	cout << "\nNo. Kamar\tTipe\tHarga\tStatus";
	cout << "\n================================================================================";
	
	for(int i = 0; i < jumlahKamar; i++) {
	
	    if(kamar[i].status == "Tersedia") {
	
	        adaKamar = true;
	
	        cout << "\n"
	             << kamar[i].nomor << "\t\t"
	             << kamar[i].tipe << "\t"
	             << kamar[i].harga << "\t"
	             << kamar[i].status;
	    }
	}
	
	cout << "\n================================================================================";
	
	// Jika tidak ada kamar tersedia
	if(!adaKamar) {
	    cout << "\n\nTidak ada kamar yang tersedia.\n";
	    return;
	}

    NodeReservasi* baru = new NodeReservasi;

    cin.ignore();

    cout << "\nNama Tamu : ";
    getline(cin, baru->data.namaTamu);

    cout << "Nomor Kamar : ";
    cin >> baru->data.nomorKamar;

    // -------------------------
    // Validasi Kamar
    // -------------------------

    bool kamarDitemukan = false;
    bool kamarTersedia = false;
    
    int indexKamar = -1;

    for(int i = 0; i < jumlahKamar; i++) {

        if(kamar[i].nomor == baru->data.nomorKamar) {

            kamarDitemukan = true;
            indexKamar = i;

            if(kamar[i].status == "Tersedia") {

                kamarTersedia = true;
            }
            else {

                cout << "\nStatus Kamar : "
                     << kamar[i].status;

                cout << "\nKamar tidak tersedia untuk reservasi.\n";

                delete baru;
                return;
            }
        }
    }

    if(!kamarDitemukan) {

        cout << "\nKamar tidak ditemukan.\n";

        delete baru;
        return;
    }

    cout << "Tanggal Check-In : ";
    cin >> baru->data.tanggalCheckIn;

    cout << "Lama Menginap : ";
    cin >> baru->data.lamaMenginap;
    
    char id[20];
	sprintf(id, "RSV%d", nomorReservasi);
	baru->data.idReservasi = id;
	nomorReservasi++;

    baru->data.statusReservasi =
        "Menunggu";

    baru->data.statusPembayaran =
        "Belum Lunas";

    baru->next = NULL;

    // -------------------------
    // Sisip di akhir linked list
    // -------------------------

    if(headReservasi == NULL) {

        headReservasi = baru;
    }
    else {

        NodeReservasi* bantu = headReservasi;

        while(bantu->next != NULL) {

            bantu = bantu->next;
        }

        bantu->next = baru;
    }
    
    // Ubah status kamar menjadi Booking
	kamar[indexKamar].status = "Booking";

    cout << "\nReservasi Berhasil";

    cout << "\nID Reservasi : "
         << baru->data.idReservasi;

    cout << "\nStatus Reservasi : "
         << baru->data.statusReservasi;

    cout << "\nStatus Pembayaran : "
         << baru->data.statusPembayaran;
         
    cout << "\nStatus Kamar : "
     	 << kamar[indexKamar].status;

    cout << endl;
}
