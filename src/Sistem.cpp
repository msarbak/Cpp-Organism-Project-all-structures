/**
 * @file Sistem.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif sistem sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Sistem.hpp"
#include "Console.hpp"

Sistem::Sistem(){
    head = NULL;
    length = 0;
}

Organ *Sistem::FindPreviousByPosition(int index){
    if (index < 0 || index > length) {
        colorStat.color(9);
        throw "eleman listede mevcut degil";
        colorStat.color(7);
    }
    Organ *prev = head;
    int sayac = 1;
    for (
        Organ* iterator = head; 
        iterator->sonraki != NULL && sayac != index;
        iterator = iterator->sonraki, sayac++
    )
    {
        prev = prev->sonraki;
    }
    return prev;
}


int Sistem::count() const{ return length; }
bool Sistem::isEmpty() const{ return length == 0; }
void Sistem::add(Organ *organ){ insert(organ, length); }

void Sistem::insert(Organ *organ, int index){
    if(index < 0 || index > length) {
        colorStat.color(9);
        throw "index tasti";
        colorStat.color(7);
    }
    if(index == 0){
        head = new Organ(organ->dokular, head);
        if(head->sonraki != NULL) head->sonraki->onceki = head;
    }
    else{
        Organ *prev = FindPreviousByPosition(index);
        prev->sonraki = new Organ(prev,organ->dokular,prev->sonraki);
        if(prev->sonraki->sonraki != NULL) prev->sonraki->sonraki->onceki = prev->sonraki;  
    }
    length++;
}

Organ *Sistem::ilk() {
    if(isEmpty()) {
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return head;
}

Organ *Sistem::son() {
    if(isEmpty()) {
        colorStat.color(9);
        throw "liste bos";
        colorStat.color(7);
    }
    return FindPreviousByPosition(length);
}

Organ *Sistem::elementAt(int index) {
    if(index < 0 || index > length) {
        colorStat.color(9);
        throw "index tasti";
        colorStat.color(7);
    }
    if(index == 0) return head;
    return FindPreviousByPosition(index)->sonraki;
}

Organ *Sistem::indexOf(Organ *organ) {
    Organ *prev = head;
    for (Organ* iterator = head; iterator->sonraki != NULL; iterator = iterator->sonraki)
    {
        if(iterator->dokular == organ->dokular) return prev;
        prev = prev->sonraki;
    }
    colorStat.color(9);
    throw "eleman listede mevcut degil";
    colorStat.color(7);
    
}

void Sistem::remove(Organ *organ){
    Organ *prev = indexOf(organ);
    if(prev == head){
        head = head->sonraki;
        head->onceki = NULL;
    }else{
        prev->sonraki = prev->sonraki->sonraki;
        if(prev->sonraki != NULL)
            prev->sonraki->onceki = prev;
    }
    length--;
}

void Sistem::removeAt(int index){
    if(index < 0 || index > length) {
        colorStat.color(9);
        throw "index sinir disi";
        colorStat.color(7);
    }
    if(index == 0){
        head = head->sonraki;
        head->onceki = NULL;
    }else{
        Organ *prev = FindPreviousByPosition(index);
        prev->sonraki = prev->sonraki->sonraki;
        if(prev->sonraki != NULL) prev->sonraki->onceki = prev;
    }
    length--;
}

void Sistem::degistir(int index, Organ *mutasyonOrgani){ //sistemdeki organ ile mutasyonlu organi degistirir, eski organi siler
    if(index < 0 || index > length) {
        colorStat.color(9);
        throw "index sinir disi";
        colorStat.color(7);
    }
    removeAt(index); //Once o indexdeki organi sistemden cikar
    insert(mutasyonOrgani, index); //Sonra da o indexe yeni organi add
}


void Sistem::yazdir(){
    for (Organ* iterator = head; iterator->sonraki != NULL; iterator = iterator->sonraki) iterator->dokular->yazdir();
}


void Sistem::temizle(){
    for(Organ* iterator = head; iterator->sonraki != NULL; iterator = iterator->sonraki) delete iterator->dokular;
    delete head;
}

Sistem::~Sistem(){ temizle(); }