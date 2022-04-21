#include "Kisi.h"

Kisi new_Kisi(char* isim,double paraMiktari,double yatirmaMiktari,int sansliSayi){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->isim = isim;
    this->paraMiktari = paraMiktari;
    this->yatirmaMiktari = yatirmaMiktari;
    this->sansliSayi = sansliSayi;

    this->delete_Kisi = &delete_Kisi;
    return this;
}

void delete_Kisi(const Kisi this){
    if(this== NULL) return;
    free(this);
}