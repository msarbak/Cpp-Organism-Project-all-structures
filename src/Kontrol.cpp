/**
 * @file Kontrol.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif kontrol sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Kontrol.hpp"
#include "Console.hpp"

Kontrol::Kontrol(string yol){
    this->yol = yol;
    this->dokular = butunDokular();
    this->organizma = new Organizma();
}

Array* Kontrol::butunDokular(){
    ifstream dosya(yol);
    if (!dosya.is_open()) {
        colorStat.color(9);
        cout<<endl<<"Dosya yolu hatalidir!!!"<<endl<<endl;
        colorStat.color(7);
    }
    string satir;
    Array *dokular = new Array();  //Butun dokularin tutuldugu dizi(Array list)
    while (getline(dosya, satir)) {
       if(!satir.empty()){ //satir bos degilse
            stringstream buffer(satir);
            char ayirici = ' ';
            string sayi;
            Doku *doku = new Doku(); //Doku olustur
            while(getline(buffer, sayi, ayirici)) {
                if(!sayi.empty()){
                    doku->ekle(stoi(sayi));
                }    
            }
            Radiks *radix = new Radiks(doku);
            Doku *sirali = radix->sort(doku, doku->elemanSayisi());
            dokular->ekle(sirali);
        }
    }
    dosya.close(); //Dosyayi kapat
    return dokular;
}

void Kontrol::organizmaOlustur(Array *dokular){
    Organ *organ; //20 dokudan olusan bir organ(BST)
    Sistem *sistem; //100 organi iceren bir sistem
    BST *bst = new BST();
    sistem = new Sistem();

    for(int i = 0; i < dokular->elemanSayisi(); i++){
        bst->ekle(dokular->elementAt(i));
        if(bst->elemanSayisi() == 20){
            organ = new Organ(bst);
            sistem->add(organ);
            if(sistem->count() == 100){
                organizma->ekle(sistem);
                sistem = new Sistem(); //sistem sifirlama
            }
            bst = new BST();  //bst sifirlama
        }
    }
    organizma->yazdir("ORGANIZMA");
}

void Kontrol::mutasyonOlustur(Organizma *organizma){
    Array *mutasyonDizisi; //mutasyonlar
    for (int i = 0; i<organizma->elemanSayisi(); i++){ 
        for(int j = 0; j < organizma->elementAt(i)->count(); j++){ 
            if(organizma->elementAt(i)->elementAt(j)->dokular->mutasyonaUgradiMi()){
                mutasyonDizisi = new Array();
                organizma->elementAt(i)->elementAt(j)->dokular->postOrder(mutasyonDizisi);
                BST *mutasyonAgaci  = new BST();
                Organ *mutasyonOrgani;
                do{
                    Doku *doku = mutasyonDizisi->elementAt(0); //Dokuyu al
                    Radiks *radix = new Radiks(doku); //Doku sirala
                    Doku *sirali = radix->sort(doku, doku->elemanSayisi());
                    mutasyonAgaci->ekle(sirali); //Tekrar agaca ekle
                    mutasyonDizisi->removeAt(0); //Ekelenen dokuyu sil
                }while(!mutasyonDizisi->bosMu());
                mutasyonOrgani = new Organ(mutasyonAgaci); //Mutasyon organi olustur(sifirlandi )
                organizma->elementAt(i)->degistir(j, mutasyonOrgani); //Mutasyon organi sistemdeki organa ekle
            }
            
        }
    }
    organizma->yazdir("ORGANIZMA (MUTASYONLU)");
}

void Kontrol::cozumuGoster(){

    organizmaOlustur(this->dokular);
    cin.get();

    mutasyonOlustur(this->organizma);
    cin.get();
}

Kontrol::~Kontrol(){
    this->dokular->~Array();
    this->organizma->~Organizma();
}