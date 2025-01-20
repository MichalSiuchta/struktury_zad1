#include <stdio.h>
#include <string.h>

struct ts_opis {
    char marka[15];
    char model[15];
};

struct ts_samochod {
    struct ts_opis opis;
    int rok;
    unsigned int przebieg;
    float cena;
};

int main() {

    struct ts_samochod tab[20] = {0};


    int opcja = 5;
    int liczba_samochodow = 0;
    int i;
    int j;
    while(opcja != 4) {
        printf("Menu\n1. dopisanie nowego samochodu\n2. sprzedaż samochodu\n3. wypisanie zawartosci komisu\n4. wyjscie\n");
        scanf("%d", &opcja);
        if (opcja == 1) {
            int pusty_indeks;
            if(liczba_samochodow <= 20) {
                for(i = 0; i < 20; i++) {
                    if(tab[i].rok == 0 && tab[i].przebieg == 0 && tab[i].cena == 0) {
                        for(j = 0; j < 20; j++) {
                            if(tab[i].opis.marka[j] == 0 && tab[i].opis.model[j] == 0) {
                                pusty_indeks = i;
                            }
                        }
                    }
                }
                fflush(stdin);
                printf("Podaj marke:");
                fgets(tab[pusty_indeks].opis.marka, 15, stdin);
                tab[pusty_indeks].opis.marka[strlen(tab[pusty_indeks].opis.marka) - 1] = '\0';
                printf("Podaj model:");
                fgets(tab[pusty_indeks].opis.model, 15, stdin);
                tab[pusty_indeks].opis.model[strlen(tab[pusty_indeks].opis.model) - 1] = '\0';
                printf("Podaj rok produkcji:");
                scanf("%d", &tab[pusty_indeks].rok);
                printf("Podaj przebieg:");
                scanf("%u", &tab[pusty_indeks].przebieg);
                printf("Podaj cene:");
                scanf("%f", &tab[pusty_indeks].cena);
            }else {
                printf("Nie ma już miejsca w komisie");
            }


        }
        if (opcja == 2) {
            char marka__[15];
            char model[15];
            int rok;
            printf("Podaj marke:");
            fflush(stdin);
            fgets(marka__, 15, stdin);
            marka__[strlen(marka__) - 1] = '\0';
            printf("Podaj model:");
            fgets(model, 15, stdin);
            model[strlen(model) - 1] = '\0';
            printf("Podaj rok produkcji:");
            scanf("%d", &rok);

            for(i = 0; i < 20; i++) {
                if(rok == tab[i].rok) {
                    for(j = 0; j < 15; j++) {
                        if(marka__[j] == tab[i].opis.marka[j] && model[j] == tab[i].opis.model[j]) {
                            liczba_samochodow -= 1;
                            tab[i].cena = 0;
                            tab[i].rok = 0;
                            tab[i].przebieg = 0;
                            for(j = 0; j < 15; j++) {
                                tab[i].opis.marka[j] = '0';
                                tab[i].opis.model[j] = '0';
                            }
                        }
                    }
                }
            }

            liczba_samochodow -= 1;
        }

        if (opcja == 3) {

            printf("Zawartosc komisu\n");
            for(i = 0; i < 20; i++) {
                if(tab[i].opis.marka != "\0" && tab[i].opis.model != "\0" && tab[i].rok != 0 && tab[i].przebieg != 0 && tab[i].cena != 0) {
                    printf("%s\t%s\t%d\t%u\t%.2f\n", tab[i].opis.marka, tab[i].opis.model, tab[i].rok,tab[i].przebieg, tab[i].cena);
                }
            }
        }
    }
    return 0;
}
