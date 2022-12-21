#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b;
    double result = 0;
    double x_intercept = 0;
    char buffer[64];
    printf("Rownanie liniowe: y = ax+b\n");

    // Wczytaj wartość a
    int ret;
    do {
        printf("Podaj wartosc a: ");
        fgets(buffer, sizeof(buffer), stdin);
        ret = sscanf(buffer, "%lf", &a);
        if (ret != 1) {
            printf("Zle wprowadzenie. Wprowadz liczbe.\n");
        }
    } while (ret != 1);

    // Wczytaj wartość b
    do {
        printf("Podaj wartosc b: ");
        fgets(buffer, sizeof(buffer), stdin);
        ret = sscanf(buffer, "%lf", &b);
        if (ret != 1) {
            printf("Zle wprowadzenie. Wprowadz liczbe.\n");
        }
    } while (ret != 1);

    // Sprawdź, czy dane są prawidlwe
    if (a == 0) {
        if (b == 0) {
            printf("Funkcja liniowa jest rownolegla do osi x i przechodzi przez jej srodek");
        } else {
            printf("Funkcja liniowa jest rownolegla do osi y i nie ma rozwiazania dla rownania y = ax + b");
        }
    } else {
        result = -b/a;
        x_intercept = -b/a;
        printf("Rozwiazanie rownania y = %.2lfx + %.2lf to x = %.2lf, a punkt przeciecia z osią x to (%.2lf, 0)", a, b, result, x_intercept);
    }

    return 0;
}