/*
ATM System Main Program

Handles login, menu navigation, and calls ATM functions.

Authors:
- Denaton Agbikossi
- Precious Mozia
*/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

void displayMenu() {
    printf("\n===== ATM MENU =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Transactions\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    char username[20], pin[5];
    int userIndex = -1;

    printf("==== Welcome to the ATM System ====\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter PIN: ");
    scanf("%s", pin);

    userIndex = login(username, pin);

    if (userIndex == -1) {
        printf("Login failed. Exiting...\n");
        return 0;
    }

    printf("Login successful! Welcome, %s\n", username[userIndex]);

    int choice;
    double amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_balance(userIndex);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(userIndex, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(userIndex, amount);
                break;
            case 4:
                view_transactions(userIndex);
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
