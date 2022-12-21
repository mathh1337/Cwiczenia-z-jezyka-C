#include <stdio.h>
#include <math.h>
#include <string.h>


int loop();

int main() {
    char operacja;
    printf("Operatory matematyczne: \n");
    printf("Dodawanie: +\n");
    printf("Odejmowanie: -\n");
    printf("Mnozenie: *\n");
    printf("Dzielenie: /\n");
    printf("Potegowanie: ^\n");
    printf("Pierwiastkowanie: |\n");
    printf("Sinus: s\n");
    printf("Cosinus: c\n");
    printf("Tangens: t\n");

    while (1) {
        if (loop() != 0) return 0;
    }

}

int loop() {
    double x, y,result;
    char operacja;
    printf("\nWprowadz operator: ");
    scanf("%s", &operacja);


    if(operacja == '|')
    {
        printf("Wprowadz liczbe, ktora chcesz spierwiastkowac: ");
        scanf("%lf", &x);
        double result = sqrt(x);
        printf("Wynik: %.3lf\n", result);
        printf("Wpisz q by zakonczyc dzialanie kalkulatora");
    }
    else if(operacja == '^')
    {
        printf("Wprowadz podstawe potegi: ");
        scanf("%lf", &x);
        printf("Wprowadz numer potegi: ");
        scanf("%lf", &y);
        double result = pow(x, y);
        printf("Wynik: %.3lf", result);
    }
    else if(operacja == '+')
    {
        double result1;
        printf("Wprowadz pierwsza liczbe: ");
        scanf("%lf", &x);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &y);
        result1 = x+y;
        printf("Wynik: %.3lf", result1);
    }
    else if(operacja=='-')
    {
        double result1;
        printf("Wprowadz pierwsza liczbe: ");
        scanf("%lf", &x);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &y);
        result1 = x-y;
        printf("Wynik: %.3lf", result1);
    }

    else if(operacja=='*')
    {
        double result1;
        printf("Wprowadz pierwsza liczbe: ");
        scanf("%lf", &x);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &y);
        result1 = x*y;
        printf("Wynik: %.3lf", result1);
    }
    else if(operacja=='/')
    {
        printf("Wprowadz pierwsza liczbe: ");
        scanf("%lf", &x);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &y);
        double result = x/y;
        printf("Wynik: %.3lf", result);
    }
    else if(operacja == 's'){
        printf("Wprowadz wartosc ktorej sinus chcesz znalezc:" );
        scanf("%lf", &x);
        double result = sin(x);
        printf("Wartosc sin dla x: %.3lf", result);
    }
    else if(operacja == 'c'){
        printf("Wprowadz wartosc ktorej cosinus chcesz znalezc:" );
        scanf("%lf", &x);
        double result = cos(x);
        printf("Wartosc cos dla x: %.3lf", result);
    }
    else if(operacja == 't'){
        printf("Wprowadz wartosc ktorej tangens chcesz znalezc:" );
        scanf("%lf", &x);
        double result = tan(x);
        printf("Wartosc tg dla x: %.3lf", result);
    }
    else if (operacja == 'q') {
        return -1;
    }
    else {
        printf("Nieprawidlowa operacja\n");
    }
    return 0;
}