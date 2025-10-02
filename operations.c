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
int login(char usernameInput[], char pinInput[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(usernameInput, usernames[i]) == 0 &&
            strcmp(pinInput, pins[i]) == 0) {
            return i; // Successful login
        }
    }
    return -1; // Failed
}

// Check balance
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
        sprintf(log, "Deposited %.2f RWF", amount);
        add_transaction(userIndex, log);
    }
}

// Withdraw
void withdraw(int userIndex, double amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount. Must be positive.\n");
    } else if (amount > balances[userIndex]) {
        printf("Insufficient funds. Your balance is %.2f RWF\n", balances[userIndex]);
    } else {
        balances[userIndex] -= amount;
        printf("Withdrew %.2f RWF. New balance: %.2f RWF\n", amount, balances[userIndex]);
        char log[MAX_STR];
        sprintf(log, "Withdrew %.2f RWF", amount);
        add_transaction(userIndex, log);
    }
}

// Record transaction
void add_transaction(int userIndex, const char* action) {
    if (transactionCount[userIndex] < MAX_TRANSACTIONS) {
        strcpy(transactions[userIndex][transactionCount[userIndex]], action);
        transactionCount[userIndex]++;
    } else {
        // Shift older transactions to make room
        for (int i = 1; i < MAX_TRANSACTIONS; i++) {
            strcpy(transactions[userIndex][i-1], transactions[userIndex][i]);
        }
        strcpy(transactions[userIndex][MAX_TRANSACTIONS-1], action);
    }
}

// View transaction history
void view_transactions(int userIndex) {
    if (transactionCount[userIndex] == 0) {
        printf("No transactions found.\n");
    } else {
        printf("Last %d transactions:\n", transactionCount[userIndex]);
        for (int i = 0; i < transactionCount[userIndex]; i++) {
            printf("%d. %s\n", i+1, transactions[userIndex][i]);
        }
    }
}

// Exit program
void exit_program(void) {
    printf("Thank you for using the ATM. Goodbye!\n");
    exit(0);
}
