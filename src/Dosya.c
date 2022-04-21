#include "Dosya.h"

Dosya new_Dosya(){
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));

    this->kisileriOlustur = &kisileriOlustur;
    this->sansliSayilariOlustur = &sansliSayilariOlustur;
    this->veriSayisi = &veriSayisi;
    this->delete_Dosya = &delete_Dosya;
    return this;
}

int *sansliSayilariOlustur(const Dosya this){
    int count = this->veriSayisi(this,"Sayilar.txt");
    int *sansliSayilar = (int*)malloc(sizeof(int)*count);
    FILE *dosya;
    int i = 0;
    dosya=fopen("Sayilar.txt","r");
    if(dosya!=NULL){
        while (!feof(dosya))
        {
            fscanf(dosya,"%d",&sansliSayilar[i]);
            i++;
        }
        
    }
    return sansliSayilar;

}
int veriSayisi (const Dosya this,char* dosyaAdi){
    FILE *dosya;
    int count = 1;
    char c;
    dosya=fopen(dosyaAdi,"r");
    if(dosya!=NULL){
        do{
            c = fgetc(dosya);
            if (c == '\n') count++;
        }while (c != EOF);
        
    }
    return count;
}
Kisi* kisileriOlustur(const Dosya this){
    

    int count = this->veriSayisi(this,"Kisiler.txt");
    Kisi *kisiler = (Kisi*)malloc(sizeof(Kisi)*count);


    FILE *dosya;
    dosya=fopen("Kisiler.txt","r");
    char* isim = (char*)malloc(sizeof(char) * count);
    float paraMiktari = 0;
    float yatirmaMiktari = 0;
    int sansliSayi = 0;
    char line[100];
    int count2 = 0;
    if(dosya!=NULL){
        
        while (fgets(line,sizeof(line),dosya))
        {

               char* isim = (char*)malloc(sizeof(char) * count);
               char * token = strtok(line, "#");
                int count = 1;
                while( token != NULL ) {
                    if(count==1){
                        strcpy(isim,token);
                    }else if(count == 2){
                        paraMiktari = atof(token);
                    }else if(count == 3){
                        yatirmaMiktari = atof(token);
                    }else{
                        sansliSayi = atoll(token);
                        
                    }
                    token = strtok(NULL, "#");
                    count++;
                }
                
                Kisi kisi = new_Kisi(isim,paraMiktari,yatirmaMiktari,sansliSayi);
                
                kisiler[count2] = kisi;
                count2++;
                
                
        }
        
    }

    return kisiler;
    
   
}
void delete_Dosya(const Dosya this){
    if(this == NULL) return;
    free(this);
}
