//
// Created by Cedric Zitzmann on 17.06.2021.
//

#ifndef SQUARE_ROOTS_FUNCTIONS_H
#define SQUARE_ROOTS_FUNCTIONS_H

#include <string.h>

int isDecimal(const char input[]) {
    int digitCount = 0;

    // Check for number's sign
    if(!(input[0] == '+' || input[0] == '-') && !(input[0] >= '0' && input[0] <= '9')) {
        printf("not a number because no sign or digits\n");
        return 0;
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
                printf("not a number because no sign or digits\n");
                return 0;
            }
        }
    }

    return 1;
}

void getInput(double *a, double *b, double *c){
    char input[32];
    char *replaceComma = NULL;

    while(1) {
        printf("\na eingeben:\n");
        scanf("%s", input);

        replaceComma = strchr(input, ',');
        if(replaceComma) {
            *strchr(input, ',') = '.';
            replaceComma = NULL;
        }

        if(isDecimal(input)) {
            *a = atof(input);
            break;
        }
    }

    while(1) {
        printf("\nb eingeben:\n");
        scanf("%s", input);

        replaceComma = strchr(input, ',');
        if(replaceComma) {
            *strchr(input, ',') = '.';
            replaceComma = NULL;
        }

        if(isDecimal(input)) {
            *b = atof(input);
            break;
        }
    }

    while(1) {
        printf("\nc eingeben:\n");
        scanf("%s", input);

        replaceComma = strchr(input, ',');
        if(replaceComma) {
            *strchr(input, ',') = '.';
            replaceComma = NULL;
        }

        if(isDecimal(input)) {
            *c = atof(input);
            break;
        }
    }

}

int confirmRestart() {
    printf("\nDo you want to do another run? (y = continue)\n");
    char input[1];
    scanf("%1s", input);

    if(input[0] != 'y') {
        return 0;
    }

    return 1;
}

#endif //SQUARE_ROOTS_FUNCTIONS_H
