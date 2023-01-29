/**
 * @file Organizma.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Organizma sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Organizma.hpp"
#include "Console.hpp"

Organizma::Organizma(){
    length = 0;
    capacity = 1;
    sistemler = new Sistem*[capacity];
}


void Organizma::reserve(int new_capacity){
    Sistem **temp = new Sistem*[new_capacity];
    for(int i=0; i<length; i++) temp[i] = sistemler[i];
    delete[] sistemler;
    sistemler = temp;
    capacity = new_capacity;
}

int Organizma::elemanSayisi() const{ return length; }
bool Organizma::bosMu() const{ return length == 0; }

int Organizma::indexOf(Sistem *sistem) const {
    for(int indeks=0; indeks<length; indeks++){
        if(sistemler[indeks] == sistem) return indeks;
    }
    colorStat.color(9);
    throw "eleman listede mevcut degil";
    colorStat.color(7);
}

Sistem* Organizma::elementAt(int index) const {
    if(index < 0 || index >= length) {
        colorStat.color(9);
        throw "eleman listede mevcut degil";
        colorStat.color(7);
    }
    return sistemler[index];
}

void Organizma::sil(Sistem * sistem) {
    int indeks = indexOf(sistem);
    removeAt(indeks);
}

void Organizma::removeAt(int index) {
    if(index < 0 || index >= length) {
        colorStat.color(9);
        throw "eleman listede mevcut degil";
        colorStat.color(7);
    }
    Sistem **temp = new Sistem*[capacity];
    for(int i=0; i<index; i++) temp[i] = sistemler[i];
    for(int i=index+1; i<length; i++) temp[i-1] = sistemler[i];
    delete[] sistemler;
    sistemler = temp;
    length--;
}

void Organizma::ekle(Sistem * sistem){
    if(length == capacity)  reserve(capacity*2);
    sistemler[length++] = sistem;
}


void Organizma::insert(int index, Sistem * sistem){
    if(index < 0 || index > length) {
        colorStat.color(9);
        throw "index tasti";
        colorStat.color(7);
    }
    if(length == capacity) reserve(capacity*2);
    
    Sistem **temp = new Sistem*[capacity];
    for(int i=0; i<index; i++) temp[i] = sistemler[i];
    temp[index] = sistem;
    for(int i=index; i<length; i++) temp[i+1] = sistemler[i];
    
    delete[] sistemler;
    sistemler = temp;
    length++;
}

Sistem* Organizma::ilk() {
    if(length == 0) {
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return sistemler[0];
}

Sistem* Organizma::son() const {
    if(length == 0) {
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return sistemler[length-1];
}

void Organizma::yazdir(string baslik){
    system("cls");
    int bosluk = (74 - baslik.length())/2;
    for(int i=0; i<bosluk; i++) cout<<" ";
    colorStat.color(14);
    cout<<baslik<<endl<<endl;
    colorStat.color(7);
    for(int i=0; i<length; i++){
        sistemler[i]->yazdir();
        cout<<endl;
    }
}


void Organizma::temizle(){
   for(int i=0; i<length; i++) sistemler[i]->~Sistem();
    delete[] sistemler;
}

Organizma::~Organizma(){ temizle(); }