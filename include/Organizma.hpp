/**
 * @file Organizma.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Organizma sınıfı, sistemleri tutan bir liste sınıfıdır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef ORGANIZMA_HPP
#define ORGANIZMA_HPP

#include <stdlib.h>
#include "Sistem.hpp"

class Organizma
{
    private:
		Sistem **sistemler;
		int length;
		int capacity;
		void reserve(int);

	public:
		Organizma();
		int elemanSayisi() const;
		bool bosMu() const;
		int indexOf(Sistem *) const;
		Sistem* elementAt(int) const;
		void sil(Sistem * );
		void removeAt(int );
		void ekle(Sistem *);
		void insert(int, Sistem *);
		Sistem* ilk();
		Sistem* son() const;
		void yazdir(string);
		void temizle();
		~Organizma();
};

#endif 
