/**
 * @file Queue.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Queue sinifi bir kuyruk veriyapısıdır, yardımcı sinifi olmaktadır
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */
#ifndef QUEUE_HPP
#define QUEUE_HPP


class Queue{

private:
    int front;
    int rear;
    int capacity;
    int length;
    int *items;
    void reserve(int);

public:
    Queue(); //Constructor
    int elemanSayisi() const; //Eleman sayisini dondurur
    bool bosMu() const; //Kuyruk bos mu?
    const int& peek(); //ilk elemani dondurur
    void enqueue(const int&); //kuyruga eleman ekler
    const int &dequeue(); //kuyruktan eleman cikarir
    void temizle(); //kuyruktaki elemanlari temizler
    ~Queue(); //Destructor
};

#endif 