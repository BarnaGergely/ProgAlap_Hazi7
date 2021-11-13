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
}STRATEGIA;

int main() {

    /* ADATBETOLTES */

    STRATEGIA strategia;

    FILE *infile;

    if (!(infile = fopen("be.txt", "r"))) {
        return 1;
    }

    char gumi;
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[0].korido, &strategia.keverek[0].kopas.kezdet, &strategia.keverek[0].kopas.mertek, &strategia.keverek[0].elhasznalodas.kezdet, &strategia.keverek[0].elhasznalodas.mertek);
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[1].korido, &strategia.keverek[1].kopas.kezdet, &strategia.keverek[1].kopas.mertek, &strategia.keverek[1].elhasznalodas.kezdet, &strategia.keverek[1].elhasznalodas.mertek);
    fscanf(infile, "%c %f %d %f %d %f\n", &gumi, &strategia.keverek[2].korido, &strategia.keverek[2].kopas.kezdet, &strategia.keverek[2].kopas.mertek, &strategia.keverek[2].elhasznalodas.kezdet, &strategia.keverek[2].elhasznalodas.mertek);
    
    fscanf(infile, "%d\n", &strategia.korokszama);
    fscanf(infile, "%f\n", &strategia.kiallas);

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


    /* SZAMOLAS */


    /* ADATKIIRAS */

    return 0;
}
