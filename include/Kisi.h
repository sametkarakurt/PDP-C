#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>

struct KISI
{
    char* isim;
    double paraMiktari;
    double yatirmaMiktari;
    int sansliSayi;

    void (*delete_Kisi) (struct KISI*);
};

typedef struct KISI* Kisi;

Kisi new_Kisi(char*,double,double,int);
void delete_Kisi(const Kisi);

#endif