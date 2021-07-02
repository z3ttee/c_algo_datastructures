//
// Created by Cedric Zitzmann on 02.07.2021.
//

#include "input.h"
#include <stdio.h>

void getInput(double *outLoan, double *outInterest, char *quest) {
    printf("Willkommen zu ihrer pers\x94nlichen Kreditberechnung!\n");
    printf("Hier k\x94nnen sie ihre Laufzeit oder monatliche Rate berechnen.\n");
    printf("Dazu ben\x94tigen wir aber ein paar Daten von Ihnen, also legen wir los:\n");
    printf("[]=====================================================[]\n\n");

    printf("Geben sie die Kreditsumme ein:\n");
    scanf("%lf", outLoan);

    printf("Geben sie den Zinssatz an (in Prozent):\n");
    scanf("%lf", outInterest);

    printf("Was soll berechnet werden?\n");
    printf("<A> - Laufzeit berechnen\n");
    printf("<Beliebiges Zeichen> - Monatl. Rate berechnen\n");

    scanf("%s", quest);
}

