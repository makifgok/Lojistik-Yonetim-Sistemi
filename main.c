#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "hashTable.h"
#include "graph.h"

// Sistemi test etmek için senin girdigin verileri otomatik yukleyen fonksiyon
void onTanimliVerileriYukle() {
    // C89 standardýna uygun olmasý için deðiþkenleri en baþta tanýmlýyoruz
    Paket p1 = {"PKT101", "Akif", "Naz", "Izmir", 0, NULL};
    Paket p2 = {"PKT102", "Eylul", "Nevin", "Osmaniye", 0, NULL};
    Paket p3 = {"PKT103", "Nisa", "Goktug", "Ankara", 0, NULL};
    Paket p4 = {"PKT104", "Gizem", "Buse", "Kayseri", 0, NULL};
    Paket p5 = {"PKT105", "Domenico", "Tedesco", "Kadikoy", 0, NULL};

    // Paketleri sisteme ekle
    printf("-> Hazir paketler sisteme isleniyor ve RAM'e yerlestiriliyor...\n");
    insertPaket(p1);
    insertPaket(p2);
    insertPaket(p3);
    insertPaket(p4);
    insertPaket(p5);
    printf("\n");

    // Þehirleri ekleyelim (0: Kirklareli, 1: Istanbul, 2: Ankara, 3: Osmaniye, 4: Izmir)
    sehirEkle(0, "Kirklareli");
    sehirEkle(1, "Istanbul");
    sehirEkle(2, "Ankara");
    sehirEkle(3, "Osmaniye");
    sehirEkle(4, "Izmir");

    // Yollarý baðlayalým (Mesafe/Maliyet örneði)
    kenarEkle(0, 1, 210); // Kirklareli - Istanbul
    kenarEkle(1, 2, 450); // Istanbul - Ankara
    kenarEkle(1, 4, 480); // Istanbul - Izmir
    kenarEkle(2, 3, 500); // Ankara - Osmaniye
}

int main() {
    /* Eski C standartlarý (C89/C90) için tüm deðiþkenleri main'in baþýnda tanýmladýk */
    int secim;
    Paket yeniPkt;
    char aranan[20];
    Paket* bul;
    int baslangic;

    // 1. Sistem kurulumu ve bellek hazýrlýklarý
    initHashTable();
    initGraph();
    
    printf("--- Lojistik Sistemi Baslatildi ---\n\n");
    onTanimliVerileriYukle();

    // 2. Kullanýcý Menüsü Döngüsü
    do {
        printf("\n=========================================\n");
        printf("       LOJISTIK YONETIM SISTEMI\n");
        printf("=========================================\n");
        printf("[1] Yeni Paket Ekle\n");
        printf("[2] Paket Sorgula\n");
        printf("[3] Lojistik Ag Haritasini Goster (Adjacency List)\n");
        printf("[4] BFS ile Rota Gezinmesi Yap\n");
        printf("[0] Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                printf("\nPaket ID (Orn: PKT106): ");
                scanf(" %s", yeniPkt.paketID); // ID'de bosluk olmaz
                
                printf("Gonderici Adi: ");
                scanf(" %[^\n]", yeniPkt.gonderici); // Bosluklu isim alabilir
                
                printf("Alici Adi: ");
                scanf(" %[^\n]", yeniPkt.alici); // Bosluklu isim alabilir
                
                printf("Hedef Sehir: ");
                scanf(" %[^\n]", yeniPkt.hedefSehir); // Bosluklu sehir alabilir
                
                yeniPkt.durum = 0;
                yeniPkt.next = NULL;
                
                printf("-> Sistem paketi isliyor...\n");
                insertPaket(yeniPkt);
                break;
                
            case 2:
                printf("\nSorgulanacak Paket ID: ");
                scanf("%s", aranan);
                
                bul = searchPaket(aranan);
                if(bul != NULL) {
                    printf("\n>>> [BULUNDU] Paket: %s | Gonderici: %s -> Alici: %s | Hedef: %s <<<\n", 
                           bul->paketID, bul->gonderici, bul->alici, bul->hedefSehir);
                } else {
                    printf("\n>>> [HATA] Paket sistemde bulunamadi! <<<\n");
                }
                break;
                
            case 3:
                grafYazdir();
                break;
                
            case 4:
                printf("\nBaslangic Sehir ID (0: Kirklareli, 1: Istanbul, 2: Ankara, 3: Osmaniye, 4: Izmir): ");
                scanf("%d", &baslangic);
                
                if(baslangic >= 0 && baslangic < 5) {
                    BFS_Gezinme(baslangic);
                } else {
                    printf("\n[HATA] Gecersiz Sehir ID!\n");
                }
                break;
                
            case 0:
                printf("\nSistem kapatiliyor. Iyi gunler dileriz...\n");
                break;
                
            default:
                printf("\nHatali secim, lutfen gecerli bir islem seciniz.\n");
        }
    } while(secim != 0);

    return 0;
}
