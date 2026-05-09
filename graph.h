#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"

#define MAX_SEHIR 10 // Sisteme eklenebilecek maksimum þehir sayýsý

// Fonksiyon prototipleri
void initGraph();
void sehirEkle(int id, const char* ad);
void kenarEkle(int kaynakID, int varisID, int mesafe);
void grafYazdir();
void BFS_Gezinme(int baslangicID);

#endif // GRAPH_H
