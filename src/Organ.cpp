/**
 * @file Organ.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Organ sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Organ.hpp"

Organ::Organ(BST *dokular){
    this->onceki = NULL;
    this->dokular = dokular;
    this->sonraki = NULL;
}

Organ::Organ(BST *dokular, Organ *sonraki){
    this->onceki = NULL;
    this->dokular = dokular;
    this->sonraki = sonraki;
}

Organ::Organ(Organ *onceki, BST *dokular){
    this->onceki = onceki;
    this->dokular = dokular;
    this->sonraki = NULL;
}

Organ::Organ(Organ *onceki, BST *dokular, Organ *sonraki){
    this->dokular = dokular;
    this->onceki = onceki;
    this->sonraki = sonraki;
}

Organ::~Organ(){
    delete dokular;
    delete onceki;
    delete sonraki;
}