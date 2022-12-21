#include <stdio.h>

int NWD(int x, int y){
    if(y!=0) {
        return NWD(y, x % y);

    }
    return x;
}

int main() {
    int x,y;
    while(1) {
        // Wczytywanie zmiennej x
        printf("\nWprowadz x: ");
        while (scanf("%d", &x) != 1) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Wprowadz x: ");
            while (getchar() != '\n'); // usuwa niepoprawne dane z bufora wejściowego
        }

        // Wczytywanie zmiennej y
        printf("Wprowadz y: ");
        while (scanf("%d", &y) != 1) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Wprowadz y: ");
            while (getchar() != '\n'); // usuwa niepoprawne dane z bufora wejściowego
        }

        printf("NWD dla liczb %d i %d wynosi: ", x, y);
        NWD(x, y);
        printf("%d", NWD(x, y));
    }
    return 0;
}