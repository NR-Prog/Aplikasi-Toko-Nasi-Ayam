#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int max_pesanan = 200;

void layar_bersih() {
    system("cls");
}

void tampilan_menu() {
    cout<<"|====================================|\n";
    cout<<"|           Toko Nasi Ayam           |\n";
    cout<<"|====================================|\n";
    cout<<"|         Pilih Menu Makanan         |\n";
    cout<<"|====================================|\n";
    cout<<"| 1. Nasi Ayam Paket 1 | Rp. 7.000   |\n";
    cout<<"| 2. Nasi Ayam Paket 2 | Rp. 8.000   |\n";
    cout<<"| 3. Nasi Ayam Paket 3 | Rp. 9.000   |\n";
    cout<<"| 4. Nasi Ayam Paket 4 | Rp. 10.000  |\n";
    cout<<"|====================================|\n";
}


void pilih_sambal(int porsi, string sambal_list[][max_pesanan], int urutan_pesanan) {
    int menu_sambal;
    for(int i = 0; i < porsi; i++) {
        cout<<endl;
        cout<<"|====================================|\n";
        cout<<"|     Pilih Sambal Untuk Porsi " << i + 1 << ":    |\n";
        cout<<"|====================================|\n";
        cout<<"| 0. Tanpa Sambal                    |\n";
        cout<<"| 1. Sambal Merah                    |\n";
        cout<<"| 2. Sambal Hijau                    |\n";
        cout<<"| 3. Saus Spageti                    |\n";
        cout<<"| 4. Saus Lada Hitam                 |\n";
        cout<<"| 5. Saus Richese                    |\n";
        cout<<"| 6. Saus Asam Manis                 |\n";
        cout<<"|====================================|\n";

        cout<<endl;
        cout<<"Pilih Sambal: "; cin>>menu_sambal;

        switch(menu_sambal) {
            case 0:
            sambal_list[urutan_pesanan][i] = "Tanpa Sambal";
            break;

            case 1:
            sambal_list[urutan_pesanan][i] = "Sambal Merah";
            break;

            case 2:
            sambal_list[urutan_pesanan][i] = "Sambal Hijau";
            break;

            case 3:
            sambal_list[urutan_pesanan][i] = "Saus Spageti";
            break;

            case 4:
            sambal_list[urutan_pesanan][i] = "Saus Lada Hitam";
            break;

            case 5:
            sambal_list[urutan_pesanan][i] = "Saus Richese";
            break;

            case 6:
            sambal_list[urutan_pesanan][i] = "Saus Asam Manis";
            break;

            default:
            cout<<"Pilihan tidak tersedia! Mohon untuk masukkan pilihan yang benar.\n";
            i--;
        }
    }
}

string waktu_tanggal() {
    time_t now = time(0); 
    tm *ltm = localtime(&now); 

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", ltm);
    return string(buffer);
}

void kasir() {
    int nomor_antrian = 1;

    while(true) {
        int total_harga = 0, jumlah_pesanan = 0;
        int harga_makanan[max_pesanan] = {}, jumlah_porsi[max_pesanan] = {};
        string sambal_list[max_pesanan][max_pesanan], nama_makanan[max_pesanan];

        layar_bersih();
        cout<<"|====================================|\n";
        cout<<"|          Nomor Antrian: "<<nomor_antrian<<"          |\n";
        cout<<"|====================================|\n";

        while(true) {
            tampilan_menu();
            int menu_makanan;
            cout<<endl;
            cout<<"Pilih Menu Makanan: "; cin>>menu_makanan;

            switch(menu_makanan) {
                case 1:
                nama_makanan[jumlah_pesanan] = "Nasi Ayam Paket 1";
                harga_makanan[jumlah_pesanan] = 7000;
                break;

                case 2:
                nama_makanan[jumlah_pesanan] = "Nasi Ayam Paket 2";
                harga_makanan[jumlah_pesanan] = 8000;
                break;

                case 3:
                nama_makanan[jumlah_pesanan] = "Nasi Ayam Paket 3";
                harga_makanan[jumlah_pesanan] = 9000;
                break;

                case 4:
                nama_makanan[jumlah_pesanan] = "Nasi Ayam Paket 4";
                harga_makanan[jumlah_pesanan] = 10000;
                break;

                default:
                cout<<"Pilihan tidak tersedia! Silahkan pilih kembali menu yang tersedia.\n";
                cout<<endl;
                continue;
            }

            cout<<"Jumlah Porsi: "; cin>>jumlah_porsi[jumlah_pesanan];

            pilih_sambal(jumlah_porsi[jumlah_pesanan], sambal_list, jumlah_pesanan);

            total_harga += harga_makanan[jumlah_pesanan] * jumlah_porsi[jumlah_pesanan];
            jumlah_pesanan++;

            char tambah;
            cout<<"Apakah anda ingin menambah menu lain? (y/t): "; cin>>tambah;
            if(tolower(tambah) != 'y') {
                break;
            }
        }

        layar_bersih();
        cout<<"|=====================================|\n";
        cout<<"|            Detail Pesanan           |\n";
        cout<<"|=====================================|\n";

        for(int i = 0; i < jumlah_pesanan; i++) {
            cout<<"  Pemesanan "<<i + 1<<endl;
            cout<<"  Makanan         : "<<nama_makanan[i]<<endl;
            cout<<"  Porsi           : "<<jumlah_porsi[i]<<endl;
            for(int j = 0; j < jumlah_porsi[i]; j++) {
                cout<<"  Sambal Porsi "<<j + 1<<"  : "<<sambal_list[i][j]<<endl;
            }
            cout<<"  Subtotal        : Rp. "<<harga_makanan[i] * jumlah_porsi[i]<<endl;
            cout<<"|=====================================|\n";
        }
        cout<<"  Total Harga     : Rp. "<<total_harga<<endl;
        cout<<"|=====================================|\n";

        int bayar, kembali;
        cout<<"|             Pembayaran              |\n";
        cout<<"|=====================================|\n";
        cout<<" Total Harga         : Rp. "<<total_harga<<endl;
        while(true) {
            cout<<" Masukkan Jumlah Uang: Rp. "; cin>>bayar;

            if(bayar < total_harga) {
                cout<<"Uang Anda Kurang! Silahkan bayar dengan uang yang cukup\n";
            } else {
                kembali = bayar - total_harga;
                break;
            }
        }

        layar_bersih();
        cout<<"|=====================================|\n";
        cout<<"|            SMKN 1 CIMAHI            |\n";
        cout<<"|=====================================|\n";
        string waktu_dan_tanggal = waktu_tanggal();
        cout<<"|Waktu Transaksi : " <<waktu_dan_tanggal<<"|\n";
        cout<<"|=====================================|\n";
        cout<<"|          Nomor Antrian : "<<nomor_antrian<<"          |\n";
        cout<<"|=====================================|\n";

        for(int i = 0; i < jumlah_pesanan; i++) {
            cout<<"  Pemesanan "<<i + 1<<endl;
            cout<<"  Makanan         : "<<nama_makanan[i]<<endl;
            cout<<"  Porsi           : "<<jumlah_porsi[i]<<endl;
            for(int j = 0; j < jumlah_porsi[i]; j++) {
                cout<<"  Sambal Porsi "<<j + 1<<"  : "<<sambal_list[i][j]<<endl;
            }
            cout<<"  Subtotal        : Rp. "<<harga_makanan[i] * jumlah_porsi[i]<<endl;
            cout<<"|=====================================|\n";
        }
        cout<<"  Total Harga     : Rp. "<<total_harga<<endl;
        cout<<"  Uang Tunai      : Rp. "<<bayar<<endl;
        cout<<"  Uang Kembali    : Rp. "<<kembali<<endl;
        cout<<"|=====================================|\n";
        cout<<" Terima Kasih. Selamat Belanja Kembali \n";
        cout<<"|===  Developer: Densus Prabowo S  ===|\n";
        cout<<"  SMS  082110938543       CALL  12345  \n";
        cout<<endl;

        nomor_antrian++;
        
        cout<<endl;
        char ulang;
        cout<<"Apakah ingin memesan lagi? (y/t): "; cin>>ulang;
        if(tolower(ulang) != 'y') {
            cout<<endl;
            cout<<"Terima Kasih Telah Memesan!\n";
            break;
        }
    }
}

int main() {
    system("color f0");
    kasir();

    system("pause");
    return 0;
}