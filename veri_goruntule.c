#include <string.h>
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