/**
 * @file Hucre.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sınıf hücre sınıfıdır. Hucre bir dugum olarak tanımlanmıştır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef HUCRE_HPP
#define HUCRE_HPP

#include <iostream>
using namespace std;

class Hucre{

public:
    Hucre *onceki;
    int DNA;
    Hucre *sonraki;
    
    //Constructors
    Hucre(int);
    Hucre(Hucre*, int);
    Hucre(int, Hucre*);
    Hucre(Hucre*, int, Hucre*);

    ~Hucre(); //Destructor

};

#endif