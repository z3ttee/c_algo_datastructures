#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isDecimal(const char *input);

int main(const int argc, const char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Please enter at least one number!");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; ++i) {
        if(isDecimal(argv[i])) {
            fprintf(stdout, "\n%s is a valid number.\n", argv[i]);
        } else {
            fprintf(stdout, "\n%s is not a number.\n", argv[i]);
        }
    }

    exit(EXIT_SUCCESS);
}

bool isDecimal(const char input[]) {
    int digitCount = 0;
    bool countDecimals = false;

    // Check for number's sign
    if(!(input[0] == '+' || input[0] == '-') && !(input[0] >= '0' && input[0] <= '9')) {
        printf("not a number because no sign or digits\n");
        return false;
    }

    // Check every symbol in string
    for(int i = 1; input[i]; ++i) {

        if((input[i] >= '0' && input[i] <= '9')) {
            continue;
        } else {
            if((input[i] == '.' || input[i] == ',') && digitCount == 0){
                ++digitCount;
                continue;
            } else {
                return false;
            }
        }
    }

    return true;
}

