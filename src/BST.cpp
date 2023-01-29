/**
 * @file bst.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif bst sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "BST.hpp"

void BST::BulVeEkle(Dugum *& dugum, Doku*& doku){
    if(dugum == NULL) dugum = new Dugum(doku);
    else if(doku->orta() <= dugum->doku->orta())
        BulVeEkle(dugum->sol,doku);
    else if(doku->orta() > dugum->doku->orta())
        BulVeEkle(dugum->sag,doku);
    else return;

}

bool  BST::BulVeSil(Dugum* & dugum, Doku*& doku){
    if(dugum == NULL) return false;
    else if(doku->orta() == dugum->doku->orta())
        Sil(dugum); 
   
    else if(doku->orta() <= dugum->doku->orta())
        BulVeSil(dugum->sol,doku);
    
    else if(doku->orta() > dugum->doku->orta())
        BulVeSil(dugum->sag,doku);
    else return false;
}

bool  BST::Sil(Dugum* &dugum){
    Dugum * cop = dugum;

    if(dugum->sag == NULL){
        dugum = dugum->sol;
    }
    else if (dugum->sol == NULL){
        dugum = dugum->sag;
    }
    else{
        cop = dugum->sol;
        Dugum* ebeveyn = dugum;
        while(cop->sag != NULL){
            ebeveyn = cop;
            cop = cop->sag;
        }
        dugum->doku = cop->doku;
        if(ebeveyn == dugum)
            dugum->sol = cop->sol;
        else
            ebeveyn->sag = cop->sol;
    }
    delete cop;
    return true;
}

void BST:: LevelOreder(Dugum* dugum, int level){
    if(dugum == NULL) return;
    if(level == 0){ //Test 
        cout <<dugum->doku->orta() << ": ";
        dugum->doku->yazdir();
        cout << endl;
    }
    else{
        LevelOreder(dugum->sol, level-1);
        LevelOreder(dugum->sag, level-1);
    }
}



void BST::PostOrder(Dugum* dugum, Array*& mutasyonDisizi){
    if(dugum != NULL){
        PostOrder(dugum->sol, mutasyonDisizi);
        PostOrder(dugum->sag, mutasyonDisizi);
        Doku *mutasyonDoku = new Doku();
        mutasyonDoku = dugum->doku->mutasyon(dugum->doku);
        mutasyonDisizi->ekle(mutasyonDoku);
    }
}
int BST::ElemanSayisi(Dugum* dugum){
    if(dugum == NULL) return 0;
    return 1 + ElemanSayisi(dugum->sol) + ElemanSayisi(dugum->sag);
}

int  BST::Uzunluk(Dugum*dugum){
    if(dugum == NULL) return -1;
    return 1 + max(Uzunluk(dugum->sol), Uzunluk(dugum->sag));
}

bool  BST::Bul(Dugum* dugum, Doku*& doku){
    if(dugum == NULL) return false;
    else if(doku->orta() == dugum->doku->orta()) return true;
    else if(doku->orta() <= dugum->doku->orta()) return Bul(dugum->sol,doku);
    else if(doku->orta() > dugum->doku->orta()) return Bul(dugum->sag,doku);
    else return false;
}

int BST::DengeKontrolu(Dugum* dugum) {
    //agac bos; dengeli
    if(dugum == NULL) return 0;
    int solHeight = Uzunluk(dugum->sol);
    int sagHeight = Uzunluk(dugum->sag);
    int balanceFactor = solHeight - sagHeight;

    if (abs(balanceFactor) > 1) {
        // agac dengeli degilse
        return -1;
    } else {
    // check balance of subtrees
        int solBalance = DengeKontrolu(dugum->sol);
        int sagBalance = DengeKontrolu(dugum->sag);
        if (solBalance == -1 || sagBalance == -1) {
        // altAgaclardan biri dengeli degilse
        return -1;
        } else {
        // agac dengeli
        return 0;
        }
    }
}


//Public
BST::BST(){
    kok = NULL;
}

bool  BST::bosMu() const{
    return kok == NULL;
}

int  BST::elemanSayisi(){
    return ElemanSayisi(kok);
}

void  BST::ekle(Doku*& doku){
    BulVeEkle(kok, doku);
}

void  BST::sil(Doku*& doku){
    BulVeSil(kok, doku);
}

void  BST::levelOrder(){
    for(int level = 0; level<=Uzunluk(kok); level++){
        LevelOreder(kok, level);
    }
}

void BST::postOrder(Array*& mutasyonDisizi){
    PostOrder(kok, mutasyonDisizi);
}

void BST::yazdir(){
    if(this->dengeliMi())cout<<" ";
    else cout<<"#";
}
int  BST::uzunluk(){
    return Uzunluk(kok);
}

bool BST::dengeliMi() {
  if(DengeKontrolu(kok) == -1) return false;
  else return true;
}



bool  BST::bul(Doku*& doku){
    return Bul(kok, doku);
}

bool BST::mutasyonaUgradiMi(){
    if(kok == NULL) return false;
    else if(kok->doku->orta()%50 == 0) return true;
    else return false;
}

void  BST::temizle(){
    while(!bosMu()){
        Sil(kok);
    }
}

BST::~BST(){ temizle(); }