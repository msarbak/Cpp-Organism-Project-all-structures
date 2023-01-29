/**
 * @file Queue.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif Queue sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Queue.hpp"
#include "Console.hpp"	

Queue::Queue(){
    capacity = 1;
    front = 0;
    rear = -1;
    length = 0;			
    items = new int[capacity];
}

void Queue::reserve(int yenicapacity){
    int *temp = new int[yenicapacity];
    for(int i=0; i<length; i++) temp[i] = items[(front + i) % capacity];
    delete[] items;
    items = temp;
    front = 0;
    rear = length - 1;
    capacity = yenicapacity;
}

int Queue::elemanSayisi() const{ return length; }
bool Queue::bosMu() const{ return length == 0;}

const int& Queue::peek() { // Kuyrukta en öndeki elemanı getirir
    if(bosMu()) {
        colorStat.color(9);
        throw "kuyruk bos";
        colorStat.color(7);
    }
    return items[front];
}

void Queue::enqueue(const int& eleman){
    if(length == capacity) reserve(capacity*2);
    rear = (rear+1) % capacity;
    items[rear] = eleman;
    length++;
}

const int& Queue::dequeue(){
    if(bosMu()) {
        colorStat.color(9);
        throw "kuyruk bos";
        colorStat.color(7);
    }
    front = (front+1) % capacity;
    length--;
}

void Queue::temizle(){
    while(!bosMu()){
        dequeue();
    }
}
Queue::~Queue(){ delete[] items; }