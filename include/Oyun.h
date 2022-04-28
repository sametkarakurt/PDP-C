#ifndef OYUN_H
#define OYUN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "Dosya.h"
#include "Kisi.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

struct OYUN
{
    double kasa;
    int sansliSayi;
    Kisi *kisiler;
    int kisiSayisi;
    int *sayilar;
    int turSayisi;
    Kisi enZengin;
    Dosya dosya;
    void (*oyun_Baslat)(struct OYUN *);
    void (*ekranaYazdir_oyunSonu)(struct OYUN *);
    void (*ekranaYazdir_turSonu)(struct OYUN *, int);
    void (*ekraniTemizle)(struct OYUN *);
    void (*delete_Oyun)(struct OYUN *);
};

typedef struct OYUN *Oyun;

Oyun new_Oyun();
void oyun_Baslat(const Oyun);
void ekranaYazdir_oyunSonu(const Oyun);
void ekranaYazdir_turSonu(const Oyun, int);
void ekraniTemizle(const Oyun);
void delete_Oyun(const Oyun);

#endif