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
void lihatReservasi();
void cariReservasi();
void batalkanReservasi();

// CHECK IN
void checkIn();

// CHECK OUT
void checkOut();

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
				checkIn();
                break;

            case 4:
                checkOut();
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
                lihatReservasi();
                break;

            case 3:
                cariReservasi();
                break;

            case 4:
                batalkanReservasi();
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

// =====================================
// LIHAT RESERVASI
// =====================================
void lihatReservasi() {

    cout << "\n===== DAFTAR RESERVASI =====\n";

    if(headReservasi == NULL) {

        cout << "\nBelum ada reservasi.\n";
        return;
    }

    cout << "\n====================================================================================";

    cout << "\nID\tNama\tKamar\tlama Menginap\tStatus Reservasi\tStatus Pembayaran";

    cout << "\n====================================================================================";

    NodeReservasi* bantu = headReservasi;

    while(bantu != NULL) {

        cout << "\n"
             << bantu->data.idReservasi << "\t"
             << bantu->data.namaTamu << "\t"
             << bantu->data.nomorKamar << "\t"
             << bantu->data.lamaMenginap << " hari\t\t";
             if(bantu->data.statusReservasi == "Menunggu") {
			    cout << bantu->data.statusReservasi << "\t\t";
			 } else if(bantu->data.statusReservasi == "Aktif") {
			    cout << bantu->data.statusReservasi << "\t\t\t";
			 } else if(bantu->data.statusReservasi == "Selesai") {
			    cout << bantu->data.statusReservasi << "\t\t";
			 }
             cout << bantu->data.statusPembayaran;

        bantu = bantu->next;
    }

    cout << "\n====================================================================================\n";
}

// =====================================
// CARI RESERVASI
// =====================================

void cariReservasi() {

    string id;

    cout << "\n===== CARI RESERVASI =====";

    cout << "\nMasukkan ID Reservasi : ";
    cin >> id;

    NodeReservasi* bantu = headReservasi;

    while(bantu != NULL) {

        if(bantu->data.idReservasi == id) {

            cout << "\n\nData Ditemukan";

            cout << "\nID Reservasi      : "
                 << bantu->data.idReservasi;

            cout << "\nNama Tamu         : "
                 << bantu->data.namaTamu;

            cout << "\nNomor Kamar       : "
                 << bantu->data.nomorKamar;

            cout << "\nTanggal Check-In  : "
                 << bantu->data.tanggalCheckIn;

            cout << "\nLama Menginap     : "
                 << bantu->data.lamaMenginap;

            cout << "\nStatus Reservasi  : "
                 << bantu->data.statusReservasi;

            cout << "\nStatus Pembayaran : "
                 << bantu->data.statusPembayaran;

            return;
        }

        bantu = bantu->next;
    }

    cout << "\nData reservasi tidak ditemukan.\n";
}

// =====================================
// BATALKAN RESERVASI
// =====================================
void batalkanReservasi() {

    string id;

    cout << "\n===== BATALKAN RESERVASI =====\n";
    
	bool adaMenunggu = false;
	
	cout << "\nDAFTAR RESERVASI";
	
	cout << "\n================================================================================";
	cout << "\nID\tNama\tKamar\tStatus Reservasi";
	cout << "\n================================================================================";
	
	NodeReservasi* tampil = headReservasi;
	
	while(tampil != NULL) {
	
	    if(tampil->data.statusReservasi == "Menunggu") {
	
	        adaMenunggu = true;
	
	        cout << "\n"
	             << tampil->data.idReservasi << "\t"
	             << tampil->data.namaTamu << "\t"
	             << tampil->data.nomorKamar << "\t"
	             << tampil->data.statusReservasi;
	    }
	
	    tampil = tampil->next;
	}
	
	cout << "\n================================================================================";
	
	if(!adaMenunggu) {
	
	    cout << "\n\nTidak ada reservasi yang dapat dibatalkan.\n";
	    return;
	}
	
	cout << "\n\nMasukkan ID Reservasi : ";
	cin >> id;

    NodeReservasi* bantu = headReservasi;
    NodeReservasi* sebelum = NULL;

    while(bantu != NULL) {

        if(bantu->data.idReservasi == id) {

            cout << "\n\nData Ditemukan";

            cout << "\nNama Tamu : "
                 << bantu->data.namaTamu;

            cout << "\nNomor Kamar : "
                 << bantu->data.nomorKamar;
                 
            cout << "\nStatus Reservasi : "
     			 << bantu->data.statusReservasi;
     			 
     		// Jika tamu sedang aktif dan selesai, reservasi tidak boleh dibatalkan
			if(bantu->data.statusReservasi == "Aktif") {
			    cout << "\n\nReservasi tidak dapat dibatalkan.";
			    cout << "\nTamu sedang menginap.";
			    cout << "\nSilakan lakukan proses Check-Out terlebih dahulu.\n";
			
			    return;
			} else if(bantu->data.statusReservasi == "Selesai") {
			    cout << "\n\nReservasi tidak dapat dibatalkan.";
			    cout << "\nTamu sudah melakukan Check-Out.";
			    cout << "\nData disimpan sebagai riwayat.\n";
			
			    return;
			}

            char konfirmasi;

            cout << "\n\nYakin ingin membatalkan reservasi? (Y/T) : ";
            cin >> konfirmasi;

            if(konfirmasi == 'Y' || konfirmasi == 'y') {
            	
            	// Kembalikan status kamar menjadi Tersedia
			    for(int i = 0; i < jumlahKamar; i++) {
			
			        if(kamar[i].nomor ==
			           bantu->data.nomorKamar) {
			
			            kamar[i].status = "Tersedia";
			            break;
			        }
			    }

                if(sebelum == NULL) {

                    headReservasi =
                        bantu->next;
                }
                else {

                    sebelum->next =
                        bantu->next;
                }

                delete bantu;

                cout << "\nReservasi berhasil dibatalkan.\n";
            }

            return;
        }

        sebelum = bantu;
        bantu = bantu->next;
    }

    cout << "\nData reservasi tidak ditemukan.\n";
}

// =====================================
// CHECK IN
// =====================================
void checkIn() {

    string id;
    
    cout << "\n===== CHECK-IN =====\n";

	if(headReservasi == NULL) {
	
	    cout << "\nBelum ada reservasi.\n";
	    return;
	}
	
	bool adaMenunggu = false;
	
	cout << "\nDAFTAR TAMU RESERVASI";
	
	cout << "\n==========================================================================";
	cout << "\nID\tNama\tKamar\tLama Menginap\tStatus Reservasi";
	cout << "\n==========================================================================";
	
	NodeReservasi* tampil = headReservasi;
	
	while(tampil != NULL) {
	
	    if(tampil->data.statusReservasi == "Menunggu") {
	
	        adaMenunggu = true;
	
	        cout << "\n"
	             << tampil->data.idReservasi << "\t"
	             << tampil->data.namaTamu << "\t"
	             << tampil->data.nomorKamar << "\t"
	             << tampil->data.lamaMenginap << " Hari\t\t"
	             << tampil->data.statusReservasi;
	    }
	
	    tampil = tampil->next;
	}
	
	cout << "\n==========================================================================\n";
	
	if(!adaMenunggu) {
	    cout << "\n\nTidak ada reservasi yang menunggu proses Check-In.\n";
	    return;
	}

    cout << "\nMasukkan ID Reservasi : ";
    cin >> id;

    // Cari reservasi
    NodeReservasi* bantu = headReservasi;

    while (bantu != NULL) {

        if (bantu->data.idReservasi == id) {

            // Sudah Check-In & Check-Out
			if(bantu->data.statusReservasi == "Aktif") {
			
			    cout << "\nReservasi sudah melakukan Check-In.";
			
			    return;
			} else if(bantu->data.statusReservasi == "Selesai") {
			
			    cout << "\nReservasi sudah selesai.";
			
			    cout << "\nTamu sudah melakukan Check-Out.\n";
			
			    return;
			}

            // Cari kamar
            for (int i = 0; i < jumlahKamar; i++) {

                if (kamar[i].nomor ==
                    bantu->data.nomorKamar) {

                    int totalBayar =
                        kamar[i].harga *
                        bantu->data.lamaMenginap;

                    cout << "\n\nData Reservasi";

                    cout << "\nNama Tamu     : "
                         << bantu->data.namaTamu;

                    cout << "\nNomor Kamar   : "
                         << bantu->data.nomorKamar;

                    cout << "\nTipe Kamar    : "
                         << kamar[i].tipe;

                    cout << "\nHarga/Hari    : "
                         << kamar[i].harga;

                    cout << "\nLama Menginap : "
                         << bantu->data.lamaMenginap
                         << " Hari";

                    cout << "\n\nTotal Bayar   : "
                         << totalBayar;

                    // ===================
                    // PEMBAYARAN
                    // ===================

                    int bayar;

                    do {

                        cout << "\n\nMasukkan Nominal Pembayaran : ";
                        cin >> bayar;

                        if (bayar < totalBayar) {

                            cout << "\nPembayaran Gagal";

                            cout << "\nKekurangan : "
                                 << totalBayar - bayar;

                            cout << "\nSilakan input ulang.\n";
                        }

                    } while (bayar < totalBayar);

                    int kembalian =
                        bayar - totalBayar;

                    cout << "\nPembayaran Berhasil";

                    cout << "\nTotal Bayar : "
                         << totalBayar;

                    cout << "\nUang Masuk  : "
                         << bayar;

                    cout << "\nKembalian   : "
                         << kembalian;

                    // ===================
                    // UPDATE STATUS
                    // ===================

                    bantu->data.statusPembayaran =
                        "Lunas";

                    bantu->data.statusReservasi =
                        "Aktif";

                    kamar[i].status =
                        "Terisi";

                    cout << "\n\nStatus Pembayaran : "
                         << bantu->data.statusPembayaran;

                    cout << "\nStatus Reservasi  : "
                         << bantu->data.statusReservasi;

                    cout << "\nStatus Kamar      : "
                         << kamar[i].status;

                    cout << "\n\nCheck-In Berhasil\n";

                    return;
                }
            }
        }

        bantu = bantu->next;
    }

    cout << "\nData reservasi tidak ditemukan.\n";
}

// =====================================
// CHECK OUT
// =====================================
void checkOut() {

    string id;

    cout << "\n===== CHECK-OUT =====\n";

    // -----------------------------
    // Tampilkan reservasi yang Aktif
    // -----------------------------

    if(headReservasi == NULL) {

        cout << "\nBelum ada data reservasi.\n";
        return;
    }

    bool adaAktif = false;

    cout << "\nDAFTAR TAMU MENGINAP";

    cout << "\n================================================================================";
    cout << "\nID\tNama\tKamar\tLama Menginap\tStatus Reservasi";
    cout << "\n================================================================================";

    NodeReservasi* tampil = headReservasi;

    while(tampil != NULL) {

        if(tampil->data.statusReservasi == "Aktif") {

            adaAktif = true;

            cout << "\n"
                 << tampil->data.idReservasi << "\t"
                 << tampil->data.namaTamu << "\t"
                 << tampil->data.nomorKamar << "\t"
                 << tampil->data.lamaMenginap << " Hari\t\t"
                 << tampil->data.statusReservasi;
        }

        tampil = tampil->next;
    }

    cout << "\n================================================================================";

    if(!adaAktif) {

        cout << "\n\nTidak ada tamu yang sedang menginap.\n";
        return;
    }

    // -----------------------------
    // Input ID Reservasi
    // -----------------------------

    cout << "\n\nMasukkan ID Reservasi : ";
    cin >> id;

    NodeReservasi* bantu = headReservasi;

    while(bantu != NULL) {

        if(bantu->data.idReservasi == id) {

            cout << "\n\nData Ditemukan";

            cout << "\nID Reservasi      : "
                 << bantu->data.idReservasi;

            cout << "\nNama Tamu         : "
                 << bantu->data.namaTamu;

            cout << "\nNomor Kamar       : "
                 << bantu->data.nomorKamar;

            cout << "\nStatus Reservasi  : "
                 << bantu->data.statusReservasi;

            cout << "\nStatus Pembayaran : "
                 << bantu->data.statusPembayaran;

            // -----------------------------
            // Validasi Status
            // -----------------------------

            if(bantu->data.statusReservasi == "Menunggu Check-In") {

                cout << "\n\nTamu belum melakukan Check-In.";
                cout << "\nCheck-Out tidak dapat dilakukan.\n";
                return;
            }

            if(bantu->data.statusReservasi == "Selesai") {

                cout << "\n\nTamu sudah melakukan Check-Out.\n";
                return;
            }

            char konfirmasi;

            cout << "\n\nYakin ingin melakukan Check-Out? (Y/T) : ";
            cin >> konfirmasi;

            if(konfirmasi == 'Y' || konfirmasi == 'y') {

                // Ubah status reservasi
                bantu->data.statusReservasi = "Selesai";

                // Ubah status kamar
                for(int i = 0; i < jumlahKamar; i++) {

                    if(kamar[i].nomor ==
                       bantu->data.nomorKamar) {

                        kamar[i].status = "Tersedia";
                        break;
                    }
                }

                cout << "\n\nCheck-Out Berhasil";

                cout << "\nStatus Reservasi : "
                     << bantu->data.statusReservasi;

                cout << "\nStatus Kamar     : Tersedia\n";
            }

            return;
        }

        bantu = bantu->next;
    }

    cout << "\nData reservasi tidak ditemukan.\n";
}