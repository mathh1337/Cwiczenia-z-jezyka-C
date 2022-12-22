#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1024

double stack[MAXSIZE]; //stos przechowujacy liczby z zdefiniowanym maxsize = 1024
int sp = 0;
double result;

void push(double x)
{
    if(sp == MAXSIZE) //jezeli stos jest pelny wyswietla wiadomosc o przepelnieniu
    {
        printf("Przepelnienie stosu!\n");
    }
    else //jesli stos jest pusty to dodaje element na stos i zwieksza wskaznik sp
    {
        stack[sp++] = x;
    }
}

double pop() //funkcja, ktora zdejmuje elementy ze stosu
{
    if(sp == 0) //jesli stos okaze sie pusty, daje o tym wiadomosc,zwraca ostatni element ze stosu i zmniejsza wskaznik sp
    {
        printf("Niedopelnienie stosu!\n");
        return 0;
    }
    else
    {
        return stack[--sp];
    }
}

int main()
{
    printf("Przyklad dzialania: \n ");
    printf("5 ENTER\n");
    printf(" 4 ENTER\n");
    printf(" + ENTER\n");
    printf(" = ENTER\n");
    printf(" Wynik: 9\n");
    printf("INSTRUKCJA:\n");
    printf("Ponizej podaj liczbe lub operator i wcisnij enter\n");
    printf("Jezeli zakonczyles juz podawanie dzialania w ONP na koncu dodaj znak = , wtedy program zwroci wynik! \n");
    printf("Aby zatrzymac program wpisz q\n");
    printf("Wpisz dzialanie:\n");

    double x, y;
    char oper[20]; //zmienna przechowujaca wpisany operator

    while(1)
    {

        scanf("%s", oper); //pobiera operator lub liczbe

        if(isdigit(oper[0])) //jezeli jest to liczba to dodaje ja na stos
        {
            push(atof(oper));
        }
        else if(!strcmp(oper, "+")) //dodaje znak +
        {
            y = pop(); //zdejmuje element ze stosu
            x = pop(); //zdejmuje element ze stosu
            push(x + y); //dodaje element na stos
        }
        else if(!strcmp(oper, "-")) //dodaje znak -
        {
            y = pop(); //zdejmuje element ze stosu
            x = pop(); //zdejmuje element ze stosu
            push(x - y); //dodaje element na stos
        }
        else if(!strcmp(oper, "*")) //dodaje znak *
        {
            y = pop(); //zdejmuje element ze stosu
            x = pop(); //zdejmuje element ze stosu
            push(x * y); //dodaje element na stos
        }
        else if(!strcmp(oper, "/")) //dodaje znak /
        {
            y = pop(); //zdejmuje element ze stosu
            x = pop(); //zdejmuje element ze stosu
            push(x / y); //dodaje element na stos
        }
        else if(!strcmp(oper, "^")) //dodaje znak ^
        {
            y = pop(); //zdejmuje element ze stosu
            x = pop(); //zdejmuje element ze stosu
            push(pow(x, y)); //dodaje element na stos
        }
        else if(!strcmp(oper, "sqrt")) //dodaje znak sqrt
        {
            x = pop(); //zdejmuje element ze stosu
            push(sqrt(x)); //dodaje element na stos
        }
        else if(!strcmp(oper, "=")) //jezeli wprowadzony znak '=' to wyswietla wynik
        {
            result = pop();
            printf("Wynik: %d\n", (int) result);
            printf("Wpisz dzialanie:\n");
        }
        else if(!strcmp(oper, "q")) //jezeli wprowadzony znak to q to wychodzi z programu
        {
            printf("Wynik: %d\n", (int) result);
            break;
        }
        else //jezeli wprowadzony znak jest niepoprawny to wyswietla wiadomosc
        {
            printf("Zly operator!\n");
        }
    }

    return 0;
}