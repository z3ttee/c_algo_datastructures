//
// Created by Cedric Zitzmann on 02.07.2021.
//
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "installment.h"
InstallmentTable *calculateInstallmentTable(double loanAmount, double interestRate, double monthlyRate, double runtime) {
    InstallmentTable *table = (InstallmentTable *) malloc(sizeof(InstallmentTable));
    table->totalRepayment = 0;
    table->totalInterest = 0;
    table->totalPaid = 0;
    table->size = ceil(runtime);
    table->arr = malloc(sizeof(Installment) * table->size);

    double lastRate = 0;

    for(int i = 0; loanAmount > 0 && i < table->size; ++i) {
        int rateNr = i + 1;

        double interestAmount = (loanAmount * interestRate) / 1200;
        double repayment = monthlyRate - interestAmount;

        if(loanAmount - repayment < 0) {
            repayment = loanAmount - interestAmount;

            lastRate = repayment + interestAmount;
            loanAmount = 0;
        } else {
            loanAmount -= repayment;
        }

        Installment *installment = (Installment *) malloc(sizeof(Installment));
        installment->rateNr = rateNr;
        installment->interestAmount = interestAmount;
        installment->repayment = repayment;
        installment->rest = loanAmount;

        table->arr[i] = *installment;
        table->totalRepayment += repayment;
        table->totalInterest += interestAmount;
    }

    table->totalPaid = table->totalRepayment + table->totalInterest;
    table->lastRate = lastRate;
    return table;
}

void printInstallmentTable(InstallmentTable *table) {
    if(table == NULL) return;

    printf("%-8s | %12s | %12s | %12s  \n", "Rate", "Zinsen", "Tilgung", "Rest");

    for(int i = 0; i < table->size; i++) {
        printf("%-8d    %12.2lf    %12.2lf    %12.2lf\n", table->arr[i].rateNr, table->arr[i].interestAmount, table->arr[i].repayment, table->arr[i].rest);
    }

    printf("\n%8s    %12.2lf    %12.2lf    %12.2lf\n", "Gesamt", table->totalInterest, table->totalRepayment, table->totalPaid);
    printf("\nDie letzte Rate betr\x84gt %.2lf Euro.\n", table->lastRate);
}
