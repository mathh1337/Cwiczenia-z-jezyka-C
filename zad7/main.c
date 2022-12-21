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
    while(1) {
        int x;
        printf("\nPodaj wartosc x: ");
        while (scanf("%d", &x) != 1) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("To nie jest poprawna liczba. Podaj wartosc x: ");
            while (getchar() != '\n');
        }
        if(x<0){
            printf("Niepoprawna liczba");
        }
        else if(x==0){
            printf("Wartosc n-tej wartosci ciagu fibonacciego wynosi: 0");
        }
        else {

            printf("Wartosc n-tej wartosci ciagu fibonacciego wynosi: %d", fib(x));
        }
    }

    return 0;
}