/**
 * @file Radix.cpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu sinif radix sinifinin kaynak dosyasidir.
 * @date 2022-12-23
 * @course 1 A
 * @assignment Odev 2
 */

#include "Radix.hpp"

Radiks::Radiks(Doku *doku){ this->doku = doku; }

int Radiks::MaxStepNumber(Doku *doku, int length){
    int max=0;
    for(int index=0;index<length;index++){
        if(this->StepCount(doku->bas->DNA) > max){
            max = this->StepCount(doku->bas->DNA);
        }
    }
    return max;
}

int Radiks::StepCount(int number){
	number = abs(number);
	int basamak = 0;
	while(number != 0){
		number /= 10;
        basamak++;
	}
	return basamak;
}

Doku* Radiks::sort(Doku* doku, int length){

    int max = MaxStepNumber(doku, length);
    int basamak = 1;
    int index = 0;
    int sayac = 0;

    int *sayacArray = new int[10];
    int *indexArray = new int[10];
    int *tempArray1 = new int[length];
    int *tempArray2 = new int[length];

    for(int i = 0; i < length; i++) tempArray1[i] = doku->elementAt(i);
    for(int i = 0; i < length; i++) tempArray2[i] = doku->elementAt(i);
    for(int i = 0; i < max; i++){
        
        for(int j = 0; j < 10; j++) sayacArray[j] = 0;
        for(int j = 0; j < length; j++) sayacArray[(tempArray1[j]/basamak)%10]++;
        indexArray[0] = 0;
        for(int j = 1; j < 10; j++) indexArray[j] = indexArray[j-1] + sayacArray[j-1];
        for(int j = 0; j < length; j++){
            index = indexArray[(tempArray1[j]/basamak)%10];
            tempArray2[index] = tempArray1[j];
            indexArray[(tempArray1[j]/basamak)%10]++;
        }
        for(int j = 0; j < length; j++) tempArray1[j] = tempArray2[j];
        basamak *= 10;
    }
    Doku* sirali = new Doku();
    for(int i = 0; i < length; i++) sirali->ekle(tempArray1[i]);
    return sirali;
}

Radiks::~Radiks(){ this->doku->~Doku(); }