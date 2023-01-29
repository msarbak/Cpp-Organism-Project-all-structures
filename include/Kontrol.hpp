/**
 * @file Kontrol.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Kontrol sınıf dosya okuma,  organizmaların ve mutasyonların olusturuldugu yerdir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */
#ifndef KONTROL_HPP
#define KONTROL_HPP

#include "Queue.hpp"
#include "Radix.hpp"
#include "Organizma.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Kontrol{
    public:
        string yol;
        Array *dokular;
        Organizma *organizma;
        Kontrol(string);
        Array* butunDokular(); //Dosya oku ve tüm sirali dokulari dondur 
        void organizmaOlustur(Array *);
        void mutasyonOlustur(Organizma *);
        void cozumuGoster();
        ~Kontrol();
};

#endif 