#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja generująca liczby pseudolosowe
int random_number(int seed) {
    return (75 * (seed + 1) % 65537) - 1; // Generuje liczbę pseudolosową na podstawie podanego "ziarna"
}

int main() {
    double x,y,distance,pi;
    double x1,y1,distance1,pi1;
    int inner =0; // Licznik punktów wewnątrz koła dla pierwszej metody
    int total =0; // Licznik całkowitej liczby punktów dla pierwszej metody
    int inner1=0; // Licznik punktów wewnątrz koła dla drugiej metody
    int total1=0; // Licznik całkowitej liczby punktów dla drugiej metody
    int seed = 17; // "Ziarno" do generowania liczb pseudolosowych
    int number = 10000; // Liczba punktów do wylosowania
    srand(time(NULL));  // Funkcja srand() inicjuje generator liczb pseudolosowych za pomocą aktualnego czasu jako "ziarna"
    for(int i=0;i<number;i++) {
        int x_rand = random_number(seed);
        int y_rand = random_number(x_rand);
        seed = y_rand;  // Aktualizuje "ziarno"

        x = (double) x_rand / (65535.0 + 1.0);  // Przekształca liczbę pseudolosową na wartość zmiennoprzecinkową z zakresu od 0 do 1
        y = (double) y_rand / (65535.0 + 1.0);  // Przekształca liczbę pseudolosową na wartość zmiennoprzecinkową z zakresu od 0 do 1

        distance = x * x + y * y;  // odleglosc punktu od srodka
        if (distance <= 1) {
            inner++;
        }
        total++;
    }

    for(int j=0;j<number*number;j++) {
        x1 = (double)rand() / (double) RAND_MAX;
        y1 = (double)rand() / (double) RAND_MAX;
        distance1 = x1 * x1 + y1 * y1;
        if(distance1<=1){
            inner1++;  // Zwiększa licznik punktów wewnątrz koła
        }
        total1++;  // Zwiększa licznik całkowitej liczby punktów


    }

    pi =(double)(4 * (double)inner)/(double)total;
    pi1=(double)(4 * (double)inner1)/(double)total1;
    printf("Przy uzyciu liczb pseudolosowych liczba pi wynosi: %lf\n", pi);
    printf("Przy uzyciu funkcji srand liczba pi wynosi: %lf", pi1);
    return 0;
}