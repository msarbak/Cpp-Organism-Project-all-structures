/**
 * @file Array.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Array list sinifinin header dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Doku.hpp"

class Array
{
    private:
	    Doku **dokular;
		int uzunluk;
		int kapasite;
		void reserve(int); //Kapasiteyi arttirir(yer acar)
		
	public:
		Array(); //Constructor
		Array(const Array &); //Copy Constructor
		int elemanSayisi() const; //elemanSayisini dondurur
		bool bosMu() const; //Liste bos olup olmadigini kontrol eder 
		int indexOf(Doku *) const; //Verilen Hucrenin pozisyonunu dondurur
		Doku*& elementAt(int ) const; //Verilen pozisyondaki Hucreyi dondurur
		void sil(Doku *); //Verilen Hucreyi siler
		void removeAt(int); //Verilen posizyondaki Hucreyi siler
		void ekle(Doku *); //Listeye Hucre ekler
		void insert(int, Doku*); //Verilen Hucreyi verilen pozisyona ekler
		Doku* ilk() const; //İlk Hucreyi dondurur
		Doku* son() const; //Son Hucreyi dondurur
		void yazdir(); //Listeyi ekrana basar
		void temizle(); //Aray listi temizler
		~Array(); //Destructor
};

#endif