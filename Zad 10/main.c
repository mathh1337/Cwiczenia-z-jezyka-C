#include <stdio.h>

int fib(int n)
{
    if(n<=1){
        return n;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main(){
    int x;
    while (1) {
        printf("Podaj wartosc x: ");
        while (scanf("%d", &x) != 1) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Podaj wartosc x: ");
            while (getchar() != '\n');
        }

        // Sprawdzenie, czy x jest dodatnią liczbą całkowitą
        if (x < 0) {
            printf("Podaj dodatnią liczbę całkowitą.\n");
            continue;
        }

        printf("Wartosc n-tej wartosci ciagu fibonacciego wynosi: %d\n", fib(x));
    }
    return 0;
}