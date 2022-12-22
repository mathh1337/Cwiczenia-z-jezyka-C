#include <stdio.h>

int NWD(int x, int y){ //funkcja rozwiazujaca NWD rekurencyjnie
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
        while (scanf("%d", &x) != 1 || x <= 0 || x != (int)x) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Wprowadz x: ");
            while (getchar() != '\n');
        }

        // Wczytywanie zmiennej y
        printf("Wprowadz y: ");
        while (scanf("%d", &y) != 1 || y <= 0 || y != (int)y) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Wprowadz y: ");
            while (getchar() != '\n');
        }

        printf("NWD dla liczb %d i %d wynosi: %d", x, y, NWD(x, y));
    }
    return 0;
}