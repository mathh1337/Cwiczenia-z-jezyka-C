#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void my_scanf(int* number) {
    int LINE_MAX = 100;
    char *end;
    char buf[LINE_MAX];

    if (!fgets(buf, sizeof buf, stdin)) {
        return;
    }

    buf[strlen(buf) - 1] = 0;

    *number = strtol(buf, &end, 10);
    return;
}



int main() {
    int x,y,wynik;

    printf("Podaj x:");
    my_scanf(&x);
    while (x == NULL) {
        printf("Zla liczba, podaj x:");
        my_scanf(&x);
    }
    printf("Podaj y:");
    my_scanf(&y);
    while (y == NULL) {
        printf("Zla liczba, podaj y:");
        my_scanf(&y);
    }
    wynik = x+y;
    printf("Wynik to: %d", wynik);

    return 0;

}