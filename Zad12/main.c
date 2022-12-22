#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char wyraz[20];
    while (1) {
        printf("Wprowadź napis: ");
        scanf("%s", wyraz);
        int dlugosc = strlen(wyraz);
        int point = 0; //zmienna pomocnicza cos w stylu flagowania


        int i = 0;
        while (i < dlugosc) { //pętla sprawdzająca czy wprowadzone dane to litery
            if (!isalpha(wyraz[i])) { //jeśli wprowadzone dane nie są literami
                printf("Podaj tylko litery. Wprowadź napis: ");
                scanf("%s", wyraz);
                dlugosc = strlen(wyraz);
                i = 0; //zresetowanie indeksu
                continue; //ponowne wczytanie danych
            }
            i++;
        }

        i = 0;
        while (i < dlugosc) { //pętla sprawdzająca czy wyraz jest palindromem
            if (tolower(wyraz[i]) != tolower(wyraz[dlugosc-i-1])) { //porównywanie znaków bez względu na wielkość liter
                point = 1;
                break; //przerwanie pętli
            }
            i++;
        }

        if (point == 1) { //jeśli wyraz nie jest palindromem
            printf("Podany napis nie jest palindromem\n");
        } else { //jeśli wyraz jest palindromem
            printf("Podany napis jest palindromem\n");
        }
    }

    return 0;
}