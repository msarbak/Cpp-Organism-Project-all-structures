/**
 * @file console.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sınıf ConsoleColor header dosyasıdır.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */


#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <conio.h> 
#include <windows.h>

static class colorStat {
    public:
    //int colors;
    static void color(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    } 
} colorStat;

#endif 

