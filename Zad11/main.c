#include <stdio.h>

int dwumian(int n, int k)
{
    if (k > n || k < 0 || n < 0) //warunek sprawdzający
        return 0;
    if (k == 0 || k == n) //warunek sprawdzający
        return 1;
    return dwumian(n - 1, k - 1) //rekurencja
           + dwumian(n - 1, k);
}

int main()
{
    int n, k;
    char input = '0';
    while (1) {
        printf("Wprowadź wartość n: ");
        while (scanf("%d", &n) != 1) { //warunek sprawdzający czy wprowadzone dane to liczba
            printf("To nie jest liczba. Wprowadź wartość n: ");
            scanf("%*s"); //czyszczenie bufora
        }
        printf("\nWprowadź wartość k: ");
        while (scanf("%d", &k) != 1) { //warunek sprawdzający czy wprowadzone dane to liczba
            printf("To nie jest liczba. Wprowadź wartość k: ");
            scanf("%*s"); //czyszczenie bufora
        }
        if(n>=k && n>0 && k>0) { //warunek sprawdzający
            printf("Wartość dwumianu(%d, %d) wynosi %d\n", n, k,
                   dwumian(n, k));
        }
        else{
            printf("Nieprawidłowe dane\n");
            continue;
        }
    }
    return 0;
}