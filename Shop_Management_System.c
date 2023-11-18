#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk menyimpan informasi produk
typedef struct {
    char nama[50];
    int stok;
    int harga; // Menggunakan tipe data int untuk harga agar tidak ada angka desimal
} Produk;

// Struktur data untuk menyimpan informasi transaksi
typedef struct {
    char namaProduk[50];
    int jumlah;
    int total; // Menggunakan tipe data int untuk total agar tidak ada angka desimal
} Transaksi;

// Fungsi untuk mencatat penjualan
void catatPenjualan(Produk *produk, int jumlah, Transaksi *transaksi, int *jumlahTransaksi) {
    printf("\n-----------------\n");
    printf("\n-- Beli barang --\n");
    printf("\n-----------------\n");
    printf("\n                 \n");
    
    // Menampilkan daftar produk
    printf("Daftar barang:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s (Stok: %d Harga: %d)\n", i + 1, produk[i].nama, produk[i].stok, produk[i].harga);
    }

    // Meminta input produk yang dijual
    int pilihan;
    printf("Pilih produk yang dijual (nomor): ");
    scanf("%d", &pilihan);
    pilihan--;

    // Memeriksa apakah stok mencukupi
    if (produk[pilihan].stok <= 0) {
        printf("Stok habis. Penjualan dibatalkan.\n");
        return;
    }

    // Meminta input jumlah produk yang dijual
    printf("Jumlah produk yang dijual: ");
    scanf("%d", &transaksi[*jumlahTransaksi].jumlah);

    // Memeriksa apakah stok mencukupi
    if (transaksi[*jumlahTransaksi].jumlah > produk[pilihan].stok) {
        printf("Stok tidak cukup.Penjualan dibatalkan.\n");
        return;
    }

    // Mengupdate stok produk
    produk[pilihan].stok -= transaksi[*jumlahTransaksi].jumlah;

    // Mengisi informasi transaksi
    strcpy(transaksi[*jumlahTransaksi].namaProduk, produk[pilihan].nama);
    transaksi[*jumlahTransaksi].total = transaksi[*jumlahTransaksi].jumlah * produk[pilihan].harga;

    // Menampilkan ringkasan transaksi
    printf("Penjualan berhasil.\n");
    printf("Produk: %s\n", transaksi[*jumlahTransaksi].namaProduk);
    printf("Jumlah: %d\n", transaksi[*jumlahTransaksi].jumlah);
    printf("Total: %d\n", transaksi[*jumlahTransaksi].total);

    // Menambah jumlah transaksi
    (*jumlahTransaksi)++;
}

// Fungsi untuk melakukan penambahan stok
void tambahStok(Produk *produk, int jumlah) {
    printf("\n-- Penambahan Stok --\n");

    // Menampilkan daftar produk
    printf("Daftar Produk:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s (Stok: %d)\n", i + 1, produk[i].nama, produk[i].stok);
    }

    // Meminta input produk yang akan ditambah stok
    int pilihan;
    printf("Pilih produk yang akan ditambah stok (nomor): ");
    scanf("%d", &pilihan);
    pilihan--;

    // Meminta input jumlah stok yang ditambah
    int tambahan;
    printf("Jumlah stok yang ditambah: ");
    scanf("%d", &tambahan);

    // Menambah stok produk
    produk[pilihan].stok += tambahan;

    // Menampilkan ringkasan penambahan stok
    printf("Stok berhasil ditambahkan untuk produk %s. Stok sekarang: %d\n", produk[pilihan].nama, produk[pilihan].stok);
}

// Fungsi untuk membuat laporan transaksi
void buatLaporan(Transaksi *transaksi, int jumlahTransaksi) {
    printf("\n-- Laporan Transaksi --\n");
     printf("\n                      \n");

    // Menampilkan transaksi per hari
    int totalHari = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        totalHari += transaksi[i].total;
        printf("Transaksi %d:\n", i + 1);
        printf("Produk: %s\n", transaksi[i].namaProduk);
        printf("Jumlah: %d\n", transaksi[i].jumlah);
        printf("Total: %d\n", transaksi[i].total);
        printf("-------------------------\n");
    }
    printf("Total pendapatan hari ini: %d\n", totalHari);
}

int main() {
    // Inisialisasi produk
    Produk produk[3];
    
    strcpy(produk[0].nama, "Sabun");
    produk[0].stok = 50;
    produk[0].harga = 3000;

    strcpy(produk[1].nama, "Shampoo");
    produk[1].stok = 30;
    produk[1].harga = 5000;

    strcpy(produk[2].nama, "Pasta Gigi");
    produk[2].stok = 40;
    produk[2].harga = 3000;

    // Inisialisasi transaksi
    Transaksi transaksi[100];
    int jumlahTransaksi = 0;

    int pilihan;

    do {
        // Menampilkan menu
        printf("\n-------------------------------------------------------------\n");
        printf("\n------------- Selamat datang di toko U.D. Antony ------------\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n                                                             \n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n-- Silahkan masukkan Nomor di bawah ini untuk melanjutkan: --\n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n                                                             \n");
        printf("1. Catat Penjualan\n");
        printf("2. Tambah Stok\n");
        printf("3. Laporan Transaksi\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);

        // Memproses pilihan menu
        switch (pilihan) {
            case 1:
                catatPenjualan(produk, 3, transaksi, &jumlahTransaksi);
                break;
            case 2:
                tambahStok(produk, 3);
                break;
            case 3:
                buatLaporan(transaksi, jumlahTransaksi);
                break;
            case 4:
                printf("Terima kasih telah berbelanja di toko kami.\n");
                break;
            default:
                printf("Pilihan anda tidak sesuai. Silakan pilih menu yang benar.\n");
        }
    } while (pilihan != 4);

    return 0;
}
