#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct HavaVerisi {
    char tarih[12];
    int hava_durumu;
    float sicaklik;
    int nem_yuzdesi;
    float basinc;
    float ruzgar;
    float gorus_mesafesi;
    int UV_indeksi;
};

char hava_durumlari[21][40] = {"Acik", "Az Bulutlu", "Parcali Bulutlu", "Cok Bulutlu", "Sisli",
                               "Hafif Yagmurlu", "Yagmurlu", "Kuvvetli Yagmurlu", "Hafif Saganak Yagisli",
                               "Saganak Yagisli", "Kuvvetli Saganak Yagisli", "Hafif Kar Yagisli",
                               "Kar Yagisli", "Yogun Kar Yagisli", "Yer Yer Saganak Yagisli", "Dolu",
                               "Gok Gurultulu Saganak Yagisli", "Karla Karisik Yagmurlu", "Ruzgarli",
                               "Toz veya Kum Firtinasi", "Kuvvetli Gok Gurultulu Saganak Yagisli"};

void veri_girisi();
bool isValid(char tarih[12]);
void veri_goruntule();
void analiz();
void siralama();
void menu();
void tarih_araligi(char tarih[12], int gun_sayisi, char list[gun_sayisi][12]);

int main(){
    menu();

}

void menu(){
    bool flag = true;
    while(flag){
        int secim;
        printf("-------------------------------------------------------------");
        printf("\n-----------------------MENU----------------------------------");
        printf("\n(1) Veri Girisi"
               "\n(2) Girilen Verileri Goruntuleme"
               "\n(3) Belirli Deger Araliklarindaki Verileri Goruntuleme"
               "\n(4) Verilerin Siralanmasi"
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
            case 4: siralama(); break;
            case 0: flag=false; break;
            default: menu();
        }
    }

}

bool isValid(char tarih[12]){
    int gun,ay,yil;
    sscanf(tarih, "%d.%d.%d", &gun, &ay, &yil);
    switch(ay){
        case 4:
        case 6:
        case 9:
        case 11:
            if(gun < 31)
                return true;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(gun < 31)
                return true;
            break;
        case 2:
            if(gun < 29)
                return true;
            break;
    }
    return false;
}

void tarih_araligi(char tarih[12], int gun_sayisi, char list[gun_sayisi][12]) {
    int gun, ay, yil;
    char gecici_tarih[12];
    strcpy(gecici_tarih,tarih);
    sscanf(gecici_tarih, "%d.%d.%d", &gun, &ay, &yil);

    for (int i = 0; i < gun_sayisi; i++) {
        sprintf(gecici_tarih, "%d.%d.%d", gun + 1, ay, yil);

        if (isValid(gecici_tarih) == false) {
            gun = 1;
            ay += 1;

            if (isValid(gecici_tarih) == false) {
                ay = 1;
                yil += 1;
            }
        }else{
            gun += 1;
        }
        // tarih dizisini list dizisine kopyala
        for (int j = 0; j < 12; j++) {
            list[i][j] = gecici_tarih[j];
        }
    }
}

void veri_girisi() {
    int gunSayisi;
    printf("Lutfen meteorolojik kayit girmek istediginiz gun sayisini giriniz:");
    scanf("%d", &gunSayisi);
    struct HavaVerisi veri[gunSayisi];
    for (int i = 0; i < gunSayisi; i++) {
        printf("--------------------------------------------------------------------------");
        printf("\n Tarih (GG.AA.YYYY): ");
        scanf("%s", &veri[i].tarih);
        while(isValid(veri[i].tarih) == false){
            printf("\n Tarih (GG.AA.YYYY): ");
            scanf("%s", &veri[i].tarih);
        }

        printf("-------------------------------------------------------------");
        printf("\n -- Hava Durumu --");
        printf("\n Lutfen secmek istediginiz hava durumunun sayisal degerini giriniz: \n" );
        for(int j=0; j<21; j++){
            printf("%s", hava_durumlari[j]);
            printf(" (%d) \n", j+1);
        }

        scanf("%d", &veri[i].hava_durumu);


        printf("\n -------------------------------------------------------------");
        printf("\n Sicaklik Degeri: ");
        scanf("%f", &veri[i].sicaklik);

        printf("-------------------------------------------------------------");
        printf("\n Nem Yuzdesi: ");
        scanf("%d", &veri[i].nem_yuzdesi);

        printf("-------------------------------------------------------------");
        printf("\n Basinc Degeri:", veri[i].basinc);
        scanf("%f", &veri[i].basinc);

        printf("-------------------------------------------------------------");
        printf("\n Ruzgar Hizi: ", veri[i].ruzgar);
        scanf("%f", &veri[i].ruzgar);

        printf("-------------------------------------------------------------");
        printf("\n Gorus Mesafesi: ", veri[i].gorus_mesafesi);
        scanf("%f", &veri[i].gorus_mesafesi);

        printf("-------------------------------------------------------------");
        printf("\n UV Indeksi: ", veri[i].UV_indeksi);
        scanf("%d", &veri[i].UV_indeksi);

        //Verileri dosyaya yazdırma
        FILE *file;
        file = fopen("../WeatherSystem/veriler","a");
        fprintf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                      "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d}\n",
                veri[i].tarih,veri[i].hava_durumu,veri[i].sicaklik,veri[i].nem_yuzdesi,veri[i].basinc,
                veri[i].ruzgar, veri[i].gorus_mesafesi, veri[i].UV_indeksi);
        fclose(file);

    }
}

void veri_goruntule() {
    int gunsayisi;
    printf("Goruntulemek istediginiz gun sayisini girin: ");
    scanf("%d", &gunsayisi);

    for (int i = 0; i < gunsayisi; i++) {
        char dateInput[12];
        printf("Goruntulemek istediginiz %d.gunun tarihini girin: ", i + 1);
        scanf("%s", dateInput);

        while (!isValid(dateInput)) {
            printf("Girilen tarih gecersiz. Tekrar girin: ");
            scanf("%s", dateInput);
        }

        FILE *file = fopen("../WeatherSystem/veriler", "r");
        if (file == NULL) {
            printf("Dosya acma hatasi\n");
            return;
        }

        struct HavaVerisi veri;
        int tarihBulundu = 0;

        while (fscanf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %f\nNem Yuzdesi: %d\n"
                            "Basinc Degeri: %f\nRuzgar Hizi: %f\nGorus Mesafesi: %f\nUV Indeksi: %d}\n",
                      veri.tarih, &veri.hava_durumu, &veri.sicaklik, &veri.nem_yuzdesi, &veri.basinc,
                      &veri.ruzgar, &veri.gorus_mesafesi, &veri.UV_indeksi) == 8) {
            if (strcmp(veri.tarih, dateInput) == 0) {
                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);

                fclose(file);
                tarihBulundu = 1;
                break;
            }
        }
        if (!tarihBulundu) {
            printf("Bu tarihe ait girili veri bulunamadı\n");
        }

        fclose(file);
    }
}

void analiz() {

    int secim, gun_sayisi;
    float min, max;
    char bas_gun[12];
    char gun_listesi[gun_sayisi][12];
    char parametre[6][15] = {"Sicaklik", "Nem Yuzdesi", "Basinc",
                             "Ruzgar", "Gorus Mesafesi", "UV_indeksi"};
    struct HavaVerisi veri;


    printf("Lutfen analiz etmek istediginiz araligin baslangic gununu giriniz: (GG.AA.YYYY)\n");
    scanf("%s", &bas_gun);
    printf("Lutfen analiz etmek istediginiz aralikta kac gun oldugunu giriniz:");
    scanf("%d", &gun_sayisi);

    tarih_araligi(bas_gun,gun_sayisi, gun_listesi);

    printf("Lutfen analiz etmek istediginiz parametreyi seciniz: \n");
    printf("-----------------------------------------------------\n");
    printf("Sicaklik (1)\n Nem Yuzdesi (2)\n Basıinc "
           "(3)\n Ruzgar (4)\n Gorus Mesafesi (5)\n UV_indeksi (6)\n");
    scanf("%d", &secim);

    printf(" %s degerinin min ve max degerini giriniz.\n", parametre[secim-1]);
    scanf("%f", &min);
    scanf("%f", &max);

    while (!((secim < 1) || (secim > 6))) {
        printf("Hata! Lutfen gecerli bir secim yapiniz");
        scanf("%d", &secim);
    }

    FILE *file = fopen("../WeatherSystem/veriler", "r");
    if (file == NULL) {
        printf("Dosya acma hatasi\n");

        while (fscanf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %f\nNem Yuzdesi: %d\n"
                            "Basinc Degeri: %f\nRuzgar Hizi: %f\nGorus Mesafesi: %f\nUV Indeksi: %d}\n",
                      veri.tarih, &veri.hava_durumu, &veri.sicaklik, &veri.nem_yuzdesi, &veri.basinc,
                      &veri.ruzgar, &veri.gorus_mesafesi, &veri.UV_indeksi) == 8) {
            for (int i = 0; i < gun_sayisi; i++) {
                if (strcmp(veri.tarih, gun_listesi[i]) == 0) {
                    switch (secim) {
                        case 1:
                            if ((min <= veri.sicaklik) && (veri.sicaklik <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);

                            }
                            break;
                        case 2:
                            if ((min <= veri.nem_yuzdesi) && (veri.nem_yuzdesi <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);

                            }
                            break;
                        case 3:
                            if ((min <= veri.basinc) && (veri.basinc <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);

                            }
                            break;

                        case 4:
                            if ((min <= veri.ruzgar) && (veri.ruzgar <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);
                            }
                            break;

                        case 5:
                            if ((min <= veri.gorus_mesafesi) && (veri.gorus_mesafesi <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);
                            }
                            break;

                        case 6:
                            if ((min <= veri.UV_indeksi) && (veri.UV_indeksi <= max)) {
                                printf("Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %.2f\nNem Yuzdesi: %d\n"
                                       "Basinc Degeri: %.2f\nRuzgar Hizi: %.2f\nGorus Mesafesi: %.2f\nUV Indeksi: %d\n",
                                       veri.tarih, veri.hava_durumu, veri.sicaklik, veri.nem_yuzdesi, veri.basinc,
                                       veri.ruzgar, veri.gorus_mesafesi, veri.UV_indeksi);
                            }
                            break;
                    }


                }
            }

        }


    }
}


void siralama(){}


