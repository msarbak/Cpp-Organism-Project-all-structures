/**
 * @file Dugum.h
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Dugum sinifinin header dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Dugum.hpp"

Dugum::Dugum(Doku *&doku){
    this->sol = NULL;
    this->doku = doku;
    this->sag = NULL;
}

Dugum::Dugum(Doku *&doku, Dugum *sag){
    this->sol = NULL;
    this->doku = doku;
    this->sag = sag;
} 

Dugum::Dugum(Dugum *sol, Doku *&doku){
    this->sol = sol;
    this->doku = doku;
    this->sag = NULL;
}

Dugum::Dugum(Dugum *sol, Doku *&doku, Dugum *sag){
    this->sol = sol;
    this->doku = doku;
    this->sag = sag;
}