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
            if(gun <= 31)
                return true;
            break;
        case 2:
            if(gun < 29)
                return true;
            break;
    }
    return false;
}