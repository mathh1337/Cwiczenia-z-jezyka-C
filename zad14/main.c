#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(const double* buffer, int size) {
    double sum = 0;
    for (int i=0; i<size; i++) {
        sum += buffer[i];
    }
    return sum / size;
}

double std(const double* buffer, int size) {
    double m = mean(buffer, size);
    double sum = 0;
    for (int i=0; i<size; i++) {
        sum += pow(buffer[i] - m, 2);
    }
    return sqrt(sum / size);

}

int main(void)
{
    int BUFFER_SIZE = 1000;
    double buffer[BUFFER_SIZE];
    double x;
    int index = 0;

    while (scanf("%lf", &x) != EOF) {
        printf("Read: %f\n", x);
        buffer[index++] = x;
    }

    printf("Mean: %lf\n", mean(buffer, index));
    printf("Std: %lf", std(buffer, index));
    return 0;
}
