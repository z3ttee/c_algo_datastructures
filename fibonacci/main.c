#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long fibonacci(int n) {
    if(n < 2) return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    char *input;
    int n;
    int quit = 1;

    while(quit != 0) {
        printf("\nDas wievielte Fibonacci-Glied ist gesucht?\n");
        scanf("%s", input);

        quit = strcmp(input, "q");

        if(quit != 0) {
            n = atoi(input);
            unsigned long long result;

            for(int i = 0; i <= n; ++i) {
                result = fibonacci(i);
                if(result == 0) {
                    continue;
                }

                printf("%d. Glied: %I64d\n", i, result);
            }

        }
    }
    return 0;
}
