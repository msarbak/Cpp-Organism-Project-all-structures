/**
 * @file Sistem.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinifta sistemimizi olusturduk. sistem organlari tutan bir liste gibi dusunulebilir.
 * @date 2022-12-25
 * @course 1 A
 * @assignment Odev 2
 */
#ifndef SISTEM_HPP
#define SISTEM_HPP


#include "Array.hpp"
#include "Organ.hpp"

class Sistem{
private:
    Organ *head;
    int length;
    Organ *FindPreviousByPosition(int);

public:
    Sistem();
    int count() const;
    bool isEmpty() const;

    void add(Organ *);
    void insert(Organ *, int);
    void removeAt(int );
    void remove(Organ *);

    Organ *ilk();
    Organ *son();
    Organ *elementAt(int );
    Organ *indexOf(Organ *);

    void degistir(int, Organ *);
    void yazdir();
    void temizle();
    
    ~Sistem();
};

#endif 