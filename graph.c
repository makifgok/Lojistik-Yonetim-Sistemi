#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// Grafý global bir dizi olarak tanýmlýyoruz
Sehir graf[MAX_SEHIR];
int sehirSayisi = 0;

// Grafý baþlangýçta temizle
void initGraph() {
	int i;
    sehirSayisi = 0;
    for(i = 0; i < MAX_SEHIR; i++) {
        graf[i].komsular = NULL;
    }
}

// Yeni bir þehir ekle
void sehirEkle(int id, const char* ad) {
    graf[id].sehirID = id;
    strcpy(graf[id].sehirAdi, ad);
    graf[id].komsular = NULL;
    sehirSayisi++;
}

// Ýki þehir arasýna yol (kenar) ekle (Çift yönlü / Undirected)
void kenarEkle(int kaynakID, int varisID, int mesafe) {
    // 1. Yön: Kaynaktan Hedefe
    Kenar* yeniKenar1 = (Kenar*)malloc(sizeof(Kenar));
    yeniKenar1->varisSehirID = varisID;
    yeniKenar1->mesafe = mesafe;
    yeniKenar1->next = graf[kaynakID].komsular;
    graf[kaynakID].komsular = yeniKenar1;

    // 2. Yön: Hedeften Kaynaða (Lojistik aðý olduðu için yollar gidiþ-dönüþ)
    Kenar* yeniKenar2 = (Kenar*)malloc(sizeof(Kenar));
    yeniKenar2->varisSehirID = kaynakID;
    yeniKenar2->mesafe = mesafe;
    yeniKenar2->next = graf[varisID].komsular;
    graf[varisID].komsular = yeniKenar2;
}

// Haritadaki þehirleri ve baðlantýlarýný göster
void grafYazdir() {
    printf("\n--- Lojistik Ag Haritasi (Adjacency List) ---\n");
    int i;
    for(i = 0; i < sehirSayisi; i++) {
        printf("[%s] -> ", graf[i].sehirAdi);
        Kenar* temp = graf[i].komsular;
        while(temp != NULL) {
            printf("%s(%d km) ", graf[temp->varisSehirID].sehirAdi, temp->mesafe);
            temp = temp->next;
        }
        printf("\n");
    }
}

// BFS (Breadth-First Search) Algoritmasý
void BFS_Gezinme(int baslangicID) {
    int ziyaretEdildi[MAX_SEHIR] = {0}; // Hangi þehre gidildiðini takip eden dizi
    int kuyruk[MAX_SEHIR];              // Basit kuyruk (Queue) yapýsý
    int bas = 0, son = 0;

    // Baþlangýç þehrini kuyruða ekle ve ziyaret edildi olarak iþaretle
    kuyruk[son++] = baslangicID;
    ziyaretEdildi[baslangicID] = 1;

    printf("\n--- BFS Rota Gezinmesi (Baslangic: %s) ---\n", graf[baslangicID].sehirAdi);

    while (bas < son) {
        int guncelSehirID = kuyruk[bas++]; // Kuyruktan çýkar (Dequeue)
        printf("%s -> ", graf[guncelSehirID].sehirAdi);

        // Komþularý kontrol et
        Kenar* temp = graf[guncelSehirID].komsular;
        while (temp != NULL) {
            int komsuID = temp->varisSehirID;
            if (!ziyaretEdildi[komsuID]) {
                kuyruk[son++] = komsuID;       // Kuyruða ekle (Enqueue)
                ziyaretEdildi[komsuID] = 1;    // Ziyaret edildi iþaretle
            }
            temp = temp->next;
        }
    }
    printf("SON\n\n");
}
