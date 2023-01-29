/**
 * @file hucre.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Hucre sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Hucre.hpp"

Hucre::Hucre(int DNA){
    this->onceki = NULL;
    this->DNA = DNA;
    this->sonraki = NULL;
}

Hucre::Hucre(Hucre * onceki, int DNA){
    this->onceki = onceki;
    this->DNA = DNA;
    sonraki = NULL;
}

Hucre::Hucre(int DNA, Hucre * sonraki){
    this->onceki = NULL;
    this->DNA = DNA;
    this->sonraki = sonraki;
}

Hucre::Hucre(Hucre * onceki, int DNA, Hucre * sonraki){
    this->onceki = onceki;
    this->DNA = DNA;
    this->sonraki = sonraki;
}

Hucre::~Hucre(){
    this->onceki = NULL;
    this->DNA = 0;
    this->sonraki = NULL;
}