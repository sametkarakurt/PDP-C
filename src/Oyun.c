#include "Oyun.h"


Oyun new_Oyun(){
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->kasa = 0;
    this->oyun_Baslat = &oyun_Baslat;
    this->delete_Oyun = &delete_Oyun;
    return this;
}
void oyun_Baslat(const Oyun this){

    Dosya dosya = new_Dosya();
    int turSayisi = dosya->veriSayisi(dosya,"Sayilar.txt");
    int kisiSayisi = dosya->veriSayisi(dosya,"Kisiler.txt");
    int *sayilar = dosya->sansliSayilariOlustur(dosya);
    Kisi *kisiler = dosya->kisileriOlustur(dosya);
    Kisi enZengin = kisiler[0];


    for (int i=0;i<turSayisi;i++){
        for(int k=0;k<kisiSayisi;k++){
            Kisi kisi = kisiler[k];
            if(kisi != NULL){
            float para = kisi->paraMiktari * kisi->yatirmaMiktari;
            kisi->paraMiktari = kisi->paraMiktari - para;
            this->kasa += para;
            if(kisi->sansliSayi == sayilar[i]){
                kisi->paraMiktari += para * 10.0;
                this->kasa -= para * 10.0;
            }
            if(kisi->paraMiktari > enZengin->paraMiktari){
               
                enZengin = kisi;
            }
            if(kisi->paraMiktari < 1000){
                kisi = NULL;
            }
            kisiler[k] = kisi;

            }
            

        };

        printf("SANSLI SAYI: %d",sayilar[i]);
        printf("\n");

        printf("TUR: %d",i);
        printf("\n");

        printf("MASA BAKIYE: %f",this->kasa);
         printf("\n");

        printf("EN ZENGIN KISI\n");
        printf("%s",enZengin->isim);
        printf("\n");
        printf("BAKIYES: %f",enZengin->paraMiktari);
        printf("\n");

        usleep(100000);
        system("clear");





    }

            printf("TUR: %d",turSayisi);
        printf("\n");

        printf("MASA BAKIYE: %f",this->kasa);
         printf("\n");

         printf("OYUN BITTI");

    

}
void delete_Oyun(const Oyun this){
    if(this== NULL) return;
    free(this);
}