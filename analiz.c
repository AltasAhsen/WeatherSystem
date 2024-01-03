#include "tarih_araligi.c"

void analiz() {
    int secim, gun_sayisi;
    float min, max;
    char bas_gun[12];
    char parametre[6][15] = {"Sicaklik", "Nem Yuzdesi", "Basinc",
                             "Ruzgar", "Gorus Mesafesi", "UV_indeksi"};
    struct HavaVerisi veri;

    printf("Lutfen analiz etmek istediginiz araligin baslangic gununu giriniz: (GG.AA.YYYY)\n");
    scanf("%s", &bas_gun);
    printf("Lutfen analiz etmek istediginiz aralikta kac gun oldugunu giriniz:");
    scanf("%d", &gun_sayisi);

    char gun_listesi[gun_sayisi][12];

    tarih_araligi(bas_gun, gun_sayisi, gun_listesi);

    printf("Lutfen analiz etmek istediginiz parametreyi seciniz: \n");
    printf("-----------------------------------------------------\n");
    printf("Sicaklik (1)\n Nem Yuzdesi (2)\n Basıinc "
           "(3)\n Ruzgar (4)\n Gorus Mesafesi (5)\n UV_indeksi (6)\n");
    scanf("%d", &secim);

    while (((secim < 1) || (secim > 6))) {
        printf("Hata! Lutfen gecerli bir secim yapiniz");
        scanf("%d", &secim);
    }

    printf(" %s degerinin min ve max degerini giriniz.\n", parametre[secim - 1]);
    scanf("%f", &min);
    scanf("%f", &max);


    FILE *file = fopen("../WeatherSystem/veriler", "r");
    if (file == NULL) {
        printf("Dosya acma hatasi\n");
    }
    while (fscanf(file, "{Tarih: %s\nHava Durumu: %d\nSicaklik Degeri: %f\nNem Yuzdesi: %d\n"
                        "Basinc Degeri: %f\nRuzgar Hizi: %f\nGorus Mesafesi: %f\nUV Indeksi: %d}\n",
                  veri.tarih, &veri.hava_durumu, &veri.sicaklik, &veri.nem_yuzdesi, &veri.basinc,
                  &veri.ruzgar, &veri.gorus_mesafesi, &veri.UV_indeksi) == 8) {
        for (int i = 0; i < gun_sayisi; i++) {
            int veri_gun, veri_ay, veri_yil, liste_gun, liste_ay, liste_yil;
            sscanf(veri.tarih, "%d.%d.%d", &veri_gun, &veri_ay, &veri_yil);
            sscanf(veri.tarih, "%d.%d.%d", &liste_gun, &liste_ay, &liste_yil);
            if (veri_gun == liste_gun && veri_ay == liste_ay && veri_yil == liste_yil) {
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
