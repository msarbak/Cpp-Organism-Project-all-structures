/**
 * @file doku.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif doku sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Doku.hpp"
#include "Console.hpp"

Doku::Doku(){
    bas = NULL;
    uzunluk = 0;
}

Doku::Doku(Doku *& kendisi){
    bas = NULL;
    uzunluk = 0;
    this->kendisi = kendisi;
    kendisi->sol = NULL;
    kendisi->sag = NULL;
}

Doku::Doku(Doku *sol, Doku *& kendisi){
    bas = NULL;
    uzunluk = 0;
    this->kendisi = kendisi;
    kendisi->sol = sol;
    kendisi->sag = NULL;
}

Doku::Doku(Doku *& doku, Doku *sag){
    bas = NULL;
    uzunluk = 0;
    this->kendisi = kendisi;
    kendisi->sol = NULL;
    kendisi->sag = sag;
}

Doku::Doku(Doku *sol, Doku *& doku, Doku *sag){
    bas = NULL;
    uzunluk = 0;
    this->kendisi = kendisi;
    kendisi->sol = sol;
    kendisi->sag = sag;
}


Hucre *Doku::OncekiElemanBul(int index) {
    if (index < 0 || index > uzunluk) {
        colorStat.color(9);
        throw "element bulunamadi";
        colorStat.color(7);
    }
    Hucre *prev = bas;
    int sayac = 1;
    for (Hucre* iterator = bas; iterator->sonraki != NULL && sayac != index; iterator = iterator->sonraki, sayac++) prev = prev->sonraki;
    return prev;
}

int Doku::elemanSayisi() const { return uzunluk; }
bool Doku::bosMu() const { return uzunluk == 0; }
void Doku::ekle(const int &DNA) { insert(DNA, uzunluk); }

void Doku::insert(const int &DNA , int index) {
    if(index < 0 || index > uzunluk) {
        colorStat.color(9);
        throw "index tasti";
        colorStat.color(7);
    }
    if(index == 0){
        bas = new Hucre(NULL,DNA,bas);
        if(bas->sonraki != NULL)
            bas->sonraki->onceki = bas;
    }else{
        Hucre *prev = OncekiElemanBul(index);
        prev->sonraki = new Hucre(prev,DNA,prev->sonraki);
        if(prev->sonraki->sonraki != NULL)
            prev->sonraki->sonraki->sonraki = prev->sonraki;
    }
    uzunluk++;
}

Hucre *Doku::ilk() {
    if(bosMu()) {
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return bas;
}

Hucre *Doku::son() {
    if(bosMu()){
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return OncekiElemanBul(uzunluk - 1)->sonraki;
}

void Doku::sil(const int &DNA){ removeAt(indexOf(DNA)); }

void Doku::removeAt(int index){

    if (index < 0 || index >= uzunluk) {
        colorStat.color(9);
        throw "index tasti";
        colorStat.color(7);
    }
    Hucre *cop;
    if (index == 0){
        cop = bas;
        bas = bas->sonraki;
        if(bas != NULL) bas->onceki = NULL;
    }else{
        Hucre *prev = OncekiElemanBul(index);
        cop = prev->sonraki;
        prev->sonraki = cop->sonraki;
        if(cop->sonraki != NULL) cop->sonraki->onceki = prev;
    }
    uzunluk--;  
    delete cop; 
}

int Doku::indexOf(const int& DNA) {
    int index = 0;
    for (Hucre* iterator = bas; iterator != NULL; iterator = iterator->sonraki){
        if(iterator->DNA == DNA) return index;
        index++;
    }
    colorStat.color(9);
    throw "eleman bulunamadi";
    colorStat.color(7);
    
}

const int&  Doku::elementAt(int index) {
    if (index < 0 || index >= uzunluk) {
        colorStat.color(9);
        throw "eleman bulunamadi";
        colorStat.color(7);
    }
    if(index == 0) return bas->DNA;
    return OncekiElemanBul(index)->sonraki->DNA;
}

int Doku::orta(){ return this->elementAt((this->elemanSayisi()/2)); }

Doku* Doku::mutasyon(Doku *doku){
    Doku *mutasyonDoku = new Doku();
    for(int i = 0; i < doku->elemanSayisi(); i++){
        if(doku->elementAt(i) % 2 == 0)  mutasyonDoku->ekle(doku->elementAt(i)/2); 
        else mutasyonDoku->ekle(doku->elementAt(i));
    }
    return mutasyonDoku;
}

void Doku::yazdir(){
    for (Hucre* iterator = bas; iterator != NULL; iterator = iterator->sonraki) cout << iterator->DNA << " "; 
    cout << endl;
}

void Doku::temizle(){
    while(!bosMu()){
        removeAt(0);
    }
}

Doku::~Doku(){
    this->bas->onceki = NULL;
    this->bas->sonraki = NULL;
    temizle(); 
}