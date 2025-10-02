/*
Header file with function prototypes.
Provides the interface for ATM operations.

Authors:
- Denaton Agbikossi
- Precious Mozia
*/

#ifndef OPERATION_H
#define OPERATION_H

#define MAX_USERS 10
#define MAX_TRANSACTIONS 5
#define MAX_STR 100

// Functions
int login(char username[], char pin[]);
void check_balance(int userIndex);
void deposit(int userIndex, double amount);
void withdraw(int userIndex, double amount);
void view_transactions(int userIndex);
void add_transaction(int userIndex, const char* action);
void exit_program(void);

#endif
