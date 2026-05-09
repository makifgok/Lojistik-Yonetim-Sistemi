#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "types.h"

// Hash tablosu boyutu (Asal sayý seçmek çakýþmalarý azaltýr)
#define HASH_TABLE_SIZE 11 

// Fonksiyon prototipleri
void initHashTable();
int hashFunctionTipB(char* key);
void insertPaket(Paket yeniPaket);
Paket* searchPaket(char* paketID);

#endif // HASHTABLE_H
