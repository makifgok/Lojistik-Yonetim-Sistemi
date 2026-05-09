#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

// Hash tablosunu global bir dizi olarak tanýmlýyoruz (Paket pointer dizisi)
Paket* hashTable[HASH_TABLE_SIZE];

// Tabloyu baþlangýçta NULL ile doldur
void initHashTable() {
	int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Tip B Hash Fonksiyonu:
// String içindeki karakterlerin ASCII deðerlerini ve pozisyonlarýný (asal çarpanla) kullanarak benzersiz bir index üretir.
int hashFunctionTipB(char* key) {
    int hashVal = 0;
    int i;
    for(i = 0; key[i] != '\0'; i++) {
        hashVal = (hashVal * 31 + key[i]) % HASH_TABLE_SIZE;
    }
    return hashVal;
}

// Zincirleme (Chaining) yöntemi ile paketi hash tablosuna ekleme
void insertPaket(Paket yeniPaket) {
    // Yeni paket için heap belleðinde yer ayýr (Bellek raporu için bu adresler önemli olacak)
    Paket* eklenecek = (Paket*)malloc(sizeof(Paket));
    *eklenecek = yeniPaket;
    eklenecek->next = NULL;

    int index = hashFunctionTipB(eklenecek->paketID);

    // Zincirleme: Ýlgili indekste eleman yoksa doðrudan ilk sýraya ekle
    if(hashTable[index] == NULL) {
        hashTable[index] = eklenecek;
    } else {
        // Çakýþma (Collision) var, listenin sonuna git ve oraya baðla
        Paket* temp = hashTable[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = eklenecek;
    }
    printf("[SISTEM] Paket ID: %s | Hash Ýndeksi: %d | RAM Adresi: %p adresine eklendi.\n", eklenecek->paketID, index, (void*)eklenecek);
}

// Paket ID'ye göre paket arama (O(1) veya O(k) karmaþýklýðýnda)
Paket* searchPaket(char* paketID) {
    int index = hashFunctionTipB(paketID);
    Paket* temp = hashTable[index];

    // Ýlgili indeksteki baðlý liste içinde gezinerek paketi ara
    while(temp != NULL) {
        if(strcmp(temp->paketID, paketID) == 0) {
            return temp; // Paket bulundu
        }
        temp = temp->next;
    }
    return NULL; // Paket bulunamadý
}
