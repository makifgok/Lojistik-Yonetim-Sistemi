#ifndef TYPES_H
#define TYPES_H

// --- HASH TABLOSU ÝÇÝN PAKET YAPISI (Zincirleme Kullanýlacak) ---
typedef struct Paket {
    char paketID[20];       // Benzersiz paket numarasý (Buna göre hash'lenecek)
    char gonderici[50];
    char alici[50];
    char hedefSehir[50];    // Graf üzerindeki hangi þehre gidecek
    int durum;              // 0: Ýþlemde, 1: Yolda, 2: Teslim Edildi
    struct Paket* next;     // Zincirleme (Chaining) için pointer
} Paket;

// --- GRAF ÝÇÝN ÞEHÝR VE KENAR YAPILARI ---
// Komþuluk Listesi (Adjacency List) mantýðý kullanacaðýz.

// Bir þehre baðlý olan diðer þehirleri (kenarlarý) tutacak yapý
typedef struct Kenar {
    int varisSehirID;       // Komþu þehrin sistemdeki ID/Ýndeks numarasý
    int mesafe;             // Þehirler arasý uzaklýk/maliyet
    struct Kenar* next;     // Diðer komþuya giden pointer
} Kenar;

// Graf içindeki ana þehir düðümü
typedef struct Sehir {
    int sehirID;            // Plaka veya sistem ID'si
    char sehirAdi[50];
    Kenar* komsular;        // Bu þehre baðlý olan yollarýn (kenarlarýn) listesi
} Sehir;

#endif // TYPES_H
