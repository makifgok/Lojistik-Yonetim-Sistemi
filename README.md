# 📦 Hibrit Veri Yapıları ile Lojistik Yönetim Sistemi

Bu proje, Kırklareli Üniversitesi Yazılım Mühendisliği bölümü "Veri Yapıları ve Algoritmalar" dersi kapsamında geliştirilmiş bir lojistik ve kargo ağ yönetimi simülasyonudur. Projede şehirler arası bağlantılar **Graf (Graph)** yapısıyla, paket arama işlemleri ise **Hash Tablosu (Hash Table)** yapısıyla hibrit olarak modellenmiştir.

## 🚀 Kullanılan Teknolojiler ve Veri Yapıları
Proje **C programlama dili** ile çoklu dosya (modüler) mimarisine uygun olarak geliştirilmiştir.

*   **Hash Tablosu (Tip B):** Paket ID'leri string tabanlı olarak alınmış ve her karakterin ASCII değeri asal bir sayı (31) ile çarpılarak indeksler üretilmiştir. O(1)'e yakın arama performansı sunar.
*   **Çakışma (Collision) Çözümü:** İndeks çakışmalarını önlemek amacıyla **Zincirleme (Chaining - Linked List)** yöntemi uygulanmıştır.
*   **Graf Yapısı:** Şehirler ve mesafeler arası bağlantılar bellek optimizasyonu sağlamak adına **Komşuluk Listesi (Adjacency List)** ile tasarlanmıştır. Çift yönlü (undirected) yollar kullanılmıştır.
*   **Hedef Arama Algoritması:** Lojistik rotaların seviye seviye taranması için kuyruk (queue) destekli **BFS (Sığ Öncelikli Arama)** algoritması kullanılmıştır.

## 📂 Proje Mimarisi (Çoklu Dosya Yapısı)
Sistem, mantıksal katmanlarına göre aşağıdaki dosyalara ayrılmıştır:

- `types.h`: Sistemde kullanılan `Paket` ve `Sehir` gibi temel struct yapılarını barındırır.
- `hashTable.h / .c`: Paketlerin belleğe eklenmesi, aranması ve çakışma durumlarının yönetildiği katmandır.
- `graph.h / .c`: Şehirlerin eklenmesi, yolların bağlanması ve BFS algoritmasının yürütüldüğü katmandır.
- `main.c`: Kullanıcı etkileşimli konsol menüsünü (switch-case) ve test verilerini içerir.

## ⚙️ Kurulum ve Çalıştırma

Projeyi kendi bilgisayarınızda derlemek ve çalıştırmak için GCC derleyicisine ihtiyacınız vardır. Konsol veya terminal üzerinden proje dizinine giderek aşağıdaki komutu çalıştırabilirsiniz:
```bash
gcc main.c hashTable.c graph.c -o LojistikSistemi
./LojistikSistemi
