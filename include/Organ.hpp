/**
 * @file Organ.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Organ sınıfı tanımlanmıştır. Hucrelerin tutulduğu organ bir dugum sınıfıdır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef ORGAN_HPP
#define ORGAN_HPP

#include "BST.hpp"


//Organ 20 Dokudan olusur(BST 20 elemanli(20 dokudan olusur)))

class Organ{
    public:
        Organ *onceki;
        BST *dokular;
        Organ *sonraki;

        //Constructors
        Organ (BST*);
        Organ (BST*, Organ *);
        Organ (Organ*, BST*);
        Organ(Organ*, BST*, Organ *);

        ~Organ(); //Destructor
    
};

#endif 