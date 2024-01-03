#include <stdio.h>
#include <stdbool.h>
#include "veri_girisi.c"
#include "veri_goruntule.c"
#include "analiz.c"

int main(){
    bool flag = true;
    while(flag){
        int secim;
        printf("-------------------------------------------------------------");
        printf("\n-----------------------MENU----------------------------------");
        printf("\n(1) Veri Girisi"
               "\n(2) Girilen Verileri Goruntuleme"
               "\n(3) Belirli Deger Araliklarindaki Verileri Goruntuleme"
               "\n(0) Çıkış");
        printf("\nLutfen yapmak istediginiz islemi secin:");

        while(scanf("%d", &secim) !=1 || !(-1<secim && secim<5)){
            printf("Lutfen gecerli bir secenek giriniz: ");
            while(getchar()!='\n'); //Hatalı girişi temizle
        }

        switch(secim){
            case 1: veri_girisi(); break;
            case 2: veri_goruntule(); break;
            case 3: analiz(); break;
            case 0: flag=false; break;
            default: main();
        }
    }


}



