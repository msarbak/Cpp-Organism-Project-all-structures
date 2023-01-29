/**
 * @file Dugum.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Burda BST ağacının düğüm sınıfı bulunmaktadır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Doku.hpp"

class Dugum{

public:
    Dugum *sol;
    Doku *doku;
    Dugum *sag;
    Dugum (Doku *&);
    Dugum (Doku*&, Dugum *);
    Dugum (Dugum*, Doku*&);
    Dugum(Dugum*, Doku*&, Dugum *);
    
};


#endif 