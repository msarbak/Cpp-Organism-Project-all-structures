/**
 * @file BST.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sınıf BST ağacının header dosyasıdır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef BST_HPP
#define BST_HPP



#include "Array.hpp"
#include "Dugum.hpp"


class BST{
    private:
        Dugum * kok;
        void BulVeEkle(Dugum *&, Doku *&);
        bool BulVeSil(Dugum* &, Doku*&);
        bool Sil(Dugum* &);
        void LevelOreder(Dugum*, int);
        void PostOrder(Dugum*, Array*&);
        int ElemanSayisi(Dugum*);
        int Uzunluk(Dugum*);
        int DengeKontrolu(Dugum*);
        bool Bul(Dugum*, Doku*&);

    public:
        BST();
        bool bosMu() const;
        int elemanSayisi();
        void ekle(Doku*&);
        void sil(Doku*&);
        void levelOrder();
        void postOrder(Array *&);
        void yazdir();
        int uzunluk();
        bool dengeliMi(); //Ağaç dengeli olup olmadığını kontrol eden fonksiyon
        bool bul(Doku*&);
        bool mutasyonaUgradiMi();
        void temizle();
        ~BST();
};

#endif