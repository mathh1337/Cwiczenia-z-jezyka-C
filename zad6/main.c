#include <stdio.h>
#include <stdlib.h>
#define MAX 500

// funkcja mnożąca liczbę przez res i zapisująca wynik w tablicy res
int multiplication(int x,int res[], int resSize){
    int carry = 0; // zmienna przechowująca przeniesienie

// mnożenie każdego elementu tablicy przez x i dodawanie przeniesienia
    for(int i=0;i<resSize;i++)
    {
        int prod = res[i] *x+carry;  // mnożenie i dodawanie przeniesienia
        res[i] = prod%10;  // zapisanie ostatniej cyfry wyniku
        carry = prod/10;  // obliczenie nowego przeniesienia
    }

// dodawanie nowych elementów do tablicy res, jeśli jest jeszcze przeniesienie
    while(carry)
    {
        res[resSize] = carry%10;  // dodanie ostatniej cyfry przeniesienia
        carry = carry/10;  // obliczenie nowego przeniesienia
        resSize++;  // zwiększenie rozmiaru tablicy res
    }
    return resSize;
}

// funkcja obliczająca silnię z liczby n i wyświetlająca wynik
void factorial(int n)
{
    int res[MAX];
    res[0]=1;
    int resSize=1;
// pętla mnożąca kolejne liczby od 2 do n i zapisująca wynik w tablicy res
    for(int x =2;x<=n;x++){
        resSize= multiplication(x, res, resSize);
    }
// wyświetlenie wyniku od końca tablicy res
    for(int i=resSize-1;i>=0;i--){
        printf("%d", res[i]);
    }
}



int main() {
    while (1) { // nieskończona pętla

        int n;
        printf("\nPodaj liczbe n: ");
        while (scanf("%d", &n) != 1) {
            printf("To nie jest poprawna liczba. Podaj liczbe n: ");
            while (getchar() != '\n');
        }

        printf("Silnia wynosi: ");
        factorial(n);
    }

    return 0;
}