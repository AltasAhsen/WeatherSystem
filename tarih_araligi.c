void tarih_araligi(char tarih[12], int gun_sayisi, char list[gun_sayisi][12]) {
    int gun, ay, yil;
    char gecici_tarih[12];
    strcpy(gecici_tarih,tarih);
    sscanf(gecici_tarih, "%d.%d.%d", &gun, &ay, &yil);

    for (int i = 0; i < gun_sayisi; i++) {
        sprintf(gecici_tarih, "%d.%d.%d", gun, ay, yil);

        if (isValid(gecici_tarih) == false) {
            gun = 01;
            ay += 01;

            if (isValid(gecici_tarih) == false) {
                ay = 01;
                yil += 01;
            }
        }else{
            gun += 1;
        }
        for (int j = 0; j < 12; j++) {
            list[i][j] = gecici_tarih[j];
        }
    }
}