#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "installment/installment.h"
#include "input/input.h"

#define DEFAULT_MONTHLY_RATE 500
#define DEFAULT_RUNTIME 12

double calculateRuntime(double loanAmount, double interestRate, double monthlyRate);
double calculateMonthlyRate(double loanAmount, double interestRate, double runtimeInMonths);

int main() {
    double loanAmount = 0;
    double interestRate = 0;

    double runtime = DEFAULT_RUNTIME;
    double monthlyRate = DEFAULT_MONTHLY_RATE;

    InstallmentTable *table;

    char input[1];
    getInput(&loanAmount, &interestRate, input);

    if(input[0] == 'A' || input[0] == 'a') {
        runtime = calculateRuntime(loanAmount, interestRate, monthlyRate);
        printf("\nBei einer monatlichen Rate von %.2f Euro betr\x84gt die Laufzeit %.0f Monate\n\n", monthlyRate, runtime);

        table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
    } else {
        monthlyRate = calculateMonthlyRate(loanAmount, interestRate, runtime);
        printf("\nBei einer Laufzeit von %.0f Monaten betr\x84gt die monatliche Rate %.2lf Euro\n\n", runtime, monthlyRate);

        table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
    }

    printInstallmentTable(table);

    while (1) {
        printf("\nM\x94""chtest du etwas \x84ndern?\n");
        printf("A - Monatl. Rate\n");
        printf("B - Laufzeit \x84ndern\n");
        printf("C - Darlehensbetrag \x84ndern\n");
        printf("D - Zinssatz \x84ndern\n");
        printf("<Beliebiges Zeichen> - Beenden\n");

        char in[1];
        scanf("%s", in);

        if(in[0] == 'A' || in[0] == 'a') {
            printf("Bitte gib die monatl. Rate an:\n");
            scanf("%lf", &monthlyRate);

            runtime = calculateRuntime(loanAmount, interestRate, monthlyRate);
            free(table);
            table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
        } else if(in[0] == 'B' || in[0] == 'b') {
            printf("Bitte gib die Laufzeit an:\n");
            scanf("%lf", &runtime);

            monthlyRate = calculateMonthlyRate(loanAmount, interestRate, runtime);
            free(table);
            table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
        } else if(in[0] == 'C' || in[0] == 'c') {
            printf("Bitte gib den Betrag an:\n");
            scanf("%lf", &loanAmount);

            monthlyRate = calculateMonthlyRate(loanAmount, interestRate, runtime);
            free(table);
            table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
        } else if(in[0] == 'D' || in[0] == 'd') {
            printf("Bitte gib den Zinssatz an:\n");
            scanf("%lf", &interestRate);

            monthlyRate = calculateMonthlyRate(loanAmount, interestRate, runtime);
            free(table);
            table = calculateInstallmentTable(loanAmount, interestRate, monthlyRate, runtime);
        } else {
            printf("\nGoodbye!\n");
            break;
        }

        printInstallmentTable(table);
    }

    return 0;
}

double calculateRuntime(double loanAmount, double interestRate, double monthlyRate) {
    double a = (-1200 * monthlyRate) / ((loanAmount * interestRate) - (1200 * monthlyRate));
    double b = (interestRate + 1200) / 1200;
    double runtime = log10(a) / log10(b);
    return ceil(runtime);
}

double calculateMonthlyRate(double loanAmount, double interestRate, double runtimeInMonths) {
    double a = (interestRate) / (12 * 100);
    double monthlyRate = loanAmount * (a / (1 - (pow( 1 + a, -runtimeInMonths))));
    return monthlyRate;
}
