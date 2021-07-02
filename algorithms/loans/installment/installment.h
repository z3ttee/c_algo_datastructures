//
// Created by Cedric Zitzmann on 02.07.2021.
//
#pragma once

#ifndef LOANS_INSTALLMENT_H
#define LOANS_INSTALLMENT_H

typedef struct Installment {
    int rateNr;
    double interestAmount;
    double repayment;
    double rest;
} Installment;

typedef struct InstallmentTable {
    int size;
    Installment *arr;
    double totalInterest;
    double totalRepayment;
    double totalPaid;
    double lastRate;
} InstallmentTable;

InstallmentTable *calculateInstallmentTable(double loanAmount, double interestRate, double monthlyRate, double runtime);
void printInstallmentTable(InstallmentTable *table);

#endif //LOANS_INSTALLMENT_H
