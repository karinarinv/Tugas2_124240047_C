#include <iostream>
#include <iomanip>
using namespace std;

const int maxPel = 1000;

struct Pesanan {
    char Nama[100];
    char Roti[100];
    int Total;
};

Pesanan antrean[maxPel];
Pesanan riwayat[maxPel];
int depan = 0, belakang = -1;
int top = -1;

void ambilAntrean() {
    if (belakang >= maxPel - 1) {
        cout << "Antrian sudah penuh" << endl;
        return;
    }

    belakang++;
    cout << setfill('=') << setw(46) << " " << endl;
    cin.ignore();
    cout << "Nama pembeli : ";
    cin.getline(antrean[belakang].Nama, 100);
    cout << "Jenis roti   : ";
    cin.getline(antrean[belakang].Roti, 100);
    cout << "Total harga  : ";
    cin >> antrean[belakang].Total;
    cout << setfill('.') << setw(46) << " " << endl;
    cout << "Silakan tunggu pesanan Anda ^^" << endl;
    cout << setfill('.') << setw(46) << " " << endl << endl;
}

void layaniPembeli() {
    if (depan > belakang) {
        cout << "Antrian masih kosong" << endl << endl;
        return;
    }

    if (top < maxPel - 1) {
        top++;
        riwayat[top] = antrean[depan];
    }

    cout << setfill('=') << setw(46) << " " << endl;
    cout << "Pelanggan" << endl;
    cout << setfill('_') << setw(46) << " " << endl;
    cout << "Nama         : " << antrean[depan].Nama << endl;
    cout << "Jenis roti   : " << antrean[depan].Roti << endl;
    cout << "Total harga  : " << antrean[depan].Total << endl;
    cout << setfill('-') << setw(46) << " " << endl;
    cout << " Telah dilayani oleh -admin karina- " << endl;
    cout << setfill('=') << setw(46) << " " << endl << endl;
    depan++;
}

void tampilkanAntrean() {
    if (depan > belakang) {
        cout << " Antrian masih kosong " << endl << endl;
        return;
    }

    cout << "Daftar antrian:" << endl;
    cout << setfill('=') << setw(46) << " " << endl;
    for (int i = depan; i <= belakang; i++) {
        cout << "Nama        : " << antrean[i].Nama << endl;
        cout << "Jenis roti  : " << antrean[i].Roti << endl;
        cout << "Total harga : " << antrean[i].Total << endl;
        cout << setfill('-') << setw(46) << " " << endl;
    }
    cout << setfill('=') << setw(46) << " " << endl;
    cout << endl;
}

void batalkanPesanan() {
    if (belakang < depan) {
        cout << "Antrian masih kosong" << endl << endl;
        return;
    }

    cout << setfill('=') << setw(46) << " "           << endl;
    cout << "Pelanggan" << endl;
    cout << setfill('_') << setw(46) << " "           << endl;
    cout << "Nama         : " << antrean[depan].Nama  << endl;
    cout << "Jenis roti   : " << antrean[depan].Roti  << endl;
    cout << "Total harga  : " << antrean[depan].Total << endl;
    cout << setfill('-') << setw(46) << " "           << endl;
    cout << " Telah dibatalkan oleh -admin karina- "    << endl;
    cout << setfill('=') << setw(46) << " "           << endl;
    belakang--;
    cout << " " << endl;
}

void tampilkanHistoryPesanan() {
    if (top < 0) {
        cout << " Belum ada pesanan yang dilayani "    << endl;
        return;
    }

    cout << "Riwayat pesanan yang telah dilayani:" << endl;
    cout << setfill('-') << setw(46) << " " << endl;
    for (int i = top; i >= 0; i--) {
        cout << "Nama        : " << riwayat[i].Nama << endl;
        cout << "Jenis roti  : " << riwayat[i].Roti << endl;
        cout << "Total harga : " << riwayat[i].Total << endl;
        cout << setfill('-') << setw(46) << " " << endl;
    }
    cout << " " << endl;
}

void keluar() {
    exit(0);
}


int main() {
    int pilihan;
    do {
        cout << setfill('=') << setw(46) << " "                 << endl;
        cout << "Selamat Datang di Toko Roti Manis Lezat Depok" << endl;
        cout << setfill('=') << setw(46) << " "                 << endl;
        cout << "Silakan pilih menu:"                           << endl;
        cout << "1. Ambil Antrean"                              << endl;
        cout << "2. Layani Pembeli"                             << endl;
        cout << "3. Tampilkan Antrean"                          << endl;
        cout << "4. Batalkan Pesanan Terakhir"                  << endl;
        cout << "5. Tampilkan Riwayat Pesanan"                  << endl;
        cout << "6. Keluar"                                     << endl;
        cout << setfill('=') << setw(46) << " "                 << endl;
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1: 
            ambilAntrean(); 
            break;

            case 2: 
            layaniPembeli(); 
            break;

            case 3: 
            tampilkanAntrean(); 
            break;

            case 4: 
            batalkanPesanan(); 
            break;

            case 5: 
            tampilkanHistoryPesanan(); 
            break;

            case 6:
            keluar();
            cout << "Terima kasih, sampai jumpa kembali ^^" << endl;
            break;
            default:
            cout << "Pilihan hanya 6" << endl << endl;
        }
    } while (true);
}
