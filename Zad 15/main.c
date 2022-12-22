#include <stdio.h>

// Funkcja do konwersji liczby dziesiętnej na binarną
void binary(int n)
{
// Tablica do przechowywania pojedynczych znakow cyfry binarnej
    int arr[32];


    int i = 0;
    while (n > 0) {
        // Obliczenie reszty z dzielenia przez 2 i zapisanie w tablicy
        arr[i] = n % 2;
        // Podzielenie liczby przez 2
        n = n / 2;
        i++;
    }

//Wyswietlenie cyfry
    for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);
}

// Funkcja do konwersji liczby dziesiętnej na ósemkową
void octal(int n) {

    int arr[32];
    int i = 0;
    while (n > 0) {
        // Obliczenie reszty z dzielenia przez 8 i zapisanie w tablicy
        arr[i] = n % 8;
        // Podzielenie liczby przez 8
        n = n / 8;
        i++;
    }

// Iteracja po elementach tablicy w odwrotnej kolejności i wyświetlenie ich
    for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);
}
void hex(int n) {
    char hex[100];
    int i = 0;
    while (n != 0) {
        // Obliczenie reszty z dzielenia przez 16
        int r = n % 16;

        // Sprawdzenie, który znak szesnastkowy odpowiada reszcie z dzielenia i dobranie odpowiedniej litery
        switch (r) {
            case 10:
                hex[i] = 'A';
                break;
            case 11:
                hex[i] = 'B';
                break;
            case 12:
                hex[i] = 'C';
                break;
            case 13:
                hex[i] = 'D';
                break;
            case 14:
                hex[i] = 'E';
                break;
            case 15:
                hex[i] = 'F';
                break;
            default:
                hex[i] = r + '0';
                break;
        }

        // Podzielenie liczby przez 16
        n = n / 16;
        // Zwiększenie iteratora
        i++;
    }

//wyswietlenie
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    int liczba;

    while (1) {
        printf("\nPodaj liczbe w systemie dziesietnym: ");
        int result = scanf("%d", &liczba);

        if (result == 1) {
            // Liczba została wprowadzona pomyślnie
            printf("W systemie binarnym: ");
            binary(liczba);
            printf("\nW systemie osemkowym: ");
            octal(liczba);
            printf("\nW systemie szesnastkowym: ");
            hex(liczba);
        } else {
            printf("Prosze podac liczbe!\n");
            while (getchar() != '\n');
        }
    }

    return 0;
}