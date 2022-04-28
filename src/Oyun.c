#include "Oyun.h"

Oyun new_Oyun()
{
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->kasa = 0;
    this->oyun_Baslat = &oyun_Baslat;
    this->delete_Oyun = &delete_Oyun;
    this->ekranaYazdir_oyunSonu = &ekranaYazdir_oyunSonu;
    this->ekranaYazdir_turSonu = &ekranaYazdir_turSonu;
    this->ekraniTemizle = &ekraniTemizle;
    return this;
}

void oyun_Baslat(const Oyun this)
{

    Dosya dosya = new_Dosya();
    this->turSayisi = dosya->veriSayisi(dosya, "Sayilar.txt");
    this->kisiSayisi = dosya->veriSayisi(dosya, "Kisiler.txt");
    this->sayilar = dosya->sansliSayilariOlustur(dosya);
    this->kisiler = dosya->kisileriOlustur(dosya);
    this->enZengin = this->kisiler[0];

    for (int i = 0; i < this->turSayisi; i++)
    {
        for (int k = 0; k < this->kisiSayisi; k++)
        {
            Kisi kisi = this->kisiler[k];
            if (kisi != NULL)
            {
                double para = kisi->paraMiktari * kisi->yatirmaMiktari;
                kisi->paraMiktari = kisi->paraMiktari - (kisi->paraMiktari * kisi->yatirmaMiktari);
                this->kasa += para;
                if (kisi->sansliSayi == this->sayilar[i])
                {
                    kisi->paraMiktari += para * 10.0;
                    this->kasa -= para * 10.0;
                }
                if (kisi->paraMiktari >= this->enZengin->paraMiktari)
                {

                    this->enZengin = kisi;
                }
                if (kisi->paraMiktari < 1000)
                {
                    kisi = NULL;
                }
                this->kisiler[k] = kisi;
            }
        };
        system("clear");

        this->ekranaYazdir_turSonu(this, i);

        usleep(10000);
    }
    this->ekraniTemizle(this);
    system("clear");
    this->ekranaYazdir_oyunSonu(this);

    free(this->kisiler);
    free(this->sayilar);
    this->enZengin->delete_Kisi(this->enZengin);
}

void ekranaYazdir_turSonu(const Oyun this, int tur)
{
    struct winsize max;
    ioctl(0, TIOCGWINSZ, &max);
    int column = (max.ws_col - 45) / 2;

    gotoxy(column, 4);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }
    //
    gotoxy(column, 5);
    printf("#");
    printf("#");
    gotoxy(column + 17, 5);
    printf("SANSLI SAYI: %d", this->sayilar[tur]);
    gotoxy(column + 43, 5);
    printf("#");
    printf("#");
    printf("\n");
    //
    gotoxy(column, 6);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            printf("#");
        }
        gotoxy(column, 7);
    }
    //
    gotoxy(column, 8);
    printf("#");
    printf("#");
    gotoxy(column + 17, 8);
    printf("TUR: %d", tur + 1);
    gotoxy(column + 43, 8);
    printf("#");
    printf("#");
    //
    gotoxy(column, 9);
    printf("#");
    printf("#");
    gotoxy(column + 9, 9);
    printf("MASA BAKIYE: %.2lf TL", this->kasa);
    gotoxy(column + 43, 9);
    printf("#");
    printf("#");
    //
    gotoxy(column, 10);
    printf("#");
    printf("#");
    gotoxy(column + 43, 10);
    printf("#");
    printf("#");
    //
    gotoxy(column, 11);
    for (int j = 0; j < 45; j++)
    {
        if (j == 0 || j == 1 || j == 43 || j == 44)
        {
            printf("#");
        }
        else
        {
            printf("-");
        }
    }
    gotoxy(column, 12);
    printf("#");
    printf("#");
    gotoxy(column + 17, 12);
    printf("EN ZENGIN KISI");
    gotoxy(column + 43, 12);
    printf("#");
    printf("#");
    //
    gotoxy(column, 13);
    printf("#");
    printf("#");
    gotoxy(column + 17, 13);
    printf("%s", this->enZengin->isim);
    gotoxy(column + 43, 13);
    printf("#");
    printf("#");

    gotoxy(column, 14);
    printf("#");
    printf("#");
    gotoxy(column + 9, 14);
    printf("BAKIYESI: %.2lf", this->enZengin->paraMiktari);
    gotoxy(column + 43, 14);
    printf("#");
    printf("#");

    gotoxy(column, 15);
    printf("#");
    printf("#");
    gotoxy(column + 43, 15);
    printf("#");
    printf("#");

    gotoxy(column, 16);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }
    gotoxy(column, 16);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }

    gotoxy(column, 16);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }

    gotoxy(column, 16);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }
}

void ekraniTemizle(const Oyun this)
{
    struct winsize max;
    ioctl(0, TIOCGWINSZ, &max);
    int column = (max.ws_col - 45) / 2;

    for (int i = 4; i < 16; i++)
    {
        gotoxy(column, i);
        for (int j = 0; j < 45; j++)
        {
            printf(" ");
        }
    }
}

void ekranaYazdir_oyunSonu(const Oyun this)
{
    struct winsize max;
    ioctl(0, TIOCGWINSZ, &max);
    int column = (max.ws_col - 45) / 2;

    gotoxy(column, 4);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }
    gotoxy(column, 5);
    printf("#");
    printf("#");
    gotoxy(column + 17, 5);
    printf("TUR: %d", this->turSayisi);
    gotoxy(column + 43, 5);
    printf("#");
    printf("#");
    //
    gotoxy(column, 6);
    printf("#");
    printf("#");
    gotoxy(column + 9, 6);
    printf("MASA BAKIYE: %.2lf TL", this->kasa);
    gotoxy(column + 43, 6);
    printf("#");
    printf("#");

    gotoxy(column, 7);
    printf("#");
    printf("#");
    gotoxy(column + 43, 7);
    printf("#");
    printf("#");

    gotoxy(column, 8);
    for (int j = 0; j < 45; j++)
    {
        if (j == 0 || j == 1 || j == 43 || j == 44)
        {
            printf("#");
        }
        else
        {
            printf("-");
        }
    }
    gotoxy(column, 9);
    printf("#");
    printf("#");
    gotoxy(column + 17, 9);
    printf("OYUN BITTI");
    gotoxy(column + 43, 9);
    printf("#");
    printf("#");

    gotoxy(column, 10);
    printf("#");
    printf("#");
    gotoxy(column + 43, 10);
    printf("#");
    printf("#");

    gotoxy(column, 11);
    printf("#");
    printf("#");
    gotoxy(column + 43, 11);
    printf("#");
    printf("#");

    gotoxy(column, 12);
    printf("#");
    printf("#");
    gotoxy(column + 43, 12);
    printf("#");
    printf("#");

    gotoxy(column, 13);
    for (int j = 0; j < 45; j++)
    {
        printf("#");
    }
}

void delete_Oyun(const Oyun this)
{
    if (this == NULL)
        return;
    free(this);
}