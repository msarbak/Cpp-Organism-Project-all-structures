/**
 * @file Test.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Burada programin calismasi icin gerekli olan main fonksiyonu bulunmaktadir.   
 * @date 2022-12-25
 * @course 1 A
 * @assignment Odev 2
 */

#include "Kontrol.hpp"
#include "Console.hpp"
#include <iomanip> 


int main(){
    cout<<endl;
    colorStat.color(10);
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl<<setw(5)<<"/     Program Baslatildi...    /"<<endl;
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl;
    colorStat.color(7);
    
        /*DOSYA ADI BELIRTMELISINIZ*/
    string path = "doc/gulenyuz.txt"; //OKUNACAK VERI DOSYASI


    Kontrol* problem = new Kontrol(path);

    colorStat.color(10);
    cout<<endl;
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl<<setw(5)<<"/     Lutfen bekleyiniz...     /"<<endl;
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl;
    colorStat.color(7);

    problem->cozumuGoster();

    colorStat.color(10);
    cout<<endl;
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl<<setw(5)<<"/     Program Sonlandi...      /"<<endl;
    cout<<endl<<setw(5)<<"/------------------------------/"<<endl;
    cout<<endl;
    colorStat.color(7);

    return 0;
}