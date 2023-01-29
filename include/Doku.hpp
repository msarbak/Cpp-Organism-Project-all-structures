/**
 * @file Doku.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Doku sinifinin header dosyasidir. Doku sınıf Hucre sınıfından oluşan bir bağlı liste yapısıdır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */
#ifndef DOKU_HPP
#define DOKU_HPP

#include "Hucre.hpp"

#include<math.h>


class Doku{

    private:
        Doku *kendisi;
        int uzunluk;
        Hucre *OncekiElemanBul(int);

    public:
        Doku *sol;
        Doku *sag;

        Hucre *bas;

        //Constructor
        Doku();
        Doku(Doku *&);
        Doku(Doku *, Doku *&);
        Doku(Doku*& , Doku* );
        Doku(Doku*, Doku*&, Doku*);

        //elemanSayisi 
        int elemanSayisi() const;

        //Liste bos olup olmadigini kontrol eder
        bool bosMu() const;

        //ekle Hucre to the end of the list
        void ekle(const int&);

        //insert Hucre at a given position in the list
        void insert(const int&, int);

        //ilk  hucreyi dondurur
        Hucre* ilk();
        //Son hucreyi dondurur
        Hucre* son();

        //Verilen Hucreyi siler
        void sil(const int&);


        //Verilen Hucrenin pozisyonunu dondurur
        int indexOf(const int&) ;
        
       

        //Verilen posizyondaki Hucreyi siler
        void removeAt(int) ;


        //Verilen pozisyondaki Hucreyi dondurur
        const int& elementAt(int) ;
        

        //Listeyi ekrana basar
        void yazdir();

        //Listenin orta hucresini bulur
        int orta();

      

        Doku * mutasyon(Doku *);

        //Listeyi temizler
        void temizle();

        //Destructor
        ~Doku();
};


#endif //Doku_H