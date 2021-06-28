#include <stdio.h>
#include <math.h>
#include <time.h>

#include "functions.h"

double a,b,c;

int main() {
    do {
        getInput(&a, &b, &c);
        clock_t start = clock();

        if (a != 0) {
            // Normalform
            double p = b / a;
            double q = c / a;

            double D = ((p / 2) * (p / 2)) - q;
            double x1, x2;

            if (D > 0) {
                x1 = -(p / 2) + sqrt(D);
                x2 = -(p / 2) - sqrt(D);
                printf("\nNST1 = %.3f\n", x1);
                printf("NST2 = %.3f\n", x2);
            } else if (D == 0) {
                x1 = -(p / 2) + sqrt(D);
                printf("\nNST1 = %.3f\n", x1);
            } else {
                // D < 0

                double rt = -(p / 2);
                double it = sqrt(-D);

                printf("\nNST1 = %.3f + %.3gi\n", rt, it);
                printf("NST2 = %.3f + %.3gi\n", rt, it);
            }
        } else {
            // a = 0;
            // y = bx + c;

            if(b == 0) {
                if(c == 0) {
                    // y = bx;
                    printf("\n Unendlich NST: Graph liegt auf der x-Achse \n");
                } else {
                    printf("\nKeine NST!\n");
                }
            } else {
                // NST = 0 = bx + c | -c
                // -c = b*x         | : b
                // -c / b = x

                double x1 = (-c / b);
                printf("\nNST1 = %.3f", x1);
            }
        }

        clock_t end = clock();
        double elapsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
        printf("Time elapsed: %.2fms\n", elapsed);
    } while(confirmRestart());
    return 0;
}


