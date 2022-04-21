#ifndef OYUN_H
#define OYUN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Dosya.h"
#include "Kisi.h"

struct OYUN
{
    double kasa;
    int sansliSayi;
    Kisi* kisiler;
    int* sayilar;
    Kisi enZengin;
    Dosya dosya;
    void (*oyun_Baslat)(struct OYUN*);
    void (*delete_Oyun) (struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun new_Oyun();
void oyun_Baslat(const Oyun);
void delete_Oyun(const Oyun);


#endif