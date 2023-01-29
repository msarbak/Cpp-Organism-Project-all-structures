/**
 * @file Array.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Array list sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Array.hpp"
#include "Console.hpp"


Array::Array(){ //Constructor
    uzunluk = 0;
    kapasite = 1;
    dokular = new Doku*[kapasite];
}

Array::Array(const Array& array){ //Copy Constructor
    uzunluk = array.uzunluk;
    kapasite = array.kapasite;
    dokular = new Doku*[kapasite];
    for(int i = 0; i < uzunluk; i++) dokular[i] = array.dokular[i];
}

void Array::reserve(int yeniKapasite) { //Kapasiteyi arttirir(yer acar)
    Doku **yeniDokular = new Doku*[yeniKapasite];
    for(int i = 0; i < uzunluk; i++) yeniDokular[i] = dokular[i];
    delete [] dokular;
    dokular = yeniDokular;
    kapasite = yeniKapasite;
}

int Array::elemanSayisi() const{ return uzunluk; } //elemanSayisini dondurur
bool Array::bosMu() const{ return uzunluk == 0; } //Liste bos olup olmadigini kontrol eder

int Array::indexOf(Doku *doku) const{ //Verilen Hucrenin pozisyonunu dondurur
    for(int i = 0; i < uzunluk; i++)
        if(dokular[i] == doku)
            return i;
    colorStat.color(9);
    throw "Listede aranan eleman yok";
    colorStat.color(7);
}

Doku*& Array::elementAt(int index) const { //Verilen pozisyondaki Hucreyi dondurur
    if(index < 0 || index >= uzunluk) {
        colorStat.color(9);
        throw "Listede aranan eleman yok";
        colorStat.color(7);
    }
    return dokular[index];
}

void Array::sil(Doku *doku){ //Verilen Hucreyi siler
    int index = indexOf(doku);
    removeAt(index);
}

void Array::removeAt(int index){ //Verilen posizyondaki Hucreyi siler
    if(index < 0 || index >= uzunluk){
        colorStat.color(9);
        throw "Listede aranan eleman yok";
        colorStat.color(7);
    }
    dokular[index]->removeAt(index);
    for(int i = index; i < uzunluk - 1; i++) dokular[i] = dokular[i + 1];
    uzunluk--;

}

void Array::ekle(Doku *doku){ //Listeye Hucre ekler
    if(uzunluk == kapasite) reserve(kapasite * 2);
    dokular[uzunluk++] = doku;
}

void Array::insert(int index, Doku* doku){ //Verilen Hucreyi verilen pozisyona ekler
    if(index < 0 || index > uzunluk) {
        colorStat.color(9);
        throw "Listede aranan eleman yok";
        colorStat.color(7);
    }
    if(uzunluk == kapasite) reserve(kapasite * 2);
    for(int i = uzunluk; i > index; i--) dokular[i] = dokular[i - 1];
    dokular[index] = doku;
    uzunluk++;
}

Doku* Array::ilk() const { //İlk Hucreyi dondurur
    if(bosMu()) {
        colorStat.color(9);
        throw "Liste bos";
        colorStat.color(7);
    }
    return dokular[0];
}

Doku* Array::son() const { //Son Hucreyi dondurur
    if(bosMu()) {
        colorStat.color(9);
        throw "Liste bos";
        colorStat.color(7);
    }
    return dokular[uzunluk - 1];
}

void Array::yazdir(){
    for(int i = 0; i < uzunluk; i++)
        dokular[i]->yazdir();
        cout<<endl;
}

void Array::temizle(){ //Aray listi temizler
    for(int i = 0; i < uzunluk; i++) dokular[i]->~Doku();
    uzunluk = 0;
    if(kapasite > 1) reserve(1);
    delete [] dokular;
}

Array::~Array(){ temizle(); } //Destructor
