#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kisi.h"

struct DOSYA
{
    int (*veriSayisi)(struct DOSYA *, char *);
    Kisi *(*kisileriOlustur)(struct DOSYA *);
    int *(*sansliSayilariOlustur)(struct DOSYA *);
    void (*delete_Dosya)(struct DOSYA *);
};

typedef struct DOSYA *Dosya;

Dosya new_Dosya();
int *sansliSayilariOlustur(const Dosya);
int veriSayisi(const Dosya, char *);
Kisi *kisileriOlustur(const Dosya);
void delete_Dosya(const Dosya);

#endif