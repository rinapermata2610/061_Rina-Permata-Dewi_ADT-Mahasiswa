#include "header.h"

void TampilkanMenu() {
    printf("\n========================================\n");
    printf("|         MENU UTAMA MAHASISWA         |\n");
    printf("========================================\n");
    printf("| 1. Tambahkan Mahasiswa              |\n");
    printf("| 2. Tampilkan Daftar Mahasiswa       |\n");
    printf("| 3. Hitung Jumlah Mahasiswa          |\n");
    printf("| 4. Salin Mahasiswa dengan Nilai > 70|\n");
    printf("| 5. Hapus Duplikat di List 2         |\n");
    printf("| 6. Hapus Semua Data                 |\n");
    printf("| 7. Keluar                           |\n");
    printf("========================================\n");
    printf("Pilihan: ");
}

void SubmenuUrutkan(List *L) {
    int pilihan, tipeUrutan;
    
    if (isEmpty(*L)) {
        printf("List kosong!\n");
        return;
    }

    printf("\nUrutkan berdasarkan:\n");
    printf("1. Nama\n");
    printf("2. Nilai UTS\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    printf("\n1. Ascending (A-Z / Kecil ke Besar)\n");
    printf("2. Descending (Z-A / Besar ke Kecil)\n");
    printf("Pilihan: ");
    scanf("%d", &tipeUrutan);

    if (pilihan == 1) { // Berdasarkan Nama
        if (tipeUrutan == 1) {
            Ascending(L, true);
            printf("\n=== Daftar Mahasiswa (A-Z) ===\n");
        } else {
            Descending(L, true);
            printf("\n=== Daftar Mahasiswa (Z-A) ===\n");
        }
    } else if (pilihan == 2) { // Berdasarkan Nilai
        if (tipeUrutan == 1) {
            Ascending(L, false);
            printf("\n=== Daftar Mahasiswa (Nilai Kecil ke Besar) ===\n");
        } else {
            Descending(L, false);
            printf("\n=== Daftar Mahasiswa (Nilai Besar ke Kecil) ===\n");
        }
    } else {
        printf("Pilihan tidak valid!\n");
        return;
    }

    PrintList(*L);
}

int main() {
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);
    int pilihan;
    Mahasiswa data;

    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // Menghindari newline issue

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = '\0'; // Hapus newline
                printf("Masukkan Nilai UTS: ");
                scanf("%d", &data.nilaiUTS);
                InsertSortedByNama(&L1, data);
                break;
            case 2:
                SubmenuUrutkan(&L1);
                break;
            case 3:
                printf("Jumlah Mahasiswa: %d\n", HitungElement(L1));
                break;
            case 4:
                CopyAtas70(&L2, L1);
                printf("Mahasiswa dengan nilai > 70 disalin ke List 2.\n");
                break;
            case 5:
                RemoveDuplikat(&L2);
                printf("Duplikat di List 2 telah dihapus.\n");
                break;
            case 6:
                DeleteList(&L1);
                DeleteList(&L2);
                printf("Semua data telah dihapus!\n");
                break;
            case 0:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
