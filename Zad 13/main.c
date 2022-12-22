#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RZYM {
    int arab;
    char *rzym;
};

int roman_arab(char *num)
{
    struct RZYM rz[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    // tablica z wartościami poszczególnych znaków rzymskich
    int values[26];
    values['I' - 'A'] = 1;
    values['V' - 'A'] = 5;
    values['X' - 'A'] = 10;
    values['L' - 'A'] = 50;
    values['C' - 'A'] = 100;
    values['D' - 'A'] = 500;
    values['M' - 'A'] = 1000;

    int result = 0;  // zmienna do przechowywania wyniku
    int i = 0;  // indeks aktualnie przetwarzanego znaku
    int prev = 0;  // zmienna do przechowywania poprzedniej wartości
    while (i < strlen(num))
    {
        int found = 0;  // zmienna do oznaczenia czy znak został znaleziony w tablicy rz
        for (int j = 0; j < 13; j++)
        {
            // sprawdzenie czy aktualny znak jest pierwszym znakiem liczby rzymskiej
            if (num[i] == rz[j].rzym[0])
            {
                // sprawdzenie, czy drugim znakiem jest drugi znak liczby rzymskiej
                if (i + 1 < strlen(num) && num[i+1] == rz[j].rzym[1])
                {
                    result += rz[j].arab;  // dodanie wartości liczby rzymskiej do wyniku
                    i += 2;  // przeskoczenie do następnego znaku
                    found = 1;  // oznaczenie znalezienia znaku
                    break;
                }
                else if (strlen(rz[j].rzym) == 1)
                {
                    result += rz[j].arab;
                    i++;
                    found = 1;
                    break;
                }
            }
        }

        if (!found)
        {
            // znak nie jest poprawnym znakiem liczby rzymskiej
            return -1;
        }

        // sprawdzenie poprawności zapisu liczby rzymskiej
        if (prev > 0 && values[num[i - 1] - 'A'] < values[num[i] - 'A'])
        {
            // jeśli poprzednia wartość była większa od aktualnej, to znaczy, że zapis jest niepoprawny
            return -1;
        }
        prev = values[num[i - 1] - 'A'];
    }
    if (result > 3999)
    {
        // Liczba rzymska nie może być większa niż 3999
        return -1;
    }
    return result;
}
int arab_roman(int num)
{
    struct RZYM rz[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
// Weryfikacja poprawności liczby arabskiej
    if (num <= 0 || num > 3999)
    {
// Liczba arabska musi być dodatnia i nie większa niż 3999
        printf("Wprowadzono niepoprawną liczbę arabską\n");
        return 1;
    }
    int i = 0;
    while (num > 0)
    {
        if (num >= rz[i].arab)
        {
            printf("%s", rz[i].rzym);
            num = num -  rz[i].arab;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    while (1)
    {
        char input[50];
        printf("\nWprowadz liczbe w systemie rzymskim lub arabskim: ");
        scanf("%s", input);

        // Sprawdzenie, czy liczba jest w systemie rzymskim
        int is_roman = 1;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isalpha(input[i]))
            {
                is_roman = 0;
                break;
            }
        }

        if (is_roman)
        {
            int result = roman_arab(input);
            if (result == -1)
            {
                printf("Wprowadzono niepoprawną liczbę rzymską\n");
                continue;
            }
            else
            {
                printf("W systemie arabskim: %d\n", result);
            }
        }
        else
        {
            int num = atoi(input);
            printf("W systemie rzymskim: ");
            arab_roman(num);
        }
    }

    return 0;
}