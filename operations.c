/*
Implementation of ATM functions.

Authors: 
- Denaton Agbikossi
- Precious Mozia
*/

#include "operations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Predefined users
char usernames[MAX_USERS][20] = {"denaton", "precious", "judith", "nene"};
char pins[MAX_USERS][5]       = {"1234", "5678", "4321", "8765"};
double balances[MAX_USERS]    = {1000.0, 1500.0, 800.0, 1200.0};
char transactions[MAX_USERS][MAX_TRANSACTIONS][MAX_STR];
int transactionCount[MAX_USERS] = {0, 0, 0, 0};

// Login validation
int login(char username[], char pin[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, usernames[i]) == 0 &&
            strcmp(pin, pins[i]) == 0) {
            return i; // Successful login
        }
    }
    return -1; // Failed
}

// Balance check
void check_balance(int userIndex) {
    printf("Your current balance is: %.2f RWF\n", balances[userIndex]);
    add_transaction(userIndex, "Checked Balance");
}

// Deposit
void deposit(int userIndex, double amount) {
    if (amount <= 0) {
        printf("Invalid deposit amount. Must be positive.\n");
    } else {
        balances[userIndex] += amount;
        printf("Deposited %.2f RWF. New balance: %.2f RWF\n", amount, balances[userIndex]);
        char log[MAX_STR];
        sprintf(log, "Deposited %.2f", amount);
        add_transaction(userIndex, log);
    }
}

// Withdraw

// View transaction history

// Record transaction

// Exit program