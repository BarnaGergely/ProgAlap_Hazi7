#include <stdio.h>

typedef struct HASZNALAT {
    int kezdet;
    float mertek;
}HASZNALAT;

typedef struct KEVEREK {
    float korido;
    HASZNALAT kopas;
    HASZNALAT elhasznalodas;
}KEVEREK;


typedef struct CSEREK {
    int kor;
     int keverek;
}CSEREK;

typedef struct STRATEGIA {
    KEVEREK keverek[3];
    int korokszama;
    float kiallas;
    CSEREK csere[100];
    int cserekSzama;
}STRATEGIA;

int beolvas(char forras[100]){
    FILE *infile;

    if (!(infile = fopen(forras, "r"))) {
        return 1;
    }

    char gumi;
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[0].korido, &strategia.keverek[0].kopas.kezdet, &strategia.keverek[0].kopas.mertek, &strategia.keverek[0].elhasznalodas.kezdet, &strategia.keverek[0].elhasznalodas.mertek);
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[1].korido, &strategia.keverek[1].kopas.kezdet, &strategia.keverek[1].kopas.mertek, &strategia.keverek[1].elhasznalodas.kezdet, &strategia.keverek[1].elhasznalodas.mertek);
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[2].korido, &strategia.keverek[2].kopas.kezdet, &strategia.keverek[2].kopas.mertek, &strategia.keverek[2].elhasznalodas.kezdet, &strategia.keverek[2].elhasznalodas.mertek);

    fscanf(infile, "%d\n", strategia.korokszama);
    fscanf(infile, "%f\n", strategia.kiallas);

    char temp[20];
    int szamlalo = 0;
    while (fscanf(infile, "%s\n", &temp) == 1){
        int i = 0;
        for (i = 0; temp[i] <= '9'; ++i);
        szamlalo++;

        if (temp[i] == 'A') {
            strategia.csere[szamlalo].keverek = 0;
        }
        if (temp[i] == 'B') {
            strategia.csere[szamlalo].keverek = 1;
        }
        if (temp[i] == 'C') {
            strategia.csere[szamlalo].keverek = 2;
        }

        temp[i] = ' ';
        sscanf(temp, "%d", &strategia.csere[szamlalo].kor );
        printf("kor: %d\n", strategia.csere[szamlalo].kor);
        printf("keverek: %d\n", strategia.csere[szamlalo].keverek);
    }
    strategia.cserekSzama = szamlalo;
    printf("cserekSzama: %d\n", strategia.cserekSzama);

    strategia.csere[strategia.cserekSzama+1].kor = strategia.korokszama;

    // Hiba kereses: kevesebb mint 1 kiallas
    if (strategia.cserekSzama < 2) {return 1;}

    // Hiba kereses: kevesebb mint 2 keverek
    int keverekekSzama = 0;
    for (int i = 0; i < szamlalo; ++i) {
        if(strategia.csere[i].keverek != strategia.csere[i+1].keverek) {
            keverekekSzama++;
        }
    }
    if(keverekekSzama == 0) {return 1;}

    return 0;
}


int kiir(char szoveg[100]){

}


float menet(int kor, int keverek){
    float megoldas = 0;
    float kopas = 0;
    float elhasznalodas = 0;
    for (int i = 0; i <= kor; ++i) {
        if(i > strategia.keverek[keverek].kopas.kezdet){ kopas = strategia.keverek[keverek].kopas.mertek; }
        if(i > strategia.keverek[keverek].elhasznalodas.kezdet){ elhasznalodas += strategia.keverek[keverek].elhasznalodas.mertek; }
        megoldas += strategia.keverek[keverek].korido + kopas + elhasznalodas;
    }
    return megoldas;
}


int main() {

    STRATEGIA strategia;

    /* ADATBETOLTES */
    if (beolvas("be.txt") == 1){
        //kiir("HIBA");
    }

    /* SZAMOLAS */
    float megoldas = 0 - strategia.kiallas;
    for (int i = 0; i <= strategia.cserekSzama; ++i) {
        megoldas += strategia.kiallas;
        megoldas += menet(strategia.csere[i+1].kor - strategia.csere[i].kor, strategia.csere[i].keverek);
        printf("\nIdo : lf\n", megoldas);
    }


    /* ADATKIIRAS */
    kiir("%lf");

    return 0;
}
