/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures dan Dynamic Array
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Muhammad Azka Rahadian (13224036)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menampilkan penjaga terbaik untuk setiap shift
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Petugas {
    char *nama;
    int id;
    char shift[3];
    int skor; 
};
int main (){
    int n;
    scanf("%d", &n);
    struct Petugas *arr;
    arr = (struct Petugas*) malloc(n *sizeof(struct Petugas));
    //input data
    for (int i=0;i<n;i++){
        arr[i].nama = (char *)malloc(100*sizeof(char));
        scanf(" %[^\n] %d %[^\n] %d", arr[i].nama, &arr[i].id, arr[i].shift, &arr[i].skor);
    }
    //4 Alya 101 PAGI 80 Bima 102 SIANG 92 Cika 103 PAGI 88 Doni 104 MALAM 70
    char pagi[]="PAGI";
    char siang[]="SIANG";
    char malam[]="MALAM"; 
    //pagi
    int idxpagi = -1;
    for(int i=0; i<n;i++){
        //cari indeks dengan skor terbesar di pagi
        if (strcmp(arr[i].shift, pagi) == 0){
            //kasus indeks i>i+1
            if (arr[i].skor >arr[i+1].skor){
                idxpagi = i;
            }
            //kasus indeks i<i+1
            else if (arr[i].skor == arr[i+1].skor){
                if (arr[i].id <arr[i+1].id){
                    idxpagi =i;
                } else if (arr[i].id ==arr[i+1].id){
                    if (strcmp(arr[i].nama,arr[i+1].nama) < 0){
                        idxpagi =i;
                    }
                }
            }
            //kasus indeks i==i+1, cari dari syarat kondisi lain juga
            else if (arr[i].skor<arr[i+1].skor){
                idxpagi = i+1;
            }            
        }
    }
    //siang
    int idxsiang = -1;
    for(int i=0; i<n;i++){
        if (strcmp(arr[i].shift, siang) == 0){
            if (arr[i].skor >arr[i+1].skor){
                idxsiang = i;
            } else if (arr[i].skor==arr[i+1].skor){
                if (arr[i].id <arr[i+1].id){
                    idxsiang =i;
                } else if (arr[i].id ==arr[i+1].id){
                    if (strcmp(arr[i].nama,arr[i+1].nama) < 0){
                        idxsiang =i;
                    }
                }
            } else if (arr[i].skor<arr[i+1].skor){
                idxsiang = i+1;
            }            
        }
    }
    //malam
    int idxmalam = -1;
    for(int i=0; i<n;i++){
        if (strcmp(arr[i].shift, malam) == 0){
            if (arr[i].skor >arr[i+1].skor){
                idxmalam = i;
            } else if (arr[i].skor==arr[i+1].skor){
                if (arr[i].id <arr[i+1].id){
                    idxmalam =i;
                } else if (arr[i].id ==arr[i+1].id){
                    if (strcmp(arr[i].nama,arr[i+1].nama) < 0){
                        idxmalam =i;
                    }
                }
            } else if (arr[i].skor<arr[i+1].skor){
                idxmalam = i+1;
            }            
        }
    }
    //print sesuai format
    if (idxpagi != -1){
        printf("PAGI %s %d %d\n", arr[idxpagi].nama,arr[idxpagi].id,arr[idxpagi].skor);
    } else {
        printf("PAGI -\n");
    }
    if (idxsiang != -1){
        printf("SIANG %s %d %d\n", arr[idxsiang].nama,arr[idxsiang].id,arr[idxsiang].skor);
    } else {
        printf("SIANG -\n");
    }
    if (idxmalam != -1){
        printf("MALAM %s %d %d\n", arr[idxmalam].nama,arr[idxmalam].id,arr[idxmalam].skor);
    } else {
        printf("MALAM -\n");
    }

    return 0;
}
