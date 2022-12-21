#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    double result=0;
    double delta;
    printf("Funkcja kwadratowa: y = ax^2 +bx +c\n");

    int ret;
    do {
        printf("Wprowadz wspolczynnik a: ");
        ret = scanf("%lf", &a);
        if (ret != 1) {
            printf("Zle wprowadzenie. Wprowadz liczbe.\n");
            getchar();
        }
    } while (ret != 1);

    do {
        printf("Wprowadz wspolczynnik b: ");
        ret = scanf("%lf", &b);
        if (ret != 1) {
            printf("Zle wprowadzenie. Wprowadz liczbe.\n");
            getchar();
        }
    } while (ret != 1);

    do {
        printf("Wprowadz wspolczynnik c: ");
        ret = scanf("%lf", &c);
        if (ret != 1) {
            printf("Zle wprowadzenie. Wprowadz liczbe.\n");
            getchar();
        }
    } while (ret != 1);

    if(a==0){
        printf("Funkcja kwadratowa nie istnieje\n");
        result = -c/b;
        printf("Miejsce zerowe funkcji liniowej: %.2lf", result);

    }
    else{
        delta = (b*b)-4*a*c;
        if(delta==0){
            result = -b/2*a;
            printf("Istnieje jedno rozwiazanie: %.2lf", result);
        }
        double result1,result2;
        if(delta>0){
            result1 = (-b- sqrt(delta))/(2*a);
            result2 = (-b+ sqrt(delta))/(2*a);
            printf("Rozwiązania: x1 = %.2lf x2 = %.2lf", result1, result2);
        }
        if(delta<0){
            printf("Funkcja kwadratowa nie ma rozwiazan");
        }
    }

    return 0;
}